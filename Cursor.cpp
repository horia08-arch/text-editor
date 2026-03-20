#include <iostream>
class Cursor {
    private:
        int row, column;
    public:
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        
        //setter
        void setPos(int r, int c) {
            ;
        }
        //getter
        std::pair <int, int> getPos() {
            return {row, column};
        }
};