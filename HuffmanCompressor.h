

#ifndef HUFFMANN_HUFFMANCOMPRESSOR_H
#define HUFFMANN_HUFFMANCOMPRESSOR_H
#include <map>
#include <string>
#include "HuffmanTree.h"

using namespace std;

/**
 * @class HuffmanCompressor
 * @brief Class for Huffman Compression operations.
 *
 * Implements methods for compressing a file using Huffman coding.
 */
class HuffmanCompressor {
public:
    /**
     * Compresses the file specified by fileInput and stores the result in fileOutput.
     * @param fileInput Path to the input file.
     * @param fileOutput Path to the output compressed file.
     * @throws std::runtime_error if files cannot be opened.
     */
    void compress(const string &fileInput, const string &fileOutput);

private:
    /**
     * Writes the header containing the frequencies of characters to the output file.
     * @param frequencies Map of character frequencies.
     * @param outputFile Reference to the output file stream.
     * @param padding Number of bits to be padded.
     */
    void writeHeader(const map<char, unsigned> &frequencies, int padding, ofstream &outputFile);

    /**
     * Writes the encoded body of the file to the output file.
     * @param fileInput Path to the input file.
     * @param codes Map of characters to their Huffman codes.
     * @param outputFile Reference to the output file stream.
     */
    void writeBody(const string &fileInput, const map<char, string> &codes, ofstream &outputFile);

    /**
     * Reads the input file and calculates the frequency of each character.
     * @param fileInput Path to the input file.
     * @return Map of characters and their frequencies.
     */
    map<char, unsigned int> getFrequencies(const string &fileInput);

    /**
     * Writes the bit stream to the output file as bytes.
     * @param bitStream Vector of bools representing the bit stream.
     * @param outputFile Reference to the output file stream.
     */
    void writeByte(vector<bool> &bitStream, ofstream &outputFile);


    /**
     * Calculates the number of bits to be padded.
     * @param frequency frequency of characters
     * @param codes codes of characters
     * @return
     */
    int calculatePadding(map<char, unsigned>& frequency, map<char, string>& codes);
};


#endif //HUFFMANN_HUFFMANCOMPRESSOR_H
