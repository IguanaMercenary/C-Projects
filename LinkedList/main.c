#include "LinkedList.h"
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

/* xn = xn-1 + xn-2 */
int fibonacci(int n) {
    if (n == 0) return n;
    else if (n == 1) return n;
    else return (fibonacci(n - 1) + fibonacci(n - 2));
}

bool powerOfTwo(int x) {
    return (x & (x - 1)) == 0;
}

int main() {
    char string[] = "Hello";
    char temp[10];

    int begin = 0;
    for (int i = (int) strlen(string) - 1; i >= 0; i--) {
        temp[begin] = string[i];
        begin++;
    }
    temp[begin] = '\0';
    printf("\n%s, %s\n", string, temp);

    int n;
    int count = 0;

    int sum;
    for (int j = 1; j < 100; j++) {
        sum += j;
        count++;
    }

    sum = sum + 21;
    int average;
    for (int i = 1; i < 100; i++) {
        average += i;
    }
    printf("%d, %d\n", sum, average);

    printf(powerOfTwo(2) ? "true\n" : "false\n");
    printf(powerOfTwo(20) ? "true\n" : "false\n");
    printf(powerOfTwo(100) ? "true\n" : "false\n");
    printf(powerOfTwo(256) ? "true\n" : "false\n");

    int f;
    printf("Enter the number of terms: ");
    scanf("%d", &f);

    /*Recursive*/
    printf("Fibonacci Series: \n");
    for (int k = 1; k < f; ++k) {
        printf("%d\n", fibonacci(k));
    }

    /*int i, h, t1 = 0, t2 = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &h);

    printf("Fibonacci Series: \n");
    *//*Iterative*//*
    for (i = 1; i <= h; ++i) {
        printf("%d, \n", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }*/

    LLNode *head = NULL;
    head = createLL(head, 2);
    head = createLL(head, 2);
    head = createLL(head, 3);
    head = createLL(head, 4);

    printLL(head);
    head = reverseLL(head);
    printLL(head);
}


