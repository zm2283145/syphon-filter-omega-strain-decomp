#include "types.h"
typedef struct { short a, b; } KP4022E0;
typedef struct { char pad0[0x10]; __int128 val; } KO4022E0;
typedef struct {
    __int128 m0;
    char pad10[0x10];
    __int128 m20;
    __int128 m30;
    char pad40[0x10];
    __int128 m50;
    char pad60[0x30];
    __int128 m90;
    char padA0[0x10];
    __int128 mB0;
    char padC0[0xC];
    unsigned int count;
    char padD0[0x1410 - 0xD0];
    KP4022E0 pairs[(0xBC10 - 0x1410) / 4];
    __int128 keys[1];
} KS4022E0;
extern char D_004BE760[];
extern int String_CompareN(char*, char*, int);
static inline int ks4022E0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 ks4022E0and(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 ks4022E0xor(__int128 a, __int128 b) {
    __int128 r;
    asm { pxor r, a, b }
    return r;
}
static inline __int128 ks4022E0from(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline int ks4022E0meq(__int128 m, __int128 a, __int128 b) {
    __int128 y = ks4022E0and(m, b);
    __int128 x = ks4022E0and(m, a);
    return ks4022E0eq(x, y);
}
static inline int ks4022E0meqB(__int128 b, __int128 a, __int128 m) {
    __int128 y = ks4022E0and(m, b);
    __int128 x = ks4022E0and(m, a);
    return ks4022E0eq(x, y);
}
void Monster_FindTheTexture(KS4022E0* s, __int128 key, KO4022E0* out, short* pa, short* pb, int mode, char c)
{
    __int128 k2;
    __int128 mask1;
    __int128 mask2;
    __int128 k;
    __int128 cmp;
    unsigned int i;
    char* p;
    p = (char*)&key;
    mask1 = s->m90;
    k2 = 0;
    ((char*)&k2)[9] = c;
    mask2 = s->m50;
    k = ks4022E0and(mask1, key);
    if (p[4] == 'X') {
        mask1 = ks4022E0xor(s->mB0, mask1);
        mask2 = ks4022E0xor(s->mB0, mask2);
    }
    if (mode == 1)
        cmp = ks4022E0from(50);
    if (mode == 0)
        cmp = ks4022E0from(49);
    for (i = 0; i < s->count; i++) {
        if (ks4022E0eq(*(__int128*)&key, s->keys[i]) && ks4022E0meq(s->m20, s->keys[i], k2))
        {
            out->val = s->keys[i];
            *pa = s->pairs[i].a;
            *pb = s->pairs[i].b;
            return;
        }
    }
    for (i = 0; i < s->count; i++) {
        if (ks4022E0eq(*(__int128*)&key, s->keys[i]) && ks4022E0meqB(s->m0, s->keys[i], s->m20))
        {
            out->val = s->keys[i];
            *pa = s->pairs[i].a;
            *pb = s->pairs[i].b;
            return;
        }
    }
    for (i = 0; i < s->count; i++) {
        if (ks4022E0meq(mask1, s->keys[i], k) && !ks4022E0meq(s->m30, s->keys[i], cmp)
            && ks4022E0meq(s->m20, s->keys[i], k2))
        {
            out->val = s->keys[i];
            *pa = s->pairs[i].a;
            *pb = s->pairs[i].b;
            return;
        }
    }
    for (i = 0; i < s->count; i++) {
        if (ks4022E0meq(mask1, s->keys[i], k) && !ks4022E0meq(s->m30, s->keys[i], cmp)
            && ks4022E0meqB(s->m0, s->keys[i], s->m20))
        {
            out->val = s->keys[i];
            *pa = s->pairs[i].a;
            *pb = s->pairs[i].b;
            return;
        }
    }
    for (i = 0; i < s->count; i++) {
        if (ks4022E0meq(mask2, s->keys[i], k) && !ks4022E0meq(s->m30, s->keys[i], cmp)
            && ks4022E0meq(s->m20, s->keys[i], k2))
        {
            out->val = s->keys[i];
            *pa = s->pairs[i].a;
            *pb = s->pairs[i].b;
            return;
        }
    }
    for (i = 0; i < s->count; i++) {
        if (ks4022E0meq(mask2, s->keys[i], k) && !ks4022E0meq(s->m30, s->keys[i], cmp)
            && ks4022E0meqB(s->m0, s->keys[i], s->m20))
        {
            out->val = s->keys[i];
            *pa = s->pairs[i].a;
            *pb = s->pairs[i].b;
            return;
        }
    }
    String_CompareN(p + 6, D_004BE760, 3);
    out->val = key;
    *pa = s->pairs[0].a;
    *pb = s->pairs[0].b;
}
