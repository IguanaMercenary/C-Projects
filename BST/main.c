/*
 * Michael O'Connell
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>

/* Binary Search tree struct. Has data, a left node, and a right node. */
typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

/* Prototypes */
BSTNode *createNode(int data);
BSTNode *insert(BSTNode *root, int data);
int searchBST(BSTNode *root, int data);

/*
 * Main function. Inserts some test data to an null binary tree.
 * Prompts user to search for a number or quit.
 */
int main() {
    int data;
    char *buffer;
    char input[1024];
    size_t size = 0;
    BSTNode *rootPtr = NULL;

    rootPtr = insert(rootPtr, 10);
    rootPtr = insert(rootPtr, 20);
    rootPtr = insert(rootPtr, 30);


    buffer = (char *) malloc(size * sizeof(char));
    if (buffer == NULL) {
        printf("Unable to allocate buffer");
        exit(1);
    }

    /*
     * Kinda slow with so many if statements.
     * I'll change it later...
     */
    while (fputs("Enter a number to find (Press 'q' to quit)\n", stdout)
           && (fgets(input, 1024, stdin) != NULL)) {
        fflush(stdout);
        if (strcmp(input, "q\n") == 0) {
            printf("Bye");
            break;
        } else if (sscanf(input, "%d", &data) > 0) {
            if (searchBST(rootPtr, data) == 1) {
                printf("Number was found \n");
            } else {
                printf("Number was not found \n");
            }
        } else {
            printf("Invalid character \n");
        }
    }
    free(buffer);
    fclose(stdin);
    return 0;
}

/*
 * Creates a new node in the binary tree and sets the child branches to null.
 */
BSTNode *createNode(int data) {
    BSTNode *newNode = (BSTNode *) malloc(sizeof(BSTNode));
    (*newNode).data = data;
    newNode->left = newNode->right = NULL;
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
 */
int searchBST(BSTNode *root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else if (data <= root->data) {
        return searchBST(root->left, data);
    } else {
        return searchBST(root->right, data);
    }
}