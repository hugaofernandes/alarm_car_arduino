//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Trava e Alarme de Carro
// 
// Made by hugo medeiros fernandes
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/2150351-trava-e-alarme-de-carro


#include <Servo.h>
#include <IRremote.h>

int RECV_PIN = 2; // the pin where you connect the output pin of TSOP4838
IRrecv irrecv(RECV_PIN);
decode_results results;

#define abrir 16575
#define fechar 255
Servo servoMotor;
int alarme = 13;
int porta = 12;
int var = 0;

void setup() {
  Serial.begin(9600);   // you can comment this line
  irrecv.enableIRIn();  // Start the receiver 
  pinMode(alarme, OUTPUT);
  pinMode(porta, INPUT);
  servoMotor.attach(5);
  servoMotor.write(180);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch (value){
      case abrir:
      		servoMotor.write(180);
        	digitalWrite(alarme, LOW);
      		var = 0;
      		break;
      case fechar:
      		servoMotor.write(90);
      		var = 1;
      		break;
    }
    irrecv.resume(); // Receive the next value
  }
  if (var and digitalRead(porta)){
      digitalWrite(alarme, HIGH);
  }
}

