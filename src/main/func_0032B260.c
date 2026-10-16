#include "types.h"
#pragma opt_strength_reduction off
typedef struct { char p0[0x68]; int* vals; char p6C[0x74 - 0x6C]; int count; int* keys; } T32B260;
int GuiKeyboard_FindKey(T32B260* t, int key)
{
    int i; int* keys;
    i = 0;
    if (i < *(volatile int*)&t->count) {
        keys = t->keys;
        do {
            if (key == keys[i]) return t->vals[i];
            i++;
        } while (i < *(volatile int*)&t->count);
    }
    return 0;
}
