#pragma opt_common_subs off
#include "types.h"
typedef struct {
    int cap;
    int count;
    int f8;
    int grow;
    int size;
    int data;
    signed char dirty;
    char pad19;
    unsigned char unique;
} Arr;
void SFOLobbyList_Append(Arr *a, int elem);
static inline int Arr_At(Arr *a, int i) {
    int d = a->data;
    if (d == 0) return 0;
    if (i < 0 || i >= a->count) return 0;
    return d + i * a->size;
}
void SFOLobbyList_CopyListFrom(Arr *dst, Arr *src) {
    int i;
    if (dst == 0 || src == 0) return;
    if (dst->size != src->size) return;
    if (dst->data != 0) {
        if (dst->count != 0) dst->dirty = 1;
        dst->count = 0;
    }
    for (i = 0; i < src->count; i++) {
        SFOLobbyList_Append(dst, Arr_At(src, i));
    }
}


