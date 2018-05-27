#include <list> // in namespace std
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <iostream> // std::cout 
#include <map>

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

// Task 3.3
    // A map allows to store pairs of values, which are then stored in a sorted order according to the key value.
    // Furthermore it allows fast access to entries with key value.
    // Downside: maps are made up of pairs, which cannot be updated.

    // Create map with number:frequency
    std::map<unsigned int,int> frequency;

    // Iterate over includedSet from the previous task, which we know to be our key values, iterate over randomList, which we know to contain our frequency,
    // add the values together into a pair, insert pair into our map.
    for (auto si : includedSet) {
        int freq = 0;
        for (auto li : randomList) {
            if (si == li) {
                freq++;
            }
        }
        frequency.insert(std::make_pair(si, freq));
    }

    // Console output
    std::cout << "Number:Frequency \n";
    for (auto mi : frequency) {
        std::cout << mi.first << ":" << mi.second << "\n";
    }
    std::cout << "\n";

    return 0;
}
