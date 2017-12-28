const int SENSOR_TEMPERATURA = A0;
int leitura_sensor;
float temperatura;
const int vermelho = 7;
const int amarelo = 6;
const int verde = 5;
const int buzina = 3;
const int botao1 = 12;
const int botao2 = 11;
int estadobotao1;
int estadobotao2;
void setup() {
  // put your setup code here, to run once:
  analogReference(INTERNAL);
  Serial.begin(9600);
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(buzina, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
}
void cabelo (){
  tone(buzina,1000);
      digitalWrite(vermelho,HIGH);
      digitalWrite(verde,LOW);
      digitalWrite(amarelo,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  //leitura do botao
   estadobotao1 =digitalRead(botao1);
   estadobotao2 =digitalRead(botao2);
  //Serial.print("botao1:");
  //Serial.println(estadobotao1);
  //delay(300);
  //Serial.print("botao2:");
  //Serial.println(estadobotao2);
  //delay(300);
  //leitura do sensor
  leitura_sensor = analogRead(SENSOR_TEMPERATURA);
  temperatura = leitura_sensor * 0.1075268817204301;  
  
  if ( estadobotao1 == HIGH )
  {
    while ( estadobotao2 == LOW )
    {
      estadobotao2 = digitalRead(botao2);
      cabelo();
    }
    noTone(buzina);
  }
  if ( temperatura < 28 && temperatura >= 22 )
  {
    digitalWrite(verde, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);
    noTone(buzina);
  }
  if ( temperatura >= 28 && temperatura < 30 )
  {
  digitalWrite(amarelo,HIGH);
  digitalWrite(vermelho,LOW);
  digitalWrite(verde,LOW);
  noTone(buzina);
  }
  if ( temperatura >= 30 && temperatura < 36 )
  {
  tone(buzina,2000);
  digitalWrite(vermelho,HIGH);
  digitalWrite(verde,LOW);
  digitalWrite(amarelo,LOW);
  }
  Serial.print("temperatura:");
  Serial.println(temperatura);
  delay(1000);
}

