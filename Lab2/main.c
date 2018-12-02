#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct monster {
    int id;
    char name[41];
    char location[41];
    int number_of_victims;
};

int main(int argc, char** argv) {
    int number_of_attacks = 0;

    printf("How many attacks?: ");
    scanf("%d", &number_of_attacks);

    // Pointer to current monster
    struct monster *current_monster;
    // Allocate memory space for array of monsters
    struct monster * monsters = (struct monster *) malloc(number_of_attacks * sizeof (struct monster));
    // Used to find the end of the array
    struct monster *last = monsters + (number_of_attacks - 1);

    for (int i = 0; i < number_of_attacks; i++) {
        current_monster = monsters + i;
        current_monster->id = i + 1;
        printf("Monster #%d\n", i + 1);
        printf("Please enter the monster's name: ");
        scanf("%s", &current_monster->name);
        printf("Please enter the location of attack: ");
        scanf("%s", &current_monster->location);
        printf("Please enter the number of victims: ");
        scanf("%d", &current_monster->number_of_victims);
        printf("\n");
    }
    
    // Return the pointer back to the begining of monsters array
    current_monster = monsters;
    
    int total_attacks = 0;

    // Pointer arithmetic loop
    do {
        total_attacks += current_monster->number_of_victims;
        printf("Monster #%d %s has attacked %d people at %s.\n", current_monster->id, current_monster->name, current_monster->number_of_victims, current_monster->location);
        current_monster++;
    } while (current_monster <= last);

    printf("The total amount of attacks is %d.\n", total_attacks);

    return (EXIT_SUCCESS);
}

