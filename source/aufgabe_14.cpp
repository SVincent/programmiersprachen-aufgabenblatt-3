#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "circle.hpp"
#include <algorithm> 
#include <vector> 

using namespace std;

//Task 3.14
/*
TEST_CASE ("radius greater than 4.0f test using lambda", "Task 3.14") {
    vector<Circle> circles{{5.0f},{3.0f},{8.0f},{1.0f},{5.0f}};
    vector<Circle> greaterCircles;

    copy_if(circles.begin(), circles.end(), greaterCircles.begin(), [](Circle const& c) {return (c.getRadius()>4.0f);});

    REQUIRE(all_of(greaterCircles.begin(), greaterCircles.end(), [](Circle const& c) {return (c.getRadius()>3);}));
} 
*/


int main(int argc, char *argv[]) { 
  return Catch::Session().run(argc, argv);
}
