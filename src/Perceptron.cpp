#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

class Perceptron {
public:
    static const int Length = 3;
    double weights[Length];
    double learningRate = 0.1;

    Perceptron() {
        Random random;

        for (int i = 0; i < Length; i++) {
            weights[i] = random.RandDouble(-1.0, 1.0);
        }
    }

    int guess(double inputs[]) {
        double sum = 0.0;
        for (int i = 0; i < Length; i++) {
            sum += inputs[i] * weights[i];
        }

        int output = sign(sum);
        return output;
    }

    // The activation function
    int sign(double num) {
        return (num < 0) ? -1 : 1;
    }

    void train(double inputs[], int target) {
        int guessVal = guess(inputs);
        int error = target - guessVal;

        // Tune all the weights
        for(int i = 0; i < Length; i++) {
            weights[i] += error * inputs[i] * learningRate;
        }
        
    }

    int func(int x){
        // y = mx + c
        return 1*x + 120;
    }
};
