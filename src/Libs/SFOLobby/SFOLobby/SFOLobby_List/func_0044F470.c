#include "types.h"
int SFOLobby_MemFree(int);
int SFOLobby_MemAlloc(int);
int memcpy(int, int, int);
int Libc_Memcmp(int, int, int);
void SFOLobbyList_DeleteSlot(void *, int);
extern int D_00585E58;

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
            if (Libc_Memcmp(p, elem, a->size) != 0) {
                a->dirty = 1;
            }
            memcpy(p, elem, a->size);
        }
    }
}

void SFOLobbyList_Append(Arr *a, int elem) {
    int i;
    int newcap;
    int p;

    if (a->data == 0) return;
    if (elem == 0) return;
    if (a->unique) {
        for (i = 0; i < a->count; i++) {
            p = Arr_At(a, i);
            if (p != 0 && Libc_Memcmp(p, elem, a->size) == 0) return;
        }
    }
    if (a->cap < a->count + 1) {
        if (a->grow <= 0) {
            SFOLobbyList_DeleteSlot(a, 0);
        } else {
            newcap = a->cap + a->grow;
            p = SFOLobby_MemAlloc(newcap * a->size);
            D_00585E58 += newcap * a->size;
            if (p == 0) return;
            memcpy(p, a->data, a->cap * a->size);
            SFOLobby_MemFree(a->data);
            D_00585E58 -= a->cap * a->size;
            a->cap = newcap;
            a->data = p;
        }
    }
    a->count++;
    Arr_Set(a, a->count - 1, elem);
    a->dirty = 1;
}

