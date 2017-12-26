int portabotao = 4;
int estadobotao;
int led = 6;
void setup() {
  // put your setup code here, to run once:
pinMode(portabotao,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
estadobotao = digitalRead(portabotao);
if ( estadobotao == HIGH ){
        digitalWrite(led,HIGH);
}
else
{
  digitalWrite(led,LOW);
}
}

