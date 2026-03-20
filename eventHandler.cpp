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
        return "ctrlandA";
    else return "character";
}

std::pair <int, int> new_pointer_position(std::pair <int, int> pos, std::string keyStroke, int numberOfLines, std::string words[10001]) {
    //If I can go to the left. If not, I go on a row above
    if(keyStroke == "arrow_left") {
        if(pos.second > -1)
            return {pos.first, pos.second - 1};
        else if(pos.second == -1 && pos.first > 1)
            return {pos.first - 1, int(words[pos.first - 1].size() - 1)};    
        return pos;
    }
    //If i can go to the right. If not, I go on a row below
    else if(keyStroke == "arrow_right") {
        if(pos.second < int(words[pos.first].size() - 1)) 
            return {pos.first, pos.second + 1};    
        else if(pos.second == int(words[pos.first].size() - 1) && pos.first < numberOfLines) {
            return {pos.first + 1, -1};
        }
        return pos;
    }
    //If i can go up. I keep the column or I am at the end of the row if row above is not long enough 
    else if(keyStroke == "arrow_up") {
        if(pos.first > 1) {
            if(pos.second <= int(words[pos.first - 1].size() - 1))
                return {pos.first - 1, pos.second};
            else return {pos.first - 1, int(words[pos.first - 1].size() - 1)};
        }  
        return pos;            
    }
    //If i can go down. I keep the column or I am at the end of the row below if it is not long enough
    else if(keyStroke == "arrow_down") {
        if(pos.first < numberOfLines) {
            if(pos.second <= int(words[pos.first + 1].size() - 1))
                return {pos.first + 1, pos.second};
            else return {pos.first + 1, int(words[pos.first + 1].size() - 1)};
        }  
        return pos;
    }
    else if(keyStroke == "ctrlandA")
        return pos;
}
