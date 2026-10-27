/*
 * SFOGame/Source/npc: 5 files, 0015AC10-0015AD70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015AC10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cSwitchControllersMsg_dtor, D_004D9300, cMessage_dtor)
static inline void merge_flush_func_0015AC10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015AC10 */

/* merge_units: begin func_0015AC70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern int cStateMachine_ChangeState(void* obj, int a1, int a2);

/* Three-word record, initialised to {0, -2, -1}. */
typedef struct NpcTriple {
    int unk0;
    int unk4;
    int unk8;
} NpcTriple;

NpcTriple* cTargetAwareness_ctor(NpcTriple* self) {
    self->unk4 = -2;
    self->unk0 = 0;
    self->unk8 = -1;
    return self;
}

Word* cObjectId_ctor_uint(Word* self, int value) {
    self->value = value;
    return self;
}

void* cPathTransfer_ctor(void* self) {
    return self;
}

void* cPathNavigatorTransfer_ctor(void* self) {
    return self;
}

void* cAiTargetTransfer_ctor(void* self) {
    return self;
}

NpcTriple* cAiTransfer_ctor(NpcTriple* self) {
    self->unk0 = 0;
    self->unk8 = 0;
    cStateMachine_ChangeState(self, 0, 0);
    return self;
}
static inline void merge_flush_func_0015AC70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015AC70 */

/* merge_units: begin func_0015AD10 */
#pragma push /* merge_units */
#include "types.h"

int cNpcTransfer_ctor(int a0) {
    int a1, v0, v1;
    int cond;

    a1 = 0;
    v1 = a0;
L0015AD18:;
    *(int*)((char*)v1 + 92) = 0;
    *(int*)((char*)v1 + 96) = 0;
    a1 = a1 + 3;
    *(int*)((char*)v1 + 100) = 0;
    v0 = a1 < 9;
    cond = v0 != 0;
    v1 = v1 + 12;
    if (cond) goto L0015AD18;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_0015AD10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015AD10 */

/* merge_units: begin func_0015AD40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc.
 */


Word* func_0015AD40(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0015AD50(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_0015AD60(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_0015AD40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015AD40 */

/* merge_units: begin func_0015AD70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct Obj_AD70 { char pad[0xC]; int serial; };
struct Handle_AD70 { Obj_AD70* obj; int serial; };
struct Node_AD70 { int f0; Node_AD70* next; Handle_AD70* handle; };
struct In_AD70 { Node_AD70* n; In_AD70() {} };
union It_AD70 { Node_AD70* n; };
struct Raw_AD70 { Node_AD70* n; };
struct R_AD70 { int a; R_AD70() {} };
struct Q_AD70 { int a; Q_AD70() {} };
struct E_AD70 { int a; E_AD70() {} };
extern "C" {
extern char g_NpcThinkList[];
extern char D_0049B670[];
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void std_list_deleter_voidPtr_begin_void(void*, void*);
void std_list_cActiveListItemPtr_generic_iterator_ctor(void*, void*);
void std_list_cActiveListItemPtr_end_void(void*, void*);
void cLListIterator_cActiveListItemPtr_ctor(void*, void*);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(void*, void*);
void std_list_cActiveListItemPtr_generic_iterator_opCast(void*, void*);
void std_list_deleter_voidPtr_erase_listdeleter(void*, void*, void*);
}
static inline int NonNull_AD70(Obj_AD70* p) { return p != 0; }
static inline Obj_AD70* Get_AD70(Handle_AD70* h) {
    bool ok = true;
    if ((NonNull_AD70(h->obj) ^ 1) == 0 && h->obj->serial != h->serial) ok = false;
    return ok ? h->obj : 0;
}
static inline void Er2(void* a, Raw_AD70* t) { char y[4], x[4]; std_list_cActiveListItemPtr_generic_iterator_opCast(x, a); std_list_deleter_voidPtr_erase_listdeleter(y, g_NpcThinkList, x); std_list_cActiveListItemPtr_generic_iterator_ctor(t, y); }
static inline void Er1(It_AD70* it, It_AD70* r) { Raw_AD70 t; char a[4]; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(a, it); Er2(a, &t); r->n = t.n; }
static inline void Bg2(It_AD70* b) { void* s; std_list_deleter_voidPtr_begin_void(&s, g_NpcThinkList); std_list_cActiveListItemPtr_generic_iterator_ctor(b, &s); }
static inline void Bg1(It_AD70* b) { Bg2(b); }
static inline void En2(It_AD70* e) { void* s; std_list_cActiveListItemPtr_end_void(&s, g_NpcThinkList); cLListIterator_cActiveListItemPtr_ctor(e, &s); }
static inline void En1(It_AD70* e) { En2(e); }
extern "C" void cNPC_RemoveFromActiveList(Obj_AD70* actor)
{
    It_AD70 it, r1, e, b;
    Bg1(&b);
    for (it.n = b.n; En1(&e), it.n != e.n; ) {
        Handle_AD70* h = it.n->handle;
        if (Get_AD70(h) == actor) {
            {
                AllocGuard g;
                cMemMan_Deallocate(0, h, D_0049B670, 0x128);
            }
            Er1(&it, &r1);
            it = r1;
        } else {
            it.n = it.n->next;
        }
    }
}
static inline void merge_flush_func_0015AD70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015AD70 */
