#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[10][10] = {
    "int", "float", "return", "if", "else", "while", "for", "char", "double", "void"
};

int isKeyword(char word[]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, word[20];
    int i = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Cannot open file\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        if (isalnum(ch)) {
            word[i++] = ch;
        } else {
            if (i != 0) {
                word[i] = '\0';
                i = 0;

                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
                printf("Operator: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
