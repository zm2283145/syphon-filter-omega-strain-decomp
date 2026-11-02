/*
 * Libs/SFOLib/Source/manUtils: 6 files, 00406DC0-00407830
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00406DC0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { __int128 a; __int128 b; } H2Pair;
typedef struct { char hdr[0x40]; H2Pair pairs[1]; } H2Pack;
int SKL_CountAttribs(H2Pack* p) {
    int n = 0;
    while ((long long)p->pairs[n].a != 0) n++;
    return n;
}
static inline void merge_flush_func_00406DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00406DC0 */

/* merge_units: begin func_00406E00 */
#pragma push /* merge_units */
/* pand/pceqw/ppach are MMI instructions with no C spelling. */

extern char g_AgentPartCache[];
static inline __int128 PAndI(__int128 a, __int128 b) {
    asm { pand b, a, b }
    return b;
}
static inline int PEq(__int128 a, __int128 b) {
    long long r;
    asm {
        pceqw a, a, b
        ppach r, a, a
    }
    return r == -1;
}
static inline __int128 PAnd(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
/* A name is blank when its masked bytes equal the masked blank name (mask at +0x60). */
static inline int IsBlank(__int128 v) {
    __int128 m = *(__int128*)(g_AgentPartCache + 0x60);
    __int128 x = PAndI(m, v);
    __int128 k = PAnd(m, *(__int128*)g_AgentPartCache);
    return PEq(x, k);
}
/* Removes every pair with a blank name, shifting the rest down. */
void SKL_RemoveBlanks(H2Pack* p) {
    int i = 0;
    while ((long long)p->pairs[i].a != 0) {
        if (IsBlank(p->pairs[i].a) || IsBlank(p->pairs[i].b)) {
            int j = i;
            while ((long long)p->pairs[j].b != 0) {
                p->pairs[j].a = p->pairs[j + 1].a;
                p->pairs[j].b = p->pairs[j + 1].b;
                j++;
            }
        } else {
            i++;
        }
    }
}
static inline void merge_flush_func_00406E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00406E00 */

/* merge_units: begin func_00406EC0 */
#pragma push /* merge_units */
typedef struct { __int128 a; __int128 b; } H2E_Pair;
typedef struct { __int128 slot0; __int128 slot1; __int128 q20; __int128 q30; H2E_Pair pairs[32]; } H2E_Pack;
typedef struct { char name[16]; } H2E_Name;
typedef struct { unsigned int count; H2E_Name e[24]; } H2E_Presets;
extern H2E_Presets D_00571300;
extern __int128 D_005609B0[];
extern __int128 D_005699B0[];
extern __int128 D_005716E0;
extern __int128* D_005712F8[];
extern int D_005712F0[];
extern char D_004BE950[];
extern char D_004BE960[];
extern void strCpyPad(H2E_Pack* p, int n, char* name);
extern void Libc_Strcpy(void* d, char* s);
extern int SKL_FindSex(H2E_Pack* p);
/* inline-asm block copy (hand-written in the original) */
static inline void H2E_Copy(void* d0, void* s0, int n0)
{
    int n = n0;
    __int128 u;
    int t;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi t, s, 0xF
        andi u, d, 0xF
        or t, t, u
        andi u, n, 0xF
        or t, t, u
        nop
        bgtz t, bytes
    quads:
        lq u, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq u, -0x10(d)
        b done
        nop
    bytes:
        lb u, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb u, -1(d)
        .set reorder
    done:
    }
}
/* inline-asm quad clear (hand-written in the original) */
static inline void H2E_QZero(void* dd, int nn)
{
    int n = nn; void* d = dd;
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
#pragma opt_propagation off
/* Decodes a packed manifest: each slot is a table index or -1 followed by 16 raw bytes. */
void SKL_UncompressSKL(H2E_Pack* dst, short* p)
{
    int n;
    int i;
    int c;
    char* raw;
    int c1;
    n = *p++;
    if (n <= 0 || n >= 0x20) n = 1;
    raw = (char*)(p + (n * 2 + 6));
    c = *p++;
    if (c == -1) {
        H2E_Copy(dst, raw, 0x10);
        raw += 0x10;
    } else {
        if ((unsigned int)c >= D_00571300.count) c = 0;
        strCpyPad(dst, 0xF, D_00571300.e[c].name);
    }
    c1 = *p++;
    if (c1 == -1) {
        H2E_Copy(&dst->slot1, raw, 0x10);
        raw += 0x10;
    }
    c = *p++;
    if (c == -1) {
        H2E_Copy(&dst->q20, raw, 0x10);
        raw += 0x10;
    } else {
        dst->q20 = D_005609B0[c];
    }
    c = *p++;
    if (c == -1) {
        H2E_Copy(&dst->q30, raw, 0x10);
        raw += 0x10;
    } else {
        dst->q30 = D_005716E0;
        if (c == 1) Libc_Strcpy(&dst->q30, D_004BE950);
        else Libc_Strcpy(&dst->q30, D_004BE960);
    }
    for (i = 0; i <= n; i++) {
        c = *p++;
        if (c != -1) {
            dst->pairs[i].a = D_005609B0[c];
        } else {
            H2E_Copy(&dst->pairs[i].a, raw, 0x10);
            raw += 0x10;
        }
        c = *p++;
        if (c != -1) {
            dst->pairs[i].b = D_005699B0[c];
        } else {
            H2E_Copy(&dst->pairs[i].b, raw, 0x10);
            raw += 0x10;
        }
    }
    H2E_QZero(&dst->pairs[i], 2);
    if (c1 != -1) {
        int k = SKL_FindSex(dst);
        __int128* tbl = D_005712F8[k];
        if (c1 >= D_005712F0[k]) c1 = 0;
        dst->slot1 = tbl[c1];
    }
}
static inline void merge_flush_func_00406EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00406EC0 */

/* merge_units: begin func_004073C0 */
#pragma push /* merge_units */
typedef struct { short n; short v[1]; } H2E_Hdr;
extern __int128 D_0055DE20;
extern unsigned int D_0055DE60;
extern unsigned int D_0055DE68;
extern unsigned int D_0055DE6C;
extern unsigned int D_0055DE70;
extern int strcmp(const void* a, const void* b);
extern int Libc_Strncmp(void* a, char* b, int n);
static inline int PEq1(__int128 a, __int128 b) { long long r; long long m1 = -1; asm { pceqw a, a, b
        ppach r, a, a } return r == m1; }
static inline int FindBoneScale(char* s)
{
    unsigned int i;
    for (i = 0; i < D_00571300.count; i++)
        if (strcmp(s, D_00571300.e[i].name) == 0) return i;
    return -1;
}
static inline int FindFace(int sex, char* s)
{
    __int128* tbl = D_005712F8[sex];
    int n = D_005712F0[sex];
    int i;
    for (i = 0; i < n; tbl++, i++)
        if (strcmp(tbl, s) == 0) return i;
    return -1;
}
static inline int FindPart(__int128 v)
{
    unsigned int i;
    __int128 m = D_0055DE20;
    __int128 k = PAnd(m, v);
    for (i = 0; i < D_0055DE60; i++)
        if (PEq(PAnd(m, D_005609B0[i]), k)) return i;
    return -1;
}
static inline int FindPart1(__int128 v)
{
    unsigned int i = 0;
    __int128 m = D_0055DE20;
    __int128 k = PAnd(m, v);
    __int128* t = D_005609B0;
    for (; i < D_0055DE60; i++)
        if (PEq1(PAnd(m, t[i]), k)) return i;
    return -1;
}
static inline int FindTex(__int128 v)
{
    unsigned int i;
    for (i = 0; i < D_0055DE6C; i++)
        if (PEq(v, D_005699B0[i])) return i;
    return -1;
}
static inline int Valid(int p, unsigned int n)
{
    if ((unsigned int)p < n) return p;
    return -1;
}
static inline int ValidR(int p, unsigned int n) { int r; if ((unsigned int)p < n) r = p; else r = -1; return r; }
char* SKL_CompressSKL(H2E_Pack* skl, int* dataSize)
{
    char* SPAD = (char*)0x70000000;
    short* data = (short*)SPAD;
    int count;
    int part;
    int sex;
    int i;
    short* data2;
    char* dataEnd;
    sex = SKL_FindSex(skl);
    for (count = 0; (long long)*(__int128*)((count << 5) + (int)skl + 0x40) != 0; count++) ;
    *data++ = count;
    part = FindBoneScale((char*)&skl->slot0);
    *data++ = part;
    part = FindFace(sex, (char*)&skl->slot1);
    *data++ = part;
    part = FindPart1(skl->q20);
    if ((unsigned int)part < D_0055DE68) { asm { nop } } else part = -1;
    *data++ = part;
    part = -1;
    if (Libc_Strncmp(&skl->q30, D_004BE950, 9) == 0) part = 1;
    else if (Libc_Strncmp(&skl->q30, D_004BE960, 0xB) == 0) part = 0;
    *data++ = part;
    for (i = 0; i <= count; i++) {
        part = FindPart(*(__int128*)((i << 5) + (int)skl + 0x40));
        if ((unsigned int)part < D_0055DE68) { asm { nop } } else part = -1;
        *data++ = part;
        part = FindTex(((H2E_Pair*)(((unsigned int)i << 5) + (int)skl + 0x40))->b);
        if ((unsigned int)part < D_0055DE70) { asm { nop } } else part = -1;
        *data++ = part;
    }
    dataEnd = (char*)data;
    for (data2 = (short*)0x70000000, data2++; data2 < data; data2++, skl = (H2E_Pack*)((char*)skl + 0x10)) {
        if (*data2 == -1) {
            H2E_Copy(dataEnd, skl, 0x10);
            dataEnd += 0x10;
        }
    }
    *dataSize = dataEnd - SPAD;
    return SPAD;

    /* Emits no code: a volatile asm anywhere in the body selects MW's less-optimised compiler mode,
       which retail SKL_CompressSKL was built in (see docs/HANDOFF.md "Less-optimised compiler mode"). */
    if (0) { asm volatile { nop } }
}
static inline void merge_flush_func_004073C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004073C0 */

/* merge_units: begin func_00407830 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

typedef union { long long q[4]; char s[32]; __int128 v[2]; } H2Key;
typedef struct { char b[0x440]; } H2Pack_00407830;
typedef struct { H2Key* keys; H2Pack_00407830* packs; int count; } H2Registry;
typedef struct { int pad; int n; } Lst;
typedef struct { char pad[0x148]; Lst* list; unsigned char loaded; } Arc;
typedef struct { int flags; char pad[0x94]; void* p98; } FObj;
typedef struct {
    char pad[0xF8];
    H2Pack_00407830* a[4];
    H2Pack_00407830* b[4];
} BodyTab;

extern "C" {
extern int D_0055DE94;
#if 0 /* merge_units */
extern BodyTab g_AgentPartCache;
#endif /* merge_units */
#define g_AgentPartCache (*(BodyTab*)&g_AgentPartCache) /* merge_units */

extern char D_004BE7F0[];
extern char D_004BE970[];
extern char D_004BE978[];
void cFileMan_ctor_void(FObj* o);
FObj* cFileMan_dtor(FObj* o, short del);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
char* cHogFile_GetBlockName(Arc* a, int i);
#if 0 /* merge_units */
void strCpyPad(char* dst, int n, char* src);
#endif /* merge_units */
#define strCpyPad(a0, a1, a2) (strCpyPad((H2E_Pack *)(a0), (a1), (a2))) /* merge_units */

void* cHogFile_GetBlock_int(Arc* a, int i);
int cHogFile_GetBlockSize(Arc* a, int i);
void SKL_ConvertSKL(H2Pack_00407830* dst, void* text, int len);
#if 0 /* merge_units */
int Libc_Strncmp(char* a, char* b, int n);
#endif /* merge_units */
#define Libc_Strncmp(a0, a1, a2) (Libc_Strncmp((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int SKL_FindSex(H2Pack_00407830* p);
#endif /* merge_units */
#define SKL_FindSex(a0) (SKL_FindSex((H2E_Pack *)(a0))) /* merge_units */

void SKLHog_LoadSKLHog(H2Registry* reg, Arc* arc);
}

