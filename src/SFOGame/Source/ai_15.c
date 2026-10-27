/*
 * SFOGame/Source/ai: 7 files, 0016DAB0-0016DFA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016DAB0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAINewAwarenessMsg_dtor, D_004DCC90, D_004DCD70, cMessage_dtor)
static inline void merge_flush_func_0016DAB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DAB0 */

/* merge_units: begin func_0016DB20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copies.
 */


Word* std_list_cTargetAwarenessPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cTargetAwarenessPtr_generic_iterator_opCast(Word* dst, Word* src) {
    dst->value = src->value;
}
static inline void merge_flush_func_0016DB20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DB20 */

/* merge_units: begin func_0016DB40 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { char pad[0xC]; int serial; } Tgt_DB40;
typedef struct { Tgt_DB40* target; int serial; } Rec_DB40;
typedef struct Node_DB40 { int pad0; struct Node_DB40* next; Rec_DB40* val; } Node_DB40;
typedef struct { Node_DB40* n; } It_DB40;
typedef struct { int a; } E_DB40;
extern void std_list_deleter_voidPtr_end_void(E_DB40* out);
#if 0 /* merge_units */
extern void std_list_cTargetAwarenessPtr_generic_iterator_ctor(It_DB40* out, E_DB40* in);
#endif /* merge_units */
#define std_list_cTargetAwarenessPtr_generic_iterator_ctor(a0, a1) ((void)std_list_cTargetAwarenessPtr_generic_iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

