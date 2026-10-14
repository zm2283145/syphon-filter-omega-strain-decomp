/*
 * main/Loader: range (2 files, 001C3E90-001C4000)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "canonical_key_copy.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_001C3E90 */
#pragma push /* merge_units */
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Key_1C3E90;
typedef struct { char pad[0x24]; int tree; } Map_1C3E90;
typedef struct { char pad[0xC]; Map_1C3E90* second; } Val_1C3E90;
typedef struct { char pad[0xC]; Val_1C3E90 v; } Node_1C3E90;
typedef struct { Node_1C3E90* n; } It_1C3E90;
extern char D_004FFBC0[];
extern void func_00130B00(It_1C3E90* out, void* tree);
extern void func_001C00C0(It_1C3E90* out, int tree);
extern void Tree_Successor(It_1C3E90* it);
extern void ModelCtx_FindNodeById(It_1C3E90* out, int* tree, Key_1C3E90* key);
extern void NodeMap_End(It_1C3E90* out, int* tree);
extern int NodeMapIter_NotEqual(It_1C3E90* a, It_1C3E90* b);
static inline unsigned char EqB_1C3E90(void* a, void* b) { return a == b; }
static inline int Eq_1C3E90(void* a, void* b) { return a == b; }
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
unsigned char SkaRegistry_AllModelsHaveKey(void* mgr, char* name)
{
    It_1C3E90 it;
    It_1C3E90 end;
    It_1C3E90 b;
    It_1C3E90 e;
    It_1C3E90 f;
    It_1C3E90 g;
    Key_1C3E90 key;
    unsigned char ok = 1;
    func_00130B00(&b, D_004FFBC0);
    it.n = b.n;
    func_001C00C0(&e, (int)D_004FFBC0);
    end.n = e.n;
    while ((Eq_1C3E90(it.n, end.n) != 0) ^ 1) {
        Val_1C3E90* v = &it.n->v;
        Map_1C3E90** pm = &v->second;
        Map_1C3E90* m;
        CANONICAL_KEY_INIT_IX(key.c, name)
        m = *pm;
        ModelCtx_FindNodeById(&f, &m->tree, &key);
        NodeMap_End(&g, &m->tree);
        if (!NodeMapIter_NotEqual(&f, &g)) { ok = 0; break; }
        Tree_Successor(&it);
    }
    return ok;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C3E90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C3E90 */

/* merge_units: begin func_001C4000 */
#pragma push /* merge_units */
typedef struct { int* p; } It_1C4000;
typedef struct { int cap; int count; int* data; } Vec_1C4000;
typedef struct { char pad[0xC]; Vec_1C4000* vec; } Obj_1C4000;
extern char D_0049EE88[];
extern int* func_001C4180(Vec_1C4000* v);
extern int* func_001C4150(Vec_1C4000* v);
extern void func_001C4170(It_1C4000* out, Vec_1C4000* v, int** src);
extern void Terrain_ResolveIdList(int id);
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int f);
extern void func_001C40F0(Vec_1C4000* v, int f);
void Pop_FinalizeTerrainList(Obj_1C4000* o)
{
    It_1C4000 it;
    It_1C4000 end;
    int* tb;
    int* te;
    int g[1];
    Vec_1C4000* v;
    int* p;
    int* e;
    v = o->vec;
    tb = func_001C4180(v);
    func_001C4170(&it, v, &tb);
    v = o->vec;
    p = it.p;
    te = func_001C4150(v);
    func_001C4170(&end, v, &te);
    e = end.p;
    if ((p == *(int* volatile*)&end.p) ^ 1) {
        do {
            Terrain_ResolveIdList(*p++);
        } while ((p == e) ^ 1);
    }
    v = o->vec;
    func_00136DA0(g);
    func_001C40F0(v, -1);
    Mem_Free(0, v, D_0049EE88, 0xAC);
    func_0012F530(g, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C4000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C4000 */
