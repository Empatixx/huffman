#include <iostream>
#include "HuffmanCompressor.h"
#include "HuffmanDecompressor.h"
#include "FileUtils.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << "c " << "target" << "dest" << std::endl;
        std::cout << "Usage: " << argv[0] << "d " << "target" << "dest" << std::endl;
        std::cerr << "Invalid number of arguments!" << std::endl;
        return 1;
    }
    std::string command = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    if (command == "c") {
        HuffmanCompressor compressor;
        FileUtils fileUtils;
        compressor.compress(inputFile, outputFile);
        std::cout << "Size diff: " << fileUtils.sizeDifference(inputFile, outputFile) << "%" << std::endl;
    } else if (command == "d") {
        HuffmanDecompressor decompressor;
        decompressor.decompress(inputFile, outputFile);
    } else {
        std::cerr << "Invalid command!" << std::endl;
        return 1;
    }
    return 0;
}
