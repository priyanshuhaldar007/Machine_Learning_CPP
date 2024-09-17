#include <iostream>
// #include "../Random.cpp"

class Point {

    public:
        float x;
        float y;
        int label;

        Point() {
            Random random;

            x = random.RandInt(0, 400);
            y = random.RandInt(0, 400);

            if( x >= y ){
                label = 1;
            }
            else {
                label = -1;
            }
        }
};