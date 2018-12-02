#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;
};

struct paragraph {
    struct sentence* data;
    int sentence_count;
};

struct document {
    struct paragraph* data;
    int paragraph_count;
};

void printStuff(char *text) {
    struct sentence sentenceObj;
    int wordCount = 0;
    int startOfWord = 0;

    char chars[1000];

    char arrayOfWords[30][100];

    int row = 0;
    int col = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '.') {
            wordCount++;
            arrayOfWords[row][col] = '\0';
            row++;
            col = 0;
        }
        else {
            arrayOfWords[row][col] = text[i];
            col++;
        }
    }

    for (int i = 0; i < 30; i++) {
        struct word wordObj;
        wordObj.data = arrayOfWords[i];

        sentenceObj.data[i] = wordObj;
    }

    printf("%s\n", sentenceObj.data[0]);
}

int main(int argc, char** argv) {
    printStuff("Learning C is fun. asdasda");

    return (EXIT_SUCCESS);
}

