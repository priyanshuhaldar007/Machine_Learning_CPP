#include "matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

int main() {
    std::vector<int> x = {1, 2, 3, 4, 5};
    std::vector<int> y = {1, 4, 9, 16, 25};
    
    for (size_t i = 0; i < x.size(); ++i) {
        std::string fill_color = (y[i] > 10) ? "green" : "red";    // Fill color condition
        std::string border_color = (x[i] % 2 == 0) ? "blue" : "black";  // Border color condition

        // Draw circle with fill and border color
        plt::scatter(std::vector<int>{x[i]}, std::vector<int>{y[i]}, 
                     100, {{"color", fill_color}, {"edgecolor", border_color}});
    }

    // plt::show();
    plt::save("./plot.png");
    return 0;
}
