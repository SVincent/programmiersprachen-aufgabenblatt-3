#define CATCH_CONFIG_RUNNER
#include "catch.hpp" //why doesn't it find catch with <>
#include <cmath>
#include <algorithm> // remove and remove_if
#include <vector>

using namespace std;

bool is_multiple_of_3(unsigned int i) {
    return (i%3)==0;
}

bool isnt_multiple_of_3(unsigned int i) {
    return (i%3)!=0;
}

TEST_CASE ("filter alle vielfache von drei ", "[erase]") {
// ihre Loesung :
// Create an empty vector of unsigned ints
	vector<unsigned int> v (100);

	// Add 100 random numbers between 0 and 100 to the vector
	for (auto& vi : v) {
	    vi = rand() % 101;
    }
    v.erase(std::remove_if(v.begin(), v.end(), isnt_multiple_of_3), v.end()); 
// ...
REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}



int main(int argc, char* argv[]) {
return Catch :: Session (). run(argc , argv );
}
