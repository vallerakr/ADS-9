// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include  <iostream>
#include <algorithm>
template <typename U>
class BST {
private:
    struct Node {
        U data;
        int count;
        Node* left;
        Node* right;
        explicit Node(const U& v) : data(v), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* add(Node* node, const U& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (node->data > value) {
            node->left = add(node->left, value);
        } else if (node->data < value) {
            node->right = add(node->right, value);
        } else {
            node->count++;
        }

        return node;
    }

    int delTree(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(delTree(node->left), delTree(node->right));
    }

    int findCounter(Node* node, const U& value) const {
        if (node == nullptr) {
            return 0;
        }
        if (node->data == value) {
            return node->count;
        } else if (node->data < value) {
            return findCounter(node->right, value);
        } else {
            return findCounter(node->left, value);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(const U& value) {
        root = add(root, value);
    }

    int depth() const {
        return delTree(root) - 1;
    }

    int search(const U& value) const {
        return findCounter(root, value);
    }
};

#endif  // INCLUDE_BST_H_
