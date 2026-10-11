#include "types.h"

/* Destroy every 0x1D0-byte element from the back, then empty the array. */
typedef struct { unsigned char b[0x1D0]; } Elem_396B80;
typedef struct { int pad0; int count; Elem_396B80* data; } Arr_396B80;
extern void func_003BA9A0(Elem_396B80* e, int flag);

void func_00396B80(Arr_396B80* a)
{
    Elem_396B80* first = a->data;
    Elem_396B80* last = first + a->count;
    while (first < last) {
        last--;
        func_003BA9A0(last, -1);
    }
    a->count = 0;
}