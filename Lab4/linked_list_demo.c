#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monster.h"
#include "account.h"
#include "node.h"
#include "linked_list.h";

int printMenu(void) {
    int choice = 0;

    printf("Menu\n");
    printf("Monster Linked List\n");
    printf("1. Insert new monster node in front of monster list.\n");
    printf("2. Print all monster nodes.\n\n");

    printf("Int Linked List\n");
    printf("3. Insert new int in front of int list.\n");
    printf("4. Insert new int in the back of int list.\n");
    printf("5. Search int in int list.\n");
    printf("6. Delete front node in int list.\n");
    printf("7. Delete end node in int list.\n");
    printf("8. Print int list.\n\n");

    printf("Float Linked List\n");
    printf("9. Insert new float in front of float list.\n");
    printf("10. Insert new float in the back of float list.\n");
    printf("11. Search float in float list.\n");
    printf("12. Delete front node in float list.\n");
    printf("13. Delete end node in floatlist.\n");
    printf("14. Print float list.\n\n");


    printf("15. Exit the program.\n");
    printf("Enter an option number: ");
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

int main(int argc, char** argv) {
    struct Node *head_of_monsters = NULL;
    struct Node *head_of_ints = NULL;
    struct Node *head_of_floats = NULL;

    while (1) {
        int choice = printMenu();
        if (choice == 1) {
            insert_front_of_monster_list(&head_of_monsters);
        } else if (choice == 2) {
            printf("List of monsters: \n");
            print_list(head_of_monsters, print_monster);
            printf("\n\n");
        } 
        else if (choice == 3) {
            insert_front_of_int_list(&head_of_ints);
        }
        else if (choice == 4) {
            insert_end_of_int_list(head_of_ints);
        }
        else if (choice == 5) {
            search_int(head_of_ints);
        }
        else if (choice == 6) {
            delete_front_of_list(&head_of_ints);
        }
        else if (choice == 7) {
            delete_end_of_list(&head_of_ints);
        }
        else if (choice == 8) {
            printf("List of ints: \n");
            print_list(head_of_ints, print_int);
            printf("\n\n");
        }
        else if (choice == 9) {
            insert_front_of_float_list(&head_of_floats);
        }
        else if (choice == 10) {
            insert_end_of_float_list(head_of_floats);
        }
        else if (choice == 11) {
            search_float(head_of_floats);
        }
        else if (choice == 12) {
            delete_front_of_list(&head_of_floats);
        } 
        else if (choice == 13) {
            delete_end_of_list(head_of_floats);
        } 
        else if (choice == 14) {
            printf("List of floats: \n");
            print_list(head_of_floats, print_float);
            printf("\n\n");
        }
        else if (choice == 15) {
            break;
        }
    }

    printf("Program exited.");

    return (EXIT_SUCCESS);
}

