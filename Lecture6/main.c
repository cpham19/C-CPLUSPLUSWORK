#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/* Functions */

/* Global variables */
int a = 1, b = 2, c = 3;
int *cptr = &c;

/* Prototype */
int get_value(void); // Ex 6

/* Pointer to function  */
void myproc(long d); // Ex 7
void mycaller(void (*f)(long), long param); // Ex 7

/* Example 1
 * Pass a pointer 
 */
void change(int val, int *p) {
    val = 500; // doesn't change anything because passing by value
    *p = 500; // changes the value at the address
}

/* Example 2*/
void change2(int *p) {
    *p = 500;
    p = 0;
}

/* Example 3*/
void change3(int array[]) {
    array[2] = 30;
}

/* Example 4*/
void change4(int val) {
    val = 500;
    *cptr = 500; // this is referring to c (as *cptr = &c) so c becomes 500
    c = 42; // Then c becomes 42
}

/* Example 5 */
int check_static() {
    // Value is kept
    static int x = 0;
    x += 1;
    return x;
}

/* Constant Argument */
int function1(const char *s, const int x) {
    const int VALUE = 10;
    printf("x = %d\n", VALUE);
    return *s; // changing *s or x will cause compiler error
}

int main(void) {
    int x = 1;
    int y = 1;

    /* In Java, we pass a copy of a reference. In C, we pass a pointer. */
    printf("Ex 1a: Passing a pointer\n");
    change(x, &y);
    printf("x: %d \ny: %d\n\n", x, y); // x was not changed, but y was!

    /* When changing the pointer itself, the original pointer remains the same. */
    printf("Ex 2: Changing the pointer itself\n");
    int *xp = &x;
    change2(&x);
    printf("x: %d \nxp: %p\n\n", x, xp); // x was changed but xp wasnt

    /* Passing a pointer again */
    printf("Ex 1b: Passing a pointer again \n");
    int x2 = 1;
    int y2 = 1;
    int *y2ptr = &y2;
    change(x2, y2ptr);
    printf("x2: %d \ny2: %d\n\n", x2, y2); // x was not changed, but y was!

    /* Remember array name is a pointer at the beginning of the array */
    printf("Ex 3: Passing an array (which is a pointer at the beginning of array)\n");
    int arrayA[] = {1, 2, 3, 4};
    change3(arrayA);
    for (int counter = 0; counter < 4; counter++) {
        printf("%d\n", arrayA[counter]);
    }
    printf("\n");

    printf("Ex 4: Global and local scope \n");
    printf("a = %d; b = %d, c = %d\n", a, b, c);
    a = 2;
    change4(b);
    printf("a = %d; b = %d, c = %d\n\n", a, b, c);

    /* Another Scope example */
    printf("Ex 5: Static variable and Scope example \n");

    for (int counter = 0; counter < 10; counter++) {
        printf("%d\n", check_static()); // Future calls to same function can access the same value from last cell
    }

    printf("\n");

    /* Prototypes 
     * Defined in header files (.h) which allows you to use functions in other .c files
     */
    printf("Ex 6: Prototype and Header Files \n");
    int d = get_value();
    printf("%d\n\n", d);

    /* Function Pointers */
    // int (*fp)(double x) - pointer to a function takes double parameter and that returns an int
    // double * (*gp)(int) - pointer to a function takes int parameter and returns a pointer to double

    /* int func(); - function returning int
     * int *func(); - function returning pointer to int
     * int (*func)(); - pointer to function returning int
     * int *(*func)(); - pointer to function returning a pointer to int
     */

    /* Pointer to function */
    printf("Pointer to function\n");
    myproc(10000000);
    mycaller(myproc, 10000000);
    printf("\n");

    /* Bitwise Operations */
    // int a = 4 - 00000000 00000000 00000000 00000100
    // int a = 0x04 - 00000000 00000000 00000000 00000100 (hex, base 16)
    int int1 = 0x10;
    printf("Bits\n");
    printf("Decimal - %d Hex - %x\n\n", int1, int1);

    /* Bit Shift */
    // Good way to multiply or divide by powers of 2
    printf("Bit Shift\n");
    int int2 = 0x04; // 00000000 00000000 00000000 00000100
    int2 = int2 >> 1; // shift each bit one position to right
    // now  00000000 00000000 00000000 00000010
    printf("%d\n", int2);

    int2 = int2 << 1; // shift all the bits one position to the left 
    printf("%d\n", int2);

    //Be careful of wraparound with twos-complement notation:
    int2 = 0x04; // 00000000 00000000 00000000 00000100
    int2 = int2 << 29; // 10000000 00000000 00000000 00000000 
    printf("%d\n\n", int2);

    /* Bitwise AND */
    printf("Bitwise AND\n");
    int int3 = 0x05; // 00000000 00000000 00000000 00000101
    int int4 = 0x06; // 00000000 00000000 00000000 00000110 
    printf("%d\n", int3 & int4); // outputs 00000000 00000000 00000000 00000100 (4)


    int int5 = 0x09; // 00000000 00000000 00000000 00001001
    int int6 = 0x06; // 00000000 00000000 00000000 00000110 
    printf("%d\n\n", int5 & int6); // outputs 0 because none of the bits match (0)

    /* Bitwise OR */
    printf("Bitwise OR\n");

    int int7 = 0x01; //  00000000 00000000 00000000 00000001
    int int8 = 0x02; //  00000000 00000000 00000000 00000010
    printf("%d\n", int7 | int8);

    int int9 = 0x03; //  00000000 00000000 00000000 00000011
    printf("%d\n", int7 | int9);

    int int10 = 0x05; //  00000000 00000000 00000000 00000101
    printf("%d\n\n", int9 | int10);

    /* Bitwise XOR */
    printf("Bitwise XOR\n");

    int1 = 0x01; //  00000000 00000000 00000000 00000001
    int2 = 0x02; //  00000000 00000000 00000000 00000010
    printf("%d\n", int1 ^ int2); // outputs 00000000 00000000 00000000 00000011 (3)

    int3 = 0x03; //  00000000 00000000 00000000 00000011
    printf("%d\n", int1 ^ int3); // outputs 00000000 00000000 00000000 00000010 (2)

    int4 = 0x07; //00000000 00000000 00000000 00000111
    printf("%d\n", int1 ^ int4); // outputs 00000000 00000000 00000000 00000110 (6)
    
    /* Bitwise NOT */
    printf("Bitwise NOT\n");
    
    int1 = 0x01; // 00000000 00000000 00000000 00000001
    int2 = ~int1; // 11111111 11111111 11111111 11111110 (-2)
    printf("%d\n", int2); 
    
    //  11111111 11111111 11111111 11111110
    // -00000000 00000000 00000000 00000001
    // ------------------------------------
    // 11111111 11111111 11111111 11111101
    
    // complements of  11111111 11111111 11111111 11111101 is 00000000 00000000 00000000 00000010

    return 0;
}

/* Example 6 */
int get_value(void) {
    return 42;
}

/* Example 7 */
void mycaller(void (* f)(long), long param) {
    (*f)(param); /* call function *f with param */
}

void myproc(long d) {
    /* do something with d */
    printf("DOING STUFF WITH D: %ld\n", d);
}


