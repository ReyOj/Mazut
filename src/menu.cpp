#include "menu.h"

void Menu::draw(){
    M5Cardputer.Display.clear();
    M5Cardputer.Display.setCursor(0, 0);
    M5Cardputer.Display.setTextSize(2);
    for (int i = 0; i < items.size(); i++) {
        if (i == selectedIndex) {
            M5Cardputer.Display.println("> " + items[i]);
        } else {
            M5Cardputer.Display.println("  " + items[i]);
        }
    }
}

void Menu::navigate(int direction){
    selectedIndex = (selectedIndex + direction + items.size()) % items.size();
    draw();
    delay(100);
}

void Menu::select(){
    if(selectedIndex == 0) wifi_mgr.connectWifi();
    if(selectedIndex == 1) ssh.startSSH();
}