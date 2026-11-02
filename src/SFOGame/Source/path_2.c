/*
 * SFOGame/Source/path: 4 files, 0015D130-0015D200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015D130 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_3(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
static inline void merge_flush_func_0015D130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015D130 */

/* merge_units: begin func_0015D170 */
#pragma push /* merge_units */
extern void cSystem_ScriptGetObjectId();
extern void cSystem_ScriptGetRealObj();
extern void cSystem_SendCreated();
extern void cSystem_NetActivate();
extern void cSystem_NetDeactivate();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSystem_IsNetworked();
extern void cPathSystem_HandleMessage();
extern void cSystem_getSOBJClassId();
extern void cSystem_ScriptHandleMessage();
extern void * const D_004D96C0[];
#if 0 /* merge_units */
extern void std_list_cPathSystemRequestPtr_dtor(void* p, int flag);
#endif /* merge_units */
void* std_list_cPathSystemRequestPtr_dtor(void* self, short deleteFlag); /* merge_units */
#define std_list_cPathSystemRequestPtr_dtor(a0, a1) ((void)std_list_cPathSystemRequestPtr_dtor((a0), (short)(a1))) /* merge_units */

extern void cSystem_dtor(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_D170;
S_D170* cPathSystem_dtor(S_D170* self, short flag)
{
    if (self) {
        void* m;
        self->vt = ((char*)D_004D96C0);
        m = (char*)self + 0x2C;
        if (m)
            std_list_cPathSystemRequestPtr_dtor(m, 0);
        m = (char*)self + 0x20;
        if (m)
            std_list_cPathSystemRequestPtr_dtor(m, 0);
        cSystem_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D96C0[16] = { (void*)0x0, (void*)0x0, (void*)cPathSystem_dtor, (void*)cPathSystem_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cSystem_getSOBJClassId, (void*)cSystem_ScriptHandleMessage, (void*)0x0 };
#undef std_list_cPathSystemRequestPtr_dtor /* merge_units */
static inline void merge_flush_func_0015D170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015D170 */

/* merge_units: begin func_0015D200 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "obj_list_dtor.h"
#pragma pop

#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cPathSystemRequestPtr_dtor)
static inline void merge_flush_func_0015D200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015D200 */

/* merge_units: begin func_0015D280 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int idx; int type; } F8Elem_15D;
struct F8It_15D {
    F8Elem_15D* p;
    bool operator==(const F8It_15D& o) const { return p == o.p; }
    bool operator!=(const F8It_15D& o) const { return !(*this == o); }
    F8It_15D& operator++() { p++; return *this; }
    F8Elem_15D* operator->() const { return p; }
};
typedef struct { char pad[0x68]; char list[4]; } F8Obj_15D;
typedef struct { char pad[8]; int* nodes; } F8Table_15D;
extern "C" {
F8Obj_15D* cAIPathData_GetNode(int self);
F8Elem_15D* std_vector_imp_tNodeLink_begin_void_2(void* c);
F8Elem_15D* std_vector_imp_tNodeLink_end_void_2(void* c);
F8It_15D std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(void* c, F8Elem_15D** raw);
extern F8Table_15D* D_004FFBE0;
}
static inline F8It_15D F8Begin(void* c) { F8Elem_15D* b = std_vector_imp_tNodeLink_begin_void_2(c); return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(c, &b); }
static inline F8It_15D F8End(void* c) { F8Elem_15D* e = std_vector_imp_tNodeLink_end_void_2(c); return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(c, &e); }
static inline F8It_15D F8CBegin(void* c) { F8It_15D r; r.p = F8Begin(c).p; return r; }
static inline bool F8More(F8It_15D& it, void* c) { return it != F8End(c); }
extern "C" int cAIPathData_GetNodeLinkType(int self, int type)
{
    int r;
    void* c;
    F8Table_15D* tbl = D_004FFBE0;
    r = 0;
    c = cAIPathData_GetNode(self)->list;
    F8It_15D it = F8CBegin(c);
    while (F8More(it, c)) {
        F8Elem_15D* e = it.p;
        if (type == e->type) {
            r = tbl->nodes[e->idx];
            break;
        }
        it.p = e + 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015D280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015D280 */
