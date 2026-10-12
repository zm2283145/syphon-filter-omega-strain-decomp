#include "types.h"
typedef struct { __int128 name; char pad[0x10]; } Ent5F10;
typedef struct { char pad[0x50]; Ent5F10 ent[1]; } Obj5F10;
static inline int k5f10eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline int k5f10find(__int128* keys, int n, __int128 key) {
    int j;
    __int128* p;
    j = 0;
    if (j < n) {
        p = keys;
        do {
            if (k5f10eq(key, *p))
                return j;
            j++;
            p++;
        } while (j < n);
    }
    return -1;
}
void func_00405F10(Obj5F10* o, int idx, __int128* keys, int n) {
    __int128 key;
    char* s;
    char* lo;
    char* hi;
    int k;
    key = o->ent[idx].name;
    if (k5f10find(keys, n, key) != -1)
        return;
    s = (char*)&key;
    lo = s + 12;
    hi = s + 11;
    for (k = 0; k < 32; k++) {
        if (*lo == '9') {
            (*hi)++;
            *lo = '0';
        } else {
            (*lo)++;
        }
        if (k5f10find(keys, n, key) != -1) {
            o->ent[idx].name = key;
            return;
        }
    }
}


