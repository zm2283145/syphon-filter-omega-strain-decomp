/*
 * main/Loader: range (2 files, 001C3940-001C3B00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001C3940 */
#pragma push /* merge_units */
typedef struct { int unk0; int size; unsigned int base; char* cur; } PopReader_1C3940;
extern char D_0048B2F8[];
extern char D_0049F030[];
extern char g_LevelDirName[];
extern void Loader_UpdateLoadingScreen(void* a, char* name, int x);
extern void* App_GetInstance(void);
extern int Archive_Open(void* a, char* name, int b, int c);
extern void Pop_LoadTER(void* l, void* a1, PopReader_1C3940* r, void* arc);
extern void Loader_InitActivationMap(void* l, PopReader_1C3940* r);
extern void Loader_InitNodes(void* l, PopReader_1C3940* r);
extern void Loader_InitSoundGOBJs(void* l, PopReader_1C3940* r, void* arc);
extern void Pop_LoadGOB(void* l, PopReader_1C3940* r, int h);
extern void Pop_LoadNPC(void* l, PopReader_1C3940* r, void* arc);
extern void Loader_LoadParticles(void* l, PopReader_1C3940* r, void* arc);
extern void Loader_InitSkybox(void* l, void* a1, PopReader_1C3940* r, void* arc);
extern void Loader_InitNIEvents(void* l, PopReader_1C3940* r, int h);
void Pop_LoadMissionSections(void* l, void* a1, PopReader_1C3940* r, void* arc)
{
    if (r->cur) {
        char name[128];
        int h;
        int mis;
        sprintf(name, "%s\\%s\\OBJECTS.HOG", D_0048B2F8, g_LevelDirName, g_LevelDirName);
        h = Archive_Open(arc, name, 1, 0);
        Loader_UpdateLoadingScreen(App_GetInstance(), "Initializing Terrain and GOBJ's...", 0);
        Pop_LoadTER(l, a1, r, arc);
        Loader_InitActivationMap(l, r);
        Loader_InitNodes(l, r);
        Loader_InitSoundGOBJs(l, r, arc);
        Pop_LoadGOB(l, r, h);
        Loader_UpdateLoadingScreen(App_GetInstance(), "Loading Character Models...", 0);
        Pop_LoadNPC(l, r, arc);
        Loader_UpdateLoadingScreen(App_GetInstance(), D_0049F030, 0);
        Loader_LoadParticles(l, r, arc);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        Loader_UpdateLoadingScreen(App_GetInstance(), "Loading Skybox...", 0);
        Loader_InitSkybox(l, a1, r, arc);
        Loader_InitNIEvents(l, r, h);
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
extern void Alloc_Unlock(int n);
extern void** PtrVec_Back_1C3C30(Vec_1C3B00* v);
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int f);
extern void func_001454E0(Vec_1C3B00* v, int f);
void func_001C3B00(Obj_1C3B00* o)
{
    Vec_1C3B00* v = o->vec;
    if (v) {
        int g[2];
        while (v->count) {
            void* p = *PtrVec_Back_1C3C30(v);
            if (g_ProfileLockEnabled)
                Alloc_Lock(9);
            g_ProfileLockDepth++;
            Mem_Free(0, p, D_0049EE88, 0x10D);
            if (g_ProfileLockEnabled)
                Alloc_Unlock(9);
            g_ProfileLockDepth--;
            o->vec->count--;
            v = o->vec;
        }
        func_00136DA0(g);
        func_001454E0(v, -1);
        Mem_Free(0, v, D_0049EE88, 0x111);
        func_0012F530(g, -1);
        o->vec = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C3B00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C3B00 */
