#include "rb_tree.hpp"
#include <iostream>

void require(bool predicate, const char* test_name) {
    if (!predicate) {
        std::cerr << test_name << ": FAILED\n"; 
    }
    return;
}

/*currently trivial RB tree tests*/
bool test_initialize() {
    RB_Tree<int> tree;
    if (!tree.empty() || tree.size() != 0) {
        return false;
    }
    RB_Tree<int>(4);
    if (tree.empty() || tree.size() == 0) {
        return false;
    }
}

bool test_insert_delete_find() {
    RB_Tree<int> tree;
    tree.insert(9);
    tree.insert(77);
    tree.insert(28);
    tree.insert(33);
    tree.insert(6);
    tree.insert(4);
    tree.insert(5);
    if (tree.size() != 7) {
        return false;
    }
    tree.erase(5);
    tree.erase(4);
    tree.erase(2);
    if (tree.size() != 5) {
        return false;
    }
    return true;
}

bool test_delete() {
    return true;
}

bool test_find() {
    return true;
}

bool test_copy_assign() {
    return true;
}

int main() {
    require(test_initialize(), "test_initialize");
    require(test_insert_delete_find(), "test_insert_delete_find");
    require(test_find(), "test_find");
    require(test_copy_assign(), "test_copy_assign");
    return 0;
}