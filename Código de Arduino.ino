#define V1 8
#define A1 9
#define R1 4
#define V2 5
#define A2 6
#define R2 7

int tiempoCambio = 1000;
int tiempoEspera = 8000;
bool peaton = true;
bool rojo = true;
int frec = 50;

void setup() {
  Serial.begin(9600);

  pinMode(V1, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(R2, OUTPUT);

  digitalWrite(V1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(V2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(V1, HIGH);
  digitalWrite(R2, HIGH);

  attachInterrupt(digitalPinToInterrupt(2), PULSADOR2, RISING);
  attachInterrupt(digitalPinToInterrupt(3), PULSADOR1, RISING);
}
void loop() {
  while ((rojo == true) && (digitalRead(V1) == HIGH) && (digitalRead(R2) == HIGH))
  {
    encenderSemaforo2();
    peaton = true;
  }
  while ((rojo == true) && (digitalRead(V2) == HIGH) && (digitalRead(R1) == HIGH))
  {
    encenderSemaforo1();
    peaton = true;
  }
  while  (peaton == false)
  {
    if ((digitalRead(V1) == HIGH) && (digitalRead(R2) == HIGH))
    {
      delay(tiempoCambio);
      digitalWrite(V1, LOW);
      digitalWrite(A1, HIGH);
      delay(tiempoCambio);
      digitalWrite(A1, LOW);
      digitalWrite(R1, HIGH);
      delay(tiempoCambio);
      digitalWrite(R2, LOW);
      digitalWrite(V2, HIGH);
      peaton = true;
    }
    else if ((digitalRead(V2) == HIGH) && (digitalRead(R1) == HIGH))
    {
      delay(tiempoEspera);
      delay(tiempoCambio);
      peaton = true;
    }
    break;
  }
  while (rojo == false)
  {
    noTone(12);
    digitalWrite(V1, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    digitalWrite(V2, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(R2, HIGH);
    delay(tiempoEspera);
    delay(tiempoEspera);
    if ((digitalRead(R2) == HIGH) && (digitalRead(R1) == HIGH))
    {
      digitalWrite(R2, LOW);
      digitalWrite(V2, HIGH);
    }
    rojo = true;
  }
}
void encenderSemaforo2() {
  delay(tiempoEspera / 4);
  if (peaton == false) {
    delay(tiempoCambio);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    delay(tiempoCambio);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    delay(tiempoCambio);
    digitalWrite(R2, LOW);
    digitalWrite(V2, HIGH);
    tone(12, frec);
    peaton = true;
  }
  delay(tiempoEspera / 4);
  if (peaton == false) {
    delay(tiempoCambio);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    delay(tiempoCambio);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    delay(tiempoCambio);
    digitalWrite(R2, LOW);
    digitalWrite(V2, HIGH);
    tone(12, frec);
    peaton = true;
  }
  delay(tiempoEspera / 4);
  if (peaton == false) {
    delay(tiempoCambio);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    delay(tiempoCambio);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    delay(tiempoCambio);
    digitalWrite(R2, LOW);
    digitalWrite(V2, HIGH);
    tone(12, frec);
    peaton = true;
  }
  delay(tiempoEspera / 4);
  if (peaton == false) {
    delay(tiempoCambio);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    delay(tiempoCambio);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    delay(tiempoCambio);
    digitalWrite(R2, LOW);
    digitalWrite(V2, HIGH);
    tone(12, frec);
    peaton = true;
  }
  digitalWrite(V1, LOW);
  digitalWrite(A1, HIGH);
  delay(tiempoCambio);
  digitalWrite(A1, LOW);
  digitalWrite(R1, HIGH);
  delay(tiempoCambio);
  digitalWrite(R2, LOW);
  digitalWrite(V2, HIGH);
  tone(12, frec);
  peaton = true;
}
void encenderSemaforo1() {
  delay(tiempoEspera / 4);
  if (peaton == false) {
    delay(tiempoEspera);
    peaton = true;
  }
  delay(tiempoEspera / 4);
  if (peaton == false) {
    delay(tiempoEspera);
    peaton = true;
  }
  delay(tiempoEspera / 4);
  if (peaton == false) {
    delay(tiempoEspera);
    peaton = true;
  }
  delay(tiempoEspera / 4);
  if (peaton == false) {
    delay(tiempoEspera);
    peaton = true;
  }
  noTone(12);
  digitalWrite(V2, LOW);
  digitalWrite(A2, HIGH);
  delay(tiempoCambio);
  digitalWrite(A2, LOW);
  digitalWrite(R2, HIGH);
  delay(tiempoCambio);
  digitalWrite(R1, LOW);
  digitalWrite(V1, HIGH);
  peaton = true;
}
void PULSADOR1 () {
  if (peaton == true)
    peaton = false;
}
void PULSADOR2() {
  if (rojo == true)
    rojo = false;
}
