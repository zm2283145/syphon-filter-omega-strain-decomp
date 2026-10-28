/*
 * Libs/SFOLib/Source/manUtils: 8 files, 00401DE0-004029B0
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

/* merge_units: begin func_004029B0 */
#pragma push /* merge_units */
/* Monster_LoadLights (004029B0) - manUtils.cc */
#pragma cplusplus on
#include "alloc_guard.h"

/* lq/sq quadword copies and VU0 math have no C equivalent; the unused xx keeps retail's dead addius */
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { const cVector* ps = &o; cVector* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct cMatrix { float m[4][4];
    cMatrix() {}
    cMatrix(const cVector& a, const cVector& b, const cVector& c, const cVector& d);
    cMatrix& operator=(const cMatrix& o) { __int128 a, b; const cMatrix* p = &o; asm volatile { lq a, 0x0(p); lq b, 0x10(p); sq a, 0x0(this); lq a, 0x20(p); sq b, 0x10(this); lq b, 0x30(p); sq a, 0x20(this); sq b, 0x30(this) } return *this; }
} __attribute__((aligned(16)));
struct cFileMan { char b[0x9C]; };
struct Monster;

extern "C" {
extern char D_004BE790[];
extern char D_004BE7A0[];
extern char D_004BE7E8[];
extern char D_004BE7F0[];
void cFileMan_ctor_charP_cFileIOP_bool(cFileMan* f, char* name, void* io, int b);
#if 0 /* merge_units */
int cFileMan_Open(cFileMan* f);
#endif /* merge_units */
#define cFileMan_Open(a0) (cFileMan_Open((SklFile_h5 *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cFileMan_GetSize(cFileMan* f);
#endif /* merge_units */
#define cFileMan_GetSize(a0) (cFileMan_GetSize((SklFile_h5 *)(a0))) /* merge_units */

void cFileMan_Read_charPP_int(cFileMan* f, char** p, int size);
#if 0 /* merge_units */
void cFileMan_Close(cFileMan* f);
#endif /* merge_units */
#define cFileMan_Close(a0) (cFileMan_Close((SklFile_h5 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cFileMan_dtor(cFileMan* f, int del);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((SklFile_h5 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int Libc_Strncmp(char* a, char* b, int n);
#endif /* merge_units */
#define Libc_Strncmp(a0, a1, a2) (Libc_Strncmp((a0), (a1), (a2))) /* merge_units */

int Libc_Sscanf(char* s, char* fmt, ...);
int cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(cMatrix* m, cVector* a, cVector* b, cVector* c, cVector* d);
}

/* quadword clear loop (sq zero) */
static inline void QZero(void* d0, int n0) { int n = n0; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
static inline void Normalize(cVector* v) {
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(v)
    }
}

inline cMatrix::cMatrix(const cVector& a, const cVector& b, const cVector& c, const cVector& d) { cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(this, (cVector*)&a, (cVector*)&b, (cVector*)&c, (cVector*)&d); }
extern "C" void Monster_LoadLights(Monster* self, char* path, cMatrix* theLightColor, cMatrix* theLightMat) {
    cVector lightDir[4];
    cFileMan lightFile;
    int size;
    char* lightData;
    char* data;
    char* end;
    int lightsFound;
    cMatrix m;
    cVector c;
    int aFlag;
    int count;
    char name[256];
    char type[256];
    float intensity;
    int i;

    cFileMan_ctor_charP_cFileIOP_bool(&lightFile, path, 0, 0);
    if (!(unsigned char)cFileMan_Open(&lightFile)) {
        size = cFileMan_GetSize(&lightFile);
        lightData = 0;
        cFileMan_Read_charPP_int(&lightFile, &lightData, size);
        cFileMan_Close(&lightFile);
        data = lightData;
        lightsFound = 0;
        end = data + size;
        *end = '\n';
        QZero(theLightColor, 4);
        while (data < end) {
            if (Libc_Strncmp(data, D_004BE790, 5) == 0) {
                while (*data != '\r' && *data != '\n') data++;
                while (*data == '\r' || *data == '\n') data++;
                while (*data != '\r' && *data != '\n') data++;
                while (*data == '\r' || *data == '\n') data++;
                do {
                    count = Libc_Sscanf(data, D_004BE7A0, name, &aFlag, type,
                        &m.m[0][0], &m.m[0][1], &m.m[0][2],
                        &m.m[1][0], &m.m[1][1], &m.m[1][2],
                        &m.m[2][0], &m.m[2][1], &m.m[2][2],
                        &m.m[3][0], &m.m[3][1], &m.m[3][2],
                        &c.x, &c.y, &c.z, &intensity);
                    if (count == 19 && Libc_Strncmp(type, D_004BE7E8, 6) == 0 && lightsFound < 4) {
                        lightDir[lightsFound].x = m.m[2][0];
                        lightDir[lightsFound].y = m.m[2][1];
                        lightDir[lightsFound].z = m.m[2][2];
                        theLightColor->m[lightsFound][0] = 128.0f * (intensity * c.x);
                        theLightColor->m[lightsFound][1] = 128.0f * (intensity * c.y);
                        theLightColor->m[lightsFound][2] = 128.0f * (intensity * c.z);
                        lightsFound++;
                    }
                    while (*data != '\r' && *data != '\n') data++;
                    while (*data == '\r' || *data == '\n') data++;
                } while (count == 19);
                break;
            }
            while (*data != '\r' && *data != '\n') data++;
            while (*data == '\r' || *data == '\n') data++;
        }
        {
            char* p = lightData;
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BE7F0, 2746);
        }
    } else {
        lightDir[0] = cVector(0.0f, 0.5f, -1.5f, 0.0f);
        lightDir[1] = cVector(1.5f, 0.5f, 0.5f, 0.0f);
        lightDir[2] = cVector(-1.5f, 0.5f, 0.5f, 0.0f);
        lightDir[3] = cVector(0.5f, 0.5f, 0.5f, 0.0f);
        *(cVector*)theLightColor->m[0] = cVector(0.2f, 0.2f, 0.2f, 0.0f);
        *(cVector*)theLightColor->m[1] = cVector(0.3f, 0.3f, 0.3f, 0.0f);
        *(cVector*)theLightColor->m[2] = cVector(0.9f, 0.9f, 0.9f, 0.0f);
        *(cVector*)theLightColor->m[3] = cVector(0.0f, 0.0f, 0.0f, 0.0f);
    }
    for (i = 0; i < 4; i++)
        { cVector* xx = &lightDir[i]; Normalize(&lightDir[i]); }
    *theLightMat = cMatrix(lightDir[0], lightDir[1], lightDir[2], lightDir[3]);
    cFileMan_dtor(&lightFile, -1);
}
#undef cFileMan_Open /* merge_units */
#undef cFileMan_GetSize /* merge_units */
#undef cFileMan_Close /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef Libc_Strncmp /* merge_units */
static inline void merge_flush_func_004029B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004029B0 */
