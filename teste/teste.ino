const int led = 7;
const int botao = 5;
int estadoled = LOW;
int ultimoled = LOW;
int estadobotao = LOW;
int ultimobotao = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadobotao = digitalRead(botao);
  if (estadobotao != ultimobotao)
  {
    if ( estadobotao == HIGH)
    {
      if (estadoled == HIGH )
      {
        digitalWrite(led,HIGH);
        ultimoled = LOW;
      }
      else
      {
        digitalWrite(led,LOW);
        ultimoled = HIGH;
      }
    }
   }
ultimobotao = estadobotao;
}
