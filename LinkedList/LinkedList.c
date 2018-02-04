//
// Created by michael on 02/02/18.
//

#include <malloc.h>
#include "LinkedList.h"

LLNode *createLL(LLNode *node, int data) {
    LLNode *temp = (LLNode*)malloc(sizeof(LLNode));
    temp->data = data;
    temp->next = node;
    node = temp;
    return node;
}

void printLL(LLNode *head) {
    while (head != NULL) {
        printf("[%d] -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

LLNode *reverseLL(LLNode *head) {
    LLNode *current, *next, *prev;
    current = head;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}