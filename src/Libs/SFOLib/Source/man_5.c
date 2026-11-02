/*
 * Libs/SFOLib/Source/man: 4 files, 0038D720-0038DD40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0038D720 */
#pragma push /* merge_units */
/* 0038D720 gunList::GunCalcBBox() - SFOLib man.cc */
#pragma cplusplus on
#include "types.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct cVector {
    float x, y, z, w;
    cVector& operator=(const cVector& v)
    {
        void* xx = this;
        u_long128 t;
        __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(t) : "r"(this), "r"(&v) : "memory");
        return *this;
    }
};

struct cMatrix {
    cVector m[4];
    void Unit()
    {
        char* xx = (char*)this;
        int t;
        cMatrix* p = this;
        asm {
            sqc2 vf0, 0x30(p)
            qmfc2.ni t, vf0
            pcpyud t, t, zero
            sq t, 0x10(p)
            pexcw t, t
            sq t, 0x20(p)
            pcpyud t, t, zero
            sq t, 0(p)
        }
    }
    void SetTrans(const cVector& v) { m[3] = v; }

};

typedef struct { unsigned char qwc; unsigned char vertCount; } manRefs;

typedef struct {
    u_long128* part;
    unsigned short qwc;
    unsigned char type;
    unsigned char patchCount;
    manRefs* Refs;
    unsigned int* blends;
} Parts;

typedef struct {
    cVector pos;
    cVector offset;
} gunBones;

typedef struct {
    cVector min;
    cVector max;
    void Extend(const cVector& v)
    {
        cVector* mn = &min;
        cVector* mx = &max;
        const cVector* p = &v;
        asm {
            lqc2 vf1, 0(mn)
            lqc2 vf2, 0(mx)
            lqc2 vf3, 0(p)
            vmini.xyz vf1, vf1, vf3
            vmax.xyz vf2, vf2, vf3
            sqc2 vf1, 0(mn)
            sqc2 vf2, 0(mx)
        }
    }
} cBox;

typedef struct {
    char gunName[32];
    char gunAttribsTable[0x100];
    gunBones gunBulletOffset;
    gunBones gunBonesOffsets[12];
    Parts gunParts[2][8];
    short gunTexID[8];
    short gunTexID2[8];
    cBox gunBBox;
    char* gunHog;
    u_long128* casingModelPart;
    unsigned short casingModelqwc;
    short gunWDBIndex;
    unsigned char gunPartCount;
    unsigned char gunHoldType;
    unsigned char gunHoldTypeHand2;
    unsigned char gunAnimType;
    signed char gunHolsterPart;
    signed char gunFlarePart;
    signed char gunLightPart;
    signed char gunStockPartOn;
    signed char gunStockPartOff;
} gunList;

extern "C" {
extern int D_00542D40;
extern int D_00542D48;
extern unsigned int D_004937C0[];
extern unsigned int D_004937D0[];
}

static inline void VecAdd(cVector* d, const cVector* a, const cVector* b)
{
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(d)
    }
}

static inline void WaitVif0(void)
{
    int a, b, c;
    while (*(volatile int*)0x10008000 & 0x100) {
        a = 7;
        b = 7;
        asm { div c, a, b }
    }
    for (c = *(volatile int*)0x10003800; c & 7; c = *(volatile int*)0x10003800) {
        __asm__ volatile("vnop");
        __asm__ volatile("sync");
    }
    __asm__ volatile("vnop");
    __asm__ volatile("sync");
}

/* VU1 output gather; a separate inline gives n/src/dst their own regs */
static inline void CopyVerts(u_long128* dst, u_long128* src, int n)
{
    while (n) {
        *dst = *src;
        n--;
        src += 2;
        dst++;
    }
}

