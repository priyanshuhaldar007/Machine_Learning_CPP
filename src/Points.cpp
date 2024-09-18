#include <iostream>
// #include "../Random.cpp"

class Point {

    public:
        float x;
        float y;
        int label;

        Point() {
            Random random;
            Perceptron p;

            x = random.RandInt(-200, 200);
            y = random.RandInt(-200, 200);

            if( y > p.func(x) ){
                label = 1;
            }
            else {
                label = -1;
            }
        }
};