/*
 * Michael O'Connell
 * Date: 2018-01-30
 */

#include "orderTraversal.h"
#include <stdio.h>

void preorderTraversal(BSTNode *root) {
    if (!root) return;
    printf("%d\n", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(BSTNode *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d\n", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(BSTNode *root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\n", root->data);
}