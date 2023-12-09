#include "CompareNode.h"

bool CompareNode::operator()(HuffmanNode *left, HuffmanNode *right) {
    return (left->frequency > right->frequency);
}
