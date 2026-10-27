/*
 * Libs/SFOLib/Source/manUtils: 8 files, 00403310-00403FD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00403310 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);

#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" char D_004BE7F0[];
/* quad copy loop idiom as in src\main\cLightMan_RemoveLight.c (retail uses a hand-written addi) */
static inline void QMove(void* d, void* s, int n) {
    __int128 t;
    int nn = n; void* ss = s; void* dd = d;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }}
struct Obj {
    char pad0[0xD4];
    void* bufA;
    void* bufB;
    int nA;
    int nB;
    char padE4[0x2C10 - 0xE4];
    char saveA[0xBC10 - 0x2C10];
    char saveB[0x10];
};
extern "C" void Monster_RestoreLockedPartsTex(Obj* o)
{
    void* s = o->bufA;
    if (s) {
        QMove(o->saveA, s, o->nA);
        QMove(o->saveB, o->bufB, o->nB);
        {
            void* p = o->bufA;
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0xA28);
        }
        {
            void* p = o->bufB;
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0xA29);
        }
        o->bufA = 0;
        o->bufB = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00403310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00403310 */

/* merge_units: begin func_00403490 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "fileman_entry.h"
extern "C" {
#if 0 /* merge_units */
extern char D_004BE7F0[];
#endif /* merge_units */
#define D_004BE7F0 ((char*)&D_004BE7F0) /* merge_units */


