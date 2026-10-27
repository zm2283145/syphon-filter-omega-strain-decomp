/*
 * main/Loader: range (3 files, 001C30A0-001C3390)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_001C30A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C30A0 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void nGobjManager_AddGOBJ(void* o);
int cPopulation_SeekBlock(PopReader_1C30A0* r, int tag);
void* cNIEventLight_ctor(void* p, PopReader_1C30A0* r);
void cMachine_ShowLoadingScreen(void* a, char* name, int x);
void* GetMachine(void);
}
extern "C" void cLoader_LoadNILights(void* a0, PopReader_1C30A0* r)
{
    if ((unsigned char)cPopulation_SeekBlock(r, 0x3A4C494E)) {
        int n;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            int i;
            int mis;
            cMachine_ShowLoadingScreen(GetMachine(), "Initializing NI Event Lights...", 0);
            for (i = 0; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = cMemMan_Allocate(0, 0x1B0, D_0049EE88, 0x1FE);
                }
                if (p)
                    p = cNIEventLight_ctor(p, r);
                nGobjManager_AddGOBJ(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C30A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C30A0 */

/* merge_units: begin func_001C3210 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C3210 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
#if 0 /* merge_units */
int cPopulation_SeekBlock(PopReader_1C3210* r, int tag);
#endif /* merge_units */
#define cPopulation_SeekBlock(a0, a1) (cPopulation_SeekBlock((PopReader_1C30A0 *)(a0), (a1))) /* merge_units */

void* cNIEventOBJ_ctor(void* p, void* x, PopReader_1C3210* r);
void cNIEventFXTrack_LoadStringTable(PopReader_1C3210* r);
}
extern "C" void cLoader_LoadNIObjs(void* a0, PopReader_1C3210* r, void* x)
{
    cNIEventFXTrack_LoadStringTable(r);
    if ((unsigned char)cPopulation_SeekBlock(r, 0x3A45494E)) {
        int n;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            int i;
            int mis;
            cMachine_ShowLoadingScreen(GetMachine(), "Initializing NI Event Objects...", 0);
            for (i = 0; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = cMemMan_Allocate(0, 0x1C0, D_0049EE88, 0x1DE);
                }
                if (p)
                    p = cNIEventOBJ_ctor(p, x, r);
                nGobjManager_AddGOBJ(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}
#undef cPopulation_SeekBlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C3210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C3210 */

/* merge_units: begin func_001C3390 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C3390 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
#if 0 /* merge_units */
int cPopulation_SeekBlock(PopReader_1C3390* r, int tag);
#endif /* merge_units */
#define cPopulation_SeekBlock(a0, a1) (cPopulation_SeekBlock((PopReader_1C30A0 *)(a0), (a1))) /* merge_units */

void* cSoundGOBJ_ctor(void* p, PopReader_1C3390* r, int flag);
}
extern "C" void cLoader_LoadSoundGOBJs(void* a0, PopReader_1C3390* r)
{
    if ((unsigned char)cPopulation_SeekBlock(r, 0x3A444E53)) {
        int n;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            int i;
            int mis;
            cMachine_ShowLoadingScreen(GetMachine(), "Initializing SoundGOBJs...", 0);
            for (i = 0; i < n; i++) {
                int kind;
                void* p;
                kind = *(int*)r->cur;
                r->cur += 4;
                {
                    AllocGuard g;
                    p = cMemMan_Allocate(0, 0x200, D_0049EE88, 0x1BB);
                }
                if (p)
                    p = cSoundGOBJ_ctor(p, r, kind != 1);
                nGobjManager_AddGOBJ(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}
#undef cPopulation_SeekBlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C3390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C3390 */
