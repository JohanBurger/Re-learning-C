#include <stdio.h>
#include <stdlib.h>

#define MAX_IDS 32

int main(void) {
    int ids[MAX_IDS] = {0};
    for (int i = 0; i < MAX_IDS; i++) {
        ids[i] = i;
    }

    printf("while loop:\n");
    int while_iter = 0;
    while (while_iter < MAX_IDS) {
        printf("%d ", ids[while_iter]);
        while_iter++;
    }
    printf("\n");

    printf("do ... while loop:\n");
    int do_while_iter = 0;
    do {
        printf("%d ", ids[do_while_iter]);
        do_while_iter++;
    }
    while (do_while_iter < MAX_IDS);
    printf("\n");

    return EXIT_SUCCESS;
}
