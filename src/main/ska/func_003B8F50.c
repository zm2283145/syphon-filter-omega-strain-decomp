#include "types.h"

typedef struct Elem20 {
    char data[20];
} Elem20;

typedef struct Array20 {
    int unk0;
    int count;
    Elem20* items;
} Array20;

extern void Array_CopyRange20(Array20* self, Elem20* first, Elem20* last, char alloc);

/* Copy constructor: clears the array, then inserts [src->items, src->items + count). */
Array20* func_003B8F50(Array20* self, Array20* src) {
    volatile char alloc[4];
    self->unk0 = 0;
    self->count = 0;
    self->items = 0;
    Array_CopyRange20(self, src->items, src->items + src->count, alloc[0]);
    return self;
}
