#include "quiz.h"
#include <WiFi.h>
#include <WebServer.h>
#include <functional>

WebServer server(80);
MyKeyboard key;

void Quiz::start_server(){
    auto tft = M5Cardputer.Display;
    tft.clear();
    tft.setCursor(0, 0);

    WiFi.softAP(ssid, passwd);
    tft.println("Server created!");
    tft.print("IP: ");
    tft.println(WiFi.softAPIP());

    server.on("/result", [this]() { handle(this); });
    server.begin();
    tft.println("Press any key to start");
    while (!key.isPressed())
    {
        key.clearKeyBuffer();
    }
    while(1){
        server.handleClient();
        if(key.isPressed()){
            if(key.getKey() == '`') break;
        }
        key.clearKeyBuffer();
    }
    server.stop();
    WiFi.softAPdisconnect(true);
    
}

void Quiz::handle(Quiz* quiz){
    auto tft = M5Cardputer.Display;
    tft.println(server.arg("player"));
    server.send(200, "text/plain", "OK");
}