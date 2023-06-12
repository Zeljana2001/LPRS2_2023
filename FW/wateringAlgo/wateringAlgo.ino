const int motorPin = A0; // Pin na kojem je spojen motor

void setup() {
  pinMode(motorPin, OUTPUT); // Postavljanje pina kao izlaznog
}

void loop() {
  digitalWrite(motorPin, HIGH); // Paljenje motora
  delay(5000); // Pauza od 1 sekunde
  
  digitalWrite(motorPin, LOW); // Gašenje motora
  delay(1000); // Pauza od 1 sekunde
}
