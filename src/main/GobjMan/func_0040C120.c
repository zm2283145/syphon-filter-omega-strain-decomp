#include "types.h"
#pragma bool off
typedef struct { int** data; int size; } VC120;
extern int** func_0040C1E0(VC120* v);
static inline int c120ne(int* a, int* b) { return (a == b) ^ 1; }
/* Finds val in the pointer vector; stores the iterator (end if absent). */
void func_0040C120(int** out, VC120* v, int* val) {
    int* it = *func_0040C1E0(v);
    int* end = *func_0040C1E0(v) + v->size;
    while (c120ne(it, end)) {
        if (*it == *val) {
            *out = it;
            return;
        }
        it++;
    }
    *out = end;
}
#pragma bool reset