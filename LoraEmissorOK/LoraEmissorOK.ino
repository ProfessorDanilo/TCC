/*
Programa para leitura e envio do nível de líquido
sensor resistivo
usada documentação do LoRa.h
https://github.com/sandeepmistry/arduino-LoRa/
*/

//chamada das bibliotecas usadas
#include <U8x8lib.h>
#include <SPI.h>
#include <LoRa.h>


//configurando lora
#define SS 18
#define RST 14
#define DI0 26
#define BAND 915E6

//Definindo o sensor
#define B 13
#define C 12
#define D 17
#define E 21

//display oled a ser usado
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/15, /* data=*/4, /* reset=*/16);

void setup() {

  pinMode(B, INPUT_PULLUP);
  pinMode(C, INPUT_PULLUP);
  pinMode(D, INPUT_PULLUP);
  pinMode(E, INPUT_PULLUP);
  
  SPI.begin(5, 19, 27, 18);
  LoRa.setPins(SS, RST, DI0);

  //comunicação serial caso queira usar o computador 
  Serial.begin(115200);

  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  Serial.println("Emissor LoRa");
  u8x8.drawString(0, 0, "Emissor LoRa");

  if (!LoRa.begin(BAND)) {
    Serial.println("Falha ao iniciar comunicação via rádio");
    u8x8.drawString(0, 1, "Falha iniciar radio");
    while (1);
  }
  else{
    u8x8.setCursor(0,0);
    u8x8.println("Radio iniciado");
    int band = BAND/1E6;
    u8x8.setCursor(0,1);
    u8x8.print(band);
    u8x8.print(" MHz");
    delay(2500);
  }
  u8x8.clearDisplay();
  u8x8.setCursor(0,1);
  u8x8.print("NIVEL DA AGUA:");
}

void loop() {
  Serial.print("Nível da água: ");
  u8x8.setCursor(5,4);
  //preparando envio do pacote ao LoRa
  LoRa.beginPacket();
  if(digitalRead(E)==0){
    Serial.print("100");    
    LoRa.print("100");
    u8x8.print("100 %");
  }
  else if(digitalRead(D)==0){
    Serial.print("75");    
    LoRa.print("75");
    u8x8.print(" 75 %");
  }
  else if(digitalRead(C)==0){
    Serial.print("50");    
    LoRa.print("50");
    u8x8.print(" 50 %");
  }
  else if(digitalRead(B)==0){
    Serial.print("25");    
    LoRa.print("25");
    u8x8.print(" 25 %");
  }
  else{
    Serial.print("0");    
    LoRa.print("0");
    u8x8.print("  0 %");
  }
  Serial.println("%");
  LoRa.endPacket();

  delay(1000);
}