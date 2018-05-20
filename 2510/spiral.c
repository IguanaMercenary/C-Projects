#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* https://archived.moe/g/thread/65952131
    https://rbt.asia/g/thread/65952131
 */

static int* SpiralArray(int height, int width) {
    assert(height>0&&width>0);
    int* theArray = malloc(sizeof(int) * height * width);
    int horizontalTravel = width;
    int verticalTravel = height-1;
    int counter = 1;
    int currentHorizontalPosition = -1;
    int currentVerticalPosition = 0;
    while (true) {
        for (int i = 0; i < horizontalTravel; i++) {
            theArray[currentVerticalPosition * width + (++currentHorizontalPosition)] = counter++;
        }
        horizontalTravel--;
        if (counter > height*width) break;
        for (int i = 0; i < verticalTravel; i++) {
            theArray[(++currentVerticalPosition) * width + currentHorizontalPosition] = counter++;
        }
        verticalTravel--;
        if (counter > height*width) break;
        for (int i = 0; i < horizontalTravel; i++) {
            theArray[currentVerticalPosition * width + (--currentHorizontalPosition)] = counter++;
        }
        horizontalTravel--;
        if (counter > height*width) break;
        for (int i = 0; i < verticalTravel; i++) {
            theArray[(--currentVerticalPosition) * width + currentHorizontalPosition] = counter++;
        }
        verticalTravel--;
        if (counter > height*width) break;
    }
    return theArray;
}

static void Print2DArray(int* array, int height, int width) {
    int numberOfEntries = height*width;
    int entryLength = ceil(log10(numberOfEntries))+1; // +1 for space
    char buf[entryLength*width];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int currentValue = array[y*width+x];
            snprintf(buf + (entryLength * x), entryLength+1, "%*d ", entryLength-1, currentValue);
        }
        buf[entryLength*width-1] = 0;  // it got overwritten with a space above
        printf("%s\n", buf);
    }
}

int main() {
    int* array = SpiralArray(3, 5);
    Print2DArray(array, 3, 5);
}
