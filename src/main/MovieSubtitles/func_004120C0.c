#include "types.h"
#pragma optimization_level 1

typedef struct Cursor {
    char pad[0x64];
    int count;
    int current;
} Cursor;

/* Advances current while below count. */
void func_004120C0(Cursor* c) {
    if (c->current < c->count) c->current++;
}
