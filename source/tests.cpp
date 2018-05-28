#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "vec2.hpp"
#include "circle.hpp"
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

TEST_CASE("vector sorting test", "Task 3.6"){
    vector<Circle>sorted_circles;

    Circle c_1{250, Color{0.0, 0.0, 1.0}, Vec2{250.0, 200.0}, "Circle 1"};
    Circle c_2{150, Color{0.0, 1.0, 0.0}, Vec2{150.0, 600.0}, "Circle the second"};
    Circle c_3{200, Color{1.0, 0.0, 0.0}, Vec2{200.0, 350.0}, "Circle III"};
    Circle c_4{400, Color{1.0, 1.0, 1.0}, Vec2{400.0, 200.0}, "Circle four"};

    sorted_circles.push_back(c_1);
    sorted_circles.push_back(c_2);
    sorted_circles.push_back(c_3);
    sorted_circles.push_back(c_4);

    sort(sorted_circles.begin(), sorted_circles.end());

    REQUIRE(is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

TEST_CASE("vector sorting with lambda test", "Task 3.7"){
    vector<Circle>sorted_circles;

    Circle c_1{250, Color{0.0, 0.0, 1.0}, Vec2{250.0, 200.0}, "Circle 1"};
    Circle c_2{150, Color{0.0, 1.0, 0.0}, Vec2{150.0, 600.0}, "Circle the second"};
    Circle c_3{200, Color{1.0, 0.0, 0.0}, Vec2{200.0, 350.0}, "Circle III"};
    Circle c_4{400, Color{1.0, 1.0, 1.0}, Vec2{400.0, 200.0}, "Circle four"};

    sorted_circles.push_back(c_1);
    sorted_circles.push_back(c_2);
    sorted_circles.push_back(c_3);
    sorted_circles.push_back(c_4);

    sort(sorted_circles.begin(), sorted_circles.end(), [](Circle const& circle1, Circle const& circle2) -> bool { return (circle1.getRadius() < circle2.getRadius()); });

    REQUIRE(is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

//Task 3.8
/*
TEST_CASE("vector sorting with funktor test", "Task 3.8"){
	//funktor
template<typename C>
class smaller {
	public:
	bool operator() (C const& a, C const& b) {
	return a.getRadius() < b.getRadius();
	}
};

    vector<Circle>sorted_circles;

    Circle c_1{250, Color{0.0, 0.0, 1.0}, Vec2{250.0, 200.0}, "Circle 1"};
    Circle c_2{150, Color{0.0, 1.0, 0.0}, Vec2{150.0, 600.0}, "Circle the second"};
    Circle c_3{200, Color{1.0, 0.0, 0.0}, Vec2{200.0, 350.0}, "Circle III"};
    Circle c_4{400, Color{1.0, 1.0, 1.0}, Vec2{400.0, 200.0}, "Circle four"};

    sorted_circles.push_back(c_1);
    sorted_circles.push_back(c_2);
    sorted_circles.push_back(c_3);
    sorted_circles.push_back(c_4);

    sort(sorted_circles.begin(), sorted_circles.end(), smaller<int>{});

    REQUIRE(is_sorted(sorted_circles.begin(), sorted_circles.end()));
}
*/