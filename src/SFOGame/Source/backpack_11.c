/*
 * SFOGame/Source/backpack: 6 files, 00256D50-00257150
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00256D50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * List / vector helpers.
 */

#include "types.h"

extern int std_list_deleter_voidPtr_insert(Iter* result, List* list, Iter* pos, int value);

/* push_back(value): inserts before the end sentinel at list+4. */
int std_list_CrateSavePtr_push_back(List* list, int value) {
    Iter it[2];   /* it[0] = end position, it[1] = returned iterator */
    it[0].p = (int*)&list->first;
    return std_list_deleter_voidPtr_insert(&it[1], list, &it[0], value);
}

int* std_vector_cBackpackPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_00256D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00256D50 */

/* merge_units: begin func_00256D90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* cBackpack_ResetCrates: copy every crate snapshot (cBackpack_SaveCratesInfo) back into
 * the backpack with the same id and give it a runtime hotbox if it has none. */

struct RT { char pad[0x94]; int id; };
struct Crate {
    char pad0[0xC];
    int id;
    char pad10[0x60 - 0x10];
    char pad60[4];
    char body[0x27C];
    int f2E0, f2E4, f2E8, f2EC;
    char pad2F0[0x2FC - 0x2F0];
    RT* rt;
};

struct Snapshot {
    int id;
    char body[0x27C];
    int f280, f284, f288, f28C;
};

struct CrateVec {
    int pad0;
    int count;
    Crate** items;
};

struct Raw { int p; };
struct SNode { SNode* prev; SNode* next; Snapshot* snap; };
extern "C" {
extern CrateVec* g_BackpackList;
extern char D_004F7F48[];
#if 0 /* merge_units */
Crate** std_vector_cBackpackPtr_opIndex(CrateVec* v, int i);
#endif /* merge_units */
#define std_vector_cBackpackPtr_opIndex(a0, a1) ((Crate * *)std_vector_cBackpackPtr_opIndex((PtrVec *)(a0), (a1))) /* merge_units */

void cBackpack_ResetCrates(void);
extern int g_HotboxTracker;
RT* cHotboxMan_CreateInteractBox(int tracker, Crate* c, int flag, int big);
Raw std_list_deleter_voidPtr_begin_void(void* list);
Raw std_list_CrateSavePtr_end(void* list);
void std_list_CrateSavePtr_generic_iterator_ctor(SNode** out, const Raw& r);
void cLListIterator_CrateSavePtr_ctor(SNode** out, const Raw& r);
}

/* byte/quadword copy macro (cLoader_AllocateAndFillAnimationBuffer.c's, without the nop after the alignment branch, as
 * retail has it here); volatile because retail recomputes the index scaling after the copy (a
 * non-volatile block lets MW keep i*4 in a saved register) */
