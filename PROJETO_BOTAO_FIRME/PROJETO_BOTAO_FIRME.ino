const int led = 7;
const int botao = 5;
int estadoled = LOW;
int ultimoestadoled = LOW;
int estadobotao = LOW;
int ultimoestadobotao = LOW;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadobotao = digitalRead(botao);
  if ( estadobotao != ultimoestadobotao )
  {
    if ( estadobotao == HIGH)
    {
      if ( ultimoestadoled == HIGH)
      {
          digitalWrite(led,HIGH);
          ultimoestadoled = LOW;
      }
      else 
      {
        digitalWrite(led,LOW);
        ultimoestadoled = HIGH;
      }
    }
  }
     ultimoestadobotao = estadobotao;
}








//  if ( estadobotao == LOW ){
//      digitalWrite(led,LOW);
//    }
//    else{
//      digitalWrite(led,HIGH);
//      }
//  if ( estadoled == HIGH ){
//      digitalWrite(led,HIGH);
//      }
//  else{
//       digitalWrite(led,LOW);
//    }
//}

