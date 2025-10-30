#include<Servo.h>

Servo servo;

int smokeA0=A0;

int buzzer =11;

int led = 12;

float sensorValue;

void setup() {
  pinMode(buzzer,OUTPUT);

  pinMode(led, OUTPUT);

  pinMode(smokeA0,INPUT);

   Serial.begin(9600);  

  Serial.println("Gas sensor warming up!");

  delay(20000);  

  servo.attach(8);

  servo.write(0);

  delay(2000);

}

void loop() {
    sensorValue=analogRead(smokeA0);

  if(sensorValue > 600)

  {

    Serial.print(  "Smoke detected!");

    digitalWrite(buzzer,HIGH);

    digitalWrite(led,HIGH);

    servo.write(90);

    delay(1000);

  }

  else

  {

     Serial.print(  "Smoke  not detected!");

    digitalWrite(buzzer, LOW);

    digitalWrite(led,LOW);

    servo.write(0);
    delay(1000);

  }

  delay(2000);  


}
