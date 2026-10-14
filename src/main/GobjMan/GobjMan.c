/*
 * main/GobjMan: GobjMan.cc (15 files, 0040BF50-0040C8E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_0040BF50 */
#pragma push /* merge_units */
#include "types.h"
#include "GobjMan_types.h"
GobjEntry* IdMgr_IsOccupied(GobjScope* scope, const GobjId* id); /* gsynth: defined below */
void IdVec_End(Iter* out, PtrVec* v); /* gsynth: defined below */
int IdVecIter_Ne(Iter* a, Iter* b); /* gsynth: defined below */
void IdVec_Find(int** out, PtrVec* v, int* id); /* gsynth: defined below */
#pragma cplusplus on
#include "alloc_guard.h"
/* Registered object; vtable slot 0 is the destructor. */
struct GobjVirt { virtual ~GobjVirt(); };
struct IdIter { int* p; };
extern "C" {
extern GobjScope* g_GobjRootScope;
extern unsigned char g_GobjDeleting;
extern char D_004BECA8[]; /* "GobjMan.cc" */
int func_0012F2B0(void); /* returns its argument + 0xC: here &obj->id */
#if 0 /* merge_units */
void IdVec_Find(IdIter* out, PtrVec* v, int id);
#endif /* merge_units */
#define IdVec_Find(a0, a1, a2) (IdVec_Find((int * *)(a0), (a1), (int *)(a2))) /* merge_units */

#if 0 /* merge_units */
void IdVec_End(IdIter* out, PtrVec* v);
#endif /* merge_units */
#define IdVec_End(a0, a1) (IdVec_End((Iter *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int IdVecIter_Ne(IdIter* a, IdIter* b);
#endif /* merge_units */
#define IdVecIter_Ne(a0, a1) (IdVecIter_Ne((Iter *)(a0), (Iter *)(a1))) /* merge_units */

#if 0 /* merge_units */
int IdMgr_IsOccupied(GobjScope* scope, int id);
#endif /* merge_units */
#define IdMgr_IsOccupied(a0, a1) ((int)IdMgr_IsOccupied((a0), (const GobjId *)(a1))) /* merge_units */

}
/* True when the id is listed in the scope's id vector or no longer visible from it. */
static inline bool CanDelete(GobjScope* scope, int id)
{
    IdIter it;
    IdIter end;
    IdVec_Find(&it, (PtrVec*)&scope->ids, id);
    IdVec_End(&end, (PtrVec*)&scope->ids);
    return IdVecIter_Ne(&it, &end) || !IdMgr_IsOccupied(scope, id);
}
/* Deletes obj (with g_GobjDeleting set) when CanDelete allows it in the root scope. */
extern "C" void Gobj_TryDelete(GobjVirt* obj)
{
    GobjScope* root = g_GobjRootScope;
    int id = func_0012F2B0();
    if (CanDelete(root, id)) {
        g_GobjDeleting = 1;
        if (obj) {
            AllocGuard guard;
            obj->~GobjVirt();
            Mem_Free(0, obj, D_004BECA8, 0x11C);
        }
        g_GobjDeleting = 0;
    }
}
#undef IdVec_Find /* merge_units */
#undef IdVec_End /* merge_units */
#undef IdVecIter_Ne /* merge_units */
#undef IdMgr_IsOccupied /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040BF50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040BF50 */

/* merge_units: begin func_0040C080 */
#pragma push /* merge_units */
extern GobjEntry* ObjRegistry_Find(GobjScope* scope, const GobjId* id);

/*
 * Returns the object registered under id if it is visible from scope (its
 * scope chain reaches scope), otherwise null.
 */
