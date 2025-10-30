int mq4Pin=A0;
float R0=22.5;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(mq4Pin);
  float voltage=sensorValue*(5.0/1023.0);

  // Assuming RL= 1k ohm on the module
  float Rs=(5.0-voltage)/voltage;
  float ratio=Rs/R0;

  // Log-log approximation from MQ-4 datasheet for CH4
  float ppm=pow(10,(-0.38*log10(ratio)+1.41));

  Serial.print("Analog:");
  Serial.print(sensorValue);
  Serial.print(" | Voltage:");
  Serial.print(voltage,2);
  Serial.print("V | Rs/R0: ");
  Serial.print(ratio,2);
  Serial.print(" | CH4 PPM :");
  Serial.println(ppm,2);
  
  delay(1000);

}
