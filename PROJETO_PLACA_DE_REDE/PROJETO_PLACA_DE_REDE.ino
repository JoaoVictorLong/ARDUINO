#include <UIPEthernet.h>
byte mac[] = { 0xDE ,0xAD ,0xBE ,0xEF,0xAA ,0xAA };
char server[] = "www.google.com.br";

EthernetClient client;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //int length
  //int len = strlen(server);
  //int len2 = strlen(a);
  //int len3 = strlen(b);
  //Serial.print(len);
  //Serial.print(len2);
  //Serial.print(len3);
  if ( Ethernet.begin(mac) == 0 )
  {
    Serial.print("DEU MERDA");
  }
  delay(1000);
  if (client.connect(server,80))
  {
    Serial.print("não deu tanta merda");
    client.println("get /search?q=arduino HTTP/1.1");
    client.println("host: www.google.com");
    client.println("connection: close");
    client.println();
  }
  else
  {
    Serial.print("DEU MERDA 2.0");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (client.available())
  {
    char c = client.read();
    Serial.println(c);
  }
   if(!client.connected())
   {
    Serial.println("não conectado");
    client.stop();
    while(true);
   }
}
