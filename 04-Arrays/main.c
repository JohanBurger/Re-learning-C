#include <stdio.h>

#define SIZE 8

int isLowercaseAlpha(char c) {
    return c >= 'a' && c <= 'z';
}

int getIndex(char c) {
    if (isLowercaseAlpha(c)) {
        return c - 'a';
    }

    return -1;
}

int main(void) {
    int sourceArray[SIZE] = { 0,2,0,1,0,0,2,0 };
    int countArray[3] = { 0 };

    for (int counter = 0; counter < SIZE; counter++) {
        int element = sourceArray[counter];
        countArray[element]++;
    }

    for(int counter = 0; counter < 3; counter++) {
        printf("There was %d %d's\n", countArray[counter], counter);
    }

    printf("---\n");

    char sourceString[] = "kibrckzm";
    int charCountArray[26] = { 0 };

    int counter = 0;
    char sourceChar = sourceString[counter];
    while (sourceChar != '\0') {
        int index = getIndex(sourceChar);
        if (index != -1) {
            charCountArray[index]++;
        }
        sourceChar = sourceString[++counter];
    }

    for (int counter = 0; counter < 26; counter++) {
        if (charCountArray[counter] > 0) {
            printf("%d %c\n", charCountArray[counter], counter + 'a');
        }
    }

    return 0;
}
