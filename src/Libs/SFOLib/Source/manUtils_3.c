/*
 * Libs/SFOLib/Source/manUtils: 7 files, 00401DE0-00402840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00401DE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad0[0xCC]; unsigned int count; char pad1[0xBC10 - 0xD0]; __int128 keys[1]; } KS00401DE0;
static inline int ks00401DE0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int FindTextureNumber__7MonsterF1(KS00401DE0* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (ks00401DE0eq(key, s->keys[i]))
            return i;
    }
    return 0;
}
static inline void merge_flush_func_00401DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00401DE0 */

/* merge_units: begin func_00401E40 */
#pragma push /* merge_units */
/* pand/pnor/por/pceqw/ppach/pcpyld are MMI instructions with no C spelling. */
typedef struct {
    char pad0[0x30];
    __int128 m30;
    char pad40[0x10];
    __int128 m50;
    char pad60[0x60];
    unsigned int count;
    char padC4[0x2C10 - 0xC4];
    __int128 keys[1];
} KS00401E40;
extern char g_AgentPartCache[];
#if 0 /* merge_units */
int Monster_CountTexByName(KS00401E40* s, __int128 key, int* out, int mode, int a, int b);
#endif /* merge_units */
int Monster_CountTexByName(); /* merge_units */

static inline int ks00401E40eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 ks00401E40and(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 ks00401E40or(__int128 a, __int128 b) {
    __int128 r;
    asm { por r, a, b }
    return r;
}
static inline __int128 ks00401E40not(__int128 a) {
    __int128 r;
    asm { pnor r, a, a }
    return r;
}
static inline __int128 ks00401E40from(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline int ks00401E40meq(__int128 m, __int128 a, __int128 b) {
    return ks00401E40eq(ks00401E40and(m, a), ks00401E40and(m, b));
}
/* (sub & ~mask) | (k & mask), mask at g_AgentPartCache + 0x60; in-place pands give retail registers. */
static inline __int128 Splice(__int128 sub, __int128 k) { __int128 m = *(__int128*)(g_AgentPartCache + 0x60); __int128 nm = ks00401E40not(m); asm { pand m, k, m } asm { pand k, sub, nm } return ks00401E40or(k, m); }
int func_00401E40(KS00401E40* s, __int128 key, __int128 sub, int* out, int mode, int a, int b)
{
    __int128 mask = s->m50;
    __int128 cmp;
    int n = 0;
    unsigned int i;
    if (mode == 1)
        cmp = ks00401E40from(50);
    if (mode == 0)
        cmp = ks00401E40from(49);
    for (i = 0; i < s->count; i++) {
        if (!ks00401E40meq(s->m30, s->keys[i], cmp)
            && ks00401E40meq(mask, s->keys[i], key)) {
            int r = -1;
            int got = Monster_CountTexByName(s, Splice(sub, s->keys[i]), &r, mode, a, b);
            if (ks00401E40eq(key, s->keys[i])) {
                *out = n;
                if (r != -1)
                    *out = n + r;
            }
            if (got)
                n += got;
            else
                n++;
        }
    }
    return n;
}
static inline void merge_flush_func_00401E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00401E40 */

/* merge_units: begin func_00401FF0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00401FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00401FF0 */

/* merge_units: begin func_00402200 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x30];
    __int128 m30;
    char pad40[0x10];
    __int128 m50;
    char pad60[0x10];
    __int128 m70;
    char pad80[0x40];
    unsigned int count;
    char padC4[0x2C10 - 0xC4];
    __int128 keys[1];
} KS00402200;
static inline int ks00402200eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 ks00402200and(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 ks00402200or(__int128 a, __int128 b) {
    __int128 r;
    asm { por r, a, b }
    return r;
}
static inline __int128 ks00402200from(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline int ks00402200meq(__int128 m, __int128 a, __int128 b) {
    return ks00402200eq(ks00402200and(m, a), ks00402200and(m, b));
}
int Monster_CountPartsByName(KS00402200* s, __int128 key, int* out, int mode, __int128 cmp)
{
    __int128 mask = s->m50;
    unsigned int i;
    int n = 0;
    if (cmp)
        mask = ks00402200or(s->m70, mask);
    if (mode == 1)
        cmp = ks00402200from(50);
    if (mode == 0)
        cmp = ks00402200from(49);
    for (i = 0; i < s->count; i++) {
        if (!ks00402200meq(s->m30, s->keys[i], cmp)
            && ks00402200meq(mask, s->keys[i], key)) {
            if (ks00402200eq(key, s->keys[i]))
                *out = n;
            n++;
        }
    }
    return n;
}
static inline void merge_flush_func_00402200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00402200 */

/* merge_units: begin func_004022E0 */
#pragma push /* merge_units */
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
extern int Libc_Strncmp(char*, char*, int);
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
    Libc_Strncmp(p + 6, D_004BE760, 3);
    out->val = key;
    *pa = s->pairs[0].a;
    *pb = s->pairs[0].b;
}
static inline void merge_flush_func_004022E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004022E0 */

/* merge_units: begin func_004027E0 */
#pragma push /* merge_units */
typedef struct { char pad0[0xCC]; unsigned int count; char pad1[0xBC10 - 0xD0]; __int128 keys[1]; } KS004027E0;
static inline int ks004027E0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int FindTex__7MonsterF1(KS004027E0* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (ks004027E0eq(key, s->keys[i]))
            return i;
    }
    return -1;
}
static inline void merge_flush_func_004027E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004027E0 */

