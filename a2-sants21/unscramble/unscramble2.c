#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 500000
#define MAX_WORD 50

int compare_(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

int readdir(const char *filename, char *dict[], char *sorted_dic[]) {
    FILE *file = fopen(filename, "r");

    int i = 0;
    char words[MAX_WORD];
    while (fscanf(file, "%s", words) != EOF) {

        dict[i] = malloc(strlen(words) + 1);
        sorted_dic[i] = malloc(strlen(words) + 1);

        strcpy(dict[i], words);
        strcpy(sorted_dic[i], words);
        qsort(sorted_dic[i], strlen(sorted_dic[i]), sizeof(char), compare_);
        ++i;
    }
    fclose(file);
    return i;
}

void checker(char **dict, char **sorted_dict, char **jumbles, char **sorted_jumbles, int dict_size, int jumbles_size) {
    for (int i = 0; i < jumbles_size; i++) {
        int matches = 0;
        printf("%s:", jumbles[i]);

        for (int j = 0; j < dict_size; j++) {
            if (strcmp(sorted_jumbles[i], sorted_dict[j]) == 0) {
                printf(" %s", dict[j]);
                matches = 1;
            }
        }

        if (!matches) {
            printf(" NO MATCHES");
        }
        printf("\n");
    }
}
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("error");
    }
    char **dict = (char **) malloc(MAX_LENGTH * (sizeof(char *)));
    char **sorted_dict = (char **) malloc(MAX_LENGTH * (sizeof(char *)));
    char **jumbles = (char **) malloc(MAX_LENGTH * (sizeof(char *)));
    char **sorted_jumbles = (char **) malloc(MAX_LENGTH * (sizeof(char *)));
    int dict_size = readdir(argv[1], dict, sorted_dict);
    int jumbles_size = readdir(argv[2], jumbles, sorted_jumbles);

    checker(dict, sorted_dict, jumbles, sorted_jumbles, dict_size, jumbles_size);

    return 0;
}
