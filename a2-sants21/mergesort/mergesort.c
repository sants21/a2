/* Name: Chavinniruch Sethi
 * ID: 65681171
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR) {
        if ((L + i)->data < (R + j)->data) {
            (output + k)->data = (L + i)->data;
            (output + k)->name = (L + i)->name;
            i++;
        } else {
            (output + k)->data = (R + j)->data;
            (output + k)->name = (R + j)->name;
            j++;
        }
        k++;
    }
    while (i < nL) {
        (output + k)->data = (L + i)->data;
        (output + k)->name = (L + i)->name;
        i++;
        k++;
    }
    while (j < nR) {
        (output + k)->data = (R + j)->data;
        (output + k)->name = (R + j)->name;
        j++;
        k++;
    }
}

void merge_sort(Entry *entries, int n) {
    if (n > 1) {
        int nL = n / 2;
        int nR = n - nL;
        Entry *L = malloc(sizeof(Entry) * nL);
        Entry *R = malloc(sizeof(Entry) * nR);
        for (int i = 0; i < nL; i++) {
            (L + i)->data = (entries + i)->data;
            (L + i)->name = (entries + i)->name;
        }
        for (int i = 0; i < nR; i++) {
            (R + i)->data = (entries + nL + i)->data;
            (R + i)->name = (entries + nL + i)->name;
        }
        merge_sort(L, nL);
        merge_sort(R, nR);
        Entry *temp = malloc(sizeof(Entry) * n); 
        merge(temp, L, nL, R, nR);
        memcpy(entries, temp, n * sizeof(Entry));
        free(L);
        free(R);
        free(temp);
    }
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    int n;
    scanf("%d", &n);
    Entry *input = (Entry *)malloc(sizeof(Entry) * n);
    for (int i = 0; i < n; i++) {
        int d;
        char *s = (char *)malloc(sizeof(char) * MAX_NAME_LENGTH);
        scanf("%d %s", &d, s);
        (input + i)->data = d;
        (input + i)->name = s;
    }
    merge_sort(input, n);
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", (input + i)->data, (input + i)->name);
        free((input + i)->name);
    }
    free(input);
    return 0;
}
