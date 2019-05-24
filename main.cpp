#include <iostream>				// std::begin(), std::end()
#include <iterator>  			// std::function
#include <functional>           // std::function
#include <algorithm> 
#include <vector>
#include "vec.h"

int main(){

	std::cout << "começo\n";

	sc::vector<int> v;//1

	sc::vector<int> a;//1

	sc::vector<int> b(20);//2

    sc::vector<int> vec1{ 1, 2, 3, 4, 5 };//4

    std::vector<int> vec{ 1, 2, 3, 4, 5 };

    sc::vector<int> vec2( std::begin(vec), std::end(vec) );//3

    sc::vector<int> vec3(vec1);//5

	std::cout << "main \n";

	for(int i= 0;i<5; i++){
		std::cout << vec2[i]<<std::endl;
	}

	return 0;
}

