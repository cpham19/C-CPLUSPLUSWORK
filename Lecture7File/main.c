#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monster.h"

int main(int argc, char **argv) {
    const int PATHSIZE = 200;
    char curr_path[PATHSIZE];
    FILE *f;
    struct monster *monsters = (struct monster *) malloc(3 * sizeof (struct monster));
    monsters[0].m_name = (char *) malloc(sizeof ("Godzilla") + 1); // m_name in the definition of the struct is a char pointer.  Still need to allocate space for the data
    strcpy(monsters[0].m_name, "Godzilla"); // copy the string literal "Godzilla" to the heap space
    monsters[0].height_in_cm = 5000;
    monsters[1].m_name = (char *) malloc(sizeof ("Bigfoot") + 1); // m_name in the definition of the struct is a char pointer.  Still need to allocate space for the data
    strcpy(monsters[1].m_name, "Bigfoot"); // copy the string literal "Godzilla" to the heap space
    monsters[1].height_in_cm = 300;
    monsters[2].m_name = (char *) malloc(sizeof ("Yeti") + 1); // m_name in the definition of the struct is a char pointer.  Still need to allocate space for the data
    strcpy(monsters[2].m_name, "Yeti"); // copy the string literal "Godzilla" to the heap space
    monsters[2].height_in_cm = 1000;

    puts("Please input a file path:");
    fgets(curr_path, PATHSIZE, stdin);
    curr_path[strcspn(curr_path, "\r\n")] = 0; // strip the \n from the end of curr_path as input

    f = fopen(curr_path, "w");
    for (int counter = 0; counter < 3; counter++)
        fprintf(f, "%s, %d\n", monsters[counter].m_name, monsters[counter].height_in_cm);
    fclose(f);
    return 0;
}

