// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include  <iostream>
#include <algorithm>
template <typename T>
class BST {
 private:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
        explicit Node(T v) : data(v), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* add(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        Node* cur = node;
        Node* par = nullptr;

        while (cur != nullptr) {
            par = cur;
            if (cur->data > value) {
                cur = cur->left;
            } else if (cur->data < value) {
                cur = cur->right;
            } else {
                cur->count++;
                return node;
            }
        }

        if (par->data > value) {
            par->left = new Node(value);
        } else {
            par->right = new Node(value);
        }

        return node;
    }

    int DelTree(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(DelTree(node->left), DelTree(node->right));
    }

    int TreeSearch(Node* node, const T& value) const {
        while (node != nullptr) {
            if (node->data == value) {
                return node->count;
            } else if (node->data < value) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return 0;
    }

 public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        root = add(root, value);
    }

    int depth() const {
        return DelTree(root) - 1;
    }

    int search(const T& value) const {
        return TreeSearch(root, value);
    }
};
#endif  // INCLUDE_BST_H_
