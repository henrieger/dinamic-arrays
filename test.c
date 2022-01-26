# include <stdio.h>

# include "dynamic.h"

void printArray(arrayType(int) * array) {
    printf("Size: %lld, Length: %lld, Array: [", realSize(array), len(array));
    for (int i = 0; i < len(array); i++)
    {
        printf("%d", data(array)[i]);
        if (i != len(array) - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    arrayType(int) *array;
    NewArray(array, int);

    for (int i = 0; i < 20; i++)
    {
        insert(array, i, int);
        printArray(array);
    }

    int item;
    pop(&item, array, 6, int);
    printArray(array);

    insertIn(array, 78, 12, int);
    printArray(array);

    popIn(&item, array, 5, int);
    printArray(array);

    pop(&item, array, 78, int);
    printArray(array);
    printf("%d\n", item);

    while (len(array) > 0)
    {
        popIn(&item, array, 0, int);
        printArray(array);
    }

    insert(array, 1, int);
    insert(array, 1, int);
    insert(array, 1, int);
    printArray(array);

    pop(&item, array, 1, int);
    printArray(array);

    int one = 1;
    pop(&item, array, one, int);
    printArray(array);

    int zero = 0;
    popIn(&item, array, zero, int);
    printArray(array);
}