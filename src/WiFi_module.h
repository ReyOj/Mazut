#ifndef WIFI_H
#define WIFI_H

#include <WiFi.h>
#include <M5Cardputer.h>

#include "mykeyboard.h"
//#include "menu.h"

class WiFiModule{
private:
    MyKeyboard kbd;
public:
    void connectWifi();
};

#endif