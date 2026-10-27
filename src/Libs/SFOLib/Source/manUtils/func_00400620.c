#include "types.h"
typedef struct { short a; short b; } KTex;
typedef struct {
    char pad0[0x20];
    __int128 m20;
    __int128 m30;
    __int128 m40;
    __int128 m50;
    __int128 m60;
    char pad70[0x20];
    __int128 m90;
    char padA0[0x10];
    __int128 mB0;
    char padC0[0xC];
    unsigned int count;
    char padD0[0x1410 - 0xD0];
    KTex tex[0x2A00];
    __int128 keys[0x600];
} KState;
typedef struct { __int128 a; __int128 key; } KOut;
typedef struct { char pad0[9]; signed char c9; } KB;
static inline __int128 kand(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 kor(__int128 a, __int128 b) {
    __int128 r;
    asm { por r, a, b }
    return r;
}
static inline __int128 knot(__int128 a) {
    __int128 r;
    asm { pnor r, a, a }
    return r;
}
static inline __int128 kxor(__int128 a, __int128 b) {
    __int128 r;
    asm { pxor r, a, b }
    return r;
}
static inline __int128 kfrom(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline __int128 kpair(__int128 hi, __int128 lo) {
    __int128 r;
    asm { pcpyld r, hi, lo }
    return r;
}
static inline int keq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 kmerge0(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pnor n, m, m
 pand c, cmp, m
 pand key, n, key
 por r, key, c }
    return r;
}
static inline __int128 kmerge(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pand c, cmp, m
 pnor n, m, m
 pand r, key, n
 por r, r, c }
    return r;
}
static inline int kmeq(__int128 m, __int128 a, __int128 b) {
    __int128 y;
    long long x;
    asm {
        pand y, m, b
        pand x, m, a
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
static inline int kmeq2(__int128 m, __int128 a, __int128 b) {
    __int128 y;
    long long x;
    asm {
        pand x, m, a
        pand y, m, b
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
static inline int flagok(__int128 k, int flag) {
    signed char* p = (signed char*)&k;
    int ok;
    if (flag == 0) ok = 1;
    else if (p[9] == '_') ok = 1;
    else if (p[9] == flag) ok = 1;
    else ok = 0;
    return ok;
}
void SwapDependencies__7MonsterFR3SKLR8ManParts11(KState* s, KOut* out, short* sh, __int128 key, __int128 k);
int FindNextAnyTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(KState* s, int step, __int128 key, __int128 cmp, unsigned int start, int idx, int mode, int flag, KOut* out, short* sh)
{
    __int128 m50;
    __int128 mask;
    __int128 K;
    __int128 v;
    m50 = s->m50;
    key = kmerge(key, cmp, s->m20);
    key = kmerge(key, cmp, s->m40);
    K = kfrom(0x5F00LL << 32);
    mask = kand(s->m90, key);
    start += step;
    if (((signed char*)&key)[4] == 'X')
        m50 = kxor(s->mB0, m50);
    if (mode == 1)
        v = kfrom(50);
    if (mode == 0)
        v = kfrom(49);
    for (; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask) && !kmeq(s->m30, s->keys[start], v)) {
            int ok;
            ok = flagok(s->keys[start], flag);
            if (ok) {
                out[idx + 2].key = s->keys[start];
                sh[idx + 0x200] = s->tex[start].a;
                sh[idx + 0x220] = s->tex[start].b;
                if (!kmeq2(s->m40, K, key))
                    SwapDependencies__7MonsterFR3SKLR8ManParts11(s, out, sh, key, s->keys[start]);
                return start;
            }
        }
    }
    start = 0;
    if (step == -1)
        start = s->count - 1;
    for (; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask) && !kmeq(s->m30, s->keys[start], v)) {
            int ok;
            ok = flagok(s->keys[start], flag);
            if (ok) {
                out[idx + 2].key = s->keys[start];
                sh[idx + 0x200] = s->tex[start].a;
                sh[idx + 0x220] = s->tex[start].b;
                if (!kmeq2(s->m40, K, key))
                    SwapDependencies__7MonsterFR3SKLR8ManParts11(s, out, sh, key, s->keys[start]);
                return start;
            }
        }
    }
    return -1;
}
