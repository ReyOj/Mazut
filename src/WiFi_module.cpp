#include "WiFi_module.h"

void WiFiManager::connectWifi(){
    String ssid = "";

    auto tft = M5Cardputer.Display;
    auto key = M5Cardputer.Keyboard;
    M5Canvas canvas(&tft);
    canvas.setTextScroll(true);

    tft.clear();
    delay(500);
    tft.setCursor(0,0);
    tft.print("SSID:");

    M5Cardputer.update();
    while(true){
        if(key.isChange()){
        if(key.isPressed()){
            tft.print('.');
            auto status = key.keysState();
            //if (status.enter) break;
            if (status.del) ssid.remove(ssid.length() - 1);
            else if (!status.del) {
                for (auto i : status.word){
                    ssid += i;
                    tft.print(i);
                }
            }
        }
    }
    }
}