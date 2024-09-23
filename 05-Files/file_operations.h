#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H
#include <stdio.h>

char readFileCharacter(FILE* filePointer);
char* readFileWithFormat(FILE* filePointer, char* format, int size);
char* readStringFromFile(FILE* filePointer);

void writeByteToFile(FILE* filePointer, char byte);
int writeFormatToFile(FILE* filePointer, char* format, ...);
int writeStringToFile(FILE* filePointer, char* string);

#endif //FILE_OPERATIONS_H
