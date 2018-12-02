#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monster.h"
#include "account.h"
#include "node.h"
#include "linked_list.h"

void print_list(struct Node *current_node, void (*fptr)(void *)) {
    if (current_node == NULL) {
        printf("Nothing to print!\n");
        return;
    }

    while (current_node != NULL) {
        (*fptr)(current_node->data);
        current_node = current_node->next;
    }
}

void print_monster(void *data) {
    struct monster *monster = (struct monster *) data;

    printf("Node #%d\n", monster->id);
    printf("\n");
}

//  print an integer

void print_int(void *n) {
    printf("%d\n", *(int *) n);
}

// print a float 

void print_float(void *f) {
    printf("%.3f\n", *(float *) f);
}

int get_user_input_for_int(void) {
    int choice = 0;

    printf("Type your int number: ");
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

float get_user_input_for_float(void) {
    float choice = 0;

    printf("Type your float number: ");
    scanf("%f", &choice);
    printf("\n");

    return choice;
}

void search_int(struct Node *current_node) {
    if (current_node == NULL) {
        printf("You can't search with a NULL head!\n\n");
        return;
    }

    int val = 0;

    printf("Enter the int value of the node that you want to search for: ");
    scanf("%d", &val);

    while (current_node != NULL) {
        // Prevent from going NULL or if we find the monster
        if (*(int *) (current_node->data) == val) {
            break;
        } else if (current_node->next == NULL) {
            printf("Node containing '%d' not found!\n\n", val);
            return;
        }
        current_node = current_node->next;
    }

    printf("Node containing '%d' has been found!\n\n", *(int *) (current_node->data));
}

void search_float(struct Node *current_node) {
    if (current_node == NULL) {
        printf("You can't search with a NULL head!\n\n");
        return;
    }

    float val = 0.0;

    printf("Enter the float value of the node that you want to search for (3 decimal places, ex: 3.234): ");
    scanf("%f", &val);

    while (current_node != NULL) {
        // Prevent from going NULL or if we find the monster
        if (*(float *) (current_node->data) == val) {
            break;
        } else if (current_node->next == NULL) {
            printf("Node containing '%f' not found!\n\n", val);
            return;
        }
        current_node = current_node->next;
    }

    printf("Node containing '%f' has been found!\n\n", *(float *) (current_node->data));
}

void insert_front_of_monster_list(struct Node **head) {
    // allocate monster structs in the heap
    struct monster *new_monster = (struct monster*) malloc(sizeof (struct monster));

    // Initialize data to nodes
    new_monster->id = 1;
    strncpy(new_monster->name, "Bigfoot", 41);
    strncpy(new_monster->location, "Los Angeles", 41);
    new_monster->number_of_victims = 10;

    // allocate memory for node in the heap
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));
    new_node->data = malloc(sizeof (struct monster));
    // assign next node to head node
    new_node->next = (*head);

    *(struct monster *) (new_node-> data) = *(new_monster);

    // change pointer to new head node
    (*head) = new_node;
}

void insert_front_of_int_list(struct Node **head) {
    // allocate memory for node in the heap
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));

    // get user input for int
    int new_int = get_user_input_for_int();

    // void pointer for int
    void *pointer = &new_int;

    new_node->data = malloc(sizeof (int));

    for (int i = 0; i < sizeof (int); i++) {
        *(char *) (new_node-> data + i) = *(char *) (pointer + i);
    }

    new_node->next = (*head);

    (*head) = new_node;
}

void insert_end_of_int_list(struct Node *head) {
    if (head == NULL) {
        printf("There is no head node! You cannot add a node at the end.\n\n");
        return;
    }

    // allocate memory for node in the heap
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));

    // get user input for int
    int new_int = get_user_input_for_int();

    // void pointer for int
    void *pointer = &new_int;

    new_node->data = malloc(sizeof (int));

    // Copy contents of new_data to newly allocated memory. 
    // Assumption: char takes 1 byte. 
    for (int i = 0; i < sizeof (int); i++) {
        *(char *) (new_node-> data + i) = *(char *) (pointer + i);
    }

    while (head != NULL) {
        // Prevent from going NULL (found the end of list)
        if (head->next == NULL) {
            break;
        }
        head = head->next;
    }

    // In A -> B -> C, if you want to insert D after C. Then A -> B -> C -> D -> NULL
    new_node->next = NULL;
    head->next = new_node;
}

void insert_front_of_float_list(struct Node **head) {
    // allocate memory for node in the heap
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));

    // get user input for int
    float new_float = get_user_input_for_float();

    // void pointer for int
    void *pointer = &new_float;

    new_node->data = malloc(sizeof (float));

    for (int i = 0; i < sizeof (float); i++) {
        *(char *) (new_node-> data + i) = *(char *) (pointer + i);
    }

    new_node->next = (*head);

    (*head) = new_node;
}

void insert_end_of_float_list(struct Node *head) {
    if (head == NULL) {
        printf("There is no head node! You cannot add a node at the end.\n\n");
        return;
    }

    // allocate memory for node in the heap
    struct Node *new_node = (struct Node*) malloc(sizeof (struct Node));

    // get user input for float
    float new_float = get_user_input_for_float();

    // void pointer for float
    void *pointer = &new_float;

    new_node->data = malloc(sizeof (float));

    // Copy contents of new_data to newly allocated memory. 
    // Assumption: char takes 1 byte. 
    for (int i = 0; i < sizeof (float); i++) {
        *(char *) (new_node-> data + i) = *(char *) (pointer + i);
    }

    while (head != NULL) {
        // Prevent from going NULL (found the end of list)
        if (head->next == NULL) {
            break;
        }
        head = head->next;
    }

    // In A -> B -> C, if you want to insert D after C. Then A -> B -> C -> D -> NULL
    new_node->next = NULL;
    head->next = new_node;
}

void delete_front_of_list(struct Node **current_node) {
    if (current_node == NULL) {
        printf("Nothing to delete!\n\n");
        return;
    }

    // pointer to head node
    struct Node *temp_node = *current_node;

    // change head pointer to point to next element (new head) and free the old head
    if (temp_node != NULL) {
        *current_node = temp_node->next;
        free(temp_node);
        return;
    }
}

void delete_end_of_list(struct Node **current_node) {
    if ((*current_node) == NULL) {
        printf("Nothing to delete!\n\n");
        return;
    }
    
    while ((*current_node)->next != NULL) {
        current_node = &(*current_node)->next;
    }
    
    // free the allocated memory
    free(*current_node);
    // set the pointer that points the address containing the last node to NULL
    (*current_node) = NULL;
}