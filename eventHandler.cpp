#include "keyEvent.h"
#include <string>
#include <conio.h>

std::string convert(int k) {
    if(k == 8)
        return "backspace";
    else if(k == 224) {
        int arrow = _getch();

        if(arrow == 72) 
            return "arrow_up";
        if(arrow == 80) 
            return "arrow_down";
        if(arrow == 75) 
            return "arrow_left";
        if(arrow == 77) 
            return "arrow_right";
    }
    else if(k == 1)
        return "ctrlandQ";
    else return "character";
}