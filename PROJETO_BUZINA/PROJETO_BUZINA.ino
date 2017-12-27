const int led = 5;
int som;
int buzina = 7;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(buzina,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (Serial.available()){
  som = Serial.parseInt();
  Serial.println(som);
  switch( som ){
      case 1:
        tone(buzina,5000);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        break;
       case 2:
        tone(buzina,1000);
        digitalWrite(led,HIGH);
        delay(1000);
        digitalWrite(led,HIGH);
        delay(1000);
        break;
       case 3:
        tone(buzina,2000);
        digitalWrite(led,HIGH);
        delay(2000);
        digitalWrite(led,HIGH);
        delay(2000);
        break;
        default:
        noTone(buzina);
        digitalWrite(led,LOW);
        break;
  }
 }
}
