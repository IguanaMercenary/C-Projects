//
// Created by michael on 02/02/18.
//

#ifndef DATASTRUCTS_LINKEDLIST_H
#define DATASTRUCTS_LINKEDLIST_H
typedef struct LLNode {
    int data;
    struct LLNode *next;
} LLNode;

LLNode *createLL(LLNode *node, int data);
void printLL(LLNode *head);
LLNode *reverseLL(LLNode *head);
#endif //DATASTRUCTS_LINKEDLIST_H
