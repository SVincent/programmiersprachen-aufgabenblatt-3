#include "circle.hpp"
#include <vector>
#include <algorithm>
#include <iostream> // std::cout 

int main(int argc, char *argv[]) {
    std::vector<Circle> sorted_circles;

    //add several circles to the container
    Vec2 vecCen(300, 300);
    Color col(0.0, 1.0, 0.0);
    Circle c_1(250, col, vecCen, "circle one");

    Vec2 vecCen2(800, 600);
    Color col2(0.2, 0.8, 0.5);
    Circle c_2(150, col2, vecCen2, "circle the second");

    Vec2 vecCen3(400, 700);
    Color col3(1.0, 1.0, 0.1);
    Circle c_3(200, col3, vecCen3, "circle 3");

    sorted_circles.push_back(c_1);
    sorted_circles.push_back(c_2);
    sorted_circles.push_back(c_3);

    //sort contents of the container
    std::sort(sorted_circles.begin(), sorted_circles.end());

    for (auto vi : sorted_circles) {
        std::cout << vi << std::endl;
    }
    
    return 0;
}