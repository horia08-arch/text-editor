#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>
#include <queue>
#include <conio.h>
#include "keyEvent.h"

std::string convert(int k);
std::pair <int, int> new_pointer_position(std::pair <int, int> pos, std::string keyStroke, int numberOfLines, std::string words[10001]);

int main() {
    std::string s;
    std::string words[10001];
    std::ifstream file("text.txt");

    int numberOfLines = 0;
    while(std::getline(file, s)) 
        words[++numberOfLines] = s;

    for(int j = 1; j <= numberOfLines; j++)
        std::cout << words[j] << '\n';
    
    std::pair <int, int> pos = {1, -1};
    std::string keyStroke = "-1";
    //Looping to detect key strokes until i press ctrl + A
    //TO DO: add enter
    while(true) {
        if(_kbhit()) {
            int k = _getch();
            keyStroke = convert(k);
            if(keyStroke == "ctrlandA")
                break;
            pos = new_pointer_position(pos, keyStroke, numberOfLines, words);

            std::cout << pos.first << ' ' << pos.second << '\n'; 
        }
        
    }

    std::cout << "done modifying" << '\n';
    for(int j = 1; j <= numberOfLines; j++)
        std::cout << words[j] << '\n';
    
    file.close();



    return 0;
}