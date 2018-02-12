#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *A, int n);
void merge(int *A, int *left, int numL, int *right, int numR);

int main() {
    int A[] = {1, 4, 6, 9, 3, 4, 5, 10, 7, 2};


    int numElements = sizeof(A) / sizeof(A[0]);
    printf("Pre-sorted array: ");
    for (int i = 0; i < numElements; i++) printf("%d ", A[i]);

    mergeSort(A, numElements);
    
    printf("\nMerge sorted array: ");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
void mergeSort(int *A, int n) {
    /*
     * n <- length A[]
     * if(n < 2) return
     *
     * mid <- n/2
     * left <- malloc(array[sizeof(mid)])
     * right <- malloc(array2[sizeof(other half)]
     *
     * for i <- 0 to mid - 1
     *  left[i] <- A[i]
     * for i <- mid to n -1
     *  right[i - mid] <- A[i]
     *
     * mergeSort(left)
     * mergeSort(right)
     * merge(left, right, A)
     *
     */
    if(n < 2) return;

    int mid = n/2;

    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((n - mid) * sizeof(int));

    for(int i = 0; i < mid; i++) {
        left[i] = A[i];
    }
    for(int i = mid; i < n; i++) {
        right[i - mid] = A[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(A, left, mid, right, n - mid);

    free(left);
    free(right);

}

void merge(int *A, int *left, int numL, int *right, int numR) {
    /*       k
     * A [2][4][1][6][8][5][3][7]
     *    0  1  2  3  4  5  6  7
     *
     *
     * L[2][4][1][6]      R[8][5][3][7]  //These arrays are created separately in memory from a copy of A
     *
     * //sort the two arrays
     * L[1][2][4][6]      R[3][5][7][8]
     *
     * //pick the smaller of the two elements from L and R and replace the value in A
     * L[1][2][4][6]      R[3][5][7][8]
     *   i                  j
     * ---->
     *    k
     * A [1][4][1][6][8][5][3][7]
     *    0  1  2  3  4  5  6  7
     *
     * while (i < numL && j < numR) {
     *  if(left[i] <= right[j]) {
     *      A[k] <- left[i];
     *      i <- i++;
     *  } else {
     *      A[k] <- right[j];
     *      j <- j++;
     *  }
     *   k <- k++;
     * }
     *
     * if one array finishes before the other
     * while (i < numL) {
     *  A[k] <- left[i];
     *  i++;
     *  k++;
     * }
     * while (j < numR) {
     *  A[k] <- right[j];
     *  j++;
     *  k++;
     * }
     */
    int i = 0, j = 0, k = 0;
    while (i < numL && j < numR) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < numL) {
        A[k] = left[i];
        i++, k++;
    }

    while (j < numR) {
        A[k] = right[j];
        j++, k++;
    }
}

