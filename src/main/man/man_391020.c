/*
 * main/man: range (4 files, 00391020-003913D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
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

void ActorModel_SwitchBodyPacking(Self391020* self);
void Appearance_RemoveBlankPairs(App391020* app);
int Appearance_GetPairCount(App391020* app);
void Appearance_RequestHardMesh(App391020* app, int hard, char* out);
void TexCache_LoadPartTexture(char* cache, __int128 name, char* tex, short* a, short* b);
int func_004027E0(char* cache, __int128 name);
void func_00403940(char* cache, int slot);
int MeshCache_FindSlot(char* cache, __int128 name);
void func_00404D90(char* cache, int slot);
void Appearance_ReorderParts(Self391020* self);
void ActorModel_Setup(Self391020* self, int flag);
}

extern "C" void func_00391020(Self391020* self)
{
    int i;
    int j;
    int n;

    ActorModel_SwitchBodyPacking(self);
    Appearance_RemoveBlankPairs(&self->app);
    self->x23C0 = Appearance_GetPairCount(&self->app);
    Appearance_RequestHardMesh(&self->app, 1, self->x20);
    for (i = 0; self->app.pairs[i].b; i++) {
        TexCache_LoadPartTexture(g_AgentPartCache, self->app.pairs[i].b, D_005711B0, &self->x22C0[i], &self->x2300[i]);
    }
    self->x22C0[i] = 0;
    n = Appearance_GetPairCount(self->x2C14);
    for (j = 0; j <= n; j++) {
        int s = func_004027E0(g_AgentPartCache, self->x2C14->pairs[j].b);
        if (s != -1) {
            func_00403940(g_AgentPartCache, s);
        }
    }
    for (i = 0; i < n; i++) {
        int s = MeshCache_FindSlot(g_AgentPartCache, self->x2C14->pairs[i].a);
        if (s != -1) {
            func_00404D90(g_AgentPartCache, s);
        }
    }
    {
        App391020* p = self->x2C14;
        AllocGuard g;
        Mem_Free(0, p, D_004BC310, 0x2DA);
    }
    self->x2C14 = 0;
    Appearance_ReorderParts(self);
    ActorModel_Setup(self, 1);
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
void func_0038E030(Self391210* self);
#if 0 /* merge_units */
void ActorModel_Setup(Self391210* self, int flag);
#endif /* merge_units */
#define ActorModel_Setup(a0, a1) (ActorModel_Setup((Self391020 *)(a0), (a1))) /* merge_units */

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

extern "C" void ActorModel_RestoreBodyPacking(Self391210* self)
{
    App391210* s = self->x2C14;
    if (s) {
        QMove_391210(&self->app, s, 0x44);
        {
            App391210* p = self->x2C14;
            AllocGuard g;
            Mem_Free(0, p, D_004BC310, 0x2A8);
        }
        self->x2C14 = 0;
        func_0038E030(self);
        ActorModel_Setup(self, 1);
    }
}
#undef ActorModel_Setup /* merge_units */
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
extern int Morph_FindShapeIndex(char* name, int which);
void Expression_Init(void)
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
    D_0053B340 = Morph_FindShapeIndex("EMO_SHOT", 0);
    D_0053B341 = Morph_FindShapeIndex("EMO_SHOT", 1);
    D_0053B348 = Morph_FindShapeIndex("BLINKBOTH", 0);
    D_0053B349 = Morph_FindShapeIndex("BLINKBOTH", 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00391300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00391300 */

/* merge_units: begin func_003913D0 */
#pragma push /* merge_units */
/* Skel_ApplyScalePreset */
typedef struct { char name[16]; } Pt2_PresetName;
typedef struct { unsigned int count; Pt2_PresetName e[24]; } Pt2_PresetTbl;
typedef struct { float x, y, z, w; } Pt2_Sc;
typedef struct { char pad0[4]; char bones[0x10]; unsigned char hasMorph; char pad15[3]; char morph[4]; } Pt2_Skl;
typedef struct { char pad0[0x40]; char name[0x2BC4]; Pt2_Skl* skel; char pad2C08[8]; unsigned char preset; } Pt2_App;
extern Pt2_PresetTbl D_00571300;
extern Pt2_Sc* D_00571484[];
extern float* func_0028D5F0(void*, int);
extern void* SkelNodes_GetAt(void*, int);
extern void func_0028D580(void*, float);
extern void func_0028D530(void*, float);
extern void func_0028D4E0(void*, float);

int Skel_ApplyScalePreset(Pt2_App* a, int preset) {
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
        func_0028D5F0(k->bones, i)[0] = v;
        if (k->hasMorph) func_0028D580(SkelNodes_GetAt(k->morph, i), v);
        k = a->skel; v = s->y;
        func_0028D5F0(k->bones, i)[1] = v;
        if (k->hasMorph) func_0028D530(SkelNodes_GetAt(k->morph, i), v);
        k = a->skel; v = s->z;
        func_0028D5F0(k->bones, i)[2] = v;
        if (k->hasMorph) func_0028D4E0(SkelNodes_GetAt(k->morph, i), v);
    }
    a->preset = preset;
    return preset;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003913D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003913D0 */
