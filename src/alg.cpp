// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include <sstream>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Ошибка при открытии файла");
    }

    std::string currentLine;
    while (std::getline(file, currentLine)) {
        std::string currentWord;
        for (char c : currentLine) {
            if (isalpha(c)) {
                currentWord += tolower(c);
            } else if (!currentWord.empty()) {
                tree.insert(currentWord);
                currentWord.clear();
            }
        }
        if (!currentWord.empty()) {
            tree.insert(currentWord);
        }
    }

    file.close();
    return tree;
}
