#include "types.h"
/* Monster_CountTexByName: counts the colour keys of the part cache usable for a key: same lod digit
 * ('1'/'2' by mode), same masked pattern (m50, or m50|m70 with flag 4), optionally the
 * matching tone digit (flag 1), the same or 'LA' pattern under m60 (flag 2) and, with
 * flag 8, not repeating the previous accepted key; stores the index of an exact match. */
typedef struct { short a; short b; } KTex;
typedef struct {
    __int128 m00;
    char pad10[0x10];
    __int128 m20;
    __int128 m30;
    __int128 m40;
    __int128 m50;
    __int128 m60;
    __int128 m70;
    char pad80[0x10];
    __int128 m90;
    char padA0[0x10];
    __int128 mB0;
    char padC0[0xC];
    unsigned int count;
    char padD0[0xE4 - 0xD0];
    unsigned int nE4;
    void* pE8;
    char padEC[0x1410 - 0xEC];
    KTex tex[0x2A00];
    __int128 keys[0x600];
} KState;
/* 128-bit key masking/compare: MMI pand/por/pceqw/ppach/pcpyld have no C equivalent */
static inline __int128 kor(__int128 a, __int128 b) {
    __int128 r;
    asm { por r, a, b }
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
static inline int kmeqB(__int128 b, __int128 a, __int128 m) {
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
static inline int kmeqD(__int128 a, __int128 b, __int128 m) {
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
int Monster_CountTexByName(KState* s, __int128 key, int* found, int mode, int flag, unsigned int flags)
{
    int cnt;
    __int128 K2;
    __int128 v;
    __int128 m50;
    __int128 prev;
    unsigned int i;
    cnt = 0;
    prev = key;
    m50 = s->m50;
    K2 = kpair(0x4C, 0x4C410000LL << 32);
    if (flags & 4)
        m50 = kor(s->m70, m50);
    if (mode == 1)
        v = kfrom(50);
    if (mode == 0)
        v = kfrom(49);
    for (i = 0; i < s->count; i++) {
        if (kmeqB(v, s->keys[i], s->m30))
            continue;
        if (!kmeq(m50, s->keys[i], key))
            continue;
        if ((flags & 1) && !flagok(s->keys[i], flag))
            continue;
        if ((flags & 2) && !kmeqB(key, s->keys[i], s->m60) && !kmeqD(s->keys[i], K2, s->m60))
            continue;
        if ((flags & 8) && cnt != 0 && kmeqB(prev, s->keys[i], s->m60))
            continue;
        prev = s->keys[i];
        if (keq(key, prev))
            *found = cnt;
        cnt++;
    }
    return cnt;
}
