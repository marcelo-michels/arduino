#include <DHT.h>

#define DHTPIN D3
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(115200);
}

void loop() {

  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature(false);
  
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  Serial.print("Umidade: ");
  Serial.println(umidade);
  Serial.println("");
  delay(5000);
}
