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
        explicit Node(U v) : data(v), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* add(Node* node, const U& value) {
        if (node == nullptr) {
            return new Node(value);
        }
 
        Node* current = node;
        Node* parent = nullptr;
 
        while (current != nullptr) {
            parent = current;
            if (current->data > value) {
                current = current->left;
            } else if (current->data < value) {
                current = current->right;
            } else {
                current->count++;
                return node;
            }
        }
 
        if (parent->data > value) {
            parent->left = new Node(value);
        } else {
            parent->right = new Node(value);
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
    BinarySearchTree() : root(nullptr) {}
 
    void insertТ(const U& value) {
        root = add(root, value);
    }
 
    int depthT() const {
        return delTree(root) - 1;
    }
 
    int searchТ(const U& value) const {
        return findCounter(root, value);
    }
};
#endif  // INCLUDE_BST_H_
