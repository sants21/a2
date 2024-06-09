#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 150

int main() {
    int ch, i = 0;
    char str[MAX_LENGTH];
    int count_alphabetically[26] = {0};

    while (i < MAX_LENGTH - 1 && (ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            str[i] = tolower(ch);
            count_alphabetically[str[i] - 'a']++;
            i++;
        }
    }

    int max_count = 0;
    for (int j = 0; j < 26; j++) {
        if (count_alphabetically[j] > max_count) {
            max_count = count_alphabetically[j];
        }
    }

    for (int row = max_count; row > 0; row--) {
        for (int col = 0; col < 26; col++) {
            if (count_alphabetically[col] >= row) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int j = 0; j < 26; j++) {
        printf("%c", 'a' + j);
    }
    printf("\n");

    return 0;
}
