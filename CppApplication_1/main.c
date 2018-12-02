// Header files
#include <stdio.h>
#include <stdbool.h>

/* include "filename.h" is relative to current directory
   include <filename.h> is relative to /usr/include
 */

#define MAXVALUE 100
#define check(x) ((x) < MAXVALUE)

/* argc is argument count
 * argv is argument vector
 * int is return value (0 is success, >0 is some error)
 * return type can also be void (no return value needed)
 */
int main(int argc, char* argv[]) {
    printf("Hello, World!\n\n");

    /* prints 3.146
     *  4 digits in total, 3 digits after decimal point
     */
    float PI = 3.1459;
    printf("%4.3f\n\n", PI);

    printf("Hello World. \n \t and you !\n too!\n\n");

    /* If statement */
    int number = 5;
    if (check(number)) {
        printf("Number is less than 100\n\n");
    } else {
        printf("Number is not less than 100\n\n");
    }

    /* Printing/Scanning user input */
    int nstudents = 0;
    printf("How many students are at CSULA?:"); /* print prompt */
    scanf("%d", &nstudents); /* read user input */
    printf("CSULA has %d students.\n\n", nstudents); /* print user input */


    /* Initializing Variables and Converting types */
    int i, j = 12; /* i not initialized, only j */
    float f1, f2 = 1.2; /* f1 not initialized, only f2 */
    printf("%d %d %f %f\n", i, j, f1, f2);

    i = (int) f2; /* explicit: i <- 1, 0.2 lost */
    f1 = i; /* implicit: f1 <- 1.0 */
    printf("%d %d %f %f\n", i, j, f1, f2);


    f1 = f2 + (int) j; /* explicit: f1 <- 1.2 + 12.0 */
    f1 = f2 + j; /* implicit: f1 <- 1.2 + 12.0 */
    printf("%d %d %f %f\n\n", i, j, f1, f2);

    /* More type conversion*/
    /* Cast to short preserves the lower 16 bits, which are 1000011010100000, 
     * as a twos complement representation.  Decimal value of twos complement value 1000011010100000 is -31072  
     */
    int x = 100000;
    short s;
    s = x;
    printf("%d %d\n\n", x, s);
    
    /* Boolean */
    bool a = true;
    printf("%s\n\n", a? "true":"false");

    /* User defined types*/
    typedef short int integer_number;
    typedef char String[100];
    
    integer_number k = 5;
    String name = "Calvin";
    
    printf("int number: %d\nstring: %s\n\n", k, name);
    
    /* Constants*/
    const float NUM = 3.0;
    /* NUM = 5; is syntax error */
    
    /* Enumerated types */
    typedef enum {
        Red, Orange, Yellow
    } Color;
     
    /*Similar to *define Red 0, #define Orange 1, #define Yellow 2 */
    
    enum monster {ZOMBIE, VAMPIRE, YETI};
    enum monster current_monster = ZOMBIE;
    
    /* Prints int. ZOMBIE is 0, VAMPIRE IS 1, YETI IS 2 */
    printf("%d\n\n", current_monster);
    
    if (current_monster == ZOMBIE) {
        printf("ZOMBIE ATTACK. SOMEONE CALL LEON!\n\n");
    }
    else if (current_monster == VAMPIRE) {
        printf("WATCH OUT FOR YOUR BLOOD!\n\n");
    }
    else if (current_monster == YETI) {
        printf("WATCH OUT YETI AVALANCHE!\n\n");
    }
    
    /* Switch statements */
    typedef enum {APPLE, ORANGE, BANANA} Fruit;
    Fruit f = APPLE;
    
    switch(f) {
        case APPLE:
            printf("GET YOUR APPLES!\n\n");
            break;
        case ORANGE:
            printf("GET YOUR ORANGES!\n\n");
            break;
        case BANANA:
            printf("GET YOUR BANANAS!\n\n");
            break;
    }
    
    return 0;
    /* exit(0) */
}

