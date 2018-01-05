//#include <Ultrasonic.h>
#include <UIPEthernet.h>
#include <PubSubClient.h>
#include <Servo.h>
//temperatura
int const TEMPERATURA_SENSOR = A0;
int leitura;
float temperatura;
//proximidade
 //const int trig = 4 ;
 //const int echo = 5 ;
 //Ultrasonic ultrasonic(trig, echo);
//rede
byte mac [] = { 0xAC, 0x11, 0xDD, 0x56, 0xCC, 0xEE };
char* servidor_mqtt = "192.168.0.52";
int porta_mqtt = 1883;
long lastReconnectAttempt = 0;
//motor
Servo motor;
//botao
int const botao = 5;
int estado = LOW;
int ultimo = LOW;
int desligado = LOW;

void mensagem_mqtt( char* topic, byte* payload, unsigned int length)
{
  char* payload_char = payload;
  payload_char[length] = 0;
  String payload_String = String (payload_char);
  String topic_string = String (topic);
  Serial.println("topic:");
  Serial.print(topic_string);
  Serial.println("payload:");
  Serial.print(payload_String);
  int payload_int = payload_String.toInt();
}
EthernetClient ethernet_client;
PubSubClient pubsub (servidor_mqtt, porta_mqtt, mensagem_mqtt, ethernet_client);

boolean reconnect ()
{
  Serial.print("reconectando...");
  if (pubsub.connect("joao", "hdfojuma" , "9paGPkloSn9u"))
  {
    Serial.println("conectado");
    pubsub.publish("distancia", "JOAO");
    Serial.println("voltei");
    pubsub.subscribe("temperatura");
  }
}

void setup() {
  // put your setup code here, to run once:
  //temperautra
  pinMode(TEMPERATURA_SENSOR, INPUT);
  Serial.begin(9600);
  analogReference(INTERNAL);
  //proximidade
   //pinMode(trig, OUTPUT);
   //pinMode(echo, INPUT);
  //rede
  if (Ethernet.begin(mac) == 0)
  {
    Serial.print("não pegou ip");
  }
  else
  {
    Serial.println("conectado");
    Serial.println(Ethernet.localIP());
  }
  if (pubsub.connect("joao", "hdfojuma" , "9paGPkloSn9u"))
  {
    pubsub.publish("temperatura", "on");
     //pubsub.publish("distancia", "on" );
    Serial.println("temperatura enviada");
     //Serial.println("distancia enviada");
  }
  else
  {
    Serial.println("mqtt não connectado");
  }
  lastReconnectAttempt = 0;
  //motor
  motor.attach(7);
  pinMode(botao,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //temperatura
  leitura = analogRead(TEMPERATURA_SENSOR);
  temperatura = leitura * 0.1075268817204301;
  String temperatura_string = String (temperatura);
  char temperatura_char[3];
  temperatura_string.toCharArray (temperatura_char, 3);
  pubsub.publish("temperatura", temperatura_char);
  Serial.println("temperatura: ");
  Serial.println(temperatura_char);
  delay(1000);
 estado = digitalRead(botao);
  if ( estado!= ultimo )
  {
    if ( estado == HIGH)
    {
      if ( desligado == HIGH)
      {
          motor.write(130);
          delay(500);
          desligado = LOW;
      }
      else 
      {
         motor.write(30);
         delay(500);
         desligado = HIGH;
      }
    }
  }
     ultimo = estado;
  /*proximidade
   int distancia = ultrasonic.distanceRead();
   String distancia_string = String (distancia);
   char distancia_char[3];
   distancia_string.toCharArray (distancia_char, 3);
   pubsub.publish("distancia", distancia_char);
   Serial.println("distancia: ");
   Serial.println(distancia_char);
   delay(1000);
  */
  if (!pubsub.connected())
  {
    long now = millis();
    if (now - lastReconnectAttempt > 5000)
    {
      Serial.print("Reconectando...");
      lastReconnectAttempt = now;
      if (reconnect())
      {
        lastReconnectAttempt = 0;
      }
    }
  }
  else
  {
    pubsub.loop();
  }
}
