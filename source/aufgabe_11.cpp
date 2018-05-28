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

//task 3.13
template<typename C, typename P>
C filter(C const& c,P const& p){
    C c1;
	for(auto ci : c){
		if(p(ci)) { 
			c1.push_back(ci);
		}
	}
	return c1;
}

bool is_even(int n) {
    return n % 2 == 0;
}

TEST_CASE("is even test","[task 3.13]") {
    std::vector<int> v{1,2,3,4,5,6};
    std::vector<int> all_even = filter (v, is_even);
	REQUIRE(all_of(all_even.begin(), all_even.end(), is_even));
}

int main(int argc, char* argv[]) {
return Catch::Session().run(argc, argv);
}
