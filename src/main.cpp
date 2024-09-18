#include <iostream>
#include <vector>
#include "../Random.cpp"
#include "Perceptron.cpp"
#include "Points.cpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    // Seed the random number generator only once in the main function
    srand(static_cast<unsigned>(time(0)));

    int limit =150;

    vector<Point> points(limit);

    // Ploting the points
    vector<float> x ;
    vector<float> y ;

    Perceptron p;

    cout << "Sl. No. \t Point X \t Point Y \t Point Label \t Guess \t Correct or not" << endl;
    int correct_count = 0;
    for(int i = 0; i < limit; i++){
        double inputs[3] = {points[i].x, points[i].y, points[i].bias};

        // Adding the points
        x.push_back(points[i].x) ;
        y.push_back(points[i].y) ;

        p.train(inputs,points[i].label);

        int guess = p.guess(inputs);

        string ans = guess == points[i].label ? "Yes" : "No";

        if( guess == points[i].label ) {
            correct_count++;
        }

        // with training 
        cout << i << "\t\t  " << points[i].x << "\t\t  " << points[i].y << "\t\t  " << points[i].label <<  "\t\t  " << guess <<  "\t\t  " << ans << endl;

        // without training
        // cout << i << "\t\t  " << points[i].x << "\t\t  " << points[i].y << "\t\t  " << points[i].label <<  "\t\t  " << 0 <<  "\t\t  " << ans << endl;
        
        // plt::scatter(points[i].x, points[i].y, 100, {{"color", "green"}});
        std::string fill_color = (points[i].label == 1) ? "green" : "red";    // Fill color condition
        std::string border_color = (guess == points[i].label) ? "yellow" : "black";  // Border color condition

        // Draw circle with fill and border color
        plt::scatter(std::vector<float>{x[i]}, std::vector<float>{y[i]}, 
                     20, {{"color", fill_color}, {"edgecolor", border_color}});
    }

    // for (size_t i = 0; i < x.size(); ++i) {
        
    // }

    // Ploting the points
    // plt::scatter(x, y, 100, {{"color", "green"}});
    // plt::plot(x, y);

    // Set axis limits for better visualization
    plt::xlim(-200, 200);
    plt::ylim(-200, 200);

    // Plotting a line
    std::vector<int> plane = {-200, 200};
    std::vector<int> line2 = {p.func(-200),p.func(200)};
    plt::plot(plane,line2,{{"color", "red"}, {"linestyle", ":"}});

    plt::save("./plot.png");

    // int res = p.guess(inputs);
    cout << correct_count << endl;

    return 0;
}
