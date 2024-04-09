#include <U8x8lib.h>
#include <SPI.h>
#include <LoRa.h>

// Definindo os pinos para o módulo LoRa
#define SS 18
#define RST 14
#define DI0 26

//Definindo o sensor
#define B 13
#define C 36
#define D 17
#define E 21  //deve-se corrigir o circuito

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/15, /* data=*/4, /* reset=*/16);


void setup() {
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  
  Serial.begin(9600);
  while (!Serial)
    ;

  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  u8x8.drawString(0, 1, "LoRa Iniciado");

  // Inicializando o módulo LoRa
  LoRa.setPins(SS, RST, DI0);
  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
  Serial.println("LoRa initialized");
}

void loop() {
  u8x8.clearDisplay();
  u8x8.setCursor(0,1);
  u8x8.println(digitalRead(B));
  u8x8.println(digitalRead(C));
  u8x8.println(digitalRead(D));
  u8x8.println(digitalRead(E));
  delay(1000);
  u8x8.clearDisplay();
}