extern "C" void gunList_GunCalcBBox(gunList* self)
{
    int bone;
    u_long128* bonesSrc;
    cMatrix* bonesMat;
    cVector offset;
    u_long128* boneDest;
    cVector* results;
    cVector* results1;
    manRefs* refData;
    unsigned int patchCount;
    unsigned int j;
    int qwc;
    int vertCount;
    int nextVertCount;
    u_long128* part;
    unsigned int i;
    unsigned int k;

    bonesMat = (cMatrix*)0x70000000;
    {
        int idx = D_00542D40;
        if (idx != D_00542D48) {
            unsigned int end = D_004937D0[idx];
            unsigned int start = D_004937C0[idx];
            *(volatile int*)0x10008020 = (end - start) >> 4;
            *(volatile int*)0x10008010 = start;
            *(volatile int*)0x10008000 = 0x101;
            __asm__ volatile("sync");
            D_00542D48 = idx;
        }
    }
    offset = self->gunBonesOffsets[0].offset;
    offset.w = 1.0f;
    bonesMat->Unit();
    bonesMat->SetTrans(offset);
    for (bone = 0; bone < 11; bone++) {
        offset = self->gunBonesOffsets[bone].offset;
        VecAdd(&offset, &offset, &self->gunBonesOffsets[((int*)self->gunBonesOffsets)[bone * 8 + 7]].offset);
        offset.w = 1.0f;
        bonesMat[bone].Unit();
        bonesMat[bone].SetTrans(offset);
    }
    WaitVif0();
    bonesSrc = (u_long128*)bonesMat;
    boneDest = (u_long128*)0x11004AC0;
    for (bone = 0; bone < 11; bone++) {
        boneDest[0] = bonesSrc[0];
        boneDest[1] = bonesSrc[1];
        boneDest[2] = bonesSrc[2];
        boneDest[3] = bonesSrc[3];
        bonesSrc += 4;
        boneDest += 4;
    }
    results = (cVector*)0x70000540;
    for (j = 0; j < self->gunPartCount; j++) {
        refData = self->gunParts[1][j].Refs;
        patchCount = self->gunParts[1][j].patchCount;
        part = self->gunParts[1][j].part;
        refData++;
        if (j == self->gunHolsterPart || j == self->gunFlarePart || j == self->gunLightPart ||
            j == self->gunStockPartOff)
            continue;
        if (part) {
            for (i = 0; i < patchCount; i++) {
                qwc = refData->qwc;
                vertCount = refData->vertCount;
                *(volatile int*)0x10008020 = qwc;
                *(volatile int*)0x10008010 = (int)part;
                *(volatile int*)0x10008000 = 0x101;
                __asm__ volatile("sync");
                part += qwc;
                refData++;
                WaitVif0();
                CopyVerts((u_long128*)results, (u_long128*)0x11004050, vertCount);
                for (k = 0; k < vertCount; k++) {
                    self->gunBBox.Extend(results[k]);
                }
            }
        }
    }
}
static inline void merge_flush_func_0038D720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038D720 */

/* merge_units: begin func_0038DB30 */
#pragma push /* merge_units */
#pragma cplusplus on

struct manAttribs {
    __int128 a;
    __int128 b;
};

struct SKL {
    __int128 hdr[4];
    manAttribs manAttribsTable[32];
};

struct cMan {
    char pad0[0x20];
    char SKLName[0x20];
    SKL skl;
    char pad480[0x22C0 - 0x480];
    short tex[0x20];
    short tex2[0x60];
    unsigned short count;
    char pad23C2[0x2BD0 - 0x23C2];
    int faceCamo;
    char pad2BD4[0x2C0D - 0x2BD4];
    char race;
};

extern "C" {
extern char g_AgentPartCache[];
extern char D_005711B0[];
extern char D_004BC398[];
extern char D_004BC3A0[];
void strCpyPad(char* dst, int n, char* src);
#if 0 /* merge_units */
char* Libc_Strcpy(char* dst, const char* src);
#endif /* merge_units */
char* Libc_Strcpy(void* dst, const void* src); /* merge_units */
#define Libc_Strcpy(a0, a1) (Libc_Strcpy((void *)(a0), (const void *)(a1))) /* merge_units */

int String_CompareNoCase(const char* a, const char* b);
char SKL_FindRace(SKL* skl);
int SKL_CountAttribs(SKL* skl);
void SKL_AddAccessorySKL(SKL* skl, int identity, int count, char* name);
void SKL_RemoveBlanks(SKL* skl);
int SKL_LoadSKLParts(SKL* skl, int hard, char* name);
void Monster_FindAddTexture(char* cache, __int128 name, char* tex, short* a, short* b);
void cMan_SortParts(cMan* self);
void cMan_BuildMan(cMan* self, int flag);
}

/* skl = *sklData quad copy loop (hand-written addi); GCC-style operands also put mwcc in the
   no-global-CSE/no-loop-opt mode retail shows (loop tests and bodies reload separately) */
static inline void QMove(void* dd, void* ss, int nn) { int n = nn; __int128 q; void* s = ss; void* d = dd;
    __asm__ volatile(".set noreorder; nop; 1: lq %0, 0(%2); addiu %1, %1, 0x10; addi %3, %3, -1; addiu %2, %2, 0x10; bgtz %3, 1b; sq %0, -0x10(%1); .set reorder" : "=&r"(q), "+r"(d), "+r"(s), "+r"(n) : : "memory");
}