extern char D_004BE800[];
void* cMemMan_Allocate(int, int, char*, int);
int cFileMan_Open(void*);
int cFileMan_GetSize(void*);
int cFileMan_Read_charPP_int(void*, char**, int);
void cFileMan_Close(void*);
int Libc_Sscanf(char*, char*, ...);
}
inline int AtEnd(char* a, char* b) { return a >= b; }
struct SortEnt { char name[16]; int a, b, c, d, e, f, g, h; };
struct App { char pad[0xEC]; int count; char pad2[0x11C10 - 0xF0]; SortEnt ents[1]; };
extern "C" void Monster_ReadSortTable(App* self, char* path) {
 if (self->count != 0) return;
 FileManEntry fe;
 char* buf;
 cFileMan_ctor_charP_cFileIOP_bool(&fe, path, 0, 0);
 int count = 0;
 if ((unsigned char)cFileMan_Open(&fe)) { cFileMan_dtor(&fe, -1); return; }
 int size = cFileMan_GetSize(&fe);
 int blocks = (size + 0x10) >> 4;
 char* p;
 {
  AllocGuard g;
  p = (char*)cMemMan_Allocate(0, blocks << 4, D_004BE7F0, 0x9E8);
 }
 buf = p;
 cFileMan_Read_charPP_int(&fe, &buf, size);
 cFileMan_Close(&fe);
 char* base = buf;
 char* dst = base;
 char* src = base;
 char* end = base + size;
 while (src < end) {
  int c = *src++;
  *dst++ = c;
  if (c == 0) dst--;
  if (c == '#') dst--;
  if (c == '$') dst--;
  if (c == '*') dst--;
  if (c == '\t') dst--;
  if (c == '\n') dst--;
  if (c == '/') {
   c = *src++;
   while (!AtEnd(src, end) && c != '\r') c = *src++;
  }
  if (c == '\r') {
   dst[-1] = 0;
   src++;
   int r = Libc_Sscanf(base, D_004BE800, self->ents[count].name, &self->ents[count].a, &self->ents[count].b, &self->ents[count].c, &self->ents[count].d, &self->ents[count].e, &self->ents[count].f, &self->ents[count].g, &self->ents[count].h);
   if (r == 9) { count++; }
   else if (r != -1) { *(__int128*)self->ents[count].name = 0; }
   dst = base;
  }
 }
 self->count = count;
 char* q = buf;
 {
  AllocGuard g;
  cMemMan_Deallocate(0, q, D_004BE7F0, 0xA1D);
 }
 cFileMan_dtor(&fe, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00403490(void) {}
#undef D_004BE7F0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00403490 */

/* merge_units: begin func_004037F0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x9C]; } FileMan;
typedef struct { char pad[0xE4]; int count; __int128* buf; } Obj37F0;
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void EnableIntc(int id);
#if 0 /* merge_units */
extern char D_004BE7F0[];
#endif /* merge_units */
#define D_004BE7F0 ((char*)&D_004BE7F0) /* merge_units */


#if 0 /* merge_units */
extern void cFileMan_ctor_charP_cFileIOP_bool(FileMan* f, char* name, int a, int b);
#endif /* merge_units */
#define cFileMan_ctor_charP_cFileIOP_bool(a0, a1, a2, a3) ((void)cFileMan_ctor_charP_cFileIOP_bool((void *)(a0), (const char *)(a1), (void *)(a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern int cFileMan_Open(FileMan* f);
#endif /* merge_units */
#define cFileMan_Open(a0) (cFileMan_Open((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern int cFileMan_GetSize(FileMan* f);
#endif /* merge_units */
#define cFileMan_GetSize(a0) (cFileMan_GetSize((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void* cMemMan_Allocate(int pool, int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern int cFileMan_Read_charPP_int(FileMan* f, __int128** out, int size);
#endif /* merge_units */
#define cFileMan_Read_charPP_int(a0, a1, a2) (cFileMan_Read_charPP_int((void *)(a0), (char * *)(a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void cFileMan_Close(FileMan* f);
#endif /* merge_units */
#define cFileMan_Close(a0) (cFileMan_Close((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void cFileMan_dtor(FileMan* f, int a);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) ((void)cFileMan_dtor((void *)(a0), (a1))) /* merge_units */


void Monster_LoadSwapRules(Obj37F0* s, char* name);
}
static inline long long iszero(__int128 a) {
    __int128 t;
    long long r;
    asm {
        pceqw t, zero, a
        ppach r, t, t
    }
    return r;
}
void Monster_LoadSwapRules(Obj37F0* s, char* name)
{
    FileMan fm;
    int size;
    __int128* end;
    __int128* p;
    void* mem;
    cFileMan_ctor_charP_cFileIOP_bool(&fm, name, 0, 0);
    if (!(unsigned char)cFileMan_Open(&fm)) {
        size = cFileMan_GetSize(&fm);
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        mem = cMemMan_Allocate(0, size, D_004BE7F0, 0x9B5);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        s->buf = (__int128*)mem;
        cFileMan_Read_charPP_int(&fm, &s->buf, size);
        cFileMan_Close(&fm);
        p = s->buf;
        if (p) {
            end = (__int128*)((char*)p + size);
            while (iszero(*p) != -1 && p < end) {
                s->count++;
                p += 8;
            }
        }
    }
    cFileMan_dtor(&fm, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004037F0(void) {}
#undef D_004BE7F0 /* merge_units */
#undef cFileMan_ctor_charP_cFileIOP_bool /* merge_units */
#undef cFileMan_Open /* merge_units */
#undef cFileMan_GetSize /* merge_units */
#undef cMemMan_Allocate /* merge_units */
#undef cFileMan_Read_charPP_int /* merge_units */
#undef cFileMan_Close /* merge_units */
#undef cFileMan_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004037F0 */

/* merge_units: begin func_00403940 */
#pragma push /* merge_units */
typedef struct { short a; short b; } P_403940;
typedef struct {
    char pad0[0xD0];
    unsigned int count;
    char padD4[0x810 - 0xD4];
    short t[(0x1410 - 0x810) / 2];
    P_403940 p[(0xBC10 - 0x1410) / 4];
    __int128 k[1];
} S_403940;
extern int g_TextureMgr;
extern __int128 D_005716E0;
extern void cTexMan_RemoveTexture(int a, int b, int c);
void Monster_FreeTexture(S_403940* s, unsigned int i)
{
    if (s->t[i] != 0) {
        s->t[i]--;
        if (s->t[i] <= 0 && i >= s->count) {
            if (s->p[i].a != s->p[i].b)
                cTexMan_RemoveTexture(g_TextureMgr, s->p[i].b, 0);
            cTexMan_RemoveTexture(g_TextureMgr, s->p[i].a, 0);
            s->p[i].a = 0;
            s->p[i].b = 0;
            s->k[i] = D_005716E0;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00403940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00403940 */

/* merge_units: begin func_00403A20 */
#pragma push /* merge_units */
typedef struct { short a; short b; } A3Tex;
typedef union { __int128 q; int w; } A3Name;
typedef struct {
    char pad0[0x80];
    __int128 mask;
    char pad1[0xCC - 0x90];
    unsigned int count;
    int loaded;
    char pad2[0x810 - 0xD4];
    short ref[0x600];
    A3Tex tex[0x2A00];
    A3Name names[0x600];
} A3State;
extern __int128 D_0055DE00;
extern __int128 g_AgentPartCache;
extern int Libc_Strncmp(char* a, char* b, int n);
extern void cFileMan_EncodeFilename_charP_cFileManR(void* f, char* name, void* src);
extern short cTexMan_AddTextureTDX(int lib, void* f, void* key);
extern short cTexMan_UseMrYuckTexture(int lib);
static inline __int128 a3and(__int128 a, __int128 b) {
    __int128 t;
    asm { pand t, a, b }
    return t;
}
static inline int a3eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
void Monster_FindAddTexture(A3State* st, __int128 key, void* f, short* outA, short* outB) {
    unsigned int i;
    unsigned int n;
    int j;
    char buf[80];
    __int128 o;
    __int128 m;
    __int128 k;
    {
        for (i = 0; i < st->count; i++) {
            if (a3eq(a3and(st->mask, st->names[i].q), a3and(st->mask, key))) {
                *outA = st->tex[i].a;
                *outB = st->tex[i].b;
                if (st->ref[i] != 0)
                    st->ref[i]++;
                return;
            }
        }
    }
    if (st->count < 0x600) {
        i = st->count;
        st->count++;
    } else {
        for (j = st->loaded; j < 0x600; j++) {
            if ((int)st->names[j].q == 0)
                break;
        }
    }
    m = D_0055DE00;
    k = key;
    o = g_AgentPartCache;
    if (a3eq(a3and(m, k), a3and(m, o)) && Libc_Strncmp((char*)&key, "_MAKE", 5) != 0) {
        st->tex[i].a = st->tex[0].b;
        st->tex[i].b = st->tex[0].b;
        *outA = st->tex[i].a;
        *outB = st->tex[i].b;
        st->names[i].q = key;
        st->ref[i] = 0;
        return;
    }
    st->names[i].q = key;
    sprintf(buf, "%s.TDX", (char*)&key);
    buf[14] = '0';
    cFileMan_EncodeFilename_charP_cFileManR(f, buf, f);
    st->tex[i].a = cTexMan_AddTextureTDX(g_TextureMgr, f, &key);
    buf[14] = '1';
    cFileMan_EncodeFilename_charP_cFileManR(f, buf, f);
    st->tex[i].b = cTexMan_AddTextureTDX(g_TextureMgr, f, &key);
    if (st->tex[i].a == -1)
        st->tex[i].a = cTexMan_UseMrYuckTexture(g_TextureMgr);
    if (st->tex[i].b == -1)
        st->tex[i].b = st->tex[i].a;
    *outA = st->tex[i].a;
    *outB = st->tex[i].b;
    st->ref[i] = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00403A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00403A20 */

/* merge_units: begin func_00403D20 */
#pragma push /* merge_units */
typedef union { __int128 q; char s[16]; struct { char stem[14]; char lod; char end; } f; } H2Name;
typedef struct { short a; short b; } H2Tex;
typedef struct {
    char pad0[0xCC];
    unsigned int count;
    unsigned int loaded;
    char pad1[0x1410 - 0xD4];
    H2Tex tex[0x2A00];
    H2Name names[1];
} H2State;
typedef struct { char pad[0x148]; int* dir; } H2Hog;
typedef struct { __int128 x[10]; } H2Reg;
#if 0 /* merge_units */
extern void cFileMan_ctor_void(H2Reg* r);
#endif /* merge_units */
#define cFileMan_ctor_void(a0) ((void)cFileMan_ctor_void((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void cFileMan_dtor(H2Reg* r, int del);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) ((void)cFileMan_dtor((void *)(a0), (a1))) /* merge_units */


extern char* cHogFile_GetBlockName(H2Hog* h, int i);
extern int cFileMan_EncodeFilename_charP_cHogFileR_bool(H2Reg* r, char* name, H2Hog* h, int opt);
extern void strCpyPad(char* dst, int n, char* src);
extern short cTexMan_AddTextureFromFile_R_cFileMan(int lib, __int128 name, H2Reg* r);
static inline int h2eq(__int128 a, __int128 b) {
    long long r;
    asm {
        pceqw a, a, b
        ppach r, a, a
    }
    return r == -1;
}
static inline unsigned int h2find(H2State* st, __int128 key) {
    unsigned int i;
    for (i = 0; i < st->count; i++) {
        if (h2eq(st->names[i].q, key))
            return i;
    }
    return i;
}
/* Registers a texture HOG and loads each member texture into the state's texture table. */
void Monster_LoadTexHog(H2State* st, H2Hog* hog) {
    H2Reg reg;
    int k;
    int total;
    cFileMan_ctor_void(&reg);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(&reg, cHogFile_GetBlockName(hog, 0), hog, 0);
    total = hog->dir[1];
    for (k = 0; k < total; k++) {
        char* e = cHogFile_GetBlockName(hog, k);
        int lod = 0;
        __int128 key;
        unsigned int i;
        if (e[14] != '0')
            lod = 1;
        strCpyPad(st->names[st->count].s, 15, e);
        st->names[st->count].s[14] = '0';
        key = st->names[st->count].q;
        i = h2find(st, key);
        if (i == st->count) {
            st->tex[st->count].a = -1;
            st->tex[st->count].b = -1;
            st->count++;
        }
        if (lod == 0) {
            st->tex[i].a = cTexMan_AddTextureFromFile_R_cFileMan(g_TextureMgr, st->names[i].q, &reg);
            if (st->tex[i].a == -1)
                st->tex[i].a = cTexMan_UseMrYuckTexture(g_TextureMgr);
            if (st->tex[i].b == -1)
                st->tex[i].b = st->tex[i].a;
        } else {
            H2State* sb;
            short* pb;
            short* pa;
            H2Name* nm;
            nm = (H2Name*)((char*)st + i * 16 + 0xBC10);
            sb = (H2State*)((char*)st + i * 4);
            nm->f.lod = '1';
            pb = &sb->tex[0].b;
            *pb = cTexMan_AddTextureFromFile_R_cFileMan(g_TextureMgr, st->names[i].q, &reg);
            if (*pb == -1)
                *pb = cTexMan_UseMrYuckTexture(g_TextureMgr);
            pa = &sb->tex[0].a;
            if (*pa == -1)
                *pa = *pb;
            nm->f.lod = '0';
        }
    }
    st->loaded = st->count;
    cFileMan_dtor(&reg, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00403D20(void) {}
#undef cFileMan_ctor_void /* merge_units */
#undef cFileMan_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00403D20 */

/* merge_units: begin func_00403FC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * manUtils.cc
 */


/* Empty stub. */
void Monster_MonsterPartMemory(void) {
}
static inline void merge_flush_func_00403FC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00403FC0 */

/* merge_units: begin func_00403FD0 */
#pragma push /* merge_units */
typedef struct { int a; int b; int c; int pad[5]; } KFD0Rec;
typedef struct { char pad0[0x80]; __int128 mask; char pad1[0xC0 - 0x90]; unsigned int count; char pad2[0x2C10 - 0xC4]; __int128 keys[0x301]; KFD0Rec recs[1]; } KFD0;
static inline __int128 kfd0and(__int128 a, __int128 b) {
    __int128 t;
    asm { pand t, a, b }
    return t;
}
static inline int kfd0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int Monster_AddMonsterPart(KFD0* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (kfd0eq(kfd0and(s->mask, s->keys[i]), kfd0and(s->mask, key)))
            return i;
    }
    s->keys[s->count] = key;
    s->recs[s->count].c = 0;
    s->count++;
    return s->count - 1;
}
static inline void merge_flush_func_00403FD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00403FD0 */
