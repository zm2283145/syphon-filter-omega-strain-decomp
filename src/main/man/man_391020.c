/*
 * main/man: range (4 files, 00391020-003913D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
void *memcpy();
int strcmp(const void *, const void *);

/* merge_units: begin func_00391020 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct Pair391020 {
    __int128 a;
    __int128 b;
};

struct App391020 {
    char pad[0x40];
    Pair391020 pairs[1];
};

struct Self391020 {
    char pad[0x20];
    char x20[0x20];
    App391020 app;
    char padX[0x22C0 - 0x40 - sizeof(App391020)];
    short x22C0[0x20];
    short x2300[0x60];
    short x23C0;
    char pad23C2[0x2C14 - 0x23C2];
    App391020* x2C14;
};

extern "C" {
extern char g_AgentPartCache[];
extern char D_005711B0[];
extern char D_004BC310[];

void cMan_MergeSKLs(Self391020* self);
void SKL_RemoveBlanks(App391020* app);
int SKL_CountAttribs(App391020* app);
void SKL_LoadSKLParts(App391020* app, int hard, char* out);
void Monster_FindAddTexture(char* cache, __int128 name, char* tex, short* a, short* b);
int FindTex__7MonsterF1(char* cache, __int128 name);
void Monster_FreeTexture(char* cache, int slot);
int FindPart__7MonsterF1(char* cache, __int128 name);
void Monster_FreePart(char* cache, int slot);
void cMan_SortParts(Self391020* self);
void cMan_BuildMan(Self391020* self, int flag);
}

extern "C" void cMan_AddDisguise(Self391020* self)
{
    int i;
    int j;
    int n;

    cMan_MergeSKLs(self);
    SKL_RemoveBlanks(&self->app);
    self->x23C0 = SKL_CountAttribs(&self->app);
    SKL_LoadSKLParts(&self->app, 1, self->x20);
    for (i = 0; self->app.pairs[i].b; i++) {
        Monster_FindAddTexture(g_AgentPartCache, self->app.pairs[i].b, D_005711B0, &self->x22C0[i], &self->x2300[i]);
    }
    self->x22C0[i] = 0;
    n = SKL_CountAttribs(self->x2C14);
    for (j = 0; j <= n; j++) {
        int s = FindTex__7MonsterF1(g_AgentPartCache, self->x2C14->pairs[j].b);
        if (s != -1) {
            Monster_FreeTexture(g_AgentPartCache, s);
        }
    }
    for (i = 0; i < n; i++) {
        int s = FindPart__7MonsterF1(g_AgentPartCache, self->x2C14->pairs[i].a);
        if (s != -1) {
            Monster_FreePart(g_AgentPartCache, s);
        }
    }
    {
        App391020* p = self->x2C14;
        AllocGuard g;
        cMemMan_Deallocate(0, p, D_004BC310, 0x2DA);
    }
    self->x2C14 = 0;
    cMan_SortParts(self);
    cMan_BuildMan(self, 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00391020(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00391020 */

/* merge_units: begin func_00391210 */
#pragma push /* merge_units */
#pragma cplusplus on

struct App391210 {
    __int128 q[0x44];
};

struct Self391210 {
    char pad[0x40];
    App391210 app;
    char padX[0x2C14 - 0x40 - sizeof(App391210)];
    App391210* x2C14;
};

extern "C" {
void cMan_GetTextureIDs(Self391210* self);
#if 0 /* merge_units */
void cMan_BuildMan(Self391210* self, int flag);
#endif /* merge_units */
#define cMan_BuildMan(a0, a1) (cMan_BuildMan((Self391020 *)(a0), (a1))) /* merge_units */

}

