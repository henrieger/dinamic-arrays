# ifndef __DYNAMIC_H__
# define __DYNAMIC_H__

# include <stdio.h>
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

// Return the length of the array
# define len(a) (a->len)

// Return the array itself
# define data(a) (a->data)

// Insert element in end of array
# define insert(a, i, type_t) ({ \
    if ((realSize(a)) <= (a->len)) \
    { \
        void *tmp; \
        tmp = malloc(((realSize(a)) * sizeof(type_t)) << 1); \
        memcpy(tmp, a->data, (realSize(a) * sizeof(type_t))); \
        free(a->data); \
        a->data = tmp; \
        a->size++; \
    } \
    a->data[a->len] = i; \
    a->len++; \
})

// Insert element in specific index of array
# define insertIn(a, i, pos, type_t) ({ \
    if ((pos) > (a->len) || ((pos) < 0)) \
    { \
        fprintf(stderr, "Error: Index %d is out of bounds.\n", (pos)); \
        exit(1); \
    } \
\
    if ((realSize(a)) <= (a->len)) \
    { \
        void *tmp; \
        tmp = malloc(((realSize(a)) * sizeof(type_t)) << 1); \
        memcpy(tmp, a->data, (realSize(a) * sizeof(type_t))); \
        free(a->data); \
        a->data = tmp; \
        a->size++; \
    } \
    memcpy(a->data+pos+1, a->data+pos, ((a->len)-(pos)-1) * sizeof(type_t)); \
    a->data[pos] = i; \
    a->len++; \
})

// Return element in 'dest' and delete it from the array
# define pop(dest, a, i, type_t) ({ \
    for (int indexOfPop = 0; indexOfPop < a->len; indexOfPop++) { \
        if ((a->data[indexOfPop]) == i) \
        { \
            if ((dest) != NULL) \
                *dest = a->data[indexOfPop]; \
            memcpy(a->data+indexOfPop, a->data+indexOfPop+1, ((a->len) - (indexOfPop) - 1) * sizeof(type_t)); \
            a->len--; \
            break; \
        } \
    } \
\
    if ((realSize(a) >> 1) > (a->len)) \
    { \
        void *tmp; \
        tmp = malloc(((realSize(a)) * sizeof(type_t)) >> 1); \
        memcpy(tmp, a->data, (len(a) * sizeof(type_t))); \
        free(a->data); \
        a->data = tmp; \
        a->size--; \
    } \
})

// Return element in 'dest' and delete it from the array
# define popIn(dest, a, pos, type_t) ({ \
    if ((pos) > (a->len) || ((pos) < 0)) \
    { \
        fprintf(stderr, "Error: Index %d is out of bounds.\n", (pos)); \
        exit(1); \
    } \
\
    if ((dest) != NULL) \
        *dest = a->data[pos]; \
    memcpy(a->data+pos, a->data+pos+1, ((a->len) - (pos) - 1) * sizeof(type_t)); \
    a->len--; \
\
    if ((realSize(a) >> 1) > (a->len)) \
    { \
        void *tmp; \
        tmp = malloc(((realSize(a)) * sizeof(type_t)) >> 1); \
        memcpy(tmp, a->data, (len(a) * sizeof(type_t))); \
        free(a->data); \
        a->data = tmp; \
        a->size--; \
    } \
})

createArrayType(int);
createArrayType(char);
createArrayType(float);
createArrayType(long);
createArrayType(double);

# endif