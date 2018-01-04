#include <UIPEthernet.h>
#include <PubSubClient.h>
#include <Ultrasonic.h>
#include <Servo.h>
//variaveis do sensor de proximidade

int const tring = 4;
int const echo = 5;
Ultrasonic ultrasonic(tring, echo);

//variaveis do motor
Servo servo1;

//variaveis do led
const int verde = A0;
const int amarelo = A1;
const int vermelho = A2;

//variavel buzina
int const buzina = 6;

//botao
const int botao = 3;
int sair;
int estadobotao;

//rede
byte mac [] = { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11};

char* servidor_mqtt = "m14.cloudmqtt.com";
int porta_mqtt = 17763;

long lastreconnectAttempt = 0;

void mensagem_mqtt(char* topic, byte* playload, unsigned int length)
{
  char* playload_char = payload;
  play_char[length] = 0;
  String playload_string = String 
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //sensor de proximidade
  pinMode(tring, OUTPUT);
  pinMode(echo, INPUT);
  //MOTOR
  servo1.attach(7);
  //LED
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  //buzina
  pinMode(buzina, OUTPUT);
  //botao
  pinMode(botao, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //sensor de distancia
  int distancia = ultrasonic.distanceRead();
  //Serial.println(distancia);
  delay(50);

  //botao
  estadobotao = digitalRead(botao);
  Serial.println(estadobotao);

  if ( estadobotao != botao )
  {
    if ( estadobotao == HIGH )
    {
      if ( sair == HIGH )
      {
        //motor
        servo1.write(30);
        delay(200);
      }
      else
      {
        servo1.write(130);
        delay(200);
      }
    }
  }
  sair = estadobotao;
  //LED
  if ( distancia >= 8)
  {
    digitalWrite(verde, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);
  }
  else
  {
    digitalWrite(verde, LOW);
  }
  if ( distancia < 8 && distancia > 4 )
  {
    digitalWrite(amarelo, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(vermelho, LOW);
    tone(buzina, 500);
    delay(300);
    noTone(buzina);
    delay(300);
  }
  if (distancia <= 4)
  {
    digitalWrite(vermelho, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, LOW);
    tone(buzina, 5000);
    delay(200);
    noTone(buzina);
    delay(200);

  }
}
