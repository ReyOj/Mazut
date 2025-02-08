#include <Arduino.h>
#include <menu.h>

Menu menu;

void setup() {
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);
  M5Cardputer.Keyboard.begin();
  menu.draw();
}

void loop() {
  M5Cardputer.update();

  auto status = M5Cardputer.Keyboard.keysState();

  if (M5Cardputer.Keyboard.isKeyPressed(';')) menu.navigate(-1);
  if (M5Cardputer.Keyboard.isKeyPressed('.')) menu.navigate(1);
  if (status.enter) menu.select();
  if (M5Cardputer.Keyboard.isKeyPressed('`')) menu.draw();
}