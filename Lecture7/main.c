/* Dynamic Memory Allocation Structs and File I/O */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Example 1 */
int * getX() {
    int x = 42;
    return &x;
}

/* Example 1*/
int * getX2() {
    int *x = (int *) malloc(sizeof (int));
    *x = 42;
    return x;
}

/* Example 1 */
void do_nothing() { // make it more likely the error will be replicated
    for (int i = 0; i <= 10000; i++) {
    }
}

/* Example 2 */
struct complex {
    double real;
    double imag;
};

/* Example 2 */
typedef struct {
    double real;
    double imag;
} Complex;

/* Example 2 */
struct person {
    char name[41];
    int age;
    float height;

    struct { /* embedded struct */
        int month;
        int day;
        int year;
    } birth;
};

/* Example 2 */
struct student {
    int id;
    char name[41];
    int age;
    double balance_owed;
};

/* Example 3 */
void change_struct(struct student *s) {
    s->id = 100;
    s->age = 75;
    s->balance_owed = 0;
}

/* Example 4 */
struct student2 {
    int id;
    char name[41];
    int age;
    float balance_owed;
};

/* Example 4 */
struct student2 * get_student(void) {
    struct student2 *sp = (struct student2 *) malloc(sizeof (struct student2));
    puts("Please enter the student's id: ");
    scanf("%d", &sp->id);
    puts("Please enter the student's age: ");
    scanf("%d", &sp->age);
    puts("Please enter the student's balance: ");
    scanf("%f", &sp->balance_owed);
    return sp;
}

/* Example 5 */
double get_total(struct student *s, int length) {
    float total = 0;
    for (int i = 0; i < length; i++) {
        total += s[i].balance_owed;
    }
    return total;
}

/* Example 7 */
// Value declares all occupy same memory space
// union can hold different types at different times

union Data {
    int i;
    float f;
    char str[20];
};

/* Example 8 */
struct Node {
    int data;
    struct Node *next;
};

/* Example 8 */
void printList(struct Node *n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

int main(int argc, char** argv) {
    /* Data object creation */

    // double my_array[10000000]; Stack space is limited. This crashed on 32gb ram linux system
    double *arrayA = (double *) malloc(10000000 * sizeof (double)); // This works

    /* Segmentation Fault */
    printf("Ex 1: Segmentation Fault\n");
    // compiler warning: function returns address of local variable
    // runtime: (usually) segmentation fault.  This happens because x exists in the stack frame for getX, which can't be used after the method returns.
    // int *x = getX();
    //do_nothing();

    int *x = getX2();
    printf("%d\n\n", *x);


    /* Structs */
    printf("Ex 2: Structs\n");
    struct complex a, b;
    Complex c, d;

    const int num_students = 3;

    srand(time(NULL)); // initialize random number generator
    struct student *curr_student;

    // Here is the key line!  It allocates heap space for the array and creates a student pointer to the beginning of the heap space 
    struct student *students = (struct student *) malloc(num_students * sizeof (struct student));
    struct student *last = students + (num_students - 1); // used to find the end of the array in the do loop below	
    float total_balance = 0;

    char names[3][41] = {"Calvin", "Paul", "Leonard"};

    for (int i = 0; i < num_students; i++) { // need the loop counter for this one
        curr_student = students + i;
        strncpy(curr_student->name, names[i], 41);
        curr_student->id = i + 1;
        curr_student->age = (double) rand() / RAND_MAX * 25 + 15;
        curr_student->balance_owed = (double) rand() / RAND_MAX * 10000;
    }

    curr_student = students; // make curr_student point to the beginning of the array

    do { // no need for loop counter, so use simpler do...while
        total_balance += curr_student->balance_owed;
        printf("Student %d %s is %d years old and owes $%8.2f\n", curr_student -> id, curr_student -> name, curr_student->age, curr_student->balance_owed);
        curr_student++;
    } while (curr_student <= last);

    printf("Total owed = $%.2f\n\n", total_balance);

    /* Pointer to Struct */
    printf("Ex 3: Pointer to Struct\n");
    struct student *curr_student2;

    // Here is the key line!  It allocates heap space for the array and creates a student pointer to the beginning of the heap space 
    struct student *students2 = (struct student *) malloc(num_students * sizeof (struct student));
    struct student *last2 = students2 + (num_students - 1); // used to find the end of the array in the do loop below	
    float total_balance2 = 0;

    for (int i = 0; i < num_students; i++) { // need the loop counter for this one
        curr_student2 = students2 + i;
        curr_student2->id = i + 1;
        strncpy(curr_student2->name, names[i], 41);
        curr_student2->age = (double) rand() / RAND_MAX * 25 + 15;
        curr_student2->balance_owed = (double) rand() / RAND_MAX * 10000;
    }

    // Change the pointer to the 2nd student in the array
    curr_student2 = students2 + 1;
    // Change the object attributes
    change_struct(curr_student2);
    // Change the pointer back to the 1st student in the array
    curr_student2 = students2;

    do {
        total_balance2 += curr_student2->balance_owed;
        printf("Student %d %s is %d years old and owes $%8.2f\n", curr_student2 -> id, curr_student2 -> name, curr_student2->age, curr_student2->balance_owed);
        curr_student2++;
    } while (curr_student2 <= last2);
    printf("Total owed = $%.2f\n\n", total_balance2);


    /* Returning pointer to a struc */
    printf("Ex 4: Returning a pointer to a struc\n");
    struct student2 *sp = get_student();
    printf("id: %d age: %d amount owed: %.2f\n\n", sp->id, sp->age, sp-> balance_owed);

    /* Pointer to array of struct as parameter */
    printf("Ex 5: Pointer to array of struct as parameter\n");
    double total_balance3 = get_total(students, num_students);
    double total_balance4 = get_total(students2, num_students);
    printf("Total owed for Students array = $%.2f\n", total_balance3);
    printf("Total owed for Students2 array = $%.2f\n\n", total_balance4);

    /* Free() */
    printf("Ex 6: Using free()\n");
    double *arrayB = (double *) malloc(100000 * sizeof (double));
    printf("%s\n\n", arrayB == NULL ? "failed" : "succeeded");
    free(arrayB);

    /* Unions */
    printf("Ex 7: Unions\n");
    union Data data;
    data.i = 10;
    data.f = 220.50;
    strncpy(data.str, "C Programming", 20);
    printf("data.i : %d\n", data.i);
    printf("data.f : %.2f\n", data.f);
    printf("data.str : %s\n\n", data.str);

    /* Single linked list*/
    printf("Ex 8: Singly Linked List\n");
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // allocate 3 nodes in the heap   
    head = (struct Node*) malloc(sizeof (struct Node));
    second = (struct Node*) malloc(sizeof (struct Node));
    third = (struct Node*) malloc(sizeof (struct Node));

    // Initialize data to nodes
    head->data = 1;
    second->data = 2;
    third->data = 3;

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    printList(head);
    printf("\n");
    printf("Inserting 5 between 2 and 3\n");

    struct Node* fifth = NULL;
    fifth = (struct Node*) malloc(sizeof (struct Node));
    fifth->data = 5;
    fifth->next = third;
    second->next = fifth;
    printList(head);
    printf("\n\n");

    return (EXIT_SUCCESS);
}

