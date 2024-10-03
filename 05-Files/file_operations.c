#include "file_operations.h"

#include <stdlib.h>
#include <string.h>

// Read the file one char at a time...
char readFileCharacter(FILE* filePointer) {
    return fgetc(filePointer); // fgetc(stdin) reads from the console, equivalent to getchar()
}

char* readFileWithFormat(FILE* filePointer, char* format, int size) {
    // This creates a memory leak if this memory is never freed.
    char* returnString = (char*)malloc(sizeof(char) * size);
    // scanf(stdin, "%s", text) reads a string from the console, like scanf
    fscanf(filePointer, format, returnString);
    return returnString;
}

char* readStringFromFile(FILE* filePointer, size_t size) {
    // This creates a memory leak if this memory is never freed.
    char* value= (char*)malloc(sizeof(char) * size);
    printf("The file is %d bytes long\n", size);
    char buffer[size];
    if (fgets(buffer, size, filePointer) == NULL) {
        return NULL;
    }
    strcpy(value, buffer);
    return value;
}

void writeByteToFile(FILE* filePointer, char byte) {
    fputc(byte, filePointer); // Equivalent to putchar()
}

int writeFormatToFile(FILE* filePointer, char* format, ...) {
    return fprintf(filePointer, format);
}

int writeStringToFile(FILE* filePointer, char* string) {
    return fputs(string, filePointer);
}

int countCharactersInFile(FILE* filePointer) {
    if (filePointer == NULL) {
        return -1;
    }

    int charCounter = 0;
    char c = fgetc(filePointer);;
    while (!feof(filePointer)) {
        printf("%c", c);
        charCounter++;
        c = fgetc(filePointer);

    }

    return charCounter;
}

int countLinesInFile(FILE* filePointer) {
    if (filePointer == NULL) {
        return -1;
    }
    // File must at least have one line, even if it is blank.
    int lineCounter = 1;

    char c = fgetc(filePointer);
    while (!feof(filePointer)) {
        if (c == '\n') {
            lineCounter++;
        }
        c = fgetc(filePointer);
    }

    return lineCounter;
}

int* getCharacterFrequencies(FILE* filePointer) {
    if (filePointer == NULL) {
        return NULL;
    }

    int* frequencies = calloc(26, sizeof(int));
    char c = fgetc(filePointer);
    while (!feof(filePointer)) {
        if (c >= 'a' && c <= 'z') {
            frequencies[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            frequencies[c - 'A']++;
        }
        c = fgetc(filePointer);
    }
    return frequencies;
}