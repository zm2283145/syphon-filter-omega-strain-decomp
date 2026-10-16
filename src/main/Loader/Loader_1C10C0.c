/*
 * main/Loader: range (2 files, 001C10C0-001C12A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_001C10C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C10C0 { int unk0; int size; unsigned int base; char* cur; };
struct Node_1C10C0 { char pad[0x64]; unsigned int flags; };
struct Vec_1C10C0 { int cap; int count; Node_1C10C0** data; };
extern "C" {
extern char D_0049EE88[];
extern Vec_1C10C0* D_004FFBE0;
extern char D_004FFB50[];
void* Mem_Alloc(int pool, int size, char* file, int line);
int Pop_FindTag(PopReader_1C10C0* r, int tag);
Node_1C10C0* Node_Construct(void* p, PopReader_1C10C0* r, int i);
void func_00165E60(void* a, char* name, int x);
void* App_GetInstance(void);
void PtrVector_Resize(Vec_1C10C0* v, int n, void** fill);
void func_0040C940(Node_1C10C0* n);
void World_RegisterNode(void* w, Node_1C10C0* n);
}
#pragma opt_strength_reduction off
extern "C" void Loader_InitNodes(void* a0, PopReader_1C10C0* r)
{
    if (r->cur) {
        int mis;
        func_00165E60(App_GetInstance(), "Initializing Nodes...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)Pop_FindTag(r, 0x3A444F4E)) {
            int n;
            Vec_1C10C0* list;
            int i;
            n = *(int*)r->cur;
            r->cur += 4;
            list = D_004FFBE0;
            if (n) {
                void* z[1];
                z[0] = 0;
                PtrVector_Resize(list, n, z);
            }
            for (i = 0; i < n; i++) {
                Node_1C10C0* p;
                Node_1C10C0** slot = &list->data[i];
                {
                    AllocGuard g;
                    p = (Node_1C10C0*)Mem_Alloc(0, 0x90, D_0049EE88, 0x519);
                }
                if (p)
                    p = Node_Construct(p, r, i);
                *slot = p;
                func_0040C940(list->data[i]);
                Node_1C10C0* q = list->data[i];
                if (q->flags & 0x200)
                    World_RegisterNode(D_004FFB50, q);
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
void Object_Register(void* o);
#if 0 /* merge_units */
int Pop_FindTag(PopReader_1C12A0* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((PopReader_1C10C0 *)(a0), (a1))) /* merge_units */

void* cEnvSettings_ctor(void* p, PopReader_1C12A0* r);
void EnvController_AddEnv(void* list, void** item);
int func_001723F0(void* list);
void** func_00172360(void* list, int i);
void EnvController_ActivateFirst(void* list, void* item);
}
extern "C" void Loader_InitEnvironmentSettings(void* a0, PopReader_1C12A0* r)
{
    int mis;
    int n;
    void* list;
    int i;
    func_00165E60(App_GetInstance(), "Initializing Environment Settings...", 0);
    mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    Pop_FindTag(r, 0x3A564E45);
    n = *(int*)r->cur;
    r->cur += 4;
    list = D_004FFBD4;
    for (i = 0; i < n; i++) {
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, 0xA8, D_0049EE88, 0x4F3);
        }
        if (p)
            p = cEnvSettings_ctor(p, r);
        void* item[1];
        item[0] = p;
        EnvController_AddEnv(list, item);
        Object_Register(p);
    }
    EnvController_ActivateFirst(list, func_001723F0(list) ? 0 : *func_00172360(list, 0));
}
#undef Pop_FindTag /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C12A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C12A0 */
