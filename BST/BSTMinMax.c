/*
 * Michael O'Connell
 * Date: 2018-01-30
 */

#include <stdio.h>
#include <stdlib.h>
#include "BSTMinMax.h"

/*
 * Finds the minimum value in a BST.
 */
BSTNode *BSTMin(BSTNode *root) {
    if(root == NULL) {
        printf("Error: Tree empty \n");
        exit(1);
    }
    while(root->left != NULL) root = root->left;
    return root;
}

/*
 * Finds the maximum value in a BST.
 */
BSTNode *BSTMax(BSTNode *root) {
    if(root == NULL) {
        printf("Error: Tree empty \n");
        exit(1);
    }
    while(root->right != NULL) root = root->right;
    return root;
}