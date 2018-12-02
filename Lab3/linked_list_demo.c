#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monster.h"
#include "node.h"
#include "linked_list.h";

int printMenu(void) {
    int choice = 0;

    printf("Menu\n");
    printf("1. Insert a monster node after monster of specified ID.\n");
    printf("2. Insert a monster node before monster of specified ID.\n");
    printf("3. Delete a monster node based on specified ID.\n");
    printf("4. Print all monster nodes.\n");
    printf("5. Search a monster node based on specified ID.\n");
    printf("6. Insert a monster node before list.\n");
    printf("7. Insert a monster node after list.\n");
    printf("8. Delete node front of list.\n");
    printf("9. Delete node end of list.\n");
    printf("10. Exit the program.\n");
    printf("Enter an option number: ");
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

int main(int argc, char** argv) {
    struct Node *head = NULL;

    while (1) {
        int choice = printMenu();
        if (choice == 1) {
            insert_after(head);
        }
        else if (choice == 2) {
            insert_before(head);
        }
        else if (choice == 3) {
            delete(head);
        }
        else if (choice == 4) {
            print_list(head);
        }
        else if (choice == 5) {
            search(head);
        }
        else if (choice == 6) {
            insert_before_list(&head);
        } 
        else if (choice == 7) {
            insert_after_list(head);
        } 
        else if (choice == 8) {
            delete_front_of_list(head);
        } 
        else if (choice == 9) {
            delete_end_of_list(head);
        }
        else if (choice == 10) {
            break;
        }
    }

    printf("Program exited.");

    return (EXIT_SUCCESS);
}

