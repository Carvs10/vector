#include <iostream>				// std::begin(), std::end()
#include <iterator>  			// std::function
#include <functional>           // std::function
#include <algorithm> 
#include <vector>
#include "vec.h"

int main(){

	std::cout << "começo\n";

	sc::vector<int> v;

	sc::vector<int> a;

	sc::vector<int> b(20);

    sc::vector<int> vec1{ 1, 2, 3, 4, 5 };

    std::vector<int> vec{ 1, 2, 3, 4, 5 };

    sc::vector<int> vec2( std::begin(vec), std::end(vec) );

	std::cout << "main \n";

	return 0;
}

