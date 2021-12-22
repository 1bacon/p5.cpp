#include <iostream>
#include "p5.hpp"

using namespace P5;

int main(){
    PVector p = {-1,1,0};
    PVector k = {1,0,-5};

    std::cout << "p: " <<p.toString() << "\n";
    std::cout << "k: " <<k.toString() << "\n";

    std::cout << p.mag() << "\n"; 
    std::cout << k.mag() << "\n"; 
    return 0;
}