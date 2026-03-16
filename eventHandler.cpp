#include "keyEvent.h"
#include <string>
#include <conio.h>

std::string convert(int k) {
    if(k == 8)
        return "backspace";
    else if(k == 224) {
        int arrow = _getch();
        
        switch(arrow) {
            case 72:
                return "arrow_up";
                break;
            case 80:
                return "arrow_up";
                break;
            case 75:
                return "arrow_left";
                break;
            case 77:
                return "arrow_right";
                break;
        }
    }
    else if(k == 17)
        return "ctrlandQ";
    else return "character";
}