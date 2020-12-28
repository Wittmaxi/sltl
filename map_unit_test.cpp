#include <map>
#include "map.hpp"
#include <iostream>

void require(bool predicate, const char* test_name) {
    if (!predicate) {
        std::cerr << test_name << ": FAILED\n"; 
    }
    return;
}

bool test_initialize() {

}

bool test_insert() {

}

bool test_delete() {

}

bool test_begin_end() {

}

bool test_find() {

}

bool test_upperb_lowerb() {

}

int main() {
    require(test_initialize(), "test_initialize");
    require(test_insert(), "test_insert");
    require(test_delete(), "test_delete");
    require(test_find(), "test_find");
    std::map<int, int> test;
    return 0;
}