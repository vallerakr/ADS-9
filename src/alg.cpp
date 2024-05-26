#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <sstream>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
if (!inputFile.is_open()) {
    throw std::runtime_error("Ошибка при открытии файла");
}

std::string line;
while (std::getline(inputFile, line)) {
    std::string word;
    for (char character : line) {
        if (isalpha(character)) {
            word += tolower(character);
        } else if (!word.empty()) {
            tree.insert(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        tree.insert(word);
    }
}

inputFile.close();
return tree;
