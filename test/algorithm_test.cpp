#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

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
bool test_all_of(){
    std::array<int,8> foo = {3,5,7,11,13,17,19,23};

    return std::all_of(foo.begin(), foo.end(), [](int i){return i%2;})
        == sltl::all_of(foo.begin(), foo.end(), [](int i){return i%2;});
}

bool test_count(){
    int ints[] = {10,20,30,30,20,10,10,20};   // 8 elements
    return std::count (ints, ints+8, 10) == sltl::count (ints, ints+8, 10);
}

int main() {
    require(test_count, std::string("test sltl::count fault"));
    require(test_all_of, std::string("test sltl::all_of fault"));
    std::cout << "Run all algorithm test clear!" << std::endl;
}

