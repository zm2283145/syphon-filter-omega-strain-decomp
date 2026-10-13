#include "types.h"
int memcpy(int, int, int);
int Name_Compare48(int, int, int);

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

static inline int Arr_At(Arr *a, int i) {
    if (a->data == 0) return 0;
    if (i < 0 || i >= a->count) return 0;
    return a->data + i * a->size;
}

static inline void Arr_Set(Arr *a, int i, int elem) {
    int p;
    if (elem != 0) {
        p = Arr_At(a, i);
        if (p != 0) {
            if (Name_Compare48(p, elem, a->size) != 0) {
                a->dirty = 1;
            }
            memcpy(p, elem, a->size);
        }
    }
}

void LobbyArray_RemoveAt(Arr *a, int idx) {
    int i;
    if (Arr_At(a, idx) != 0) {
        for (i = idx; i < a->count - 1; i++) {
            Arr_Set(a, i, Arr_At(a, i + 1));
        }
        a->count--;
    }
}
