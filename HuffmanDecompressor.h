

#ifndef HUFFMANN_HUFFMANDECOMPRESSOR_H
#define HUFFMANN_HUFFMANDECOMPRESSOR_H

#include <map>
#include <string>
#include <vector>
#include "HuffmanTree.h"

using namespace std;

/**
 * @class HuffmanDecompressor
 * @brief Class for Huffman Decompression operations.
 *
 * Implements methods for decompressing a file that was compressed using Huffman coding.
 */
class HuffmanDecompressor {
public:
    /**
     * Decompresses the file specified by fileInput and stores the result in fileOutput.
     * @param fileInput Path to the input compressed file.
     * @param fileOutput Path to the output decompressed file.
     * @throws std::runtime_error if files cannot be opened.
     */
    void decompress(const string &fileInput, const string &fileOutput);

private:
    /**
     * Reads the header from the input file and constructs a frequency map.
     * @param inputFile Reference to the input file stream.
     * @return Map of characters and their frequencies.
     */
    std::map<char, unsigned> readHeader(std::ifstream &inputFile);

    /**
     * Reads the encoded body from the input file.
     * @param inputFile Reference to the input file stream.
     * @param tree Reference to the HuffmanTree used for decoding.
     * @return Vector of bools representing the bit stream.
     */
    std::string readBody(std::ifstream &inputFile, HuffmanTree &tree);

    /**
     * Decodes the bit stream using the Huffman tree.
     * @param bitStream Vector of bools representing the bit stream.
     * @param tree Reference to the HuffmanTree used for decoding.
     * @return The decoded part text.
     */
    std::string readBodyPart(vector<bool> &bitStream, HuffmanTree &tree);
};

#endif //HUFFMANN_HUFFMANDECOMPRESSOR_H
