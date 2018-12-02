#include <stdio.h>
#include <stdlib.h>

/* Includes functions used with strings */
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {
    /* Strings */

    /* Refer to string via pointer to first character */
    printf("Refer string via pointer\n");
    char *str = "my string";
    char *s = &str[0];
    char *s2 = str;
    printf("%s\n", s);
    printf("%s\n\n", s2);

    /* Get characters of a string using Array notation or pointer arithmetic */
    printf("Printing characters via array notation or pointer arithmetic \n");
    char *str2 = "Godzilla";
    printf("%c %c \n\n", *(str2 + 3), str2[3]);

    /* Print string differently */
    printf("Print string method #1 \n");
    char *str3 = "Godzilla";
    int i;
    for (i = 0; str3[i] != '\0'; i++) {
        printf("%c", str3[i]);
    }
    printf("\n\n");

    printf("Print string method #2 \n");
    char *str4;
    for (str4 = str3; *str4; str4++) {
        /* str3 refers to the address at the first character of the string
         * str4 condition tells you "as long as there is a character at *str4" 
         * str4++ increments 4 bytes?
         */
        printf("%c", *str4);
    }
    printf("\n\n");

    /* Reading string from input using Scanf */

    /* Scanf only read up to first white space */
    //    printf("Read string from input using Scanf\n");
    //    char str5[11];
    //    printf("Enter a string of up to ten characters: ");
    //    scanf("%10s", str5);
    //    printf("You entered %s\n\n", str5);
    //    
    /* Another way to read string from input */

    /*  char *fgets(char *str, int n, FILE *stream)
        -str is the destination array to store the string in
        -n is the length of the string to read (including the terminating nul, so that fgets will read n-1 characters)
        -stream is the file to read from.  We will cover file i/o later, but for now note that stdin, console input, counts as a file.
     * 
     * fgets can read string that contains white space
     */

    printf("Read string from input using fgets\n");
    char str6[11];
    printf("Enter a string of up to ten characters: ");
    fgets(str6, 11, stdin);
    printf("You entered %s\n\n", str6);

    /* Functions */
    printf("Various functions\n");
    char str7[12] = "Dishonored";
    char str8[12];

    printf("Length of '%s' is %d\n", str7, strlen(str7));
    printf("First occurence of 'i' in '%s' is %p\n", str7, *strchr(str7, 'i'));

    //    char *str9 = "b a c k";
    //    printf("First occurence of 'i' in '%s' is %s\n", str9, *strstr(str9, "c"));


    /* Copying strings */
    strncpy(str8, str7, 10);
    printf("Copied contents of %s (str7) to %s (str8) \n\n", str7, str8);


    /* Manipulate arrays */
    char str10[] = "Oh, d@mn! Here come 25 zombies!";
    for (int i = 0; i < strlen(str10); i++) {
        printf("%c is ", str10[i]);
        if (isalpha(str10[i])) {
            printf("alpha!\n");
        } else {
            printf("not alpha!\n");
        }
    }
    printf("\n");

    /* Incorrect String assignment
     * assigns an array of chars to a variable that is a pointer to a char
     */

    // char my_monster[100];
    // my_monster = "Godzilla";

    /* Most character count */
    printf("Most character count\n");
    char max_char, str11[100];
    int char_num, max_times, occurs[256] = {0}; // one per ascii character

    printf("Enter text: ");
    fgets(str11, 100, stdin);
    max_char = max_times = 0;

    for (int p = 0; str11[p] != '\0'; p++) {
        // Character at the index
        char_num = str11[p];

        // Increment the number of occurrences for that character
        occurs[char_num]++;

        /* Check if the number of occurrences of the character is bigger than the current max */
        if (occurs[char_num] > max_times) {
            max_times = occurs[char_num];
            max_char = char_num;
        }
    }

    printf("'%c' appears %d times\n\n", max_char, max_times);

    /* Formatted Strings */
    printf("Formatted Strings\n");

    int day, year;
    char weekday[20], month[20], dtm[100];

    strcpy(dtm, "Saturday March 25 1989");
    sscanf(dtm, "%s %s %d  %d", weekday, month, &day, &year);

    printf("%s %d, %d = %s\n\n", month, day, year, weekday);

    char buffer [50];
    int n, a = 5, b = 3;
    n = sprintf(buffer, "%d plus %d is %d", a, b, a + b);
    printf("[%s] is a string %d chars long\n\n", buffer, n);

    /* Array of strings */
    printf("Array of Strings (2-D Arrays)\n");
    char str12[3][40] = {"Apples", "Oranges", "Bananas"};
    printf("%s\n", str12[0]);
    printf("%c%c\n", str12[0][0], str12[0][1]);
    printf("%s\n", str12[1]);
    printf("%c%c\n", str12[1][0], str12[1][1]);
    printf("%s\n", str12[2]);
    printf("%c%c\n\n", str12[2][0], str12[2][1]);

    // Determines number of rows
    const int NUM_FOODS = 3;
    // Determine number of cols
    const int MAX_LENGTH = 30;

    // Each row for each string (each column for each character)
    char orders[NUM_FOODS][MAX_LENGTH];

    printf("Hi, my name is Hannibal.  I will be serving you this evening.\n");
    for (int i = 0; i < NUM_FOODS; i++) {
        printf("What would you like for course #%d? ", i);
        fgets(orders[i], MAX_LENGTH, stdin);
    }

    printf("You asked for: \n");
    for (int i = 0; i < NUM_FOODS; i++)
        printf("%s", orders[i]);


    return (EXIT_SUCCESS);
}

