#ifndef MENU_H
#define MENU_H

#include <vector>
#include <Arduino.h>

#include "M5Cardputer.h"
#include "SSH.h"
#include "WiFi_module.h"
#include "quiz.h"

class Menu{
private:
    std::vector<String> items = {"WiFi", "Quiz", "SSH", "Options", "Exit"};
    int selectedIndex = 0;

public:
    void draw();
    void navigate(int direction);
    void select();

    SSH ssh;
    Quiz quiz;
    WiFiModule wifi_mgr;
};

#endif