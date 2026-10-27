/*
 * Libs/SFOLib/Source/GobjMan: 16 files, 0040BF50-0040C940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040BF50 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);

#include "types.h"
#include "GobjMan_types.h"
GobjEntry* cObjList_cGOBJPtr_LookupObj(GobjScope* scope, const GobjId* id); /* gsynth: defined below */
void cArray_cObjectId_End_void_2(Iter* out, PtrVec* v); /* gsynth: defined below */
int cArray_cObjectId_ConstIterator_opNe(Iter* a, Iter* b); /* gsynth: defined below */
void cArray_cObjectId_Find(int** out, PtrVec* v, int* id); /* gsynth: defined below */
#pragma cplusplus on
#include "alloc_guard.h"
/* Registered object; vtable slot 0 is the destructor. */
struct GobjVirt { virtual ~GobjVirt(); };
struct IdIter { int* p; };
extern "C" {
extern GobjScope* g_GobjRootScope;
extern unsigned char g_GobjDeleting;
extern char D_004BECA8[]; /* "GobjMan.cc" */
int cSystem_GetObjectID_void(void); /* returns its argument + 0xC: here &obj->id */
#if 0 /* merge_units */
void cArray_cObjectId_Find(IdIter* out, PtrVec* v, int id);
#endif /* merge_units */
#define cArray_cObjectId_Find(a0, a1, a2) (cArray_cObjectId_Find((int * *)(a0), (a1), (int *)(a2))) /* merge_units */


#if 0 /* merge_units */
void cArray_cObjectId_End_void_2(IdIter* out, PtrVec* v);
#endif /* merge_units */
#define cArray_cObjectId_End_void_2(a0, a1) (cArray_cObjectId_End_void_2((Iter *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
int cArray_cObjectId_ConstIterator_opNe(IdIter* a, IdIter* b);
#endif /* merge_units */
#define cArray_cObjectId_ConstIterator_opNe(a0, a1) (cArray_cObjectId_ConstIterator_opNe((Iter *)(a0), (Iter *)(a1))) /* merge_units */


#if 0 /* merge_units */
int cObjList_cGOBJPtr_LookupObj(GobjScope* scope, int id);
#endif /* merge_units */
#define cObjList_cGOBJPtr_LookupObj(a0, a1) ((int)cObjList_cGOBJPtr_LookupObj((a0), (const GobjId *)(a1))) /* merge_units */


}
/* True when the id is listed in the scope's id vector or no longer visible from it. */
static inline bool CanDelete(GobjScope* scope, int id)
{
    IdIter it;
    IdIter end;
    cArray_cObjectId_Find(&it, (PtrVec*)&scope->ids, id);
    cArray_cObjectId_End_void_2(&end, (PtrVec*)&scope->ids);
    return cArray_cObjectId_ConstIterator_opNe(&it, &end) || !cObjList_cGOBJPtr_LookupObj(scope, id);
}
/* Deletes obj (with g_GobjDeleting set) when CanDelete allows it in the root scope. */
extern "C" void nGobjManager_DeleteNow(GobjVirt* obj)
{
    GobjScope* root = g_GobjRootScope;
    int id = cSystem_GetObjectID_void();
    if (CanDelete(root, id)) {
        g_GobjDeleting = 1;
        if (obj) {
            AllocGuard guard;
            obj->~GobjVirt();
            cMemMan_Deallocate(0, obj, D_004BECA8, 0x11C);
        }
        g_GobjDeleting = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040BF50(void) {}
#undef cArray_cObjectId_Find /* merge_units */
#undef cArray_cObjectId_End_void_2 /* merge_units */
#undef cArray_cObjectId_ConstIterator_opNe /* merge_units */
#undef cObjList_cGOBJPtr_LookupObj /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040BF50 */

/* merge_units: begin func_0040C080 */
#pragma push /* merge_units */
extern GobjEntry* cBaseObjList_LookupObj(GobjScope* scope, const GobjId* id);

/*
 * Returns the object registered under id if it is visible from scope (its
 * scope chain reaches scope), otherwise null.
 */
GobjEntry* cObjList_cGOBJPtr_LookupObj(GobjScope* scope, const GobjId* id) {
    GobjScope* s;
    GobjEntry* obj;

    obj = cBaseObjList_LookupObj(scope, id);
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
int cArray_cObjectId_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* end() iterator of the id vector. */
void cArray_cObjectId_End_void_2(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C0E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C0E0 */

/* merge_units: begin func_0040C120 */
#pragma push /* merge_units */
#pragma bool off
extern int** std_vector_deleter_cObjectId_data_void_2(PtrVec* v);
static inline int IdIter_Ne(int* a, int* b) { return (a == b) ^ 1; }
/* Finds the id word *id in the vector; stores its iterator (end() if absent). */
void cArray_cObjectId_Find(int** out, PtrVec* v, int* id) {
    int* it = *std_vector_deleter_cObjectId_data_void_2(v);
    int* end = *std_vector_deleter_cObjectId_data_void_2(v) + v->count;
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
int** std_vector_deleter_cObjectId_data_void_2(PtrVec* v) {
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
char* nGobjManager_GetObjectName(GobjId* id)
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
GobjEntry* nGobjManager_LookupGOBJ_int_int(unsigned int category, unsigned int index); /* gsynth: defined below */
#pragma mpwc_relax on
#if 0 /* merge_units */
int nGobjManager_LookupGOBJ_int_int(int category, int index);
#endif /* merge_units */
#define nGobjManager_LookupGOBJ_int_int(a0, a1) ((int)nGobjManager_LookupGOBJ_int_int((unsigned int)(a0), (unsigned int)(a1))) /* merge_units */


/* Next index per category (256 counters). */
extern char g_GobjIdCounters;

/*
 * Allocates a fresh id in a category: bumps the category's counter (wrapping
 * after 0xFFFF) until no visible object uses the index.
 */
void nGobjManager_GetNextId(GobjId* out, int category) {
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
    } while (nGobjManager_LookupGOBJ_int_int(cat, *counter) != 0);
    out->word = *counter | (cat << 0x10);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C240(void) {}
#undef nGobjManager_LookupGOBJ_int_int /* merge_units */
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



void* cMemMan_Allocate(int, int, char*, int);
void cBaseObjList_ctor(GobjScope* self, int capacity, GobjScope* parent);
}
static inline void* AllocL_n1(int size, char* file, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, file, line);
}
/* Creates the root and world scopes and resets the per-category id counters. */
extern "C" void nGobjManager_InitIDs(void)
{
    int i;
    GobjScope* scope;
    scope = (GobjScope*)AllocL_n1(sizeof(GobjScope), D_004BECA8, 0xCF);
    if (scope) {
        cBaseObjList_ctor(scope, 4500, 0);
    }
    g_GobjRootScope = scope;
    scope = (GobjScope*)AllocL_n1(sizeof(GobjScope), D_004BECA8, 0xD0);
    if (scope) {
        cBaseObjList_ctor(scope, 2500, g_GobjRootScope);
    }
    g_GobjWorldScope = scope;
    for (i = 0; i < 256; i++) {
        g_GobjIdCounters[i] = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C2D0(void) {}
#undef g_GobjIdCounters /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040C2D0 */

/* merge_units: begin func_0040C460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: scope chain accessors used by the script object lookup.
 */


GobjScope* cBaseObjList_GetParent(GobjScope* self) {
    return self->parent;
}

GobjScope* cSystem_GetOwningList(GobjEntry* self) {
    return self->scope;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C460 */

/* merge_units: begin func_0040C480 */
#pragma push /* merge_units */
extern int cObjectId_IsValidLevelID(unsigned int category);
extern int cObjectId_IsValidItemID(unsigned int index);
extern GobjId* cObjectId_ctor_int_int_int(GobjId* id, int category, int index, int kind);
#if 0 /* merge_units */
extern GobjEntry* cObjList_cGOBJPtr_LookupObj(GobjScope* scope, GobjId* id);
#endif /* merge_units */
#define cObjList_cGOBJPtr_LookupObj(a0, a1) (cObjList_cGOBJPtr_LookupObj((a0), (const GobjId *)(a1))) /* merge_units */



/* Check whether a valid category and index already identify a visible object. */
GobjEntry* nGobjManager_LookupGOBJ_int_int(unsigned int category, unsigned int index)
{
    GobjScope* root = g_GobjRootScope;
    GobjId id;
    if (!cObjectId_IsValidLevelID(category) || !cObjectId_IsValidItemID(index))
        return 0;
    return cObjList_cGOBJPtr_LookupObj(root, cObjectId_ctor_int_int_int(&id, category, index, -1));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C480(void) {}
#undef cObjList_cGOBJPtr_LookupObj /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040C480 */

/* merge_units: begin func_0040C500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: script object ID word helpers.
 */


/* Pack (category, index, kind) into an ID word. */
GobjId* cObjectId_ctor_int_int_int(GobjId* id, int category, int index, int kind) {
    id->word = index | (((kind + 1) << 24) | (category << 16));
    return id;
}

/* Index fits in the 16-bit index field. */
int cObjectId_IsValidItemID(unsigned int index) {
    return index < 0x10000;
}

/* Category fits in the 8-bit category field. */
int cObjectId_IsValidLevelID(unsigned int category) {
    return category < 256;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C500 */

/* merge_units: begin func_0040C540 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern GobjScope* cSystem_GetOwningList(GobjEntry* obj);
#endif /* merge_units */
#define cSystem_GetOwningList(a0) (cSystem_GetOwningList((a0))) /* merge_units */


#if 0 /* merge_units */
extern GobjScope* cBaseObjList_GetParent(GobjScope* scope);
#endif /* merge_units */
#define cBaseObjList_GetParent(a0) (cBaseObjList_GetParent((a0))) /* merge_units */



/*
 * Looks an id up in the global registry; returns the object only if its
 * scope chain reaches the root scope, otherwise null.
 */
GobjEntry* nGobjManager_LookupGOBJ_cObjectIdR(const GobjId* id) {
    GobjEntry* o;
    GobjScope* s;
    GobjScope* root = g_GobjRootScope;
    o = cBaseObjList_LookupObj(root, id);
    if (o) {
        for (s = cSystem_GetOwningList(o); s; s = cBaseObjList_GetParent(s)) {
            if (s == root) { asm { .set reorder } goto out; } /* barrier: keeps the found branch unmerged */
        }
    }
    o = 0;
out:
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C540(void) {}
#undef cSystem_GetOwningList /* merge_units */
#undef cBaseObjList_GetParent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040C540 */

/* merge_units: begin func_0040C5C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc
 */


extern void cBaseObjList_PurgeRemovals(void);

/* Thunk to cBaseObjList_PurgeRemovals (calls cBaseObjList_Purge on every scope, newest first). */
void nGobjManager_PurgeRemovals(void) {
    cBaseObjList_PurgeRemovals();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C5C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C5C0 */

/* merge_units: begin func_0040C5D0 */
#pragma push /* merge_units */
void* cObjList_cGOBJPtr_dtor(void* self, short del); /* gsynth: defined below */
#pragma cplusplus on
#pragma inline_depth(10)

/* Registered object seen through its vtable; slot 0 is the destructor. */
struct GobjVirt_0040C5D0 { virtual void Dtor(int flags); };
typedef struct { char pad[4]; int unk04; } Pool_40C5D0;
struct GobjIter { GobjVirt_0040C5D0** p; };
struct GobjIterB : GobjIter { GobjIterB() {} };
/*
 * AllocGuard with out-of-line constructor/destructor calls
 * (cTimerDisable_ctor / cTimerDisable_dtor) instead of the inlined ones.
 */
struct AllocGuardCall;
extern "C" void cTimerDisable_dtor(AllocGuardCall* g, int f);
extern "C" void cTimerDisable_ctor(AllocGuardCall* g);
struct AllocGuardCall { char c; AllocGuardCall() { cTimerDisable_ctor(this); } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~AllocGuardCall() { cTimerDisable_dtor(this, -1); } };
extern "C" {
#if 0 /* merge_units */
extern void* g_GobjWorldScope;
#endif /* merge_units */
#define g_GobjWorldScope (*(void **)&g_GobjWorldScope) /* merge_units */


extern Pool_40C5D0* D_00571750;
extern Pool_40C5D0* D_00571758;
extern Pool_40C5D0* D_00571760;
extern char D_00571C10[]; /* global id -> object map (GobjMap) */
GobjIterB cArray_cGOBJPtr_Begin(int v);
void cArray_cGOBJPtr_End(GobjIter* out, int v);
int cObjList_cGOBJPtr_GetList(void* p);
void cArray_cGOBJPtr_dtor(void* p, int f);
#if 0 /* merge_units */
void cObjList_cGOBJPtr_dtor(void* p, int f);
#endif /* merge_units */
#define cObjList_cGOBJPtr_dtor(a0, a1) ((void)cObjList_cGOBJPtr_dtor((a0), (short)(a1))) /* merge_units */


void std_tree_pair_cObjectId_value_compare_clear(void* p);
}
static inline void DeleteObject(GobjVirt_0040C5D0* o) { AllocGuard g; o->Dtor(-1); cMemMan_Deallocate(0, o, D_004BECA8, 0x9B); }
static inline bool IterNe(const GobjIter& a, const GobjIter& b) { return !(a.p == b.p); }
static inline void DeleteScope(void* p, int line) { AllocGuardCall g; cObjList_cGOBJPtr_dtor(p, -1); cMemMan_Deallocate(0, p, D_004BECA8, line); }
static inline void DeletePool(void* p, int line) { AllocGuardCall g; cArray_cGOBJPtr_dtor(p, -1); cMemMan_Deallocate(0, p, D_004BECA8, line); }

/*
 * Tears the object manager down: deletes every live object registered in the
 * root scope, clears the global registry map, deletes both scopes and the
 * three pools.
 */
extern "C" void nGobjManager_RemoveAll(void)
{
    nGobjManager_PurgeRemovals();
    {
        void* root = g_GobjRootScope;
        GobjIter end;
        unsigned char wasDeleting;
        cArray_cGOBJPtr_End(&end, cObjList_cGOBJPtr_GetList(root));
        wasDeleting = g_GobjDeleting;
        g_GobjDeleting = 1;
        GobjIter it = cArray_cGOBJPtr_Begin(cObjList_cGOBJPtr_GetList(root));
        while (IterNe(it, end)) {
            GobjVirt_0040C5D0* o = *it.p;
            if (((GobjEntry*)o)->magic == (int)GOBJ_ALIVE_MAGIC) DeleteObject(o);
            it.p++;
        }
        g_GobjDeleting = wasDeleting;
    }
    std_tree_pair_cObjectId_value_compare_clear(D_00571C10);
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C5D0(void) {}
#undef g_GobjWorldScope /* merge_units */
#undef cObjList_cGOBJPtr_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040C5D0 */

/* merge_units: begin func_0040C8E0 */
#pragma push /* merge_units */
extern void cBaseObjList_dtor(void* self, short del);
extern void operator_delete(void* p);
/* Scope destructor: run the base destructor, then delete when del > 0. */
void* cObjList_cGOBJPtr_dtor(void* self, short del)
{
    if (self) {
        cBaseObjList_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040C8E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040C8E0 */

/* merge_units: begin GobjMan_40C940 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* g_GobjRootScope;
#endif /* merge_units */
#define g_GobjRootScope (*(void **)&g_GobjRootScope) /* merge_units */

extern void cSystem_SetOwningList(void* obj, void* registry);
extern void cBaseObjList_Add(void* registry, void* obj);

/* Attaches the object to the global registry and appends it recursively. */
void nGobjManager_AddNode(void* obj)
{
    void* registry;
    cSystem_SetOwningList(obj, registry = g_GobjRootScope);
    cBaseObjList_Add(registry, obj);
}
#undef g_GobjRootScope /* merge_units */
static inline void merge_flush_GobjMan_40C940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GobjMan_40C940 */
