

#include "HuffmanCompressor.h"
#include <fstream>
#include <iostream>
#include <bitset>

#define BYTE_SIZE 8
#define SPECIAL_CHAR "$"

void HuffmanCompressor::compress(const string &fileInput, const string &fileOutput) {
    std::ofstream outputFile(fileOutput, std::ios::binary | std::ios::out);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        throw std::runtime_error("Error opening files!");
    }

    map<char,unsigned> frequencies = getFrequencies(fileInput);
    HuffmanTree tree(frequencies);
    map<char, string> codes = tree.getCodes();

    int padding = calculatePadding(frequencies, codes);
    writeHeader(frequencies, padding, outputFile);
    writeBody(fileInput, codes, outputFile);

    outputFile.close();
}

map<char, unsigned> HuffmanCompressor::getFrequencies(const string &fileInput) {
    std::ifstream inputFile(fileInput, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        throw std::runtime_error("Error opening files!");
    }
    std::map<char, unsigned> freqMap;
    char c;
    while (inputFile.get(c)) {
        freqMap[c]++;
    }

    inputFile.close();
    return freqMap;
}

void HuffmanCompressor::writeHeader(const map<char, unsigned int> &frequencies, int padding, std::ofstream &outputFile) {
    for (auto &pair: frequencies) {
        outputFile << pair.first << pair.second;
    }

    outputFile << SPECIAL_CHAR << SPECIAL_CHAR; // End of codes
    outputFile << padding << SPECIAL_CHAR; // Padding
}

void HuffmanCompressor::writeBody(const string &fileInput, const map<char, string> &codes, std::ofstream &outputFile) {
    std::vector<bool> bitStream;
    std::ifstream inputFile(fileInput, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        throw std::runtime_error("Error opening files!");
    }
    char c;
    int totalWrittenBytes = 0;
    while (inputFile.get(c)){
        std::string code = codes.at(c);
        for (char bit: code) {
            bitStream.push_back(bit == '1');
        }
        while(bitStream.size() >= BYTE_SIZE){
            // get first 8 bits
            vector<bool> first8Bits(bitStream.begin(), bitStream.begin() + BYTE_SIZE);
            bitStream.erase(bitStream.begin(), bitStream.begin() + BYTE_SIZE);

            writeByte(first8Bits, outputFile);
            totalWrittenBytes++;
        }
    }
    totalWrittenBytes++;
    inputFile.close();
    cout << "Compression total body bytes written: " << totalWrittenBytes << endl;
    writeByte(bitStream, outputFile);
}

void HuffmanCompressor::writeByte(vector<bool> &bitStream, ofstream &outputFile) {
    // Convert bitStream to a string of bytes and write to the output file
    while (bitStream.size() % BYTE_SIZE != 0) {
        bitStream.push_back(false); // padding with 0
    }

    std::bitset<BYTE_SIZE> byte;
    for (size_t j = 0; j < BYTE_SIZE; ++j) {
        byte[j] = bitStream[j];
    }
    outputFile.put(static_cast<char>(byte.to_ulong()));
}


int HuffmanCompressor::calculatePadding(map<char, unsigned>& frequency, map<char, string>& codes) {
    int totalBits = 0;
    for (auto &pair: frequency) {
        totalBits += pair.second * codes.at(pair.first).size();
    }
    int padding = BYTE_SIZE - (totalBits % BYTE_SIZE);
    return padding;
}
