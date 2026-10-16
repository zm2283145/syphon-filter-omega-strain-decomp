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
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C30A0* r, int tag);
void* cNIEventLight_ctor(void* p, PopReader_1C30A0* r);
void func_00165E60(void* a, char* name, int x);
void* App_GetInstance(void);
}
extern "C" void Loader_InitNIEventLights(void* a0, PopReader_1C30A0* r)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A4C494E)) {
        int n;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            int i;
            int mis;
            func_00165E60(App_GetInstance(), "Initializing NI Event Lights...", 0);
            for (i = 0; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 0x1B0, D_0049EE88, 0x1FE);
                }
                if (p)
                    p = cNIEventLight_ctor(p, r);
                Object_Register(p);
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
int Pop_FindTag(PopReader_1C3210* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((PopReader_1C30A0 *)(a0), (a1))) /* merge_units */

void* cNIEventOBJ_ctor(void* p, void* x, PopReader_1C3210* r);
void func_002390A0(PopReader_1C3210* r);
}
extern "C" void Loader_InitNIEventObjects(void* a0, PopReader_1C3210* r, void* x)
{
    func_002390A0(r);
    if ((unsigned char)Pop_FindTag(r, 0x3A45494E)) {
        int n;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            int i;
            int mis;
            func_00165E60(App_GetInstance(), "Initializing NI Event Objects...", 0);
            for (i = 0; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 0x1C0, D_0049EE88, 0x1DE);
                }
                if (p)
                    p = cNIEventOBJ_ctor(p, x, r);
                Object_Register(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}
#undef Pop_FindTag /* merge_units */
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
int Pop_FindTag(PopReader_1C3390* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((PopReader_1C30A0 *)(a0), (a1))) /* merge_units */

void* cSoundGOBJ_ctor(void* p, PopReader_1C3390* r, int flag);
}
extern "C" void Loader_InitSoundGOBJs(void* a0, PopReader_1C3390* r)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A444E53)) {
        int n;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            int i;
            int mis;
            func_00165E60(App_GetInstance(), "Initializing SoundGOBJs...", 0);
            for (i = 0; i < n; i++) {
                int kind;
                void* p;
                kind = *(int*)r->cur;
                r->cur += 4;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 0x200, D_0049EE88, 0x1BB);
                }
                if (p)
                    p = cSoundGOBJ_ctor(p, r, kind != 1);
                Object_Register(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}
#undef Pop_FindTag /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C3390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C3390 */
