#include <stdio.h>

int main(void) {
    // Reading the contents of a file:
    FILE* fp = fopen("../file_to_read.txt", "r");
    if (fp == NULL) {
        printf("Could not open the file\n");
        return 1;
    }

    // Read the file one char at a time...
    char c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);

    // Writing to a file:
    fp = fopen("../file_to_write.txt", "w");
    char* textToWrite = "Hello, File!";
    char charToWrite = *textToWrite;
    while (charToWrite != '\0') {
        fputc(charToWrite, fp);
        charToWrite = *(++textToWrite);
    }

    int bytesWritten = fprintf(fp, "\nHello, File! %d times!", 2);
    printf("Bytes written: %d\n", bytesWritten);

    fclose(fp);
    return 0;
}
