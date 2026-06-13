#include <SPI.h>
#include <mcp2515.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

struct can_frame canMsg;

MCP2515 mcp2515(10);

LiquidCrystal_I2C lcd(0x27, 16, 2);

int blinkDelay = 500;

void setup()
{
  pinMode(7, OUTPUT);

  pinMode(6, OUTPUT);

  Serial.begin(9600);

  SPI.begin();

  mcp2515.reset();

  mcp2515.setBitrate(CAN_500KBPS, MCP_16MHZ);

  mcp2515.setNormalMode();

  lcd.init();

  lcd.backlight();

  lcd.setCursor(0,0);

  lcd.print("CAN RX Started");

  delay(2000);

  lcd.clear();
}

void loop()
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
  {
    blinkDelay = (canMsg.data[0] << 8) | canMsg.data[1];

    int obstacle = canMsg.data[2];

    lcd.clear();

    lcd.setCursor(0,0);

    lcd.print("Delay:");

    lcd.print(blinkDelay);

    if(obstacle == 1)
    {
      digitalWrite(6, HIGH);

      lcd.setCursor(0,1);

      lcd.print("Obstacle!");

      Serial.println("Obstacle Detected");
    }
    else
    {
      digitalWrite(6, LOW);

      lcd.setCursor(0,1);

      lcd.print("Area Safe");
    }
  }

  // Speed LED
  digitalWrite(7, HIGH);

  delay(blinkDelay);

  digitalWrite(7, LOW);

  delay(blinkDelay);
}