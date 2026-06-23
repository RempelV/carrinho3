#define velmotor_left 3
#define motor_left_fwd 4
#define motor_left_bck 5
#define velmotor_right 10
#define motor_right_fwd 9
#define motor_right_bck 8
#define tmp 3000
int vel=0;

void setup() {
  pinMode(velmotor_left,OUTPUT);
  pinMode(motor_left_fwd,OUTPUT);
  pinMode(motor_left_bck,OUTPUT);
  pinMode(velmotor_right,OUTPUT);
  pinMode(motor_right_fwd,OUTPUT);
  pinMode(motor_right_bck,OUTPUT);
  digitalWrite(motor_left_fwd,LOW);
  digitalWrite(motor_left_bck,LOW);
  digitalWrite(motor_right_fwd,LOW);
  digitalWrite(motor_right_bck,LOW);
  analogWrite(velmotor_left,vel);
  analogWrite(velmotor_right,vel);
}

void stopAll() {
  digitalWrite(motor_left_fwd, LOW);
  digitalWrite(motor_left_bck, LOW);
  digitalWrite(motor_right_fwd, LOW);
  digitalWrite(motor_right_bck, LOW);
  delay(100)
}

void loop() {
  vel=255;
  analogWrite(velmotor_left, vel);
  analogWrite(velmotor_right, vel);

  stopAll();
  digitalWrite(motor_left_fwd, HIGH);
  delay(tmp);

  stopAll();
  digitalWrite(motor_right_fwd, HIGH);
  delay(tmp);

  stopAll();
  digitalWrite(motor_left_bck, HIGH);
  digitalWrite(motor_right_bck, HIGH);
  delay(tmp);

}
