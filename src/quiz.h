#ifndef __QUIZ_H__
#define __QUIZ_H__

#include "mykeyboard.h"

#include <M5Cardputer.h>

class Quiz{
private:
    const char* ssid = "Quiz";
    const char* passwd = "12345678";
public:
    void start_server();
    void handle(Quiz* quiz);
};

#endif