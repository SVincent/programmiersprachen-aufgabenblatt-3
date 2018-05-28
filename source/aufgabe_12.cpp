#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <vector>
#include <iostream> 
#include <algorithm> //std::all_of

std::vector<int> v_1 {1,2,3,4,5,6,7,8,9};
std::vector<int> v_2 {9,8,7,6,5,4,3,2,1};
std::vector<int> v_3(9);

bool equals_10 (int i) {
    return i == 10 ; 
}

TEST_CASE ("equals 10 test" "[transform]") {
    REQUIRE(std::all_of(v_3.begin(), v_3.end(), equals_10));
}

int main(int argc, char* argv[])
{    
    //addition lambda function
    auto addition = [](int x, int y) -> int {return x + y;}; 
  
    //iteratively uses addition over v_1 and v_2 and stores results in v_3
    std::transform (v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), addition);
  
  return Catch::Session().run(argc, argv);
} 