extern "C" void cMan_Load(cMan* self, char* name, SKL* sklData, int identity)
{
    int count;
    int texParts;
    if (sklData) QMove(&self->skl, sklData, sizeof(SKL) / 16);
    if (name) strCpyPad(self->SKLName, 31, name);
    else Libc_Strcpy(self->SKLName, D_004BC398);
    for (char* p = self->SKLName; *p; p++) {
        char c = *p; if (c >= 'a' && c <= 'z') *p = c - 32;
    }
    self->race = SKL_FindRace(&self->skl);
    if (identity >= 0) {
        self->count = SKL_CountAttribs(&self->skl);
        if (String_CompareNoCase(name, D_004BC3A0)) {
            SKL_AddAccessorySKL(&self->skl, identity, self->count, self->SKLName);
        } else {
            count = self->count;
            self->skl.manAttribsTable[0] = self->skl.manAttribsTable[count];
            count++; self->skl.manAttribsTable[1] = self->skl.manAttribsTable[count];
            self->count = 0;
        }
    } else {
        SKL_RemoveBlanks(&self->skl);
    }
    cMan_SortParts(self);
    for (texParts = 0; self->skl.manAttribsTable[texParts].b; texParts++) {
        Monster_FindAddTexture(g_AgentPartCache, self->skl.manAttribsTable[texParts].b, D_005711B0, &self->tex[texParts], &self->tex2[texParts]);
    }
    self->tex[texParts] = 0;
    self->count = SKL_LoadSKLParts(&self->skl, 1, self->SKLName);
    if (self->count < texParts) self->faceCamo = 1;
    cMan_BuildMan(self, 1);
}
#undef Libc_Strcpy /* merge_units */
static inline void merge_flush_func_0038DB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038DB30 */

/* merge_units: begin func_0038DD40 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"

#if 0 /* merge_units */
extern void Monster_FindAddTexture(void* cache, __int128 name, int arg, short* slot, short* out);
#endif /* merge_units */
#define Monster_FindAddTexture(a0, a1, a2, a3, a4) (Monster_FindAddTexture((char *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

char D_00493410[16] = "_THER_BLA_----0";
char D_00493420[16] = "_THER_COO_----0";
char D_00493430[16] = "_THER_WAR_----0";
char D_00493440[16] = "_THER_HOT_----0";
char D_00493450[16] = "_THER_FLA_----0";
extern short D_0053B360;
extern short D_0053B362;
extern short D_0053B364;
extern short D_0053B366;
extern short D_0053B368;
#pragma opt_propagation off
void cMan_LoadIRTextures(int arg)
{
    short tmp;
    __int128* p;
    p = (__int128*)D_00493410;
    Monster_FindAddTexture(g_AgentPartCache, *p, arg, &D_0053B360, &tmp);
    p = (__int128*)D_00493420;
    Monster_FindAddTexture(g_AgentPartCache, *p, arg, &D_0053B362, &tmp);
    p = (__int128*)D_00493430;
    Monster_FindAddTexture(g_AgentPartCache, *p, arg, &D_0053B364, &tmp);
    Monster_FindAddTexture(g_AgentPartCache, *(__int128*)D_00493440, arg, &D_0053B366, &tmp);
    Monster_FindAddTexture(g_AgentPartCache, *(__int128*)D_00493450, arg, &D_0053B368, &tmp);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038DD40(void) {}
#undef Monster_FindAddTexture /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038DD40 */

/* merge_units: begin func_0038DE20 */
#pragma push /* merge_units */
extern char D_004BC3B0[];
extern unsigned int D_005712F0[];
extern __int128* D_005712F8[];
static inline int ks0038DE20eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 ks0038DE20and(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 ks0038DE20from(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline int ks0038DE20meq(__int128 m, __int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pand t, m, a
        pand b, m, b
        pceqw t, t, b
        ppach r, t, t
    }
    return r == -1;
}
int cMan_CountFaceShapes(int idx)
{
    __int128 mask = ks0038DE20from(0xFFFFFFFFFFFFLL);
    __int128 key;
    __int128* e;
    unsigned int i;
    int n;
    Libc_Strcpy(&key, D_004BC3B0);
    e = D_005712F8[idx];
    n = 0;
    for (i = 0; i < D_005712F0[idx]; i++) {
        if (ks0038DE20meq(mask, key, e[i]))
            n++;
    }
    return n;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038DE20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038DE20 */
