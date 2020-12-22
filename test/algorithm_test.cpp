#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "../src/algorithm.hpp"


void require (bool (*f)() , std::string throw_text) {
    try {
        bool predicate = f();
        if (!predicate) {
            throw std::runtime_error(throw_text);
        }
    }catch (const std::exception& ex) {
        std::cerr << ex.what() << "\nFatal error" << std::endl;
    }
}

bool test_count(){
    int ints[] = {10,20,30,30,20,10,10,20};   // 8 elements
    return std::count (ints, ints+8, 10) == sltl::count (ints, ints+8, 10);
}

int main() {
    require(test_count, std::string("test sltl::count fault"));
    require(test_count, std::string("test sltl::count fault"));
    std::cout << "Run all algorithm test clear!" << std::endl;
}

