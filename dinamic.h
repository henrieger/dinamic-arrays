# ifndef __DINAMIC_H__
# define __DINAMIC_H__

# include <stdlib.h>
# include <string.h>

// Return the dinamic array type for type_t 
# define arrayType(type_t) type_t##_array_t

// Create a dinamic array type for type_t type
# define createArrayType(type_t) typedef struct type_t##_array {int size; long long len; type_t *data;} type_t##_array_t

// Create new dinamic array struct
# define NewArray(a, type_t) ({ \
    a = (arrayType(type_t) *) malloc(sizeof(arrayType(type_t))); \
    a->len = 0; \
    a->size = 2; \
    a->data = malloc(4*sizeof(type_t)); \
})

// Return the real number of blocks allocated by the array
# define realSize(a) (1 << a->size)

// Insert element in array
# define insert(a, i, type_t) ({ \
    if ((realSize(a)) > (a->len)) \
    { \
        a->data[a->len] = i; \
        a->len++; \
    } \
    else \
    { \
        void *tmp; \
        tmp = malloc(2*((realSize(a)) * sizeof(type_t))); \
        memcpy(tmp, a->data, (realSize(a) * sizeof(type_t))); \
        a->data = tmp; \
        a->size++; \
        a->data[a->len] = i; \
        a->len++; \
    } \
})

# endif