/*
 * main/GobjMan: 5 files, 0040C480-0040C5D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040C480 */
#pragma push /* merge_units */
#include "GobjMan_types.h"

extern GobjScope* g_GobjRootScope;
extern int Id_IsValidCategory(unsigned int category);
extern int Id_IsValidIndex(unsigned int index);
extern GobjId* Id_Build(GobjId* id, int category, int index, int kind);
extern GobjEntry* IdMgr_IsOccupied(GobjScope* scope, GobjId* id);

/* Check whether a valid category and index already identify a visible object. */
GobjEntry* IdMgr_FindCollision(unsigned int category, unsigned int index)
{
    GobjScope* root = g_GobjRootScope;
    GobjId id;
    if (!Id_IsValidCategory(category) || !Id_IsValidIndex(index))
        return 0;
    return IdMgr_IsOccupied(root, Id_Build(&id, category, index, -1));
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C480 */

/* merge_units: begin func_0040C500 */
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
/* merge_units: end func_0040C500 */

/* merge_units: begin func_0040C540 */
#pragma push /* merge_units */
extern GobjEntry* ObjRegistry_Find(GobjScope* scope, const GobjId* id);
extern GobjScope* Object_GetScope(GobjEntry* obj);
extern GobjScope* Scope_GetParent(GobjScope* scope);

/*
 * Looks an id up in the global registry; returns the object only if its
 * scope chain reaches the root scope, otherwise null.
 */
GobjEntry* Object_LookupById(const GobjId* id) {
    GobjEntry* o;
    GobjScope* s;
    GobjScope* root = g_GobjRootScope;
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
#pragma pop /* merge_units */
/* merge_units: end func_0040C540 */

/* merge_units: begin func_0040C5C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc
 */


extern void func_0040B4B0(void);

/* Thunk to func_0040B4B0 (calls func_0040B510 on every scope, newest first). */
void func_0040C5C0(void) {
    func_0040B4B0();
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C5C0 */

/* merge_units: begin func_0040C5D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma inline_depth(10)

/* Registered object seen through its vtable; slot 0 is the destructor. */
struct GobjVirt { virtual void Dtor(int flags); };
typedef struct { char pad[4]; int unk04; } Pool_40C5D0;
struct GobjIter { GobjVirt** p; };
struct GobjIterB : GobjIter { GobjIterB() {} };
/*
 * AllocGuard with out-of-line constructor/destructor calls
 * (func_00136DA0 / func_0012F530) instead of the inlined ones.
 */
struct AllocGuardCall;
extern "C" void func_0012F530(AllocGuardCall* g, int f);
extern "C" void func_00136DA0(AllocGuardCall* g);
struct AllocGuardCall { char c; AllocGuardCall() { func_00136DA0(this); } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~AllocGuardCall() { func_0012F530(this, -1); } };
extern "C" {
extern char D_004BECA8[]; /* "GobjMan.cc" */
extern void* g_GobjWorldScope;
extern Pool_40C5D0* D_00571750;
extern Pool_40C5D0* D_00571758;
extern Pool_40C5D0* D_00571760;
extern unsigned char g_GobjDeleting;
extern char D_00571C10[]; /* global id -> object map (GobjMap) */
void Mem_Free(int pool, void* p, char* file, int line);
GobjIterB PtrVec_Begin(int v);
void PtrVec_End(GobjIter* out, int v);
int func_001339A0(void* p);
void func_00134E80(void* p, int f);
void GobjScope_Dtor(void* p, int f);
void func_0040CAC0(void* p);
}
static inline void DeleteObject(GobjVirt* o) { AllocGuard g; o->Dtor(-1); Mem_Free(0, o, D_004BECA8, 0x9B); }
static inline bool IterNe(const GobjIter& a, const GobjIter& b) { return !(a.p == b.p); }
static inline void DeleteScope(void* p, int line) { AllocGuardCall g; GobjScope_Dtor(p, -1); Mem_Free(0, p, D_004BECA8, line); }
static inline void DeletePool(void* p, int line) { AllocGuardCall g; func_00134E80(p, -1); Mem_Free(0, p, D_004BECA8, line); }

/*
 * Tears the object manager down: deletes every live object registered in the
 * root scope, clears the global registry map, deletes both scopes and the
 * three pools.
 */
extern "C" void IdMgr_Destroy(void)
{
    func_0040C5C0();
    {
        void* root = g_GobjRootScope;
        GobjIter end;
        unsigned char wasDeleting;
        PtrVec_End(&end, func_001339A0(root));
        wasDeleting = g_GobjDeleting;
        g_GobjDeleting = 1;
        GobjIter it = PtrVec_Begin(func_001339A0(root));
        while (IterNe(it, end)) {
            GobjVirt* o = *it.p;
            if (((GobjEntry*)o)->magic == (int)GOBJ_ALIVE_MAGIC) DeleteObject(o);
            it.p++;
        }
        g_GobjDeleting = wasDeleting;
    }
    func_0040CAC0(D_00571C10);
    DeleteScope(g_GobjWorldScope, 0xA0);
    DeleteScope(g_GobjRootScope, 0xA1);
    g_GobjWorldScope = 0;
    g_GobjRootScope = 0;
    if (D_00571750) {
        D_00571750->unk04 = 0;
        D_00571758->unk04 = 0;
        D_00571760->unk04 = 0;
        DeletePool(D_00571750, 0xAC);
        DeletePool(D_00571758, 0xAD);
        DeletePool(D_00571760, 0xAE);
        D_00571750 = 0;
        D_00571758 = 0;
        D_00571760 = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C5D0 */