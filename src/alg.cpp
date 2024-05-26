// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

bool isLetter(char* ch) {
    int letterIndex = 0;
    for (int i = 65; i < 91; ++i) {
        if (*ch == i) {
            *ch = 97 + letterIndex;
            return true;
        }
        ++letterIndex;
    }
    for (int i = 97; i < 123; ++i) {
        if (*ch == i) {
            return true;
        }
    }
    return false;
}

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    std::string currentWord;
    BST<std::string> bst;
    while (!file.eof()) {
        char ch = file.get();
        if (!isLetter(&ch)) {
            bst.add(currentWord);
            currentWord = "";
        } else if (isLetter(&ch)) {
            currentWord += ch;
        }
    }
    file.close();
    return bst;
}
