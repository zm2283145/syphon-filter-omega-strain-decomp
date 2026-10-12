#include "types.h"
typedef union { __int128 q; char s[16]; } Key5E10;
typedef struct { int pad; int count; char** names; } List5E10;
extern __int128 D_005716E0;
extern char* strchr(const char*, int);
extern void Appearance_RegistryKey(char* dst, int n, char* src);
static inline int k5e10eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline void k5e10clear(__int128* keys, int n, __int128 key) {
    int j;
    __int128* p;
    j = 0;
    if (j < n) {
        p = keys;
        do {
            if (k5e10eq(key, *p)) {
                keys[j] = D_005716E0;
                return;
            }
            j++;
            p++;
        } while (j < n);
    }
}
#pragma push
#pragma opt_strength_reduction off
void func_00405E10(void* self, List5E10* list, __int128* keys, int n) {
    int i;
    int total = list->count;
    for (i = 0; i < total; i++) {
        if (strchr(list->names[i], '.') == 0) {
            Key5E10 key;
            Appearance_RegistryKey(key.s, 15, list->names[i]);
            k5e10clear(keys, n, key.q);
        }
    }
}
#pragma pop


