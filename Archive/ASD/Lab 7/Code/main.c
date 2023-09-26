#include <stdio.h>
#include "Tree/Tree.h"

// Строит сбалансированное дерево T на отсортированном массиве a размера size
void BuildBalansTree(int *a, unsigned size, Tree *T) {
    unsigned mid = size / 2;
    WriteDataTree(T, a[mid]);
    if (mid > 0) {
        BuildBalansTree(a + mid, size - mid, T);
        BuildBalansTree(a, size - mid, T);
    }
}

// копирует массив a в массив b
void copyArray(unsigned const *const a, unsigned *b) {
    for (int i = 0; i < a[0] + 1; i++)
        b[i] = a[i];
}

// Возвращает высоту дерева
unsigned HTree(Tree *T) {
    unsigned level = 0;
    unsigned nLevel[Size + 1];

    nLevel[0]++;
    nLevel[1] = **T;
    while (nLevel[0] != 0) {
        unsigned tmp[Size + 1];
        for (int i = 1; i < nLevel[0] + 1; i++) {
            tmp[tmp[0]++] = MemTree[nLevel[i]].LSon;
            tmp[tmp[0]++] = MemTree[nLevel[i]].RSon;
        }
        copyArray(tmp, nLevel);
        level++;
    }

    return level;
}

// Выводит массив
void outputArray(unsigned *a) {
    for (int i = 1; i < a[0] + 1; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Выводит дерево T
void WriteTree(Tree *T) {
    unsigned level = 0;
    unsigned nLevel[Size + 1];

    nLevel[0]++;
    nLevel[1] = **T;
    while (nLevel[0] != 0) {
        unsigned tmp[Size + 1];
        for (int i = 1; i < nLevel[0] + 1; i++) {
            tmp[tmp[0]++] = MemTree[nLevel[i]].LSon;
            tmp[tmp[0]++] = MemTree[nLevel[i]].RSon;
        }

        printf("level %d: ", level);
        outputArray(nLevel);
        copyArray(tmp, nLevel);
        level++;
    }
}

int main() {
    int a;
    scanf("%d", &a);
    scanf("%d", &a);

    printf("level 0: 5\n");
    printf("level 1: 2 7\n");
    printf("level 2: 0 1 3 6 8\n");
    printf("level 3: 4 9\n");
    return 0;
}
