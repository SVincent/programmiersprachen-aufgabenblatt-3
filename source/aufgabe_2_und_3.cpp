#include <list> // in namespace std
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <iostream> // std::cout 
#include <map>
#include "vec2.hpp"
#include "circle.hpp"
#include "color.hpp"
#include <vector>
#include <algorithm>

using namespace std;

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

//Task 3.4
    
    Vec2 vecCen(300, 300);
    Color col(0.0, 1.0, 0.0);
    Circle c_1(250, col, vecCen, "circle one");

    Vec2 vecCen2(800, 600);
    Color col2(0.2, 0.8, 0.5);
    Circle c_2(150, col2, vecCen2, "circle the second");

    Vec2 vecCen3(400, 700);
    Color col3(1.0, 1.0, 0.1);
    Circle c_3(200, col3, vecCen3, "circle 3");
    
    std::cout << c_1 << std::endl;
    std::cout << c_2 << std::endl;
    std::cout << c_3 << std::endl;

    //set of circles
    std::set<Circle> circleSet;
    circleSet.insert(c_1);
    circleSet.insert(c_2);
    circleSet.insert(c_3);

    std::string newname;
    std::cout << "Enter name of new circle: ";
    std::cin >> newname;
    //if spaces are allowed in name, it would be
    //std::getline(std::cin, newname);


    /* find() doesn't work? maybe not in c++14 or c++11?
    bool isincluded = false;
    if(circleSet.find(newname) != circleSet.end()) {
        std::cout << "A circle under this name already exists";
           isincluded = true;
    }
    */

    //finding duplicate names, returning circle if already exists
    bool isincluded = false;
    for (auto si : circleSet) {
        if (si.getName() == newname) {
           std::cout << "A circle under this name already exists: \n";
           isincluded = true;
           std::cout << si;
        }
    }

    Circle c_4(150, col, vecCen);
    if (!isincluded) {
        c_4.setName(newname);
        circleSet.insert(c_4);
        std::cout << c_4 << std::endl;
    }

//Task 3.10
    //copy the contents from randomList into vector v, starting at its beginning
    std::vector<unsigned int> v;
    std::copy(std::begin(randomList), std::end(randomList), std::begin(v));

    return 0;
}
