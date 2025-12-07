#include <SPI.h>
#include <LoRa.h>


#define LORA_SCK   18
#define LORA_MISO  19
#define LORA_MOSI  23
#define LORA_CS     5
#define LORA_RST   14
#define LORA_DIO0  26

//  Change to match your module
#define LORA_FREQ  433E6   // 433E6 or 866E6 or 915E6

//  LED Pin
#define LED_PIN    13

String inputText = "";

void blinkLED(int times, int delayMs) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(delayMs);
    digitalWrite(LED_PIN, LOW);
    delay(delayMs);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  while (!Serial);

  Serial.println("\n2-WAY LoRa Chat Started");
  Serial.println("Type message and press Enter\n");

  // ========== LoRa Init ==========
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_CS);
  LoRa.setPins(LORA_CS, LORA_RST, LORA_DIO0);

  if (!LoRa.begin(LORA_FREQ)) {
    Serial.println("❌ LoRa Init Failed!");
    while (1);
  }

  Serial.println("✅ LoRa Initialized Successfully\n");
}

void loop() {

  // ✅ SEND MESSAGE FROM SERIAL
  if (Serial.available()) {
    inputText = Serial.readStringUntil('\n');
    inputText.trim();

    if (inputText.length() > 0) {
      Serial.print("📤 Sending: ");
      Serial.println(inputText);

      LoRa.beginPacket();
      LoRa.print(inputText);
      LoRa.endPacket();

      Serial.println("✅ Message Sent\n");
    }
  }

  // ✅ RECEIVE MESSAGE
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String receivedText = "";

    while (LoRa.available()) {
      receivedText += (char)LoRa.read();
    }

    Serial.print("📥 Received: ");
    Serial.println(receivedText);

    Serial.print("📶 RSSI: ");
    Serial.println(LoRa.packetRssi());

    // ✅ Blink LED on receive
    blinkLED(3, 120);
    Serial.println();
  }
}
