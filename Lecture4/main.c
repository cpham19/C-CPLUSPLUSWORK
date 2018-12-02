#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    printf("Initializing Array");
    /* Create array of size 10 */
    int my_array[10];

    int i, sum = 0;

    /* initialize array before usage 
     *  Look carefully: i++ causes error so we use i = i + 1 instead
     */
    for (i = 0; i < (sizeof my_array) / 4; i = i + 1) {
        my_array[i] = i;
    }

    for (i = 0; i < (sizeof my_array) / 4; i = i + 1) {
        sum += my_array[i];
    }


    for (i = 0; i < (sizeof my_array) / 4; i = i + 1) {
        printf("%d\n", my_array[i]);
    }

    printf("%d\n", sum);
    /* Each variable is 4 bytes, so 10 variables in array = 40 bytes*/
    printf("%d\n\n", sizeof my_array);

    /* Pointer is a variable who holds the memory address of another variable 
     * if p contains address of data object, then *p allows you to access the object 
     * * and & cancel each other out
     */

    printf("Pointers");

    int j = 42;
    int *p1 = &j;
    printf("address of j: %p; p1: %p; value of j: %d; value at address p1: %d\n\n", &j, p1, j, *p1);

    int k = 42;
    int *kp = &k;
    printf("k: %d\nvalue at the address of k: %d\nkp: %p\naddress of value pointed to by kp: %p\n\n", k, *&k, kp, &*kp);


    /* Use pointer to change value at address it points to */
    int m = 42;
    int *ptr = &m;
    *ptr = *ptr + 5;
    printf("%d\n\n", m);

    /* Pointers are 64 bit on 64-bit systems. Irrespective of size of data type they point to */
    int o = 42;
    double d = 42.0;
    int *op = &o;
    double *dp = &d;
    printf("size of an int: %lu; size of op, a pointer to an int: %lu; size of a double: %lu; size of dp, a pointer to a double: %lu\n\n", sizeof (*op), sizeof (op), sizeof (*dp), sizeof (dp));

    /* Void pointers */
    printf("Void pointers");
    void *v;
    printf("%lu\n\n", sizeof (*v));

    /* Null pointer: setting a pointer to 0 makes it a null pointer! Not to be confused with void pointers. */
    void *v1 = 0;

    /* Constant pointers */
    printf("Pointer to const int");

    int u = 0, y = 42;
    /* Pointer to a const int */
    const int *up = &u;
    printf("%d\n", *up);
    up = &y;
    printf("%d\n\n", *up);
    /* *up = 47; would cause an error because int is constant */

    /* Prevent pointer from changing to a different address */
    printf("Const pointer to an int");
    int x = 0, z = 42;
    /* Constant pointer to an int */
    int * const xp = &x;
    printf("%d\n", *xp);

    *xp = 1;
    printf("%d\n\n", *xp);
    /* xp = &z causes error because constant pointer cannot change address */

    /* Pointers with array */
    int array[] = {1, 2};
    int array2[] = {3, 4};
    /* array[] = array2[] is error because arrays are constant pointers! */

    /* Distance */
    printf("Distance\n");
    int int_array[] = {1, 2, 3, 4, 5};
    int index0 = 0, index4 = 4;
    int *pointer1 = &int_array[index0], *pointer2 = &int_array[index4];
    long unsigned int_size = sizeof (int), distance = pointer2 - pointer1;
    printf("The distance in bytes from address %p to address %p is %lu times %lu.\n\n", pointer1, pointer2, distance, int_size);
    
    /* Printing out array using pointers */
    printf("Printing array using pointers\n");
    int size = 4;
    int arrayA[] = {1,2,3,4};
    int *w, *last;
    /* Address of last index of array */
    last = &arrayA[size - 1];
    for (w = arrayA; w <= last; w = w + 1) {
        printf("%d\n", *w);
    }
    printf("\n");
    
    int arrayB[] = {1,2,3,4};
    int * arrayBp;
    arrayBp = arrayB;
    int *end = arrayBp + 4;
    
    printf("start %p + 4 * 4 = end %p\n", arrayB, end);
    do {
        printf("address %p contains value %d\n", arrayBp, *arrayBp);
        arrayBp++;
    } while (arrayBp < end);
    
    printf("\n");
    
    /* 2-d arrays */
    printf("2-D Arrays\n");
    int arrayC[2][2] = {{1,2}, 
                          {3,4}};
    for (int row = 0; row < 2; row = row + 1) {
        for (int col = 0; col < 2; col = col + 1)  {
            printf("%d\n", arrayC[row][col]);
        }
    }
    
    printf("\n");
    
    /* weekends[2][1] = *(weekends + 2 * 2 + 1) */
    
    /* Array of pointers */
    printf("Array of pointers\n");
    int *arrayD[3];
    int x1 = 1, y1 = 2, z1 = 3;
    arrayD[0] = &x1;
    arrayD[1] = &y1;
    arrayD[2] = &z1;
    
    for (int counter = 0; counter < 3; counter = counter + 1) {
        printf("%d\n", *arrayD[counter]);
    }
    printf("\n");
    
    

    return (EXIT_SUCCESS);
}

