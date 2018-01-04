#include <Ultrasonic.h>

const int trig = 4;
const int echo = 5;

Ultrasonic ultrasonic(trig,echo);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int distancia = ultrasonic.distanceRead();
Serial.println(distancia);
delay(1000);
}
