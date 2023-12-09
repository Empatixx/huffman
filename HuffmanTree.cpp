

#include "HuffmanTree.h"

void HuffmanTree::buildTree(map<char, unsigned int> &freqMap) {
// Create a priority queue to store the nodes of the Huffman tree
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNode> pq;

    // Create a leaf node for each character and add it to the priority queue.
    for (auto pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Iterate until the size of the queue is 1
    while (pq.size() != 1) {
        // Remove the two nodes of the highest priority (lowest frequency) from the queue
        HuffmanNode *left = pq.top(); pq.pop();
        HuffmanNode *right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children and with a frequency equal to the sum of the two nodes' frequencies. Add the new node to the priority queue.
        HuffmanNode *top = new HuffmanNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        pq.push(top);
    }

    // The remaining node is the root of the Huffman tree.
    root = pq.top();
}

void HuffmanTree::generateCodes(HuffmanNode *root, string str) {
    if (root == nullptr) {
        return;
    }

    // If this is a leaf node (it contains a character), then we have found a code for one of the characters.
    if (root->character != '$') {
        codes[root->character] = str;
    }

    // Move left and right in the tree and append '0' for left and '1' for right
    generateCodes(root->left, str + "0");
    generateCodes(root->right, str + "1");
}

HuffmanTree::HuffmanTree(map<char, unsigned int> &freqMap) {
    root = nullptr;
    buildTree(freqMap);
    generateCodes(root, "");
}

std::map<char, std::string> HuffmanTree::getCodes() {
    return codes;
}

HuffmanNode *HuffmanTree::getRoot() {
    return root;
}
