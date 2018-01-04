#include <Servo.h>
//declara a variavel
Servo servo1;

void setup() {
  // put your setup code here, to run once:
  //declara a porta
servo1.attach(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(30);
  delay(500);
  servo1.write(130);
  delay(500);
}
