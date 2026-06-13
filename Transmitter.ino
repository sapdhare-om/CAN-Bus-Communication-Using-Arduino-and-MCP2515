#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;

MCP2515 mcp2515(10);

#define TRIG_PIN 3
#define ECHO_PIN 4

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);

  pinMode(ECHO_PIN, INPUT);

  SPI.begin();

  mcp2515.reset();

  mcp2515.setBitrate(CAN_500KBPS, MCP_16MHZ);

  mcp2515.setNormalMode();

  Serial.println("CAN TX Started");
}

void loop()
{
  int potValue = analogRead(A0);

  int blinkDelay = map(potValue, 0, 1023, 100, 1000);

  // Ultrasonic distance measurement
  digitalWrite(TRIG_PIN, LOW);

  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);

  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  int distance = duration * 0.034 / 2;

  // CAN DATA
  canMsg.can_id = 0x100;

  canMsg.can_dlc = 3;

  canMsg.data[0] = highByte(blinkDelay);

  canMsg.data[1] = lowByte(blinkDelay);

  // obstacle flag
  if(distance < 20)
  {
    canMsg.data[2] = 1;
  }
  else
  {
    canMsg.data[2] = 0;
  }

  mcp2515.sendMessage(&canMsg);

  Serial.print("Delay: ");

  Serial.print(blinkDelay);

  Serial.print(" Distance: ");

  Serial.println(distance);

  delay(200);
}