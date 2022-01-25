# include <stdio.h>

# include "dinamic.h"

int main() {
    createArrayType(int);

    arrayType(int) *array;
    NewArray(array, int);

    for (int i = 0; i < 20; i++)
    {
    
        insert(array, i, int);

        printf("Size: %lld, Length: %lld, Array: [", realSize(array), array->len);
        for (int i = 0; i < array->len; i++)
        {
            printf("%d", array->data[i]);
            if (i != array->len - 1)
                printf(", ");
        }
        printf("]\n");
    }
}