#include "types.h"
typedef struct { char d[0x124]; } RB000;
typedef struct { int m0; unsigned int size; RB000* data; } VB000;
extern void func_00408930(RB000* r, short del);
/* Destroys every record and sets the size to zero. */
void func_0040B000(VB000* v) {
    RB000* b = v->data;
    RB000* e = b + v->size;
    while (b < e) {
        --e;
        func_00408930(e, -1);
    }
    v->size = 0;
}