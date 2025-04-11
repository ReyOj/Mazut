#ifndef __MY_KEYBOARD_H__
#define __MY_KEYBOARD_H__

#include <M5Cardputer.h>
#include <vector>

class MyKeyboard{
private:
    Keyboard_Class keyboard = M5Cardputer.Keyboard;
    bool _keyPressed = false; // Флаг для отслеживания нажатия клавиши
    unsigned long _lastPressTime;
    char _lastKey;
    std::vector<char> _keyBuffer; // Буфер для хранения нажатых клавиш
public:
    void begin();
    bool isPressed();
    char getKey();
    void update();
    std::vector<char> getKeyBuffer();
    void clearKeyBuffer();
};

#endif