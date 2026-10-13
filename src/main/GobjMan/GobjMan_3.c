/*
 * main/GobjMan: 5 files, 0040C480-0040C5D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin IdMgr_FindCollision */
#pragma push /* merge_units */
#include "GobjMan_types.h"

extern GobjScope* D_00571740;
extern int Id_IsValidCategory(unsigned int category);
extern int Id_IsValidIndex(unsigned int index);
extern GobjId* Id_Build(GobjId* id, int category, int index, int kind);
extern GobjEntry* IdMgr_IsOccupied(GobjScope* manager, GobjId* id);

/* Check whether a valid category and index already identify an object. */
GobjEntry* IdMgr_FindCollision(unsigned int category, unsigned int index)
{
    GobjScope* manager = D_00571740;
    GobjId id;
    if (!Id_IsValidCategory(category) || !Id_IsValidIndex(index))
        return 0;
    return IdMgr_IsOccupied(manager, Id_Build(&id, category, index, -1));
}
#pragma pop /* merge_units */
/* merge_units: end IdMgr_FindCollision */

/* merge_units: begin Id_Build */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: script object ID word helpers.
 */

#include "types.h"

/* Pack (category, index, kind) into an ID word. */
GobjId* Id_Build(GobjId* id, int category, int index, int kind) {
    id->word = index | (((kind + 1) << 24) | (category << 16));
    return id;
}

/* Index fits in the 16-bit index field. */
int Id_IsValidIndex(unsigned int index) {
    return index < 0x10000;
}

/* Category fits in the 8-bit category field. */
int Id_IsValidCategory(unsigned int category) {
    return category < 256;
}
#pragma pop /* merge_units */
/* merge_units: end Id_Build */

/* merge_units: begin Object_LookupById */
#pragma push /* merge_units */
/* Object_LookupById */
#if 0 /* merge_units */
extern void* D_00571740;
#endif /* merge_units */
#define D_00571740 (*(void **)&D_00571740) /* merge_units */

extern void* ObjRegistry_Find(void*, int);
extern void* Object_GetScope(void*);
extern void* Scope_GetParent(void*);

void* Object_LookupById(int id) {
    void* o;
    void* s;
    void* root = D_00571740;
    o = ObjRegistry_Find(root, id);
    if (o) {
        for (s = Object_GetScope(o); s; s = Scope_GetParent(s)) {
            if (s == root) { asm { .set reorder } goto out; } /* barrier: keeps the found branch unmerged */
        }
    }
    o = 0;
out:
    return o;
}
#undef D_00571740 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end Object_LookupById */

/* merge_units: begin func_0040C5C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc
 */


extern int func_0040B4B0(void);

/* Thunk to func_0040B4B0. */
int func_0040C5C0(void) {
    return func_0040B4B0();
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C5C0 */

/* merge_units: begin IdMgr_Destroy */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma inline_depth(10)

struct VObj_40C5D0 { virtual void dtor(int f); };
typedef struct { int vt; int magic; } Ent_40C5D0;
typedef struct { char pad[4]; int f4; } Pool_40C5D0;
struct It_40C5D0 { VObj_40C5D0** p; };
struct ItB_40C5D0 : It_40C5D0 { ItB_40C5D0() {} };
struct G_40C5D0;
extern "C" void func_0012F530(G_40C5D0* g, int f);
extern "C" void func_00136DA0(G_40C5D0* g);
struct G_40C5D0 { char c; G_40C5D0() { func_00136DA0(this); } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~G_40C5D0() { func_0012F530(this, -1); } };
extern "C" {
extern char D_004BECA8[];
#if 0 /* merge_units */
extern void* D_00571740;
#endif /* merge_units */
#define D_00571740 (*(void **)&D_00571740) /* merge_units */

extern void* D_00571748;
extern Pool_40C5D0* D_00571750;
extern Pool_40C5D0* D_00571758;
extern Pool_40C5D0* D_00571760;
extern unsigned char D_00571768;
extern char D_00571C10[];
void Mem_Free(int pool, void* p, char* file, int line);
ItB_40C5D0 PtrVec_Begin(int v);
void PtrVec_End(It_40C5D0* out, int v);
int func_001339A0(void* p);
void func_00134E80(void* p, int f);
#if 0 /* merge_units */
void func_0040C5C0(void);
#endif /* merge_units */
#define func_0040C5C0() ((void)func_0040C5C0()) /* merge_units */

void func_0040C8E0(void* p, int f);
void func_0040CAC0(void* p);
}
static inline void Del_40C5D0(VObj_40C5D0* o) { AllocGuard g; o->dtor(-1); Mem_Free(0, o, D_004BECA8, 0x9B); }
static inline bool Ne_40C5D0(const It_40C5D0& a, const It_40C5D0& b) { return !(a.p == b.p); }
static inline void DelA_40C5D0(void* p, int line) { G_40C5D0 g; func_0040C8E0(p, -1); Mem_Free(0, p, D_004BECA8, line); }
static inline void DelB_40C5D0(void* p, int line) { G_40C5D0 g; func_00134E80(p, -1); Mem_Free(0, p, D_004BECA8, line); }

extern "C" void IdMgr_Destroy(void)
{
    func_0040C5C0();
    {
        void* v = D_00571740;
        It_40C5D0 e;
        unsigned char old;
        PtrVec_End(&e, func_001339A0(v));
        old = D_00571768;
        D_00571768 = 1;
        It_40C5D0 it = PtrVec_Begin(func_001339A0(v));
        while (Ne_40C5D0(it, e)) {
            VObj_40C5D0* o = *it.p;
            if (((Ent_40C5D0*)o)->magic == (int)0xBEBAAFDE) Del_40C5D0(o);
            it.p++;
        }
        D_00571768 = old;
    }
    func_0040CAC0(D_00571C10);
    DelA_40C5D0(D_00571748, 0xA0);
    DelA_40C5D0(D_00571740, 0xA1);
    D_00571748 = 0;
    D_00571740 = 0;
    if (D_00571750) {
        D_00571750->f4 = 0;
        D_00571758->f4 = 0;
        D_00571760->f4 = 0;
        DelB_40C5D0(D_00571750, 0xAC);
        DelB_40C5D0(D_00571758, 0xAD);
        DelB_40C5D0(D_00571760, 0xAE);
        D_00571750 = 0;
        D_00571758 = 0;
        D_00571760 = 0;
    }
}
#undef D_00571740 /* merge_units */
#undef func_0040C5C0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end IdMgr_Destroy */
