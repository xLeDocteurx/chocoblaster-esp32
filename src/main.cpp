#include <Arduino.h>

#include "hidkeyboard.h"
// #include "Wire.h"

#if CFG_TUD_HID
#define KEYBOARD_I2C_ADDR 0X5f

// HID_LOCAL_French

HIDkeyboard keyboard;
const int buttonPin = 4;        // input pin for pushbutton
const int ledPin = 2;           // output pin for status led
int previousButtonState = HIGH; // for checking the state of a pushButton
const char* message = "Demain je paye ma tournee de pains au chocolat !\nParce que l on dit pain au chocolat.\n\nCeci est un chocoblast. Pour votre securite n oubliez pas de verrouiller vos postes et de ne pas laisser Christopher brancher un peripherique usb douteux dessus.";

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

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
    // bool stepRes = keyboard.sendKey(HID_KEY_HOME);
    bool stepRes = keyboard.sendKey(HID_KEY_MENU);
    // bool stepRes = keyboard.sendKey(HID_KEY_GUI_LEFT);
    printf("HID_KEY_HOME : %s\n", stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    }
    delay(100);
    stepRes = keyboard.sendString("slack");
    printf("slack : %s\n", stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    } 
    delay(10);
    stepRes = keyboard.sendKey(HID_KEY_ENTER);
    printf("HID_KEY_ENTER : %s\n", stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    } 
    delay(100);
    stepRes = keyboard.sendPress(HID_KEY_CONTROL_LEFT);
    printf("HID_KEY_CONTROL_LEFT : %s\n", stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    } 
    delay(10);
    stepRes = keyboard.sendPress(HID_KEY_F);
    printf("HID_KEY_F : %s\n", stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    } 
    delay(10);
    stepRes = keyboard.sendRelease();
    printf("sendRelease : %s\n", stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    } 
    delay(50);
    stepRes = keyboard.sendString("#general");
    printf("#general : %s\n", stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    } 
    delay(100);
    stepRes = keyboard.sendKey(HID_KEY_ARROW_UP);
    printf("HID_KEY_ARROW_UP : %s\n", stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    } 
    delay(10);
    stepRes = keyboard.sendKey(HID_KEY_ENTER);
    printf("HID_KEY_ENTER : %s\n", stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    } 
    delay(10);
    stepRes = keyboard.sendString(message);
    printf("%s : %s\n", message, stepRes ? "OK" : "FAIL");
    if(!stepRes) {
     return;
    } 
    // delay(100);
    // stepRes = keyboard.sendKey(HID_KEY_ENTER);
    //   printf("HID_KEY_ENTER : %s\n", stepRes ? "OK" : "FAIL");
    // if(!stepRes) {
    //  return;
    // } 
  }
  
  previousButtonState = buttonState;
}

#endif
