/* CC BY-NC 2024 by Júlia Rosell Saldaña
Use this code as you please. It's free and the main idea is that you will use it for helping people.
The only I would like is to use the Attribution-NonCommercial Creative Commons License and remember who wrote it in the first place, 
but it's not important and I don't really care. I only want people to enjoy music as much as I do.
*/

#include <Servo.h>

Servo fingerServo1;  // Servomotor per al dit 1
Servo fingerServo2;  // Servomotor per al dit 2
Servo bowServo1;     // Servomotor per a l'arc 1
Servo bowServo2;     // Servomotor per a l'arc 2
Servo bowServo3;     // Servomotor per a l'arc 3
Servo bowServo4;     // Servomotor per a l'arc 4

bool bowDirection1 = false;  // Direcció del servomotor de l'arc 1
bool bowDirection2 = false;  // Direcció del servomotor de l'arc 2
bool bowDirection3 = false;  // Direcció del servomotor de l'arc 3
bool bowDirection4 = false;  // Direcció del servomotor de l'arc 4

int motorPin1A = 2; // Primer motor DC connectat al pin digital 2 (PWM)
int motorPin1B = 3; // Primer motor DC connectat al pin digital 3 (PWM)
int motorPin2A = 4; // Segon motor DC connectat al pin digital 4 (PWM)
int motorPin2B = 5; // Segon motor DC connectat al pin digital 5 (PWM)
int motorPin3A = 6; // Tercer motor DC connectat al pin digital 6 (PWM)
int motorPin3B = 7; // Tercer motor DC connectat al pin digital 7 (PWM)
int motorPin4A = 8; // Quart motor DC connectat al pin digital 8 (PWM)
int motorPin4B = 9; // Quart motor DC connectat al pin digital 9 (PWM)

void setup() {
  Serial.begin(9600);  // Inicia la comunicació serial a 9600 bps
    // Inicialitza la posició dels servos a una posició segura abans de fer l'attach
  fingerServo1.write(30);
  fingerServo2.write(0);
  bowServo1.write(0);
  bowServo2.write(0);
  bowServo3.write(0);
  bowServo4.write(0);
  fingerServo1.attach(A0);  // Connecta el servomotor del dit 1 al pin A0
  fingerServo2.attach(A1);  // Connecta el servomotor del dit 2 al pin A1
  bowServo1.attach(A4);     // Connecta el servomotor de l'arc 1 al pin A4
  bowServo2.attach(A5);     // Connecta el servomotor de l'arc 2 al pin A5
  bowServo3.attach(A3);     // Connecta el servomotor de l'arc 3 al pin A6
  bowServo4.attach(A2);     // Connecta el servomotor de l'arc 4 al pin A7
  pinMode(motorPin1A, OUTPUT); // Configura el pin del primer motor com a sortida
  pinMode(motorPin1B, OUTPUT); // Configura el pin del primer motor com a sortida
  pinMode(motorPin2A, OUTPUT); // Configura el pin del segon motor com a sortida
  pinMode(motorPin2B, OUTPUT); // Configura el pin del segon motor com a sortida
  pinMode(motorPin3A, OUTPUT); // Configura el pin del tercer motor com a sortida
  pinMode(motorPin3B, OUTPUT); // Configura el pin del tercer motor com a sortida
  pinMode(motorPin4A, OUTPUT); // Configura el pin del quart motor com a sortida
  pinMode(motorPin4B, OUTPUT); // Configura el pin del quart motor com a sortida
  digitalWrite(motorPin1A, LOW); // Assegura't que el primer motor està aturat
  digitalWrite(motorPin1B, LOW); // Assegura't que el primer motor està aturat
  digitalWrite(motorPin2A, LOW); // Assegura't que el segon motor està aturat
  digitalWrite(motorPin2B, LOW); // Assegura't que el segon motor està aturat
  digitalWrite(motorPin3A, LOW); // Assegura't que el tercer motor està aturat
  digitalWrite(motorPin3B, LOW); // Assegura't que el tercer motor està aturat
  digitalWrite(motorPin4A, LOW); // Assegura't que el quart motor està aturat
  digitalWrite(motorPin4B, LOW); // Assegura't que el quart motor està aturat
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');  // Llegeix la comanda fins a la nova línia

    if (command.startsWith("finger1:")) {
      int position = command.substring(8).toInt();  // Extreu la posició de la comanda
      moveFingerAndBow(position, fingerServo1, bowServo1, motorPin1A, motorPin1B);
    } else if (command.startsWith("finger2:")) {
      int position = command.substring(8).toInt();  // Extreu la posició de la comanda
      moveFingerAndBow(position, fingerServo1, bowServo2, motorPin3A, motorPin3B);
    } else if (command.startsWith("finger3:")) {
      int position = command.substring(8).toInt();  // Extreu la posició de la comanda
      moveFingerAndBow(position, fingerServo1, bowServo3, motorPin2A, motorPin2B);
    } else if (command.startsWith("finger4:")) {
      int position = command.substring(8).toInt();  // Extreu la posició de la comanda
      moveFingerAndBow(position, fingerServo1, bowServo4, motorPin4A, motorPin4B);
    }
  }
}

void moveFingerAndBow(int position, Servo &fingerServo, Servo &bowServo, int motorPinA, int motorPinB) {
  if (&fingerServo == &fingerServo1) {
    // Per a fingerServo1, manté les quatre posicions originals
    switch (position) {
      case 1:
        fingerServo.write(0);  // Posició 1
        break;
      case 2:
        fingerServo.write(0);  // Posició 2
        break;
      case 3:
        fingerServo.write(0);  // Posició 3
        break;
      case 0:
      default:
        fingerServo.write(30);   // No tocar la corda
        break;
    }
  } else if (&fingerServo == &fingerServo2) {
    // Per a fingerServo2, mou endavant i enrere en tres posicions
    switch (position) {
      case 1:
        fingerServo.write(0);  // Posició 1
        break;
      case 2:
        fingerServo.write(45);  // Posició 2
        break;
      case 3:
        fingerServo.write(90);  // Posició 3
        break;
      case 0:
      default:
        fingerServo.write(30);   // Posició 0
        break;
    }
  }

  // La resta del codi es manté igual
  if (&bowServo == &bowServo1 || &bowServo == &bowServo4) {  // Si es tracta del bowServo1 o bowServo4, canvia la direcció
    bowServo.write(0);  // Mou l'arc a una posició fixa en la direcció contrària
  } else {
    bowServo.write(10);  // Mou l'arc a una posició fixa (ajusta segons sigui necessari)
  }
  analogWrite(motorPinA, 50);  // Gira el motor DC a una direcció a aproximadament el 25% de la velocitat
  digitalWrite(motorPinB, HIGH); // Gira el motor DC a una direcció
  delay(500); // Espera 
  if (&bowServo == &bowServo1 || &bowServo == &bowServo4) {  // Si es tracta del bowServo1 o bowServo4, canvia la direcció
    bowServo.write(10);  // Mou l'arc a la posició original en la direcció contrària
  } else {
    bowServo.write(0);  // Mou l'arc a la posició original
  }
  digitalWrite(motorPinA, LOW); // Atura el motor DC
  digitalWrite(motorPinB, LOW); // Atura el motor DC
}