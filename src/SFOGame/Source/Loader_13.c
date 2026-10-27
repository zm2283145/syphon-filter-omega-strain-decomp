/*
 * SFOGame/Source/Loader: 3 files, 001C1080-001C10C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C1080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* v.push_back(value): insert one copy at end(). */
int std_vector_int_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

/* Zero-initialise a three-word vector. */
Rel* std_vector_int_ctor_void(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_001C1080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C1080 */

/* merge_units: begin func_001C10C0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

#pragma cplusplus on
struct PopReader_1C10C0 { int unk0; int size; unsigned int base; char* cur; };
struct Node_1C10C0 { char pad[0x64]; unsigned int flags; };
struct Vec_1C10C0 { int cap; int count; Node_1C10C0** data; };
extern "C" {
extern char D_0049EE88[];
extern Vec_1C10C0* D_004FFBE0;
extern char g_Game[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
int cPopulation_SeekBlock(PopReader_1C10C0* r, int tag);
Node_1C10C0* cNode_ctor_cPopulationR_int(void* p, PopReader_1C10C0* r, int i);
void cMachine_ShowLoadingScreen(void* a, char* name, int x);
void* GetMachine(void);
void std_vector_pod_int_resize(Vec_1C10C0* v, int n, void** fill);
void nGobjManager_AddNode(Node_1C10C0* n);
void cGameSystem_AddTeleport(void* w, Node_1C10C0* n);
}
#pragma opt_strength_reduction off
extern "C" void cLoader_LoadNodes(void* a0, PopReader_1C10C0* r)
{
    if (r->cur) {
        int mis;
        cMachine_ShowLoadingScreen(GetMachine(), "Initializing Nodes...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)cPopulation_SeekBlock(r, 0x3A444F4E)) {
            int n;
            Vec_1C10C0* list;
            int i;
            n = *(int*)r->cur;
            r->cur += 4;
            list = D_004FFBE0;
            if (n) {
                void* z[1];
                z[0] = 0;
                std_vector_pod_int_resize(list, n, z);
            }
            for (i = 0; i < n; i++) {
                Node_1C10C0* p;
                Node_1C10C0** slot = &list->data[i];
                {
                    AllocGuard g;
                    p = (Node_1C10C0*)cMemMan_Allocate(0, 0x90, D_0049EE88, 0x519);
                }
                if (p)
                    p = cNode_ctor_cPopulationR_int(p, r, i);
                *slot = p;
                nGobjManager_AddNode(list->data[i]);
                Node_1C10C0* q = list->data[i];
                if (q->flags & 0x200)
                    cGameSystem_AddTeleport(g_Game, q);
            }
        }
    }
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C10C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C10C0 */

/* merge_units: begin func_001C12A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C12A0 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
extern void* D_004FFBD4;
void nGobjManager_AddGOBJ(void* o);
#if 0 /* merge_units */
int cPopulation_SeekBlock(PopReader_1C12A0* r, int tag);
#endif /* merge_units */
#define cPopulation_SeekBlock(a0, a1) (cPopulation_SeekBlock((PopReader_1C10C0 *)(a0), (a1))) /* merge_units */


void* cEnvSettings_ctor(void* p, PopReader_1C12A0* r);
void cLList_cEnvSettingsPtr_PushBackActual(void* list, void** item);
int cLList_cEnvSettingsPtr_Empty(void* list);
void** cLList_cEnvSettingsPtr_opIndex(void* list, int i);
void cEnvMan_SetCurrent(void* list, void* item);
}
extern "C" void cLoader_LoadEnvSettings(void* a0, PopReader_1C12A0* r)
{
    int mis;
    int n;
    void* list;
    int i;
    cMachine_ShowLoadingScreen(GetMachine(), "Initializing Environment Settings...", 0);
    mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    cPopulation_SeekBlock(r, 0x3A564E45);
    n = *(int*)r->cur;
    r->cur += 4;
    list = D_004FFBD4;
    for (i = 0; i < n; i++) {
        void* p;
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, 0xA8, D_0049EE88, 0x4F3);
        }
        if (p)
            p = cEnvSettings_ctor(p, r);
        void* item[1];
        item[0] = p;
        cLList_cEnvSettingsPtr_PushBackActual(list, item);
        nGobjManager_AddGOBJ(p);
    }
    cEnvMan_SetCurrent(list, cLList_cEnvSettingsPtr_Empty(list) ? 0 : *cLList_cEnvSettingsPtr_opIndex(list, 0));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C12A0(void) {}
#undef cPopulation_SeekBlock /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C12A0 */
