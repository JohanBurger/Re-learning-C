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
    char c;
    while (!feof(filePointer)) {
        c = fgetc(filePointer);
        if (c != '\n') {
            printf("%c", c);
            charCounter++;
        }
    }

    return charCounter;
}