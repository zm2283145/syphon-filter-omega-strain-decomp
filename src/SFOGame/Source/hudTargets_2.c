/*
 * SFOGame/Source/hudTargets: 4 files, 00272CC0-00272D50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00272CC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

const float D_0048B310[2] = { 1.25f, 0.0f };

float cHudTargetManager_GetDangerMag(void) {
    return (*(float*)D_0048B310);
}
static inline void merge_flush_func_00272CC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00272CC0 */

/* merge_units: begin func_00272CD0 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int key; } Node2CD0;
typedef struct { char pad[0x34]; Node2CD0* node; int key; } Obj2CD0;
Node2CD0* cHudTargetManager_GetWaypoint(Obj2CD0* o) {
    Node2CD0* n = o->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != o->key) ok = 0;
    return ok ? n : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00272CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00272CD0 */

/* merge_units: begin func_00272D10 */
#pragma push /* merge_units */
void cHudTargetManager_SetWaypoint(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 52) = a1;
    if (cond) goto L00272D28;
    v1 = a1 + 12;
    goto L00272D38;
L00272D28:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L00272D38:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 56) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00272D10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00272D10 */

/* merge_units: begin func_00272D50 */
#pragma push /* merge_units */
// cHudTargetManager::Remove(const cObjectId&, bool) (hudTargets.cc)
#pragma cplusplus on
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#pragma inline_depth(8)


struct MRec;
struct LNode { LNode* x0; LNode* next; MRec* data; };
union It { LNode* p; float f; };

extern "C" {
int cMemMan_Deallocate(...);
int String_Dtor(...);
int std_list_deleter_voidPtr_erase_listdeleter(...);
int std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(...);
int cLListIterator_cHudTargetInfoPtr_ctor_cLListIteratorR(...);
int opNe_cLListIteratorR_cLListIteratorR_5(...);
int cLList_cHudTargetInfoPtr_End(...);
int cLListIterator_cHudTargetInfoPtr_opInc(...);
int* cLListIterator_cHudTargetInfoPtr_opMul(...);
int cLListIterator_cHudTargetInfoPtr_opAssign(...);
int cLList_cHudTargetInfoPtr_Begin(...);
int cLListIterator_cHudTargetInfoPtr_ctor_void(...);
int cLListIterator_cHudTargetsObserverPtr_ctor(...);
int std_list_cHudTargetsObserverPtr_end(...);
int std_list_cHudTargetsObserverPtr_generic_iterator_ctor(...);
int std_list_cHudTargetInfoPtr_end_void_2(...);
int cLListIterator_cHudTargetInfoPtr_ctor_listR(...);
int std_list_cHudTargetInfoPtr_begin_void_2(...);
int std_list_deleter_voidPtr_begin_void(...);
int cIE_GOBJ_AnimateOff(...);
extern char D_004A8F60;
extern unsigned char D_0048B308;
}

struct MRec { int id; char* icon0; char* icon1; int pad0C; int kind; };
class OObj { public: int x; virtual void v0(); virtual void v1(); virtual void OnRemove(MRec* r); };
static inline bool IsMapKind(MRec* r) { return r->kind == 1 || r->kind == 2; }
static inline void beg0_(It* o, char* l) { It r; std_list_cHudTargetInfoPtr_begin_void_2(&r, l); cLListIterator_cHudTargetInfoPtr_ctor_listR(o, &r); }
static inline void end0_(It* o, char* l) { It r; std_list_cHudTargetInfoPtr_end_void_2(&r, l); cLListIterator_cHudTargetInfoPtr_ctor_listR(o, &r); }
static inline void end1_(It* o, char* l) { It r; std_list_cHudTargetsObserverPtr_end(&r, l); cLListIterator_cHudTargetsObserverPtr_ctor(o, &r); }
static inline void beg2_(It* o, char* l) { It r; std_list_deleter_voidPtr_begin_void(&r, l); std_list_cHudTargetsObserverPtr_generic_iterator_ctor(o, &r); }
static inline bool ne(It* a, It* b) { return a->p != b->p; }
static inline void adv(It* a) { a->p = a->p->next; }
static inline MRec* deref(It* a) { return a->p->data; }
static inline void SDtor(char* s) { if (s) String_Dtor(s, 0); }

static inline void Find2_(It* out, char* l, MRec** key) {
    It i;
    It t;
    It e3;
    cLListIterator_cHudTargetInfoPtr_ctor_void(&i);
    cLList_cHudTargetInfoPtr_Begin(&t, l);
    cLListIterator_cHudTargetInfoPtr_opAssign(&i, &t);
    while (cLList_cHudTargetInfoPtr_End(&e3, l), opNe_cLListIteratorR_cLListIteratorR_5(&i, &e3)) {
        int* p = cLListIterator_cHudTargetInfoPtr_opMul(&i); if (*p == (int)*key) break;
        cLListIterator_cHudTargetInfoPtr_opInc(&i);
    }
    cLListIterator_cHudTargetInfoPtr_ctor_cLListIteratorR(out, &i);
}

static inline void beg0(It* o, char* l) { beg0_(o, l); }
static inline void end0(It* o, char* l) { end0_(o, l); }
static inline void end1(It* o, char* l) { end1_(o, l); }
static inline void beg2(It* o, char* l) { beg2_(o, l); }
static inline void Find2(It* out, char* l, MRec** key) { Find2_(out, l, key); }
static inline void Erase(char* l, It* a) { It d; It c; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&c, a); std_list_deleter_voidPtr_erase_listdeleter(&d, l, &c); }
extern "C" int cHudTargetManager_Remove(char* mgr, int* id, bool send) {
    It it;
    It found;
    It b;
    It e;
    It e1;
    It e2;
    It e4;
    It b2;
    It a2;
    beg0(&b, mgr + 0xC);
    it = b;
    while ((end0(&e, mgr + 0xC), ne(&it, &e))) {
        MRec* r = deref(&it);
        if (r->id == *id && IsMapKind(r) == send) break;
        adv(&it);
    }
    end0(&e1, mgr + 0xC);
    if (ne(&it, &e1)) {
        beg2(&b2, mgr);
        char* n = (char*)b2.p;
        for (; (end1(&e2, mgr), n != (char*)e2.p); n = F_(n, 4, char*)) {
            OObj* o = F_(n, 8, OObj*);
            o->OnRemove(deref(&it));
        }
        if (deref(&it) == *(MRec**)(mgr + 0x3C)) *(MRec**)(mgr + 0x3C) = 0;
        Find2(&found, mgr + 0x24, &it.p->data);
        end0(&e4, mgr + 0x24);
        if (ne(&found, &e4)) {
            a2.p = found.p;
            Erase(mgr + 0x24, &a2);
        }
        {
            MRec* rec = deref(&it);
            AllocGuard g;
            if (rec) {
                if (D_0048B308) {
                    cIE_GOBJ_AnimateOff(rec->icon1);
                    cIE_GOBJ_AnimateOff(rec->icon0);
                }
                SDtor((char*)rec + 0x28);
                SDtor((char*)rec + 0x1C);
            }
            cMemMan_Deallocate(0, rec, &D_004A8F60, 0x24A);
        }
        {
        It a1;
        a1.p = it.p;
        Erase(mgr + 0xC, &a1);
        }
        return 1;
    }
    return 0;
}
static inline void merge_flush_func_00272D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00272D50 */
