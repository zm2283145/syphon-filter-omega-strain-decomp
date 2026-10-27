/*
 * SFOGame/Source/SpecFxDefs: 2 files, 00235A00-00235AE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00235A00 */
#pragma push /* merge_units */
#include "types.h"
#include "vu0_ops.h"
#include "vc_copy.h"

typedef struct ListNode235A00 {
    struct ListNode235A00* prev;
    struct ListNode235A00* next;
    struct LightRef235A00* value;
} ListNode235A00;

typedef struct LightRef235A00 {
    void* obj;
    int pad4[3];
    Vec4 pos;
} LightRef235A00;

typedef struct {
    ListNode235A00* node;
} ListIt235A00;

typedef struct {
    char pad0[0x38];
    int key;
    char pad3C[0x74 - 0x3C];
    char list[8];
} Fx235A00;

typedef struct {
    Vec4 r[4];
} Mtx235A00;

extern void std_list_cElementPtr_begin_void_2(ListIt235A00* out, void* list);
extern void std_list_cElementPtr_end_void_2(ListIt235A00* out, void* list);
extern ListIt235A00* cLListIterator_cElementPtr_ctor_listR_2(ListIt235A00* dst, ListIt235A00* src);
extern void cParticle_Render(void* obj, int key, Mtx235A00* m);

#pragma push
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
void cCameraAtmosphericEffect_Render(Fx235A00* self) {
    ListIt235A00 it;
    ListIt235A00 first;
    ListIt235A00 last;
    ListIt235A00 tmpBegin;
    ListIt235A00 tmpEnd;
    Mtx235A00 m;

    VU0_UnitMatrix(&m);
    std_list_cElementPtr_begin_void_2(&tmpBegin, self->list);
    cLListIterator_cElementPtr_ctor_listR_2(&first, &tmpBegin);
    it = first;
    while (std_list_cElementPtr_end_void_2(&tmpEnd, self->list), cLListIterator_cElementPtr_ctor_listR_2(&last, &tmpEnd), it.node != last.node) {
        LightRef235A00* v = it.node->value;
        if (v->obj != 0) {
            /* unfolded quad copy idiom */
            VCopyF(&m.r[3], &v->pos);
            cParticle_Render(v->obj, self->key, &m);
        }
        it.node = it.node->next;
    }
}
#pragma pop
static inline void merge_flush_func_00235A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00235A00 */

/* merge_units: begin func_00235AE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004A6E38[];
extern char D_004A6F48[];
extern char D_004DBC70[];
extern char D_004DF860[];
void cGOBJ_dtor(void* p, int flag);
void cParticle_dtor(void* p, int flag);
void operator_delete(void* p);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}
struct E_35AE0 { void* a; };
struct LNode_35AE0 { LNode_35AE0* prev; LNode_35AE0* next; E_35AE0* value; };
struct It_35AE0 { LNode_35AE0* n; };
struct List_35AE0 { int x0; int x4; LNode_35AE0* x8; };
extern "C" {
#if 0 /* merge_units */
void std_list_cElementPtr_end_void_2(It_35AE0* out, List_35AE0* list);
#endif /* merge_units */
#define std_list_cElementPtr_end_void_2(a0, a1) (std_list_cElementPtr_end_void_2((ListIt235A00 *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
It_35AE0* cLListIterator_cElementPtr_ctor_listR_2(It_35AE0* dst, It_35AE0* src);
#endif /* merge_units */
#define cLListIterator_cElementPtr_ctor_listR_2(a0, a1) ((It_35AE0 *)cLListIterator_cElementPtr_ctor_listR_2((ListIt235A00 *)(a0), (ListIt235A00 *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_cElementPtr_begin_void_2(It_35AE0* out, List_35AE0* list);
#endif /* merge_units */
#define std_list_cElementPtr_begin_void_2(a0, a1) (std_list_cElementPtr_begin_void_2((ListIt235A00 *)(a0), (void *)(a1))) /* merge_units */

void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(It_35AE0* out, List_35AE0* list, LNode_35AE0** first, int** last);
void std_list_cElementPtr_dtor_void_2(List_35AE0* l, int flag);
}
struct S_35AE0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(int a);
    char pad4[0x28]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2f[0x74 - 0x2F]; List_35AE0 list;
};
struct F_35AE0 { float f; };
#pragma opt_propagation off
#pragma opt_common_subs off
static inline bool Ok(S_35AE0* s) { return s->b2D && s->b2C && !s->b2E; }
static inline void Beg1(It_35AE0* out, List_35AE0* l) { It_35AE0 t; std_list_cElementPtr_begin_void_2(&t, l); cLListIterator_cElementPtr_ctor_listR_2(out, &t); }
static inline void End1(It_35AE0* out, List_35AE0* l) { It_35AE0 t; std_list_cElementPtr_end_void_2(&t, l); cLListIterator_cElementPtr_ctor_listR_2(out, &t); }
static inline void Beg2(It_35AE0* out, List_35AE0* l) { Beg1(out, l); }
static inline void End2(It_35AE0* out, List_35AE0* l) { End1(out, l); }
static inline void Kill2(E_35AE0* e) { void* q = e->a; if (q) { AllocGuard g2; cParticle_dtor(q, -1); cMemMan_Deallocate(0, q, D_004A6F48, 298); } }
extern "C" S_35AE0* cCameraAtmosphericEffect_dtor(S_35AE0* self, short flag)
{
    if (self) {
        *(char**)self = D_004DBC70;
        {
            It_35AE0 it;
            It_35AE0 t2;
            It_35AE0 end;
            Beg2(&t2, &self->list);
            { F_35AE0* s = (F_35AE0*)&t2; F_35AE0* d = (F_35AE0*)&it; *d = *s; }
            for (; End2(&end, &self->list), it.n != end.n; it.n = it.n->next) {
                E_35AE0* e = it.n->value;
                AllocGuard g;
                if (e) {
                    Kill2(e);
                }
                cMemMan_Deallocate(0, e, D_004A6E38, 702);
            }
        }
        {
            It_35AE0 r; LNode_35AE0* first; int* last;
            last = &self->list.x4;
            first = self->list.x8;
            std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, &self->list, &first, &last);
        }
        {
            List_35AE0* l = &self->list;
            if (l) std_list_cElementPtr_dtor_void_2(l, 0);
        }
        if (self) {
            *(char**)self = D_004DF860;
            if (Ok(self)) self->v22(1);
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#undef std_list_cElementPtr_end_void_2 /* merge_units */
#undef cLListIterator_cElementPtr_ctor_listR_2 /* merge_units */
#undef std_list_cElementPtr_begin_void_2 /* merge_units */
static inline void merge_flush_func_00235AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00235AE0 */