extern void std_list_cTargetAwarenessPtr_end_void(E_DB40* out, void* map);
extern void std_list_cTargetAwarenessPtr_begin(E_DB40* out, void* map);
extern void cLListIterator_cTargetAwarenessPtr_ctor(It_DB40* out, E_DB40* in);
void cAITarget_cAwareList_Find(It_DB40* out, void* map, Tgt_DB40* key)
{
    It_DB40 it;
    It_DB40 b;
    It_DB40 end;
    It_DB40 a;
    E_DB40 t0;
    E_DB40 t1;
    E_DB40 t2;
    std_list_deleter_voidPtr_end_void(&t0);
    std_list_cTargetAwarenessPtr_generic_iterator_ctor(&a, &t0);
    it.n = a.n;
    if (key) {
        std_list_cTargetAwarenessPtr_begin(&t1, map);
        cLListIterator_cTargetAwarenessPtr_ctor(&b, &t1);
        it = b;
        while (std_list_cTargetAwarenessPtr_end_void(&t2, map), cLListIterator_cTargetAwarenessPtr_ctor(&end, &t2), it.n != end.n) {
            unsigned char ok;
            int isNull;
            Tgt_DB40* c;
            Rec_DB40* h;
            h = it.n->val;
            c = h->target;
            isNull = !c;
            ok = 1;
            if (!isNull)
                if (c->serial != h->serial)
                    ok = 0;
            if ((ok ? c : 0) == key)
                break;
            it.n = it.n->next;
        }
    }
    out->n = it.n;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016DB40(void) {}
#undef std_list_cTargetAwarenessPtr_generic_iterator_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DB40 */

/* merge_units: begin func_0016DC60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Node_DC60 { int pad0; Node_DC60* next; void* val; };
struct It_DC60 { Node_DC60* n; };
struct E_DC60 { int a; };
struct Perc_DC60 { char pad[0x30]; char map[4]; char hdr[4]; char* first; };
extern "C" {
extern char D_0049C650[];
#if 0 /* merge_units */
void std_list_cTargetAwarenessPtr_end_void(E_DC60* out, void* map);
#endif /* merge_units */
#define std_list_cTargetAwarenessPtr_end_void(a0, a1) (std_list_cTargetAwarenessPtr_end_void((E_DB40 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
void std_list_cTargetAwarenessPtr_begin(E_DC60* out, void* map);
#endif /* merge_units */
#define std_list_cTargetAwarenessPtr_begin(a0, a1) (std_list_cTargetAwarenessPtr_begin((E_DB40 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
void cLListIterator_cTargetAwarenessPtr_ctor(It_DC60* out, E_DC60* in);
#endif /* merge_units */
#define cLListIterator_cTargetAwarenessPtr_ctor(a0, a1) (cLListIterator_cTargetAwarenessPtr_ctor((It_DB40 *)(a0), (E_DB40 *)(a1))) /* merge_units */


void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int* out, void* map, char** first, char** last);
}
static inline void Free_DC60(void* v)
{
    AllocGuard g;
    cMemMan_Deallocate(0, v, D_0049C650, 0x235);
}
static inline void Begin0_DC60(It_DC60* out, void* map) { E_DC60 t; std_list_cTargetAwarenessPtr_begin(&t, map); cLListIterator_cTargetAwarenessPtr_ctor(out, &t); }
static inline void End0_DC60(It_DC60* out, void* map) { E_DC60 t; std_list_cTargetAwarenessPtr_end_void(&t, map); cLListIterator_cTargetAwarenessPtr_ctor(out, &t); }
static inline void Begin_DC60(It_DC60* out, void* map) { Begin0_DC60(out, map); }
static inline void End_DC60(It_DC60* out, void* map) { End0_DC60(out, map); }
static inline void Erase_DC60(Perc_DC60* self)
{
    int res;
    char* first;
    char* last;
    last = self->hdr;
    first = self->first;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&res, self->map, &first, &last);
}
typedef struct It_DC60 It_DC60;
typedef struct E_DC60 E_DC60;
typedef struct Perc_DC60 Perc_DC60;
#pragma cplusplus off
void cAITarget_dtor(Perc_DC60* self)
{
    It_DC60 it;
    It_DC60 b;
    It_DC60 end;
    Begin_DC60(&b, self->map);
    it = b;
    while (End_DC60(&end, self->map), it.n != end.n) {
        Free_DC60(it.n->val);
        it.n = it.n->next;
    }
    Erase_DC60(self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016DC60(void) {}
#undef std_list_cTargetAwarenessPtr_end_void /* merge_units */
#undef std_list_cTargetAwarenessPtr_begin /* merge_units */
#undef cLListIterator_cTargetAwarenessPtr_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DC60 */

/* merge_units: begin func_0016DDB0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0xC]; int serial; char pad10[0x48]; int f58; } Tgt_DDB0;
typedef struct { char pad[0x10]; char pos[0x2A]; unsigned char b3A; } Rec_DDB0;
typedef struct { char pad[8]; Rec_DDB0* val; } Node_DDB0;
typedef struct {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
} Flags_DDB0;
typedef struct {
    char pad[0x1C];
    int prio;
    Flags_DDB0 flags;
    char pad21[0xF];
    char map[0x10];
    Tgt_DDB0* target;
    int serial;
} Perc_DDB0;
extern "C" char g_TargetVisMgr[];
#if 0 /* merge_units */
extern "C" void cAITarget_cAwareList_Find(Node_DDB0** out, void* map, Tgt_DDB0* key);
#endif /* merge_units */
#define cAITarget_cAwareList_Find(a0, a1, a2) (cAITarget_cAwareList_Find((It_DB40 *)(a0), (a1), (Tgt_DB40 *)(a2))) /* merge_units */


#if 0 /* merge_units */
extern "C" void std_list_cTargetAwarenessPtr_end_void(Node_DDB0** out, void* map);
#endif /* merge_units */
#define std_list_cTargetAwarenessPtr_end_void(a0, a1) (std_list_cTargetAwarenessPtr_end_void((E_DB40 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern "C" void cLListIterator_cTargetAwarenessPtr_ctor(Node_DDB0** out, Node_DDB0** in);
#endif /* merge_units */
#define cLListIterator_cTargetAwarenessPtr_ctor(a0, a1) (cLListIterator_cTargetAwarenessPtr_ctor((It_DB40 *)(a0), (E_DB40 *)(a1))) /* merge_units */


extern "C" void cAITarget_SetTargetPositionLastSeen(Perc_DDB0* self, Tgt_DDB0* t, void* pos, int f);
extern "C" void cTargetManager_AddGobj(void* mgr, Tgt_DDB0* t);
extern "C" void cAITarget_SetTarget(Perc_DDB0* self, Tgt_DDB0* t, int prio)
{
    Node_DDB0* it;
    Node_DDB0* end;
    int def;
    Node_DDB0* tmp;
    Tgt_DDB0* cur;
    {
        bool isNull;
        bool ok;
        Tgt_DDB0* c;
        c = self->target;
        isNull = !c;
        ok = true;
        if (!isNull) if (c->serial != self->serial) ok = false;
        cur = ok ? c : 0;
    }
    if (t == cur && t)
        return;
    if (prio < self->prio)
        return;
    self->target = t;
    self->serial = *(t ? &t->serial : (def = -1, &def));
    self->prio = prio;
    int v = 0;
    self->flags.b3 = v;
    self->flags.b4 = v;
    self->flags.b0 = v;
    self->flags.b1 = v;
    self->flags.b2 = v;
    self->flags.b2 = v;
    self->flags.b6 = v;
    if (t) {
        cAITarget_cAwareList_Find(&it, self->map, t);
        std_list_cTargetAwarenessPtr_end_void(&tmp, self->map);
        cLListIterator_cTargetAwarenessPtr_ctor(&end, &tmp);
        if (it != end) {
            self->flags.b3 = it->val->b3A;
            cAITarget_SetTargetPositionLastSeen(self, t, it->val->pos, 0);
        }
        if (t->f58 == 0)
            cTargetManager_AddGobj(g_TargetVisMgr, t);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016DDB0(void) {}
#undef cAITarget_cAwareList_Find /* merge_units */
#undef std_list_cTargetAwarenessPtr_end_void /* merge_units */
#undef cLListIterator_cTargetAwarenessPtr_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DDB0 */

/* merge_units: begin func_0016DFA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Initializes a few fields of an AI state record.
 */


extern char g_LevelFarDistance[]; /* float */
extern char g_VideoFrameCounter[]; /* pointer */

typedef struct AIStateInit {
    char pad00[0x10];
    float unk10;  /* 0x10 */
    int unk14;    /* 0x14: written as the bit pattern of pi/4 */
    char pad18[0x38];
    int unk50;    /* 0x50 */
} AIStateInit;

void cAITarget_Activate(AIStateInit* self) {
    self->unk14 = 0x3F490FDB; /* 0.7853982f */
    self->unk10 = *(float*)g_LevelFarDistance;
    self->unk50 = *(int*)g_VideoFrameCounter + 20;
}
static inline void merge_flush_func_0016DFA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DFA0 */

/* merge_units: begin func_0016DFD0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cAITarget_dtor(void* self);
#endif /* merge_units */
#define cAITarget_dtor(a0) (cAITarget_dtor((Perc_DC60 *)(a0))) /* merge_units */

extern void cLList_cTargetAwarenessPtr_dtor(void* p, int flag);
#if 0 /* merge_units */
extern void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

void* func_0016DFD0(char* self, short flag)
{
    if (self) {
        void* m;
        cAITarget_dtor(self);
        m = self + 0x30;
        if (m)
            cLList_cTargetAwarenessPtr_dtor(m, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#undef cAITarget_dtor /* merge_units */
#undef operator_delete /* merge_units */
static inline void merge_flush_func_0016DFD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DFD0 */
