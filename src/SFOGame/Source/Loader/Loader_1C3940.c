/*
 * main/Loader: range (2 files, 001C3940-001C3B00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001C3940 */
#pragma push /* merge_units */
typedef struct { int unk0; int size; unsigned int base; char* cur; } PopReader_1C3940;
extern char D_0048B2F8[];
extern char D_0049F030[];
extern char g_LevelDirName[];
extern void cMachine_ShowLoadingScreen(void* a, char* name, int x);
extern void* GetMachine(void);
extern int cHogList_Open(void* a, char* name, int b, int c);
extern void cLoader_LoadVUMs(void* l, void* a1, PopReader_1C3940* r, void* arc);
extern void cLoader_LoadActivation(void* l, PopReader_1C3940* r);
extern void cLoader_LoadNodes(void* l, PopReader_1C3940* r);
extern void cLoader_LoadSoundGOBJs(void* l, PopReader_1C3940* r, void* arc);
extern void cLoader_LoadGOBJs(void* l, PopReader_1C3940* r, int h);
extern void cLoader_LoadSKMs(void* l, PopReader_1C3940* r, void* arc);
extern void cLoader_LoadPARs(void* l, PopReader_1C3940* r, void* arc);
extern void cLoader_LoadSKY(void* l, void* a1, PopReader_1C3940* r, void* arc);
extern void cLoader_LoadNIEvents(void* l, PopReader_1C3940* r, int h);
void cLoader_LoadModels(void* l, void* a1, PopReader_1C3940* r, void* arc)
{
    if (r->cur) {
        char name[128];
        int h;
        int mis;
        sprintf(name, "%s\\%s\\OBJECTS.HOG", D_0048B2F8, g_LevelDirName, g_LevelDirName);
        h = cHogList_Open(arc, name, 1, 0);
        cMachine_ShowLoadingScreen(GetMachine(), "Initializing Terrain and GOBJ's...", 0);
        cLoader_LoadVUMs(l, a1, r, arc);
        cLoader_LoadActivation(l, r);
        cLoader_LoadNodes(l, r);
        cLoader_LoadSoundGOBJs(l, r, arc);
        cLoader_LoadGOBJs(l, r, h);
        cMachine_ShowLoadingScreen(GetMachine(), "Loading Character Models...", 0);
        cLoader_LoadSKMs(l, r, arc);
        cMachine_ShowLoadingScreen(GetMachine(), D_0049F030, 0);
        cLoader_LoadPARs(l, r, arc);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        cMachine_ShowLoadingScreen(GetMachine(), "Loading Skybox...", 0);
        cLoader_LoadSKY(l, a1, r, arc);
        cLoader_LoadNIEvents(l, r, h);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C3940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C3940 */

/* merge_units: begin func_001C3B00 */
#pragma push /* merge_units */
typedef struct { int cap; int count; void** data; } Vec_1C3B00;
typedef struct { char pad[0x10]; Vec_1C3B00* vec; } Obj_1C3B00;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_0049EE88[];
extern void Alloc_Lock(int n);
extern void EnableIntc(int n);
extern void** std_vector_charPtr_back(Vec_1C3B00* v);
extern void cTimerDisable_ctor(int* g);
extern void cTimerDisable_dtor(int* g, int f);
extern void cArray_charPtr_dtor_void(Vec_1C3B00* v, int f);
void cLoader_DeallocateAllAnimationBuffers(Obj_1C3B00* o)
{
    Vec_1C3B00* v = o->vec;
    if (v) {
        int g[2];
        while (v->count) {
            void* p = *std_vector_charPtr_back(v);
            if (g_ProfileLockEnabled)
                Alloc_Lock(9);
            g_ProfileLockDepth++;
            cMemMan_Deallocate(0, p, D_0049EE88, 0x10D);
            if (g_ProfileLockEnabled)
                EnableIntc(9);
            g_ProfileLockDepth--;
            o->vec->count--;
            v = o->vec;
        }
        cTimerDisable_ctor(g);
        cArray_charPtr_dtor_void(v, -1);
        cMemMan_Deallocate(0, v, D_0049EE88, 0x111);
        cTimerDisable_dtor(g, -1);
        o->vec = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C3B00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C3B00 */
