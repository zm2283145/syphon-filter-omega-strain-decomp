#include "types.h"
typedef struct { int head; int bits[1]; } E7PS;
E7PS* PrioritySet_Copy(E7PS* dst, E7PS* src) {
    int i;
    dst->head = src->head;
    for (i = 0; i < 12; i++) {
        if ((*(int*)((char*)src + (i / 32) * 4 + 4) >> (i & 31)) & 1) {
            *(int*)((char*)dst + (i / 32) * 4 + 4) |= 1 << (i & 31);
        } else {
            *(int*)((char*)dst + (i / 32) * 4 + 4) &= ~(1 << (i & 31));
        }
    }
    return dst;
}