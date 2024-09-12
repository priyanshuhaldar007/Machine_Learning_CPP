#include <iostream>
#include "../Random.cpp"
#include "Perceptron.cpp"

int main() {
    // Seed the random number generator only once in the main function
    srand(static_cast<unsigned>(time(0)));

    double inputs[2] = {-1, 0.5};
    Perceptron p;

    int res = p.guess(inputs);
    cout << res << endl;

    return 0;
}
