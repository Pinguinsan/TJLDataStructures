#include <string>
#include <iostream>
#include <memory>
#include "../tjlds_pair.h"

using namespace TJLDataStructures;

int main()
{
    pair<int, int> firstPair{5, 4};
    pair<std::string, int> secondPair{"Hello", 42};
    pair<int *, std::string *> thirdPair{&secondPair.second, &secondPair.first};

    std::cout << "firstPair = (" << firstPair.first << ", " << firstPair.second << ")" << std::endl;
    std::cout << "secondPair = (" << secondPair.first << ", " << secondPair.second << ")" << std::endl;
    std::cout << "thirdPair = (" << *(thirdPair.first) << ", " << *(thirdPair.second) << ")" << std::endl;
    std::cout << std::endl;
    secondPair.first = "Goodbye";
    secondPair.second = 2;

    std::cout << "secondPair = (" << secondPair.first << ", " << secondPair.second << ")" << std::endl;
    std::cout << "thirdPair = (" << *(thirdPair.first) << ", " << *(thirdPair.second) << ")" << std::endl;
    
    std::unique_ptr<int> myInt{new int{4}};
    std::unique_ptr<double> myDouble{new double{3.14}};
    pair<std::unique_ptr<int>, std::unique_ptr<double>> fourthPair{std::move(myInt), std::move(myDouble)};
    pair<int *, double *> fifthPair{make_pair(new int{10}, new double{123.4})};
    std::cout << "fourthPair = (" << *(fourthPair.first.get()) << ", " << *(fourthPair.second.get()) << ")" << std::endl;
    std::cout << "fifthPair = (" << *(fifthPair.first) << ", " << *(fifthPair.second) << ")" << std::endl;
    
    return 0;
}
