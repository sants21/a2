/* Name: Chavinniruch Sethi     
 * ID: 6581171
 */
#include <stdio.h>
#include <stdlib.h>
#include "box.h"

void createBox(Box **b, int init_cap) {
    if (*b == NULL){
        *b = malloc(sizeof(Box));
        (*b)->data = (int *)malloc(sizeof(int) * (init_cap));
        (*b)->size = 0;
        (*b)->cap = init_cap;
    }
        
}

void insert(Box *b, int elem) {
    if (b->size == b->cap){
        b->cap = b->cap * 2;
        b -> data = realloc(b->data, sizeof(int)*b->cap);
    }
    b->data[b->size] = elem;
    b->size++;   


    
}

void removeAll(Box *b, int elem) {
    int * temp = (int *)malloc(sizeof(int)*(b->size));
    int count = 0;
    for (int i = 0; i < b->size; i++){
        if (b->data[i] != elem){
            temp[count ++] = b->data[i];
        }
    }
    free(b->data);
    b->data = temp;
    b->size = count;
}


void printBox(Box *b) {
    for (int i = 0; i < b->size; i++){
        printf("%d\n", *(b->data+i));
    }
}

double getMean(Box *b) {
    double total = 0;
    for (int i = 0; i < b->size; i++) {
        total += b->data[i];
    }
    return total / b->size;
}

void dealloc(Box **b) {
    free((*b) -> data);
    free(*b);
}

/*
TEST: ./box < test.in
OUTPUT:
AVG = 4.00
box1 size = 10
box2 size = 1
box1 cap = 16
box2 cap = 2
-- b1
11
2
3
4
5
2
3
2
2
6
-- b2
2
--
-- b1 (after remove)
11
3
4
5
3
6
--
-- b2 (after remove)
--
*/
int main(int argc, char **argv)
{
    Box *b1 = NULL;
    Box *b2 = NULL;

    createBox(&b1, 1);
    createBox(&b2, 2);

    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int tmp;
        scanf("%d",&tmp);
        insert(b1, tmp);
    }
    insert(b2, 2);

    printf("AVG = %0.2f\n",getMean(b1));
    printf("box1 size = %d\n",b1->size);
    printf("box2 size = %d\n",b2->size);
    printf("box1 cap = %d\n",b1->cap);
    printf("box2 cap = %d\n",b2->cap);

    printf("-- b1\n");
    printBox(b1);
    printf("-- b2\n");
    printBox(b2);
    printf("--\n");

    removeAll(b1, 2);
    printf("-- b1 (after remove)\n");
    printBox(b1);
    printf("--\n");
    removeAll(b2, 2);
    printf("-- b2 (after remove)\n");
    printBox(b2);
    printf("--\n");

    dealloc(&b1);
    dealloc(&b2);
}
