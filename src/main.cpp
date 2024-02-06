#include <Arduino.h>

#include "hidkeyboard.h"
// #include "Wire.h"

#if CFG_TUD_HID
#define KEYBOARD_I2C_ADDR 0X5f

HIDkeyboard keyboard;
const int buttonPin = 4;        // input pin for pushbutton
const int ledPin = 2;           // input pin for pushbutton
int previousButtonState = HIGH; // for checking the state of a pushButton
const char* message = "Demain je paye ma tournee de pains au chocolat !\nParce que l on dit pain au chocolat.\n\nCeci est un chocoblast. Pour votre securite n oubliez pas de verrouiller vos postes et de ne pas laisser Christopher brancher un peripherique usb douteux dessus.";

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  // pinMode(buttonPin, INPUT_PULLDOWN);

  digitalWrite(ledPin, HIGH);

  keyboard.begin();
  keyboard.manufacturer("Christopher Lenoir");
  keyboard.product("Chocoblaster"); // product name
  keyboard.serial("42");  // serial number SN

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

    // KEY_MENU ? // KEY_LEFT_GUI ?
    printf("HID_KEY_HOME : %s\n", keyboard.sendKey(HID_KEY_HOME) ? "OK" : "FAIL");
    delay(100);
    printf("slack : %s\n", keyboard.sendString("slack") ? "OK" : "FAIL");
    delay(10);
    printf("HID_KEY_ENTER : %s\n", keyboard.sendKey(HID_KEY_ENTER) ? "OK" : "FAIL");
    delay(100);
    printf("HID_KEY_CONTROL_LEFT : %s\n", keyboard.sendPress(HID_KEY_CONTROL_LEFT) ? "OK" : "FAIL");
    delay(10);
    printf("HID_KEY_F : %s\n", keyboard.sendPress(HID_KEY_F) ? "OK" : "FAIL");
    delay(10);
    printf("sendRelease %s\n", keyboard.sendRelease() ? "OK" : "FAIL");
    delay(50);
    printf("#general : %s\n", keyboard.sendString("#general") ? "OK" : "FAIL");
    delay(100);
    printf("HID_KEY_ARROW_UP : %s\n", keyboard.sendKey(HID_KEY_ARROW_UP) ? "OK" : "FAIL");
    delay(10);
    printf("HID_KEY_ENTER : %s\n", keyboard.sendKey(HID_KEY_ENTER) ? "OK" : "FAIL");
    delay(10);
    printf("%s : %s\n", message, keyboard.sendString(message) ? "OK" : "FAIL");
    delay(100);
    printf("HID_KEY_ENTER : %s\n", keyboard.sendKey(HID_KEY_ENTER) ? "OK" : "FAIL");
  }
    previousButtonState = buttonState;
}

#endif
