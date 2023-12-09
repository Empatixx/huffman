

#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(char character, unsigned int frequency) {
    this->character = character;
    this->frequency = frequency;
    this->left = nullptr;
    this->right = nullptr;
}

bool HuffmanNode::isLeaf() {
    return (this->left == nullptr && this->right == nullptr);
}


