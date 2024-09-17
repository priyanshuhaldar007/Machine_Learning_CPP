#include <iostream>
#include <random>

using namespace std;

class Random {
private:
    random_device rd;  // Non-deterministic seed source
    mt19937 generator; // Mersenne Twister engine

public:
    Random() : generator(rd()) {} // Initialize in the constructor

    int RandInt(int lb = 0, int ub = 10 ) {
        uniform_int_distribution<int> distribution(lb, ub);
        return distribution(generator);
    }

    double RandDouble(double lb = 0.0, double ub = 1.0) {
        uniform_real_distribution<double> distribution(lb, ub);
        return distribution(generator);
    }
};

// int main() {
//     Random random;

//     int count = 5;
//     while(count--){
//         cout << "Random Integer (5 to 15): " << random.RandInt(5, 15) << endl;
//         cout << "Random Integer (default lower bound): " << random.RandInt(10) << endl;
//         cout << "Random Double (2.5 to 7.5): " << random.RandDouble(2.5, 7.5) << endl;
//         cout << "Random Double (default range): " << random.RandDouble() << endl;
//         cout<<endl;
//     }

//     return 0;
// }