

#include <bitset>
#include "HuffmanDecompressor.h"
#include "HuffmanTree.h"
#include <fstream>
#include <iostream>

#define BYTE_SIZE 8
#define SPECIAL_CHAR '$'


void HuffmanDecompressor::decompress(const string &fileInput, const string &fileOutput) {
    std::ifstream inputFile(fileInput, std::ios::binary);
    std::ofstream outputFile(fileOutput, std::ios::binary | std::ios::out);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        throw std::runtime_error("Error opening files!");
    }
    map<char, unsigned> frequencies = readHeader(inputFile);
    HuffmanTree tree(frequencies);
    std::string decodedText = readBody(inputFile, tree);
    outputFile << decodedText;
    outputFile.close();
    inputFile.close();
}

std::map<char, unsigned> HuffmanDecompressor::readHeader(ifstream &inputFile) {
    char ch;
    std::string header = "";
    while (inputFile.get(ch)) { // Read character by character
        if (ch == SPECIAL_CHAR) {
            char nextChar = inputFile.peek(); // Look at the next character
            if (nextChar == SPECIAL_CHAR) {
                inputFile.ignore(); // Ignore the second '$'
                break; // Break the loop if "$$" is found
            }
        }
        header += ch; // Add the character to the header
    }
    int padding;
    inputFile >> padding;
    // Ignore $ after padding
    inputFile.ignore();

    std::map<char, unsigned> freqMap;
    for (size_t i = 0; i < header.size(); ++i) {
        char character = header[i];
        std::string occurence = "";
        while (header[i + 1] >= '0' && header[i + 1] <= '9') {
            occurence += header[i + 1];
            ++i;
        }
        freqMap[character] = (unsigned) std::stoi(occurence);
    }
    return freqMap;
}

std::string HuffmanDecompressor::readBody(ifstream &inputFile, HuffmanTree &tree) {
    std::vector<bool> bitStream;
    char byte;
    int totalBytesReaded = 0;
    std::string decodedText;
    while (inputFile.get(byte)) {
        std::bitset<BYTE_SIZE> bits(byte);
        for (int i = 0; i < BYTE_SIZE; ++i) {
            bitStream.push_back(bits[i]);
        }
        ++totalBytesReaded;
        std::string decodePart = readBodyPart(bitStream, tree);
        decodedText += decodePart;
    }
    cout << "Total bytes readed: " << totalBytesReaded << endl;
    return decodedText;
}

std::string HuffmanDecompressor::readBodyPart(vector<bool> &bitStream, HuffmanTree &tree) {
    HuffmanNode *currentNode = tree.getRoot();
    std::string decodedText = "";

    int lastDeletedBitIndex = 0;

    for (size_t i = 0; i < bitStream.size(); ++i) {
        currentNode = bitStream[i] ? currentNode->right : currentNode->left;

        if (currentNode->isLeaf()) {
            decodedText += currentNode->character;
            lastDeletedBitIndex = i;
            currentNode = tree.getRoot();
        }
    }
    bitStream.erase(bitStream.begin(), bitStream.begin() + lastDeletedBitIndex + 1);
    return decodedText;
}

