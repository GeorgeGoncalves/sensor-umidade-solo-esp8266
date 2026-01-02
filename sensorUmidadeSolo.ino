void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensor = analogRead(A0);
  Serial.print("Valor da umidade do solo: ");
  Serial.println(sensor);

  delay(2000);
}
