#include <list> // in namespace std
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <iostream> // std::cout 

int main() {
//Task 3.2

	// Create an empty list of unsigned ints
	std::list<unsigned int> randomList;

	// Push back 100 random numbers between 0 and 100 in the list
	for (int i = 0; i <= 100; i++)
		randomList.push_back(rand() % 101);

    // Iterate over the list and add all numbers to a set, to find all unique numbers included in our list
    std::set<unsigned int> includedSet;
    for (auto li : randomList) {
        includedSet.insert(li);
    }
    std::cout << "Number of unique numbers in list: " << includedSet.size() <<"\n";

    // Wanted to use set_difference, but turns out that is c++ 17
    std::set<unsigned int> comparisonSet;
    for (int i = 0; i<= 100; i++) {
        comparisonSet.insert(i);
    }
    std::set<unsigned int> differenceSet;
    //std::set_difference(comparisonSet.begin(), comparisonSet.end(), includedSet.begin(), includedSet.end(), std::inserter(differenceSet, differenceSet.begin()));
    //set_difference would've been more elegant (and probably efficient), but since this is c++ 14, I can't use it - so it's two for loops instead.
    for (auto si : comparisonSet) {
        bool isincluded = false;
        for (auto sii : includedSet) {
            if (si == sii) {
                isincluded = true;
            }
        }
        if (!isincluded) {
            differenceSet.insert(si);
        }
    }

    // console output
    std::cout << "Not included: \n";
    for (auto si : differenceSet) {
        std::cout << si << "; ";
    }
    std::cout << "\n";

    return 0;
}
