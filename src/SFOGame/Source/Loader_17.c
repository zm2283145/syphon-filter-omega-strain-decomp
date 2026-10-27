/*
 * SFOGame/Source/Loader: 4 files, 001C29F0-001C2A10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C29F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

/* Zero-initialise a three-word vector. */
Rel* std_vector_cObjectId_ctor_void(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_001C29F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C29F0 */

/* merge_units: begin func_001C2A10 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

typedef struct { int unk0; int size; unsigned int base; char* cur; } PopReader_1C2A10;
extern int cPopulation_SeekBlock(PopReader_1C2A10* r, int tag);
extern void cMachine_ShowLoadingScreen(void* a, char* name, int x);
extern void* GetMachine(void);
extern void cBackpack_NewBackpack_cPopulationR(PopReader_1C2A10* r);
void cLoader_LoadWeaponCrates(void* a0, PopReader_1C2A10* r)
{
    if ((unsigned char)cPopulation_SeekBlock(r, 0x3A564E49)) {
        int n;
        int i;
        int mis;
        n = *(int*)r->cur;
        r->cur += 4;
        cMachine_ShowLoadingScreen(GetMachine(), "Loading Inventory defs...", 0);
        for (i = 0; i < n; i++)
            cBackpack_NewBackpack_cPopulationR(r);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C2A10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C2A10 */

/* merge_units: begin func_001C2AE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C2AE0 { int version; int size; unsigned int base; char* cur; };
struct Ctl_1C2AE0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad[0x3C];
    char region[0x10];
    unsigned char dirty;
};
struct Gen_1C2AE0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void Attach(int x);
    char pad[0x4C];
    Ctl_1C2AE0* ctl;
};
extern "C" {
extern char D_0049EE88[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void nGobjManager_AddGOBJ(void* o);
#if 0 /* merge_units */
int cPopulation_SeekBlock(PopReader_1C2AE0* r, int tag);
#endif /* merge_units */
#define cPopulation_SeekBlock(a0, a1) (cPopulation_SeekBlock((PopReader_1C2A10 *)(a0), (a1))) /* merge_units */


Gen_1C2AE0* cGenerator_ctor(void* p, PopReader_1C2AE0* r);
void cMachine_ShowLoadingScreen(void* a, char* name, int x);
void* GetMachine(void);
void* nActivation_GetClosestTerrainPiece(void* region);
void cTerrain_AddActivation(void* reg, Gen_1C2AE0* g, int a, int b);
}
extern "C" void cLoader_LoadGenerators(void* a0, PopReader_1C2AE0* r)
{
    if ((unsigned char)cPopulation_SeekBlock(r, 0x3A4E4547)) {
        int n;
        int i;
        int mis;
        n = *(int*)r->cur;
        r->cur += 4;
        cMachine_ShowLoadingScreen(GetMachine(), "Loading Generator defs...", 0);
        for (i = 0; i < n; i++) {
            Gen_1C2AE0* p;
            {
                AllocGuard g;
                p = (Gen_1C2AE0*)cMemMan_Allocate(0, 0xD4, D_0049EE88, 0x250);
            }
            if (p)
                p = cGenerator_ctor(p, r);
            nGobjManager_AddGOBJ(p);
            if (r->version < 0x32) {
                Ctl_1C2AE0* c = p->ctl;
                void* reg;
                if (c->dirty)
                    c->Refresh();
                reg = nActivation_GetClosestTerrainPiece(c->region);
                if (reg)
                    cTerrain_AddActivation(reg, p, 1, 0);
                else
                    p->Attach(1);
            }
        }
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C2AE0(void) {}
#undef cPopulation_SeekBlock /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C2AE0 */

/* merge_units: begin func_001C2CB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C2CB0 { int version; int size; unsigned int base; char* cur; };
struct TerList_1C2CB0 { int a, b, c; unsigned char d; };
struct Ter_1C2CB0 { char pad[0x1C]; void* reg; };
struct Level_1C2CB0 { char pad[0xC]; TerList_1C2CB0* ters; };
extern "C" {
extern char D_0049F018[];
extern char D_0048B2F8[];
extern char g_LevelDirName[];
extern void* D_004FFD48;
#if 0 /* merge_units */
int cPopulation_SeekBlock(PopReader_1C2CB0* r, int tag);
#endif /* merge_units */
#define cPopulation_SeekBlock(a0, a1) (cPopulation_SeekBlock((PopReader_1C2A10 *)(a0), (a1))) /* merge_units */


int cHogList_Open(void* a, char* name, int b, int c);
void std_vector_cTerrainPtr_ctor(TerList_1C2CB0* l);
Ter_1C2CB0* cTerrain_ctor(void* p, PopReader_1C2CB0* r, void* a1, int h);
void cBaseObjList_Add(void* reg, Ter_1C2CB0* t);
void std_vector_cTerrainPtr_push_back(TerList_1C2CB0* l, Ter_1C2CB0** item);
}
extern "C" void cLoader_LoadVUMs(Level_1C2CB0* l, void* a1, PopReader_1C2CB0* r, void* arc)
{
    if ((unsigned char)cPopulation_SeekBlock(r, 0x3A524554)) {
        Ter_1C2CB0* item[1];
        int n;
        char name[128];
        int h;
        TerList_1C2CB0* list;
        int i;
        int mis;
        n = *(int*)r->cur;
        r->cur += 4;
        cMachine_ShowLoadingScreen(GetMachine(), "Initializing Terrain Data...", 0);
        sprintf(name, D_0049F018, D_0048B2F8, g_LevelDirName, g_LevelDirName);
        h = cHogList_Open(arc, name, 0, 0);
        {
            AllocGuard g;
            list = (TerList_1C2CB0*)cMemMan_Allocate(0, 0x10, D_0049EE88, 0x230);
        }
        if (list) {
            std_vector_cTerrainPtr_ctor(list);
            list->d = 1;
        }
        l->ters = list;
        for (i = 0; i < n; i++) {
            Ter_1C2CB0* t;
            {
                AllocGuard g;
                t = (Ter_1C2CB0*)cMemMan_Allocate(0, 0x260, D_0049EE88, 0x233);
            }
            if (t)
                t = cTerrain_ctor(t, r, a1, h);
            item[0] = t;
            void* reg = D_004FFD48;
            t->reg = reg;
            cBaseObjList_Add(reg, t);
            std_vector_cTerrainPtr_push_back(l->ters, item);
        }
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C2CB0(void) {}
#undef cPopulation_SeekBlock /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C2CB0 */
