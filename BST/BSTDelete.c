/*
 * Michael O'Connell
 * Date: 2018-01-30
 */
#include "BSTDelete.h"
#include "BSTMinMax.h"
#include <stdlib.h>

/*
 * If a node has no children, no problem.
 * If a node has one child, easy.
 * If a node has 2 children:
 *  -Find the minimum in the right subtree. This value will be greater
 *   than any value in the left subtree and less than any value in the right subtree.
 *  -OR find the maximum in the left subtree.
 *  -Copy this value to the targeted node
 *  -Remove the duplicate, free memory, and establish new link.
 */
BSTNode *deleteNode(BSTNode *root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) { /* data must be in left subtree */
        (*root).left = deleteNode(root->left, data);
    } else if (data > root->data) { /* data must be in right subtree */
        (*root).right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) { /* No children, therefore delete */
            free(root);
            root = NULL;
        } else if (root->left == NULL) { /* One child in the right subtree */
            BSTNode *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) { /* One child in the left subtree */
            BSTNode *temp = root;
            root = root->left;
            free(temp);
        } else {
            BSTNode *temp = BSTMin(root->right);
            /* BSTNode *temp = findMax(root->left); */
            root->data = temp->data;
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;
}