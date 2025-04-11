#include <Arduino.h>
#include <menu.h>
#include "mykeyboard.h"

Menu menu;
MyKeyboard kbd;

void setup() {
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);
  kbd.begin();
  menu.draw();
}

void loop() {
  kbd.update();
  if(kbd.isPressed()){
  if (kbd.getKey() == ';') menu.navigate(-1);
  if (kbd.getKey() == '.') menu.navigate(1);
  if (kbd.getKey() == '\n'){
    delay(200);
    menu.select();
  }
  if (kbd.getKey() == '`') menu.draw();
  }
  kbd.clearKeyBuffer();
  delay(100);
}