#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monster.h"
#include "node.h"
#include "linked_list.h"

void print_list(struct Node *current_node) {
    if (current_node == NULL) {
        printf("Nothing to print!\n\n");
        return;
    }

    while (current_node != NULL) {
        printf("Monster #%d %s at %s with %d victims.\n", current_node->data->id, current_node->data->name, current_node->data->location, current_node->data->number_of_victims);
        current_node = current_node->next;
    }

    printf("\n");
}

void insert_after(struct Node *current_node) {
    if (current_node == NULL) {
        printf("You can't insert a node with a NULL head!\n\n");
        return;
    }

    int id = 0;

    print_list(current_node);
    printf("Enter the id of the node that you want to insert after: ");
    scanf("%d", &id);

    while (current_node != NULL) {
        // Prevent from going NULL or if we find the monster
        if (current_node->data->id == id) {
            break;
        } else if (current_node->next == NULL) {
            printf("Monster of ID not found!\n\n");
            return;
        }
        current_node = current_node->next;
    }

    // allocate node struct in the heap
    struct Node* new_node = NULL;
    new_node = (struct Node*) malloc(sizeof (struct Node));

    // create a new monster struct
    struct monster* new_monster = NULL;

    // get user input
    new_monster = get_user_input();

    new_node->data = new_monster;

    // In A -> B -> C, if you want to insert D between B and C, then D -> C and B -> D
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void insert_before(struct Node *current_node) {
    if (current_node == NULL) {
        printf("You can't insert a node with a NULL head!\n\n");
        return;
    }

    int id = 0;

    print_list(current_node);
    printf("Enter the id of the node that you want to insert before: ");
    scanf("%d", &id);

    struct Node* before_node = NULL;

    while (current_node != NULL) {
        // Prevent from going NULL or if we find the monster
        if (current_node->data->id == id) {
            break;
        } else if (current_node->next == NULL) {
            printf("Monster of ID not found!\n\n");
            return;
        }
        before_node = current_node;
        current_node = current_node->next;
    }

    // allocate node struct in the heap
    struct Node* new_node = NULL;
    new_node = (struct Node*) malloc(sizeof (struct Node));

    // create a new monster struct
    struct monster* new_monster = NULL;

    // get user input
    new_monster = get_user_input();

    new_node->data = new_monster;

    // In A -> B -> C, if you want to insert D between B and C, then D -> C and B -> D
    before_node->next = new_node;
    new_node->next = current_node;
}

void search(struct Node *current_node) {
    if (current_node == NULL) {
        printf("You can't search with a NULL head!\n\n");
        return;
    }

    int id = 0;

    printf("Enter the id of the node that you want to search for: ");
    scanf("%d", &id);

    while (current_node != NULL) {
        // Prevent from going NULL or if we find the monster
        if (current_node->data->id == id) {
            break;
        } else if (current_node->next == NULL) {
            printf("Monster of ID not found!\n\n");
            return;
        }
        current_node = current_node->next;
    }

    printf("Monster #%d %s has been found!\n\n", current_node->data->id, current_node->data->name);
}

struct monster * get_user_input(void) {
    // allocate monster struct in the heap
    struct monster *new_monster = NULL;
    new_monster = (struct monster*) malloc(sizeof (struct monster));

    printf("Enter an id for new monster: ");
    scanf("%d", &new_monster->id);

    getchar();

    char *name;
    name = (char *) malloc(100);
    printf("Enter a name for new monster: ");
    fgets(name, 100, stdin);
    //name[strcspn (name, "\n")] = "\0";
    name[strlen(name) - 1] = "\0";
    strncpy(new_monster->name, name, 100);

    char *location;
    location = (char *) malloc(100);
    printf("Enter a location for new monster: ");
    fgets(location, 100, stdin);

    //location[strcspn (location, "\n")] = "\0";
    location[strlen(location) - 1] = "\0";
    strncpy(new_monster->location, location, 100);

    printf("Enter a number of victims for new monster: ");
    scanf("%d", &new_monster->number_of_victims);
    printf("\n");

    return new_monster;
}

void delete(struct Node *current_node) {
    if (current_node == NULL) {
        printf("You can't delete a node with a NULL head!\n\n");
        return;
    }

    int id = 0;

    print_list(current_node);
    printf("Enter the id of the node that you want to delete: ");
    scanf("%d", &id);

    struct Node* before_node = NULL;

    while (current_node != NULL) {
        // Prevent from going NULL or if we find the monster
        if (current_node->data->id == id) {
            break;
        } else if (current_node->next == NULL) {
            printf("Monster of ID not found!\n\n");
            return;
        }
        before_node = current_node;
        current_node = current_node->next;
    }

    // If you want to delete the head node
    if (before_node == NULL) {
        if (current_node->next == NULL) {
            printf("Cannot delete head node!\n\n");
            return;
        }
        else {
            (*current_node) = (*current_node->next);
        }
    }
    else {
        // In A -> B -> C, if you want to delete B, then A -> C
        before_node->next = current_node->next;
    }
}

void delete_end_of_list(struct Node *current_node) {
    if (current_node == NULL) {
        printf("You can't delete a node with a NULL head!\n\n");
        return;
    }
    
    struct Node *before_node = NULL;

    while (current_node != NULL) {
        // Prevent from going NULL (go to the last node of the end of the list)
        if (current_node->next == NULL) {
            break;
        }
        before_node = current_node;
        current_node = current_node->next;
    }

    // If you want to delete the head node
    if (before_node == NULL) {
        if (current_node->next == NULL) {
            printf("Cannot delete head node!\n\n");
            return;
        } 
        else {
            (*current_node) = (*current_node->next);
        }
    }
    else {
        before_node->next = NULL;
        (*current_node) = (*before_node);
    }
}

void delete_front_of_list(struct Node *current_node) {
    if (current_node == NULL) {
        printf("You can't insert a node with a NULL head!\n\n");
        return;
    }

    if (current_node->next == NULL) {
        printf("You can't delete the last node!\n\n");
        return;
    }
    else {
        (*current_node) = (*current_node->next);
    }
}

void insert_before_list(struct Node **current_node) {
    // allocate node struct in the heap
    struct Node* new_node = NULL;
    new_node = (struct Node*) malloc(sizeof (struct Node));

    // create a new monster struct
    struct monster *new_monster = NULL;

    // get user input
    new_monster = get_user_input();

    new_node->data = new_monster;

    // In A -> B -> C, if you want to insert D between B and C, then D -> C and B -> D
    new_node->next = (*current_node);
    (*current_node) = new_node;
}

void insert_after_list(struct Node *current_node) {
    if (current_node == NULL) {
        printf("You can't insert a node with a NULL head!\n\n");
        return;
    }

    while (current_node != NULL) {
        // Prevent from going NULL (found the end of list)
        if (current_node->next == NULL) {
            break;
        }
        current_node = current_node->next;
    }

    // allocate node struct in the heap
    struct Node* new_node = NULL;
    new_node = (struct Node*) malloc(sizeof (struct Node));

    // create a new monster struct
    struct monster* new_monster = NULL;

    // get user input
    new_monster = get_user_input();

    new_node->data = new_monster;

    // In A -> B -> C, if you want to insert D after C. Then A -> B -> C -> D -> NULL
    new_node->next = NULL;
    current_node->next = new_node;
}