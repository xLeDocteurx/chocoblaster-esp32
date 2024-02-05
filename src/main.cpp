#include <Arduino.h>

#include "hidkeyboard.h"
#include "Wire.h"

#if CFG_TUD_HID
#define KEYBOARD_I2C_ADDR 0X5f
// #endif

HIDkeyboard dev;
const int buttonPin = 4;        // input pin for pushbutton
const int ledPin = 2;           // input pin for pushbutton
int previousButtonState = HIGH; // for checking the state of a pushButton
int counter = 0;                // button push counter

void setup()
{
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, !HIGH);
  vTaskDelay(pdMS_TO_TICKS(1000));
  pinMode(buttonPin, INPUT_PULLDOWN);

  Wire.begin(7, 8);
  dev.begin();

  digitalWrite(ledPin, !LOW);
  printf("INIT DONE\n");
}

void loop()
{
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == HIGH))
  {
    printf("BUTTON PRESSED\n");
    // // increment the button counter
    // counter++;
    // // type out a message
    // Keyboard.print("You pressed the button ");
    // Keyboard.print(counter);
    // Keyboard.println(" times.");

    // Keyboard.write(KEY_HOME); // KEY_MENU ? // KEY_LEFT_GUI ?
    // delay(100);
    // Keyboard.println("slack");
    // delay(100);
    // Keyboard.press(KEY_LEFT_CTRL);
    // delay(100);
    // Keyboard.press("f");
    // delay(100);
    // Keyboard.releaseAll();
    // delay(100);
    // Keyboard.print("#general");
    // delay(100);
    // Keyboard.write(KEY_UP_ARROW);
    // delay(100);
    // Keyboard.write(KEY_RETURN); // KEY_KP_ENTER ? // Keyboard.println(); ?
    // delay(100);
    // Keyboard.println("Demain je paye ma tournée de pains au chocolat !\nParce que l’on dit pain au chocolat.\n\nCeci est un chocoblast . Pour votre sécurité n’oubliez pas de verrouiller vos postes et de ne pas laisser Christopher brancher un périphérique usb douteux dessus.");
  }

  // // save the current button state for comparison next time:
  // previousButtonState = buttonState;

  // delay(10);
  // Wire.requestFrom(KEYBOARD_I2C_ADDR, 1); // request 1 byte from keyboard
  // while (Wire.available())
  // {
  //   uint8_t key_val = Wire.read(); // receive a byte as character
  //   if (key_val != 0)
  //   {
  //     dev.sendChar(key_val); // send ASCII char
  //   }
  // }
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}

#endif