GobjEntry* IdMgr_IsOccupied(GobjScope* scope, const GobjId* id) {
    GobjScope* s;
    GobjEntry* obj;

    obj = ObjRegistry_Find(scope, id);
    if (obj != 0) {
        s = obj->scope;
        if (s != 0) {
loop:
            if (s == scope) {
                return obj;
            }
            s = s->parent;
            if (s == 0) {
                goto none;
            }
            goto loop;
        }
    }
none:
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C080 */

/* merge_units: begin func_0040C0E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: iterator helpers for a scope's id vector (GobjScope.ids).
 */


/* Iterator inequality. */
int IdVecIter_Ne(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* end() iterator of the id vector. */
void IdVec_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C0E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C0E0 */

/* merge_units: begin func_0040C120 */
#pragma push /* merge_units */
#pragma bool off
extern int** IdVec_DataRef(PtrVec* v);
static inline int IdIter_Ne(int* a, int* b) { return (a == b) ^ 1; }
/* Finds the id word *id in the vector; stores its iterator (end() if absent). */
void IdVec_Find(int** out, PtrVec* v, int* id) {
    int* it = *IdVec_DataRef(v);
    int* end = *IdVec_DataRef(v) + v->count;
    while (IdIter_Ne(it, end)) {
        if (*it == *id) {
            *out = it;
            return;
        }
        it++;
    }
    *out = end;
}
#pragma bool reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C120 */

/* merge_units: begin func_0040C1E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc
 */


/* Address of the vector's data pointer. */
int** IdVec_DataRef(PtrVec* v) {
    return &v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C1E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C1E0 */

/* merge_units: begin func_0040C1F0 */
#pragma push /* merge_units */
extern char g_GobjIdText[];

/* Formats an id as "(category index)" into a static buffer and returns it. */
char* Object_ToString(GobjId* id)
{
    sprintf(g_GobjIdText, "(%d %d)", (id->word & 0xFF0000) >> 16, id->word & 0xFFFF);
    return g_GobjIdText;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C1F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C1F0 */

/* merge_units: begin func_0040C240 */
#pragma push /* merge_units */
GobjEntry* IdMgr_FindCollision(unsigned int category, unsigned int index); /* gsynth: defined below */
#pragma mpwc_relax on
#if 0 /* merge_units */
int IdMgr_FindCollision(int category, int index);
#endif /* merge_units */
#define IdMgr_FindCollision(a0, a1) ((int)IdMgr_FindCollision((unsigned int)(a0), (unsigned int)(a1))) /* merge_units */

/* Next index per category (256 counters). */
extern char g_GobjIdCounters;

/*
 * Allocates a fresh id in a category: bumps the category's counter (wrapping
 * after 0xFFFF) until no visible object uses the index.
 */
void IdMgr_Allocate(GobjId* out, int category) {
    int next;
    int* counter;
    int cat;

    cat = category & 0xFF;
    counter = (int*)(&g_GobjIdCounters + (cat * 4));
    do {
        next = *counter + 1;
        *counter = next;
        if (next > 0xFFFF) {
            *counter = 0;
        }
    } while (IdMgr_FindCollision(cat, *counter) != 0);
    out->word = *counter | (cat << 0x10);
}
#undef IdMgr_FindCollision /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C240(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C240 */

/* merge_units: begin func_0040C2D0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern GobjScope* g_GobjWorldScope;
#if 0 /* merge_units */
extern int g_GobjIdCounters[256];
#endif /* merge_units */
#define g_GobjIdCounters ((int*)&g_GobjIdCounters) /* merge_units */


void* Mem_Alloc(int, int, char*, int);
void GobjScopeBase_Ctor(GobjScope* self, int capacity, GobjScope* parent);
}
static inline void* AllocL_n1(int size, char* file, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, file, line);
}
/* Creates the root and world scopes and resets the per-category id counters. */
extern "C" void IdMgr_Init(void)
{
    int i;
    GobjScope* scope;
    scope = (GobjScope*)AllocL_n1(sizeof(GobjScope), D_004BECA8, 0xCF);
    if (scope) {
        GobjScopeBase_Ctor(scope, 4500, 0);
    }
    g_GobjRootScope = scope;
    scope = (GobjScope*)AllocL_n1(sizeof(GobjScope), D_004BECA8, 0xD0);
    if (scope) {
        GobjScopeBase_Ctor(scope, 2500, g_GobjRootScope);
    }
    g_GobjWorldScope = scope;
    for (i = 0; i < 256; i++) {
        g_GobjIdCounters[i] = 0;
    }
}
#undef g_GobjIdCounters /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C2D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C2D0 */

/* merge_units: begin func_0040C460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: scope chain accessors used by the script object lookup.
 */


GobjScope* Scope_GetParent(GobjScope* self) {
    return self->parent;
}

GobjScope* Object_GetScope(GobjEntry* self) {
    return self->scope;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C460 */

/* merge_units: begin func_0040C480 */
#pragma push /* merge_units */
extern int Id_IsValidCategory(unsigned int category);
extern int Id_IsValidIndex(unsigned int index);
extern GobjId* Id_Build(GobjId* id, int category, int index, int kind);
#if 0 /* merge_units */
extern GobjEntry* IdMgr_IsOccupied(GobjScope* scope, GobjId* id);
#endif /* merge_units */
#define IdMgr_IsOccupied(a0, a1) (IdMgr_IsOccupied((a0), (void *)(a1))) /* merge_units */


/* Check whether a valid category and index already identify a visible object. */
GobjEntry* IdMgr_FindCollision(unsigned int category, unsigned int index)
{
    GobjScope* root = g_GobjRootScope;
    GobjId id;
    if (!Id_IsValidCategory(category) || !Id_IsValidIndex(index))
        return 0;
    return IdMgr_IsOccupied(root, Id_Build(&id, category, index, -1));
}
#undef IdMgr_IsOccupied /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C480 */

/* merge_units: begin func_0040C500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: script object ID word helpers.
 */


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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C500 */

/* merge_units: begin func_0040C540 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern GobjScope* Object_GetScope(GobjEntry* obj);
#endif /* merge_units */
#define Object_GetScope(a0) (Object_GetScope((a0))) /* merge_units */

#if 0 /* merge_units */
extern GobjScope* Scope_GetParent(GobjScope* scope);
#endif /* merge_units */
#define Scope_GetParent(a0) (Scope_GetParent((a0))) /* merge_units */


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
#undef Object_GetScope /* merge_units */
#undef Scope_GetParent /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C540(void) {}
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C5C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C5C0 */

/* merge_units: begin func_0040C5D0 */
#pragma push /* merge_units */
void* GobjScope_Dtor(void* self, short del); /* gsynth: defined below */
#pragma cplusplus on
#pragma inline_depth(10)

/* Registered object seen through its vtable; slot 0 is the destructor. */
struct GobjVirt_0040C5D0 { virtual void Dtor(int flags); };
typedef struct { char pad[4]; int unk04; } Pool_40C5D0;
struct GobjIter { GobjVirt_0040C5D0** p; };
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
#if 0 /* merge_units */
extern void* g_GobjWorldScope;
#endif /* merge_units */
#define g_GobjWorldScope (*(void **)&g_GobjWorldScope) /* merge_units */

extern Pool_40C5D0* D_00571750;
extern Pool_40C5D0* D_00571758;
extern Pool_40C5D0* D_00571760;
extern char D_00571C10[]; /* global id -> object map (GobjMap) */
GobjIterB PtrVec_Begin(int v);
void PtrVec_End(GobjIter* out, int v);
int func_001339A0(void* p);
void func_00134E80(void* p, int f);
#if 0 /* merge_units */
void GobjScope_Dtor(void* p, int f);
#endif /* merge_units */
#define GobjScope_Dtor(a0, a1) ((void)GobjScope_Dtor((a0), (short)(a1))) /* merge_units */

void func_0040CAC0(void* p);
}
static inline void DeleteObject(GobjVirt_0040C5D0* o) { AllocGuard g; o->Dtor(-1); Mem_Free(0, o, D_004BECA8, 0x9B); }
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
            GobjVirt_0040C5D0* o = *it.p;
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
#undef g_GobjWorldScope /* merge_units */
#undef GobjScope_Dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C5D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C5D0 */

/* merge_units: begin func_0040C8E0 */
#pragma push /* merge_units */
extern void GobjScopeBase_Dtor(void* self, short del);
extern void operator_delete(void* p);
/* Scope destructor: run the base destructor, then delete when del > 0. */
void* GobjScope_Dtor(void* self, short del)
{
    if (self) {
        GobjScopeBase_Dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C8E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C8E0 */
