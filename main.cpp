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
    //Looping to detect key strokes until i press ctrl
    //TO DO: add enter
    while(keyStroke != "ctrlandA") {
        if(_kbhit()) {
            int k = _getch();
            keyStroke = convert(k);

            //If I can go to the left. If not, I go on a row above
            if(keyStroke == "arrow_left") {
                if(pos.second > -1)
                    pos.second--;
                else if(pos.second == -1 && pos.first > 1)
                    pos.first--, pos.second = int(words[pos.first].size() - 1);
            }
            //If i can go to the right. If not, I go on a row below
            else if(keyStroke == "arrow_right") {
                if(pos.second < int(words[pos.first].size() - 1)) 
                    pos.second++;
                else if(pos.second == int(words[pos.first].size() - 1) && pos.first < numberOfLines) {
                    pos.second = -1, pos.first++;
                }
            }
            //If i can go up. I keep the column or I am at the end of the row if row above is not long enough 
            else if(keyStroke == "arrow_up") {
                if(pos.first > 1) {
                    if(pos.second <= int(words[pos.first - 1].size() - 1))
                        pos.first--;
                    else pos.first--, pos.second = int(words[pos.first].size() - 1);
                }  
                else pos.first;             
            }
            //If i can go down. I keep the column or I am at the end of the row below if it is not long enough
            else if(keyStroke == "arrow_down") {
                if(pos.first < numberOfLines) {
                    if(pos.second <= int(words[pos.first + 1].size() - 1))
                        pos.first++;
                    else pos.first++, pos.second = int(words[pos.first].size() - 1);
                }  
            }

            std::cout << pos.first << ' ' << pos.second << '\n'; 
        }
        
    }

    std::cout << "done modifying" << '\n';
    for(int j = 1; j <= numberOfLines; j++)
        std::cout << words[j] << '\n';
    
    file.close();



    return 0;
}