int led_arduino = 6;
int led_arduino2 = 4;

void setup() {
  // put your setup code here, to run once:
pinMode (led_arduino,OUTPUT);
pinMode (led_arduino2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if ( 5 > 6 ){
digitalWrite(led_arduino,HIGH);
}
else{
digitalWrite(led_arduino2,HIGH);
}
}


