#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

int main() {
    // Data for X and Y axis
    std::vector<double> x = {-10, 10}; // X-axis line
    std::vector<double> y = {0, 0};    // Y-values are zero to get a horizontal line

    std::vector<double> y2 = {-10, 10}; // Y-axis line
    std::vector<double> x2 = {0, 0};    // X-values are zero to get a vertical line

    // Plotting the axis lines
    plt::plot(x, x, "b-");  // Horizontal axis in black
    // plt::plot(x2, x2, "k-"); // Vertical axis in black

    // Set axis limits for better visualization
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);

    // Show the plot
    plt::show();

    plt::save("./plot.png");

    return 0;
}
