/*Red-black tree library
  Author: Christopher Huggins*/

#include <iterator>

template<typename T>
class RB_Tree {
public:
    RB_Tree() {}

    RB_Tree(T datum) {
        root = new Node(datum, 'b');
        tree_size = 1;
    }

    RB_Tree& operator=(const RB_Tree& rhs) { //O(n)
        if (this == &rhs) {
            return *this;
        }
        //copy right subtree
    }

    void insert(T datum) {
        Node* new_node = new Node(datum, 'b');
        if (empty()) {
            root = new_node;
            return;
        }
        Node* current_node = root;
        bool space_found = false;
        while (!space_found) {
            if (datum == current_node) {
                return;
            }
            else if (datum < current_node) {
                if (current_node->left) {
                    current_node = current_node->left;
                }
                else {
                    current_node->left = new_node;
                    space_found = 1;
                }
            }
            else {
                if (current_node->right) {
                    current_node = current_node->right;
                }
                else {
                    current_node->right = new_node;
                    space_found = 1;
                }
            }
        }
        ++tree_size;
        return;
    }

    //return iterator
    Node* find(T datum) const {
        Node* current_node = root;
        while (current_node) {
            if (*current_node == datum) {
                return current_node;
            }
            if (datum <= *current_node) {
                current_node = current_node->left;
            }
            else {
                current_node = current_node->right;
            }
        }
        return nullptr;
    } 

    void erase(T datum) { //not correct
        Node* erase_node = find(datum);
        if (erase_node) {
            delete erase_node;
            --tree_size;
        } 
        return;
    }

    bool empty() const {
        return (root == nullptr);
    }

    int size() const {
        return tree_size;
    }

private:
    int tree_size;
    class Node {
    public:
        Node() : left(nullptr), right(nullptr) {}

        Node(T datum, char color) : left(nullptr), right(nullptr),
         datum(datum), color(color) {}

        Node operator*() const {
            return datum;
        }

        char get_color() const {
            return color;
        }

    private:
        Node * left;
        Node * right;
        char color;
        T datum;
    };
    Node* root;
};