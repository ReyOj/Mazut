#include "mykeyboard.h"

#define DEBOUNCE_DELAY 10

void MyKeyboard::begin() {
    keyboard.begin();
    _lastPressTime = 0;
    _lastKey = '\0';
}

bool MyKeyboard::isPressed() {
    update();
    return _keyPressed;
}

char MyKeyboard::getKey() {
    update();

    if (_keyPressed) {
        unsigned long currentTime = millis();
        if(currentTime - _lastPressTime < DEBOUNCE_DELAY){
            return '\0';
        }

        auto state = keyboard.keysState();
        char key = '\0';

        if (state.enter) {
            key = '\n';
        } else if (state.del) {
            key = '\b';
        } else if (!state.word.empty()) {
            key = state.word[0];
        }

        if (key != _lastKey){
            _lastPressTime = currentTime;
            _lastKey = key;
            return key;
        }
    }
    return '\0';
}

void MyKeyboard::update() {
    keyboard.updateKeyList();
    keyboard.updateKeysState();

    _keyPressed = keyboard.isPressed();

    if (_keyPressed) {
        auto state = keyboard.keysState();
        for (char c : state.word) {
            _keyBuffer.push_back(c);
        }
    }
}

std::vector<char> MyKeyboard::getKeyBuffer() {
    return _keyBuffer;
}

void MyKeyboard::clearKeyBuffer() {
    _keyBuffer.clear();
}