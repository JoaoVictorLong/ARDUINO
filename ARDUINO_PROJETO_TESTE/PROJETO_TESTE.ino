int soma1 = 5;
int soma2 = 3;
int resultado;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
resultado = soma1 = soma2;
Serial.println(resultado);
delay(1000);
}
