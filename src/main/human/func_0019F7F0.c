#include "types.h"
typedef struct { int head; int bits[2]; int c; int d; } E7PS2;
E7PS2* func_0019F7F0(E7PS2* dst, E7PS2* src) {
    int i;
    dst->head = src->head;
    for (i = 0; i < sizeof(int) * 8; i++) {
        if ((*(int*)((char*)src + (i / 32) * 4 + 4) >> (i & 31)) & 1) {
            *(int*)((char*)dst + (i / 32) * 4 + 4) |= 1 << (i & 31);
        } else {
            *(int*)((char*)dst + (i / 32) * 4 + 4) &= ~(1 << (i & 31));
        }
    }
    dst->c = src->c;
    dst->d = src->d;
    return dst;
}