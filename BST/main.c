/*
 * Michael O'Connell
 * Date: 2018-01-30
 */
#include "BSTStruct.h"
#include "BSTDelete.h"
#include "BSTMinMax.h"
#include "orderTraversal.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/* Prototypes */
BSTNode *createNode(int data);
BSTNode *insert(BSTNode *root, int data);
int searchBST(BSTNode *root, int data);
void loop(BSTNode *root);

/*
 * Main function. Inserts some test data to an null binary tree.
 * Prompts user to search for a number or quit.
 */
int main() {
    BSTNode *rootPtr = NULL;

    rootPtr = insert(rootPtr, 20);
    rootPtr = insert(rootPtr, 10);rootPtr = insert(rootPtr, 40);
    rootPtr = insert(rootPtr, 50);rootPtr = insert(rootPtr, 63);
    rootPtr = insert(rootPtr, 12);rootPtr = insert(rootPtr, 82);
    rootPtr = insert(rootPtr, 90);rootPtr = insert(rootPtr, 38);
    rootPtr = insert(rootPtr, 30);rootPtr = insert(rootPtr, 23);


    loop(rootPtr);

    free(rootPtr->left);
    free(rootPtr->right);
    free(rootPtr);
    fclose(stdin);
    return 0;
}

void loop(BSTNode *root) {
    int data;
    char *buffer;
    char input[1024];
    char argument;
    size_t size = 0;
    buffer = (char *) malloc(size * sizeof(char));
    if (buffer == NULL) {
        printf("Unable to allocate buffer");
        exit(1);
    }

    restart:
    while (fputs("Your options are: \n's' to search, \n'd' to delete, \n't' to traverse the tree, \n'm' to find the min/max number, or \n'q' to quit\n", stdout)
           && (fgets(input, sizeof(input), stdin) != NULL)) {

        fflush(stdout);

        sscanf(input, "%c", &argument);
        switch (argument) {
            case 'q':
                printf("Bye\n");
                return;
            case 's':
                printf("Enter the number you wish to search \n");
                while (fgets(input, sizeof(input), stdin) != NULL) {
                    if(sscanf(input, "%d", &data) > 0) {
                        printf(searchBST(root, data) ?
                               "Number was found \n\n" : "Number was not found \n\n");
                        goto restart;
                    }
                }
            case 'd':
                printf("Enter the number you wish to delete \n");
                while (fgets(input, sizeof(input), stdin) != NULL) {
                    if(sscanf(input, "%d", &data) > 0) {
                        searchBST(root, data) ?
                            deleteNode(root, data) && printf("Goodbye, %d\n\n", data) : printf("Could not find %d\n\n", data);
                        goto restart;
                    }
                }
            case 't':
            traversal:
                printf("Your traversal options are: \n'i' for inorder traversal, \n'r' for preorder traversal, or \n'p' for postorder traversal \n");
                while (fgets(input, sizeof(input), stdin) != NULL) {
                    char traversal;
                    sscanf(input, "%c", &traversal);
                    switch (traversal) {
                        case 'i':
                            inorderTraversal(root);
                            goto restart;
                        case 'r':
                            preorderTraversal(root);
                            goto restart;
                        case 'p':
                            postorderTraversal(root);
                            goto restart;
                        default:
                            printf("Invalid entry \n");
                            goto traversal;
                    }
                }
            case 'm':
            minmax:
                printf("Type: \n 'n' for the minimum value, or\n 'x' for the maximum value \n");
                while (fgets(input, sizeof(input), stdin) != NULL) {
                    char value;
                    int tempData;
                    BSTNode *tempPtr;
                    sscanf(input, "%c", &value);
                    switch (value) {
                        case 'n':
                            tempPtr = BSTMin(root);
                            tempData = tempPtr->data;
                            printf("The minimum number is: %d\n\n", tempData);
                            goto restart;
                        case 'x':
                            tempPtr = BSTMax(root);
                            tempData = tempPtr->data;
                            printf("The maximum number is: %d\n\n", tempData);
                            goto restart;
                        default:
                            printf("Invalid entry \n");
                            goto minmax;
                    }
                }
            default:
                printf("Invalid character \n");
                goto restart;
        }
    }
    free(buffer);
}

/*
 * Creates a new node in the binary tree and sets the child branches to null.
 */
BSTNode *createNode(int data) {
    BSTNode *newNode = malloc(sizeof(BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*
 * Inserts data into the binary tree depending on if the number is greater than
 * or less than or equal to the root node data.
 *
 */
BSTNode *insert(BSTNode *root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= (*root).data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

/*
 * Searches the binary tree for a number. Returns 0 if the number is not found.
 * Returns non-zero if the is found.
 */
int searchBST(BSTNode *root, int data) {

    if (!root) return 0;

    else if (root->data == data) return 1;

    return (data <= root->data) ?
           searchBST(root->left, data) : searchBST(root->right, data);
}
