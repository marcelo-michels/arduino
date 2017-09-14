// DHT
#include <DHT.h>
#define DHTPIN D3
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);
int umidade;
int temperatura;

// Display
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.clearDisplay();
}

void loop() {
  lerDHT();
  mostrarDisplay();
}

void lerDHT(){
    umidade = dht.readHumidity();
  temperatura = dht.readTemperature(false);
  
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  Serial.print("Umidade: ");
  Serial.println(umidade);
  Serial.println("");
  delay(1000);
}

void mostrarDisplay() {
  imprimeDisplay("Temperatura", (temperatura), " C");
  imprimeDisplay("Umidade", (umidade), " %");
}

void imprimeDisplay(const char* texto1, int medicao, const char* texto2) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(texto1);
  display.setTextSize(5);
  display.setCursor(20, 20);
  display.print(medicao);
  display.setTextSize(2);
  display.print(texto2);
  display.display();
  delay(2000);
}

