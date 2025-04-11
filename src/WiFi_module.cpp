#include "WiFi_module.h"

void WiFiModule::connectWifi(){
    String ssid = "";

    auto tft = M5Cardputer.Display;
    M5Canvas canvas(&tft);
    canvas.setTextScroll(true);

    tft.clear();
    tft.setCursor(0,0);
    tft.print("SSID:");

    while(true){
        kbd.update();
        if(kbd.isPressed()){
            if (kbd.getKey() == '\n') break;
            if (kbd.getKey() == '\b'){
                ssid.remove(ssid.length() - 1);
            }
            else {
                    ssid += kbd.getKey();
            }
            tft.clear();
            tft.drawString("SSID:"+ssid, 0, 0);
        }
        kbd.clearKeyBuffer();
        delay(120);
    }
    delay(200);
    tft.drawString("Pass:", 0, 20);
    String passwd = "";
    while(true){
        kbd.update();
        if(kbd.isPressed()){
            if (kbd.getKey() == '\n') break;
            if (kbd.getKey() == '\b'){
                passwd.remove(passwd.length() - 1);
            }
            else {
                    passwd += kbd.getKey();
            }
            tft.clear();
            tft.drawString("Pass:"+passwd, 0, 20);
            tft.drawString("SSID:"+ssid, 0, 0);
        }
        kbd.clearKeyBuffer();
        delay(120);
    }
    tft.setCursor(0, 40);
    tft.println("Connecting...");
    WiFi.begin(ssid.c_str(), passwd.c_str());
    while(1){
        if(WiFi.status() == WL_CONNECTED){
            tft.println("Connected!");
            break;
        }
    }
    tft.println("Press any key to exit");
    #define WIFI_CONNECTED
    while(1){
        if(kbd.isPressed()) break;
    }
    kbd.clearKeyBuffer();
}