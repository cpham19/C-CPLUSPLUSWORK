#include <stdio.h>
#include "quick_sort.h"

int main(void) {
    const int ARRAYSIZE = 9;
    int my_ints[] = {5, 1, 7, 8, 0, 9, 4, 2, 3};
    quick_sort(my_ints, ARRAYSIZE);
    for (int i = 0; i < ARRAYSIZE; i++) {
        printf("%d ", my_ints[i]);
    }
    printf("\n");
    return 0;
}