static inline void* SAlloc(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004BE7F0, line);
}

void SKLHog_LoadSKLHog(H2Registry* reg, Arc* arc)
{
    FObj fo;
    char* name;
    int nA = 0;
    int nB = 0;
    int i;
    int n;
    cFileMan_ctor_void(&fo);
    D_0055DE94 = 0;
    reg->count = 0;
    g_AgentPartCache.a[0] = 0;
    g_AgentPartCache.b[0] = 0;
    g_AgentPartCache.a[1] = 0;
    g_AgentPartCache.b[1] = 0;
    g_AgentPartCache.a[2] = 0;
    g_AgentPartCache.b[2] = 0;
    g_AgentPartCache.a[3] = 0;
    g_AgentPartCache.b[3] = 0;
    if (!arc->loaded) {
        cFileMan_dtor(&fo, -1);
        return;
    }
    n = arc->list->n;
    reg->keys = (H2Key*)SAlloc(n * 32, 0xCE);
    reg->packs = (H2Pack_00407830*)SAlloc(n * 0x440, 0xCF);
    for (i = 0; i < n; i++) {
        name = cHogFile_GetBlockName(arc, i);
        strCpyPad(reg->keys[i].s, 0x1F, name);
        SKL_ConvertSKL(&reg->packs[i], cHogFile_GetBlock_int(arc, i), cHogFile_GetBlockSize(arc, i));
        Libc_Strncmp(name, D_004BE970, 3);
        if (Libc_Strncmp(name, D_004BE978, 8) == 0) {
            D_0055DE94++;
            if (SKL_FindSex(&reg->packs[i]) == 0) {
                if (nA < 4)
                    g_AgentPartCache.a[nA] = &reg->packs[i];
                nA++;
            } else {
                if (nB < 4)
                    g_AgentPartCache.b[nB] = &reg->packs[i];
                nB++;
            }
        }
    }
    if (nB != 0 && nB < 4) {
        i = nB;
        do {
            g_AgentPartCache.b[i] = g_AgentPartCache.b[nB - 1];
        } while (++i < 4);
    }
    if (nA != 0 && nA < 4) {
        i = nA;
        do {
            g_AgentPartCache.a[i] = g_AgentPartCache.a[nA - 1];
        } while (++i < 4);
    }
    reg->count = n;
    cFileMan_dtor(&fo, -1);
}
#undef g_AgentPartCache /* merge_units */
#undef strCpyPad /* merge_units */
#undef Libc_Strncmp /* merge_units */
#undef SKL_FindSex /* merge_units */
static inline void merge_flush_func_00407830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00407830 */

/* merge_units: begin func_00407BE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cMemMan_Deallocate(int, int, char *, int);                         
#if 0 /* merge_units */
extern char D_004BE7F0;
#endif /* merge_units */
#define D_004BE7F0 (*(char*)&D_004BE7F0) /* merge_units */


extern unsigned char g_ProfileLockEnabled;
extern int D_0055D4F8;
extern int D_0055D4FC;
extern int D_0055D500;
}
extern "C" void SKLHog_DeleteIdentities(void) {
    int temp_s0;
    int temp_s0_2;

    if (D_0055D500 != 0) {
        temp_s0 = D_0055D4F8;
        {
            AllocGuard g;
        cMemMan_Deallocate(0, temp_s0, &D_004BE7F0, 0xB0);
        }
        temp_s0_2 = D_0055D4FC;
        {
            AllocGuard g;
        cMemMan_Deallocate(0, temp_s0_2, &D_004BE7F0, 0xB1);
        }
        D_0055D500 = 0;
    }
}
#undef D_004BE7F0 /* merge_units */
static inline void merge_flush_func_00407BE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00407BE0 */
