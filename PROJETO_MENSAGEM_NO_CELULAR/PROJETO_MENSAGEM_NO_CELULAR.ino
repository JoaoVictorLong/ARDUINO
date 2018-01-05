#include <UIPEthernet.h>
#include <PubSubClient.h>
int buzina = 6;
int led = 7;

byte mac [] = { 0xDE, 0xAD, 0xAB, 0xCE, 0x3E, 0xAA};

char* servidor_mqtt = "m14.cloudmqtt.com";
int port_mqtt = 17763;

long lastReconnectAttempt = 0;

void mensagem_mqtt ( char* topic, byte* payload, unsigned int length) {
  char* payload_char = payload;
  payload_char[length] = 0;
  String payload_string = String (payload_char);
  String topic_string = String (topic);
  Serial.println("TOPIC;");
  Serial.println(topic_string);
  Serial.println("payload:");
  Serial.println(payload_string);
}
EthernetClient ethernet_client;
PubSubClient pubsub(servidor_mqtt, port_mqtt, mensagem_mqtt, ethernet_client);

boolean reconnect ()
{
  Serial.print("reconectando");
  if (pubsub.connect("joao", "hdfojuma" , "9paGPkloSn9u"))
  {
    Serial.println("conectado");
    pubsub.publish("temperatura", "voltei");
    Serial.println("voltei enviado");
    pubsub.subscribe("temperatura");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzina,OUTPUT);
  pinMode(led,OUTPUT);
  if (Ethernet.begin(mac) == 0)
  {
    Serial.print("não pegou endereço via DHCP");
  }
  else
  {
    Serial.println("conectado");
    Serial.println(Ethernet.localIP());
  }
  if (pubsub.connect("joao", "hdfojuma" , "9paGPkloSn9u"))
  {
   // Serial.println("conectando");
    pubsub.publish("temperatura", "15 grau celsius");
    Serial.println("temperatura enviada");
    // pubsub.subscribe("temperatura");
  }
  else
  {
    Serial.println("MQTT não conectado");
  }
  lastReconnectAttempt = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
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
