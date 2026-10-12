#include "types.h"
typedef struct { __int128 name; char pad[0x10]; } Ent6040;
typedef struct { char pad[0x50]; Ent6040 ent[1]; } Obj6040;
static inline int k6040eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline int k6040find(__int128* keys, int n, __int128 key) {
    int j;
    __int128* p;
    j = 0;
    if (j < n) {
        p = keys;
        do {
            if (k6040eq(key, *p))
                return j;
            j++;
            p++;
        } while (j < n);
    }
    return -1;
}
void func_00406040(Obj6040* o, int idx, __int128* keys, int n) {
    __int128 key;
    char* s;
    char* lo;
    char* hi;
    int k;
    key = o->ent[idx].name;
    if (k6040find(keys, n, key) != -1)
        return;
    s = (char*)&key;
    lo = s + 13;
    hi = s + 12;
    for (k = 0; k < 32; k++) {
        if (*lo == '-') {
            if (*hi == '9') {
                *hi = '1';
                *lo = '0';
            } else {
                (*hi)++;
            }
        } else if (*lo == '9') {
            (*hi)++;
            *lo = '0';
        } else {
            (*lo)++;
        }
        if (k6040find(keys, n, key) != -1) {
            o->ent[idx].name = key;
            return;
        }
    }
}



