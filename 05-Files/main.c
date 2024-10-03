#include <stdio.h>
#include <stdlib.h>

#include "file_operations.h"

int main(void) {
    // Reading the contents of a file:
    // modes are:
    //   r: read
    //   w: write (wil overwrite existing file)
    //   a: append
    FILE* fp = fopen("../file_to_read.txt", "r");
    if (fp == NULL) {
        printf("Could not open the file\n");
        return 1;
    }

    char c = readFileCharacter(fp);
    while (!feof(fp)) {
    // while (c != EOF) {
        printf("%c", c);
        c = readFileCharacter(fp);
    }
    fclose(fp);
    printf("\n");

    // Read the file with fscanf
    // fscanf(<file pointer>, <format string>, address of target) reads formatted input, like scanf()
    // fprintf(<file pointer>, <format string>, <values>) writes formatted output, like printf()

    fp = fopen("../file_to_read.txt", "r");
    if (fp == NULL) {
        printf("Could not open the file\n");
        return 1;
    }

    char* format = "%s";
    char* text = readFileWithFormat(fp, format, 100);
    printf("Read with fscanf: %s\n", text);
    fclose(fp);

    // Writing to a file one char at a time:
    fp = fopen("../file_to_write.txt", "w");
    char* textToWrite = "Hello, File!";
    char charToWrite = *textToWrite;
    while (charToWrite != '\0') {
        writeByteToFile(fp, charToWrite);
        charToWrite = *(++textToWrite);
    }

    format = "\nHello, File! %d times!";
    int bytesWritten = writeFormatToFile(fp, format, 2);
    printf("Bytes written: %d\n", bytesWritten);

    int success = writeStringToFile(fp, "\nHello, File! Again!");
    if (success) {
        printf("Bytes written: %d\n", bytesWritten);
    }

    fclose(fp);

    fp = fopen("../file_to_read.txt", "r");
    if (fp == NULL) {
        printf("Could not open the file\n");
        return 1;
    }

    size_t size = 10;
    char* contents = readStringFromFile(fp, size);
    while (contents != NULL) {
        printf("%s\n", contents);
        free(contents);
        contents = readStringFromFile(fp, size);
    }
    fclose(fp);

    fp = fopen("../char_count_file.txt", "r");
    if (fp == NULL) {
        printf("Could not open the file\n");
        return 1;
    }
    int charCount = countCharactersInFile(fp);
    printf("File has %d characters\n", charCount);
    fclose(fp);

    fp = fopen("../char_count_file.txt", "r");
    if (fp == NULL) {
        printf("Could not open the file\n");
        return 1;
    }

    int lineCount = countLinesInFile(fp);
    printf("File has %d lines\n", lineCount);

    fclose(fp);

    fp = fopen("numbers_squares.txt", "w");
    if (fp == NULL) {
        return 1;
    }
    for (int counter = 1; counter <= 10; counter++) {
        fprintf(fp, "%2d : %3d\n", counter, counter * counter);
    }
    fclose(fp);

    fp = fopen("../char_count_file.txt", "r");
    int* frequencies = getCharacterFrequencies(fp);
    if (frequencies == NULL) {
        printf("Could not get character frequency\n");
        return 1;
    }
    fclose(fp);

    for (int counter = 0; counter < 26; counter++) {
        printf("%c: %d\n", 'a' + counter, frequencies[counter]);
    }

    free(frequencies);

    return 0;
}