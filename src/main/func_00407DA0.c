#include "types.h"
typedef union { long long q[4]; char s[32]; __int128 v[2]; } H2Key;
typedef struct { char b[0x440]; } H2Pack;
typedef struct { H2Key* keys; H2Pack* packs; int count; } H2Registry;
extern void func_00407EC0(char* dst, int n, char* src);
/* Finds the registry packing whose key equals the upper-cased stem of name. */
H2Pack* func_00407DA0(H2Registry* reg, char* name) {
    int n;
    char* p;
    int i;
    H2Key key;
    if (name == 0)
        return 0;
    n = reg->count;
    func_00407EC0(p = key.s, 0x1f, name);
    while (*p != 0) {
        int c = *(volatile char*)p;
        if (c >= 'a' && c <= 'z')
            *p = c - 0x20;
        p++;
    }
    for (i = 0; i < n; i++) {
        if (reg->keys[i].q[0] == key.q[0] && reg->keys[i].q[1] == key.q[1] &&
            reg->keys[i].q[2] == key.q[2] && reg->keys[i].q[3] == key.q[3])
            return &reg->packs[i];
    }
    return 0;
}
