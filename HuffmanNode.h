

#ifndef HUFFMANN_HUFFMANNODE_H
#define HUFFMANN_HUFFMANNODE_H

/**
 * @class HuffmanNode
 * @brief Node class used in HuffmanTree.
 *
 * Represents a node in the Huffman tree with character, frequency, and pointers to left and right children.
 */
class HuffmanNode {
public:
    char character; ///< Character represented by the node.
    unsigned frequency; ///< Frequency of the character.
    HuffmanNode *left, *right; ///< Pointers to the left and right children.

    /**
     * Constructor for HuffmanNode.
     * @param character The character this node represents.
     * @param frequency The frequency of the character.
     */
    HuffmanNode(char character, unsigned frequency);

    /**
     * Checks if the node is a leaf node.
     * @return True if the node is a leaf, false otherwise.
     */
    bool isLeaf();
};

#endif //HUFFMANN_HUFFMANNODE_H