/* merge_units: begin func_00402840 */
#pragma push /* merge_units */
typedef struct SklFile_h5 {
    int unk0;
    char name[0x9C];
} SklFile_h5;
extern signed char D_00493A60;
extern char D_0055D510[];
extern char D_0055D950[];
extern void cFileMan_ctor_void(SklFile_h5* f);
extern void cFileMan_EncodeFilename_charP_cFileIOP_bool(SklFile_h5* f, char* path, int a, int b);
extern int cFileMan_Open(SklFile_h5* f);
extern int cFileMan_GetSize(SklFile_h5* f);
extern void* cFileMan_Read_void(SklFile_h5* f);
extern void cFileMan_Close(SklFile_h5* f);
extern void cFileMan_dtor(SklFile_h5* f, int flags);
extern int sprintf(char* buf, const char* fmt, ...);
extern void SKL_ConvertSKL(char* dst, void* text, int len);
void Monster_LoadMenSKLs(void* self, char* skelPath, char* animPath)
{
    D_00493A60 = 0;
    {
        SklFile_h5 f;
        cFileMan_ctor_void(&f);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&f, skelPath, 0, 0);
        if ((unsigned char)cFileMan_Open(&f)) {
            char msg[128];
            sprintf(msg, "Failed to open %s in LoadSKL\n", f.name);
            cFileMan_dtor(&f, -1);
        } else {
            int len = cFileMan_GetSize(&f);
            SKL_ConvertSKL(D_0055D510, cFileMan_Read_void(&f), len);
            cFileMan_Close(&f);
            cFileMan_dtor(&f, -1);
        }
    }
    {
        SklFile_h5 f;
        cFileMan_ctor_void(&f);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&f, animPath, 0, 0);
        if ((unsigned char)cFileMan_Open(&f)) {
            char msg[128];
            sprintf(msg, "Failed to open %s in LoadSKL\n", f.name);
            cFileMan_dtor(&f, -1);
        } else {
            int len = cFileMan_GetSize(&f);
            SKL_ConvertSKL(D_0055D950, cFileMan_Read_void(&f), len);
            cFileMan_Close(&f);
            cFileMan_dtor(&f, -1);
        }
    }
}
static inline void merge_flush_func_00402840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00402840 */
