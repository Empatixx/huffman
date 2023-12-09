#ifndef HUFFMANN_COMPARENODE_H
#define HUFFMANN_COMPARENODE_H


#include "HuffmanNode.h"

/**
 * @class CompareNode
 * @brief Comparator class for HuffmanNode pointers.
 *
 * This class defines the operator() to compare two HuffmanNode pointers based on their frequency.
 * It's typically used in a priority queue to build the Huffman tree.
 */
class CompareNode {
public:
    /**
     * Comparison operator for HuffmanNode pointers.
     * @param left Pointer to the left HuffmanNode.
     * @param right Pointer to the right HuffmanNode.
     * @return True if the frequency of the left node is greater than the right node, false otherwise.
     */
    bool operator()(HuffmanNode* left, HuffmanNode* right);
};


#endif //HUFFMANN_COMPARENODE_H
