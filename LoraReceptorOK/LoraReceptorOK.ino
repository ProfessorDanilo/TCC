/*tutorial usado
https://robotzero.one/heltec-wifi-lora-32/
*/
#include <U8x8lib.h>
#include <LoRa.h>

String receivedText;
int receivedValue;
String receivedRssi;

// WIFI_LoRa_32 ports
// GPIO5  -- SX1278's SCK
// GPIO19 -- SX1278's MISO
// GPIO27 -- SX1278's MOSI
// GPIO18 -- SX1278's CS
// GPIO14 -- SX1278's RESET
// GPIO26 -- SX1278's IRQ(Interrupt Request)

#define SS 18
#define RST 14
#define DI0 26
#define BAND 915E6

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/15, /* data=*/4, /* reset=*/16);

void setup() {

  SPI.begin(5, 19, 27, 18);
  LoRa.setPins(SS, RST, DI0);

  Serial.begin(9600);
  while (!Serial)
    ;  //if just the the basic function, must connect to a computer
  delay(1000);

  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  //Serial.println("LoRa Receptor");
  u8x8.drawString(0, 1, "Receptor");

  if (!LoRa.begin(BAND)) {
    //Serial.println("Falha ao iniciar comunicação via rádio");
    u8x8.drawString(0, 1, "Falha iniciar radio");
    while (1)
      ;
  }
}

void loop() {

  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    //Serial.print("Received packet '");
    u8x8.drawString(0, 4, "Nivel da agua: ");

    // read packet
    while (LoRa.available()) {
      receivedValue = LoRa.parseInt();
      Serial.println(receivedValue);
      u8x8.setCursor(5,5);
      u8x8.print(receivedValue);
      u8x8.setCursor(8,5);
      u8x8.print(" %");
      //u8x8.drawString(5, 5, receivedText);
    }

    // print RSSI of packet
    //Serial.print("' with RSSI ");
    //Serial.println(LoRa.packetRssi());
    u8x8.drawString(0, 6, "PacketRS");
    receivedRssi = LoRa.packetRssi();
    char currentrs[64];
    receivedRssi.toCharArray(currentrs, 64);
    u8x8.drawString(9, 6, currentrs);
  }
}
