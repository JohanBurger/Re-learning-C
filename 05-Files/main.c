#include <stdio.h>

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

    // Read the file one char at a time...
    char c = fgetc(fp); // fgetc(stdin) reads from the console, equivalent to getchar()
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
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
    char text[100];
    fscanf(fp, "%s", text); // scanf(stdin, "%s", text) reads a string from the console, like scanf
    printf("Read with fscanf: %s\n", text);
    fclose(fp);

    // Writing to a file one char at a time:
    fp = fopen("../file_to_write.txt", "w");
    char* textToWrite = "Hello, File!";
    char charToWrite = *textToWrite;
    while (charToWrite != '\0') {
        fputc(charToWrite, fp); // Equivalent to putchar()
        charToWrite = *(++textToWrite);
    }

    int bytesWritten = fprintf(fp, "\nHello, File! %d times!", 2);
    printf("Bytes written: %d\n", bytesWritten);

    fclose(fp);

    fp = fopen("../file_to_read.txt", "r");
    if (fp == NULL) {
        printf("Could not open the file\n");
        return 1;
    }
    // Find the size of the file:
    fseek(fp, 0, SEEK_END);
    long sz = ftell(fp);
    rewind(fp);

    printf("The file is %d bytes long\n", sz);
    char textRead[sz];
    char* test = fgets(textRead, sz, fp);
    printf("%s\n", test);
    printf("%s\n", textRead);
    return 0;
}
