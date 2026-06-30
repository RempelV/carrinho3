#include <SoftwareSerial.h>

SoftwareSerial BT(6, 7); // Arduino RX, TX

#define ENA 3
#define IN1 4
#define IN2 5

#define ENB 10
#define IN3 9
#define IN4 8

int velocidade = 255;

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println("STOP");
}

void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("FORWARD");
}

void re() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("BACKWARD");
}

void esquerda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("LEFT");
}

void direita() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("RIGHT");
}

void setup() {

  Serial.begin(9600);
  BT.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  parar();

  Serial.println("Bluetooth RC iniciado.");
}

void loop() {

  if (BT.available()) {

    char c = BT.read();

    Serial.print("ASCII ");
    Serial.print((int)c);
    Serial.print(" -> ");
    Serial.println(c);

    // Ignora aspas e quebras de linha
    if (c == '"' || c == '\r' || c == '\n')
      return;

    switch (c) {

      case 'F':
        frente();
        break;

      case 'B':
        re();
        break;

      case 'L':
        esquerda();
        break;

      case 'R':
        direita();
        break;

      case 'S':
        parar();
        break;

      default:
        Serial.println("Comando desconhecido.");
        break;
    }
  }
}
