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

char* readStringFromFile(FILE* filePointer) {
    fseek(filePointer, 0, SEEK_END);
    long size = ftell(filePointer);
    rewind(filePointer);

    // This creates a memory leak if this memory is never freed.
    char* value= (char*)malloc(sizeof(char) * size);
    printf("The file is %d bytes long\n", size);
    char buffer[size];
    char* contents = fgets(buffer, size, filePointer);
    strcpy(value, contents);
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