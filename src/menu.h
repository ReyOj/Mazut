#ifndef __MENU_H__
#define __MENU_H__

#include <vector>
#include <Arduino.h>

#include "M5Cardputer.h"
#include "SSH.h"
#include "WiFi_module.h"

class Menu{
private:
    std::vector<String> items = {"WiFi", "SSH", "Options", "Exit"};
    int selectedIndex = 0;

public:
    void draw();
    void navigate(int direction);
    void select();

    SSH ssh;
    WiFiManager wifi_mgr;
};

#endif