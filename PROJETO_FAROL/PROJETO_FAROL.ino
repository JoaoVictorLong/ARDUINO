int verde = 5;
int amarelo = 6;
int vermelho = 7;
int botao = 4;
int estadobotao;
int aceso = 1;
//int ax = HIGH;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(verde,OUTPUT);
pinMode(amarelo,OUTPUT);
pinMode(vermelho,OUTPUT);
pinMode(botao,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    estadobotao = digitalRead(botao);
   Serial.print(estadobotao);
     //if ( ax == HIGH){
     while ( aceso == 1)
     {
     digitalWrite(verde,HIGH);
    delay(70);
    digitalWrite(verde,LOW);
    delay(20);
     digitalWrite(amarelo,HIGH);
    delay(20);
    digitalWrite(amarelo,LOW);
    delay(20);
     digitalWrite(vermelho,HIGH);
    delay(50);
    digitalWrite(vermelho,LOW);
    delay(20);
    estadobotao = digitalRead(botao);
    Serial.print(estadobotao);
   if (estadobotao == 1){
     Serial.println("TESTE");
     aceso++;
    }
      
     }
}
