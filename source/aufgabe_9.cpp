#include <cstdlib> // std::rand()
#include <vector> // std::vector<>
#include <list> // std::list<>
#include <iostream> // std::cout
#include <iterator> // std::ostream_iterator<>
#include <algorithm> // std::reverse, std::generate

int main ()
{
    //initialize a vector of the length 10 and fill it with random numbers
    std::vector<int> v_0 (10);
    for (auto& v : v_0) {
        v = std::rand();
    }

    //copy the contents of v_0 to another place, which happens to be cout, with every value separated by \n
    std::copy(std::cbegin(v_0), std::cend(v_0),
    std::ostream_iterator<int>(std::cout, "\n"));

    //two lists which are created by iterating over the contents of v_0 and l_0 respectively
    //they aren't creating copies however
    std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));
    std::list<int> l_1(std::cbegin(l_0), std::cend(l_0));
    //reverse the order of contents within l_1
    //v_0 and v_1 should be unaffected
    std::reverse(std::begin(l_1), std::end(l_1));

    //copy the contents of l_1 to another place, which happens to be cout, with every value separated by \n
    std::copy(std::cbegin(l_1), std::cend(l_1) ,
    std::ostream_iterator<int>(std::cout, "\n"));

    //sort the contents of l_1
    //v_0 and v_1 should be unaffected
    l_1.sort();

    //again: output
    std::copy(l_1.cbegin(), l_1.cend(),
    std::ostream_iterator<int >( std::cout, "\n"));

    //creates a new generator rand(), iterates over v_0 and assigns new values
    std::generate(std::begin(v_0), std::end(v_0), std::rand);
    //copy the contents of v_0 in reverse order to another place, which happens to be cout, with every value separated by \n
    std::copy(v_0.crbegin(), v_0.crend() ,
    std::ostream_iterator<int >(std::cout, "\n"));
    return 0;
}
