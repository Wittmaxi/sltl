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

bool test_any_of(){
    std::array<int,7> foo = {0,1,-1,3,-3,5,-5};

    return std::any_of(foo.begin(), foo.end(), [](int i){return i<0;})
        == sltl::any_of(foo.begin(), foo.end(), [](int i){return i<0;});
}

bool test_none_of(){
    std::array<int,8> foo = {1,2,4,8,16,32,64,128};

    return std::none_of(foo.begin(), foo.end(), [](int i){return i<0;})
        == sltl::none_of(foo.begin(), foo.end(), [](int i){return i<0;});
}

void test_args_for_each_fn(int i) {  // function:
    std::cout << ' ' << i;
}

struct test_args_for_each_struct {           // function object type:
    void operator() (int i) {std::cout << ' ' << i;}
} test_args_for_each_object;

bool test_for_each() {

    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    std::cout << "myvector contains:";
    sltl::for_each (myvector.begin(), myvector.end(), test_args_for_each_fn);
    std::cout << '\n';

    // or:
    std::cout << "myvector contains:";
    sltl::for_each (myvector.begin(), myvector.end(), test_args_for_each_object);
    std::cout << '\n';
    return true;
}

bool test_count(){
    int ints[] = {10,20,30,30,20,10,10,20};   // 8 elements
    return std::count (ints, ints+8, 10) == sltl::count (ints, ints+8, 10);
}

int main() {
    require(test_count, std::string("test sltl::count fault"));
    require(test_all_of, std::string("test sltl::all_of fault"));
    require(test_any_of, std::string("test sltl::any_of fault"));
    require(test_none_of, std::string("test sltl::none_of fault"));
    require(test_for_each, std::string("test sltl::for_each fault"));
    std::cout << "Run all algorithm test clear!" << std::endl;
}

