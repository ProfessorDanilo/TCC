/*
  This is a simple example show the Heltec.LoRa sended data in OLED.
*/

#include <heltec.h>
#include "imagem.h"

#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

unsigned int contador = 0;
String rssi = "RSSI --";
String packSize = "--";
String packet ;

void logo()
{
  Heltec.display->clear();
  Heltec.display->drawXbm(25,0,imagem_width,imagem_height,imagem_bits);
  Heltec.display->display();
}

void setup()
{
   //WIFI Kit series V1 not support Vext control
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
 
  Heltec.display->init();
  Heltec.display->flipScreenVertically();  
  Heltec.display->setFont(ArialMT_Plain_10);
  logo();
  delay(5000);
  Heltec.display->clear();
  
  Heltec.display->drawString(0, 0, "Heltec.LoRa Initial success!");
  Heltec.display->display();
  delay(1000);
  Serial1.begin(115200, SERIAL_8N1, 3, 1);
}

void loop()
{
  Heltec.display->clear();
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_10);
  
  Heltec.display->drawString(0, 0, "Enviando pacote: ");
  Heltec.display->drawString(90, 0, String(contador));
   Heltec.display->setFont(ArialMT_Plain_16);
  Heltec.display->drawString(0, 22, "Profe");
  Heltec.display->drawString(0, 40, "Marco Cuadros");
  Heltec.display->display();

  // send packet
  LoRa.beginPacket();
 /*
 * LoRa.setTxPower(txPower,RFOUT_pin);
 * txPower -- 0 ~ 20
 * RFOUT_pin could be RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
 *   - RF_PACONFIG_PASELECT_PABOOST -- LoRa single output via PABOOST, maximum output 20dBm
 *   - RF_PACONFIG_PASELECT_RFO     -- LoRa single output via RFO_HF / RFO_LF, maximum output 14dBm
*/
  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print("Olá ");
  LoRa.print(contador);
  LoRa.endPacket();

  contador++;
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial1.println("Led Ligado");
  delay(200);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  Serial1.println("Led Desligado");
  delay(200);                       // wait for a second
}
