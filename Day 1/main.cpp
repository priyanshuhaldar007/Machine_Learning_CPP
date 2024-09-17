#include <iostream>
#include <vector>
#include "../Random.cpp"
#include "Perceptron.cpp"
#include "Points.cpp"

int main() {
    // Seed the random number generator only once in the main function
    srand(static_cast<unsigned>(time(0)));

    vector<Point> points(100);
    Perceptron p;

    cout << "Sl. No. \t Point X \t Point Y \t Point Label \t Guess \t Correct or not" << endl;
    int correct_count = 0;
    for(int i = 0; i < 100; i++){
        double inputs[2] = {points[i].x, points[i].y};

        p.train(inputs,points[i].label);

        int guess = p.guess(inputs);

        string ans = guess == points[i].label ? "Yes" : "No";

        if( guess == points[i].label ) {
            correct_count++;
        }

        // with training 
        cout << i << "\t\t  " << points[i].x << "\t\t  " << points[i].y << "\t\t  " << points[i].label <<  "\t\t  " << guess <<  "\t\t  " << ans << endl;

        // without training
        cout << i << "\t\t  " << points[i].x << "\t\t  " << points[i].y << "\t\t  " << points[i].label <<  "\t\t  " << 0 <<  "\t\t  " << ans << endl;
    }



    // int res = p.guess(inputs);
    cout << correct_count << endl;

    return 0;
}
