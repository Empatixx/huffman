

#ifndef HUFFMANN_HUFFMANTREE_H
#define HUFFMANN_HUFFMANTREE_H

#include <string>
#include "HuffmanNode.h"
#include "CompareNode.h"
#include <map>
#include <queue>


using namespace std;

/**
 * @class HuffmanTree
 * @brief Class representing the Huffman Tree used for Huffman coding.
 *
 * Manages the construction and traversal of the Huffman tree used for encoding and decoding.
 */
class HuffmanTree {
private:
    HuffmanNode *root; ///< Pointer to the root of the Huffman tree.
    map<char, string> codes; ///< Map of characters to their Huffman codes.

    /**
     * Builds the Huffman tree from a given frequency map.
     * @param freqMap Map of character frequencies.
     */
    void buildTree(std::map<char, unsigned> &freqMap);

    /**
     * Generates the Huffman codes for each character in the tree.
     * This function is typically called recursively.
     * @param root Pointer to the current node in the tree.
     * @param str Accumulated string of bits representing the path to the current node.
     */
    void generateCodes(HuffmanNode *root, string str);

public:
    /**
     * Constructor that builds a Huffman tree from a frequency map.
     * @param freqMap Map of character frequencies.
     */
    HuffmanTree(std::map<char, unsigned> &freqMap);

    /**
     * Retrieves the Huffman codes for the characters.
     * @return Map of characters to their Huffman codes.
     */
    std::map<char, std::string> getCodes();

    /**
     * Gets the root of the Huffman tree.
     * @return Pointer to the root HuffmanNode.
     */
    HuffmanNode *getRoot();
};


#endif //HUFFMANN_HUFFMANTREE_H
