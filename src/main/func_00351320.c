#pragma cplusplus on

#include "types.h"

/* Destroy all elements (0x5C bytes each, last first) and clear the count. */
struct E351320 { int words[0x5C / 4]; };
struct V351320 { int capacity; unsigned int count; E351320* data; };
extern "C" {
void* func_0034F720(void* self, short deleteFlag);
void func_00351320(V351320* v);
}
void func_00351320(V351320* v)
{
    E351320* first = v->data;
    E351320* last = first + v->count;
    while (first < last) {
        --last;
        func_0034F720(last, -1);
    }
    v->count = 0;
}