static inline void MemCopy(void* dst, void* src, int n)
{
    int t;
    int m;
    asm volatile {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}

struct SIt {
    SNode* p;
    SIt() {}
    SIt(const SIt& o) { p = o.p; }
    SIt& operator=(const SIt& o) { p = o.p; return *this; }
};

void cBackpack_ResetCrates(void)
{
    CrateVec* list = g_BackpackList;
    SIt it;
    SIt old;
    SNode* end;
    SNode* b;
    SIt r;
    SIt t;
    int i;
    std_list_CrateSavePtr_generic_iterator_ctor(&b, std_list_deleter_voidPtr_begin_void(D_004F7F48));
    it.p = b;
    while ((cLListIterator_CrateSavePtr_ctor(&end, std_list_CrateSavePtr_end(D_004F7F48)), it.p != end)) {
        for (i = 0; i < list->count; i++) {
            Crate* c = *std_vector_cBackpackPtr_opIndex(list, i);
            Snapshot* s = it.p->snap;
            if (s->id == c->id) {
                { int v = it.p->snap->f280; list->items[i]->f2E0 = v; }
                { int v = it.p->snap->f284; list->items[i]->f2E4 = v; }
                { int v = it.p->snap->f288; list->items[i]->f2E8 = v; }
                { int v = it.p->snap->f28C; list->items[i]->f2EC = v; }
                MemCopy((*std_vector_cBackpackPtr_opIndex(list, i))->body, it.p->snap->body, sizeof(it.p->snap->body));
                if (!list->items[i]->rt) {
                    Crate* k = *std_vector_cBackpackPtr_opIndex(list, i);
                    if (!k->rt) {
                        RT* q;
                        int id;
                        k->rt = cHotboxMan_CreateInteractBox(g_HotboxTracker, k, 0, 1);
                        id = k->id;
                        q = k->rt;
                        q->id = id;
                    }
                }
            }
        }
        /* it++ (post-increment, result kept): t = it, advance, r = t, old = r */
        t = it;
        it.p = it.p->next;
        r = t;
        old = r;
    }
}
#undef std_vector_cBackpackPtr_opIndex /* merge_units */
static inline void merge_flush_func_00256D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00256D90 */

/* merge_units: begin func_00256FD0 */
#pragma push /* merge_units */
typedef struct { int id; int a[4]; int b[4]; int pad; } G3En_00256FD0;
typedef struct { G3En_00256FD0 e[5]; int pad2; int cc; unsigned char d0; } G3El_00256FD0;
typedef struct { int pad; G3El_00256FD0 el[3]; int x280[4]; } G3S_00256FD0;
void cBackpack_InitCrate(G3S_00256FD0* s) {
    int j, i, k;
    for (i = 0; i < 4; i++) s->x280[i] = 0;
    for (j = 0; j < 3; j++) {
        s->el[j].cc = 0;
        s->el[j].d0 = 0;
        for (i = 0; i < 5; i++) {
            for (k = 0; k < 4; k++) {
                s->el[j].e[i].a[k] = 0;
                s->el[j].e[i].b[k] = 0;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00256FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00256FD0 */

/* merge_units: begin func_00257040 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { char pad[0x2F3]; unsigned char b2F3; char pad2[0x308 - 0x2F4]; int x308; } G3E_00257040;
typedef struct { int pad; int count; G3E_00257040** items; } G3L_00257040;
extern unsigned char g_IsMultiplayer;
#if 0 /* merge_units */
extern G3L_00257040* g_BackpackList;
#endif /* merge_units */
#define g_BackpackList (*(G3L_00257040 **)&g_BackpackList) /* merge_units */

void func_00257040(int x) {
    if (g_IsMultiplayer) {
        G3L_00257040* l = g_BackpackList;
        int i;
        for (i = 0; i < l->count; i++) {
            G3E_00257040* e = l->items[i];
            if (!e->b2F3) {
                int* p = &e->x308;
                if (x == *p) *p = 0;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00257040(void) {}
#undef g_BackpackList /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257040 */

/* merge_units: begin func_002570C0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
typedef struct BackpackEntry{char pad[0x60];unsigned char active;}BackpackEntry;
typedef struct BackpackRegistry{int capacity,count;BackpackEntry**items;}BackpackRegistry;
#if 0 /* merge_units */
extern BackpackRegistry*g_BackpackList;
#endif /* merge_units */
#define g_BackpackList (*(BackpackRegistry **)&g_BackpackList) /* merge_units */


void cBackpack_Remove(BackpackEntry*);void ResetInteractBoxes(void);
static inline int Identity(int n){return n;}
void cBackpack_RemoveAll(void){BackpackRegistry*list=g_BackpackList;int i;for(i=0;i<list->count;i++){int offset=i<<2;int base=(int)list->items;BackpackEntry*p=*(BackpackEntry**)(base+offset);if(!p->active){i--;cBackpack_Remove(p);}}cBackpack_ResetCrates();ResetInteractBoxes();}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002570C0(void) {}
#undef g_BackpackList /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002570C0 */

/* merge_units: begin func_00257150 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
typedef struct BackpackRegistry_00257150{int capacity,count;void**items;}BackpackRegistry_00257150;
#if 0 /* merge_units */
extern BackpackRegistry_00257150*g_BackpackList;
#endif /* merge_units */
#define g_BackpackList (*(BackpackRegistry_00257150 **)&g_BackpackList) /* merge_units */
extern int D_004F7F70;extern char D_004A7B50[];
void nGobjManager_RemoveGOBJ(void*);void cSystem_ActualScheduleDelete(void*,float);void cArray_cBackpackPtr_dtor(BackpackRegistry_00257150*,int);
void cTimerDisable_ctor(int*);void cTimerDisable_dtor(int*,int);void cMemMan_Deallocate(int,void*,char*,int);
void cBackpack_Reset(void){
 BackpackRegistry_00257150*list=g_BackpackList;int i;int guard;
 for(i=0;i<list->count;i++){int off=i*4;nGobjManager_RemoveGOBJ(*(void**)((char*)list->items+off));cSystem_ActualScheduleDelete(*(void**)((char*)list->items+off),0.1f);}
 list=g_BackpackList;cTimerDisable_ctor(&guard);cArray_cBackpackPtr_dtor(list,-1);cMemMan_Deallocate(0,list,D_004A7B50,0x18A);cTimerDisable_dtor(&guard,-1);g_BackpackList=0;D_004F7F70=0;
}
#undef g_BackpackList /* merge_units */
static inline void merge_flush_func_00257150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257150 */
