//
// Created by michael on 30/01/18.
//

#ifndef BST_BSTSTRUCT_H
#define BST_BSTSTRUCT_H
/* Binary Search tree struct. Has data, a left node, and a right node. */
typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;
#endif //BST_BSTSTRUCT_H
