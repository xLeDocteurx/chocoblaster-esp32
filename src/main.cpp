#include <Arduino.h>

#include "hidkeyboard.h"
// #include "Wire.h"

#if CFG_TUD_HID
#define KEYBOARD_I2C_ADDR 0X5f

HIDkeyboard keyboard;
const int buttonPin = 4;        // input pin for pushbutton
const int ledPin = 2;           // input pin for pushbutton
int previousButtonState = HIGH; // for checking the state of a pushButton
int counter = 0;                // button push counter

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  // pinMode(buttonPin, INPUT_PULLDOWN);

  digitalWrite(ledPin, HIGH);

  keyboard.begin();
  // device.manufacturer(char*);
  // device.product(char*); // product name
  // device.serial(char*);  // serial number SN
  // device.revision(uint16_t); // product revison
  // device.deviceID(uint16_t VID, uint16_t PID);
  // device.deviceID(uint16_t* VID, uint16_t* PID);

  vTaskDelay(pdMS_TO_TICKS(1000));
  digitalWrite(ledPin, LOW);
  printf("INIT DONE\n");
}

void loop()
{
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // printf("buttonState : %i\n", buttonState);
  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and is currently pressed:
      && (buttonState == HIGH))
  {
    printf("BUTTON PRESSED\n");

    // Serial.println(dev.sendString(String("123456789\n"))?"OK":"FAIL");

    // keyboard.sendKey(HID_KEY_HOME); // KEY_MENU ? // KEY_LEFT_GUI ?
    // delay(100);
    // keyboard.sendString("slack");
    // delay(100);
    // keyboard.sendKey(HID_KEY_ENTER);
    // delay(100);
    // keyboard.sendPress(HID_KEY_CONTROL_LEFT);
    // delay(100);
    // keyboard.sendPress(HID_KEY_F);
    // delay(100);
    // keyboard.sendRelease();
    // delay(100);
    // keyboard.sendString("#general");
    // delay(100);
    // keyboard.sendKey(HID_KEY_ARROW_UP);
    // delay(100);
    // keyboard.sendKey(HID_KEY_ENTER);
    // delay(100);
    keyboard.sendString("Demain je paye ma tournée de pains au chocolat !\nParce que l’on dit pain au chocolat.\n\nCeci est un chocoblast . Pour votre sécurité n’oubliez pas de verrouiller vos postes et de ne pas laisser Christopher brancher un périphérique usb douteux dessus.");
    // delay(100);
    // keyboard.sendKey(HID_KEY_ENTER);

    // previousButtonState = buttonState;
  }
    previousButtonState = buttonState;
}

#endif