/* 16-byte block copy loop (lq/sq). */
static inline void QMove_391210(void* d0, void* s, int n0) {
    int n = n0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

extern "C" void cMan_RemoveCostume(Self391210* self)
{
    App391210* s = self->x2C14;
    if (s) {
        QMove_391210(&self->app, s, 0x44);
        {
            App391210* p = self->x2C14;
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BC310, 0x2A8);
        }
        self->x2C14 = 0;
        cMan_GetTextureIDs(self);
        cMan_BuildMan(self, 1);
    }
}
#undef cMan_BuildMan /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00391210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00391210 */

/* merge_units: begin func_00391300 */
#pragma push /* merge_units */
extern int WoundEffectTable[5];
extern unsigned char D_0053B340;
extern unsigned char D_0053B341;
extern unsigned char D_0053B348;
extern unsigned char D_0053B349;
extern int FindFace(char* name, int which);
void cMan_ManInit(void)
{
    int i;
    if (WoundEffectTable[0] == -1) {
        WoundEffectTable[0] = 0;
    }
    for (i = 1; i < 5; i++) {
        if (WoundEffectTable[i] == -1) {
            WoundEffectTable[i] = WoundEffectTable[0];
        }
    }
    D_0053B340 = FindFace("EMO_SHOT", 0);
    D_0053B341 = FindFace("EMO_SHOT", 1);
    D_0053B348 = FindFace("BLINKBOTH", 0);
    D_0053B349 = FindFace("BLINKBOTH", 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00391300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00391300 */

/* merge_units: begin func_003913D0 */
#pragma push /* merge_units */
/* cMan_SetBoneSet */
typedef struct { char name[16]; } Pt2_PresetName;
typedef struct { unsigned int count; Pt2_PresetName e[24]; } Pt2_PresetTbl;
typedef struct { float x, y, z, w; } Pt2_Sc;
typedef struct { char pad0[4]; char bones[0x10]; unsigned char hasMorph; char pad15[3]; char morph[4]; } Pt2_Skl;
typedef struct { char pad0[0x40]; char name[0x2BC4]; Pt2_Skl* skel; char pad2C08[8]; unsigned char preset; } Pt2_App;
extern Pt2_PresetTbl D_00571300;
extern Pt2_Sc* D_00571484[];
extern float* cArray_cBoneScale_opIndex(void*, int);
extern void* cArray_cBone_opIndex_int_2(void*, int);
extern void cBone_SetScaleX(void*, float);
extern void cBone_SetScaleY(void*, float);
extern void cBone_SetScaleZ(void*, float);

int cMan_SetBoneSet(Pt2_App* a, int preset) {
    Pt2_Sc* s;
    int i;
    if (preset < 0) {
        for (preset = 0; (unsigned int)preset < D_00571300.count; preset++) {
            if (!strcmp(a->name, D_00571300.e[preset].name)) break;
        }
        if ((unsigned int)preset >= D_00571300.count) {
            strcmp(a->name, "BONENOSCALE");
            return 0;
        }
    }
    if ((unsigned int)preset >= D_00571300.count) return 0;
    memcpy(a->name, D_00571300.e[preset].name, 0xF);
    s = D_00571484[preset];
    for (i = 0; i < 0x15; i++, s++) {
        Pt2_Skl* k;
        float v;
        k = a->skel; v = s->x;
        cArray_cBoneScale_opIndex(k->bones, i)[0] = v;
        if (k->hasMorph) cBone_SetScaleX(cArray_cBone_opIndex_int_2(k->morph, i), v);
        k = a->skel; v = s->y;
        cArray_cBoneScale_opIndex(k->bones, i)[1] = v;
        if (k->hasMorph) cBone_SetScaleY(cArray_cBone_opIndex_int_2(k->morph, i), v);
        k = a->skel; v = s->z;
        cArray_cBoneScale_opIndex(k->bones, i)[2] = v;
        if (k->hasMorph) cBone_SetScaleZ(cArray_cBone_opIndex_int_2(k->morph, i), v);
    }
    a->preset = preset;
    return preset;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003913D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003913D0 */
