/*
 * Libs/SFOLib/Source/scriptManager: 3 files, 003E20A0-003E2150
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E20A0 */
#pragma push /* merge_units */
#include "types.h"
#include "scriptManager_types.h"

extern unsigned char D_004938D0;
extern int cScriptInterpreter_LoadScript(void* self, const char* name, int a2);
extern void cScriptInterpreter_ExecuteInitCode(void* self);
extern int cScriptInterpreter_CallFunction(void* self, const char* name, int a2);
extern unsigned char cScriptInterpreter_CheckAllReferences(void* self);

/* Runs the load steps in order; returns 1 only if every step succeeds. */
unsigned char cScriptInterpreter_ExecInitScript(void* self)
{
    unsigned char ok = 0;
    if (D_004938D0 && cScriptInterpreter_LoadScript(self, "init", 0) && cScriptInterpreter_LoadScript(self, "utils", 0)) {
        cScriptInterpreter_ExecuteInitCode(self);
        ok = cScriptInterpreter_CallFunction(self, "init::Init", 0) != 0;
        if (ok)
            ok = cScriptInterpreter_CheckAllReferences(self);
    }
    return ok;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E20A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E20A0 */

/* merge_units: begin func_003E2140 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void cScriptInterpreter_SetHog(ScriptManager* self, int value) {
    self->unk4E90 = value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E2140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E2140 */

/* merge_units: begin func_003E2150 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct G_E2150;
struct Node_E2150 { char pad[0x10]; void* val; };
struct It_E2150 { Node_E2150* p; };
struct ANode_E2150 { int x0; int x4; void* val; };
struct Cmp_E2150 {};
struct Pred_E2150 { Cmp_E2150 cmp; void** pp; Pred_E2150(const Cmp_E2150& c, void** p) : cmp(c), pp(p) {} };
struct FA_E2150 { int n; int a[5000]; };
struct PV_E2150 { int x0; int count; void** data; };
struct Mgr_E2150 {
    int x0; int x4; int x8;
    int alCount; ANode_E2150* alHead; int x14;
    PV_E2150 strs; int x24;
    FA_E2150 fa;
    PV_E2150 objs;
    int pad4E58;
    void* map;
    int x4E60; int x4E64; int x4E68; int* x4E6C; int* x4E70; int x4E74; int x4E78; int x4E7C;
    int x4E80; int x4E84; int x4E88; int x4E8C; int x4E90; unsigned char b4E94; char pad4E95[3];
    int x4E98; int x4E9C; int x4EA0;
};
extern "C" {
extern char D_004BD4C0[];
extern int D_004938D8;
extern int D_004938E0;
void cMemMan_Deallocate(int, void*, char*, int);
void cTimerDisable_dtor(G_E2150* g, int f);
void cTimerDisable_ctor(G_E2150* g);
void Script_ClearSchedules_3DFB20(void);
void func_003E2640(It_E2150*, void*);
void func_003E2630(It_E2150*, void*);
void std_red_black_tree_1_increment(It_E2150*);
void cArray_FuncDefPtr_dtor(void*, int);
void cAssocArray_int_cArray_FuncDefPtrPtr_dtor(void*, int);
void std_list_imp_voidPtr_remove_if(void*, Pred_E2150);
void cScriptInterpreter_SymbolTable_dtor(void*, int);
void nArray_InitSlots_intP_int_int_intR(int*, int, int, int*);
void cArray_FixedCapacity_int_5000_ResizeActual(FA_E2150*, unsigned int, int*);
void** std_vector_cGroupPtr_opIndex(PV_E2150*, int);
void std_vector_deleter_cObjectId_dtor(void*, int);
void cScriptInterpreter_removeString(Mgr_E2150*, void*);
void std_vector_pod_int_reserve(PV_E2150*, int);
void cScriptBase_FreeScriptSyms(void);
void std_list_deleter_PopVar_erase(int*, Mgr_E2150*, int*, int*);
}
struct G_E2150 { char c; G_E2150() { cTimerDisable_ctor(this); } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~G_E2150() { cTimerDisable_dtor(this, -1); } };
static inline int PNe_E2150(Node_E2150* a, Node_E2150* b) { return (a == b) ^ 1; }
static inline bool ItEq_E2150(const It_E2150& a, const It_E2150& b) { return a.p == b.p; }
static inline bool ItNe_E2150(const It_E2150& a, const It_E2150& b) { return !ItEq_E2150(a, b); }
static inline Pred_E2150 MakePred_E2150(void** p) { Cmp_E2150 c; return Pred_E2150(c, p); }
static inline void D3_E2150(void* p) { if (p) std_vector_deleter_cObjectId_dtor(p, 0); }
static inline void D2_E2150(void* p) { if (p) D3_E2150(p); }
static inline void D1_E2150(void* p) { if (p) D2_E2150(p); }
static inline void D0_E2150(void* p) { if (p) D1_E2150(p); }
static inline void* Back_E2150(PV_E2150* v) { return v->data[v->count - 1]; }
static inline void DelL0_E2150(void* l) { G_E2150 g; cArray_FuncDefPtr_dtor(l, -1); cMemMan_Deallocate(0, l, D_004BD4C0, 0x7F); }
static inline void DelM0_E2150(void* mp) { G_E2150 g; cAssocArray_int_cArray_FuncDefPtrPtr_dtor(mp, -1); cMemMan_Deallocate(0, mp, D_004BD4C0, 0x81); }
static inline void DelL_E2150(void* l) { DelL0_E2150(l); }
static inline void DelM_E2150(void* l) { DelM0_E2150(l); }
static inline void DelO_E2150(void* p) { AllocGuard g; cScriptInterpreter_SymbolTable_dtor(p, -1); cMemMan_Deallocate(0, p, D_004BD4C0, 0x88); }
static inline void DelS_E2150(void* p) { AllocGuard g; if (p) { if (p) { if (p) { if (p) std_vector_deleter_cObjectId_dtor(p, 0); } } } cMemMan_Deallocate(0, p, D_004BD4C0, 0x92); }

static inline void ListClear_E2150(Mgr_E2150* m)
{
    int r;
    int first;
    int last;
    last = (int)&m->x4;
    first = m->x8;
    std_list_deleter_PopVar_erase(&r, m, &first, &last);
}

extern "C" void cScriptInterpreter_Reset(Mgr_E2150* m)
{
    It_E2150 it;
    void* o;
    int i;
    Script_ClearSchedules_3DFB20();
    {
        It_E2150 t1;
        func_003E2640(&t1, m->map);
        it = t1;
    }
    {
        It_E2150 end;
        {
            It_E2150 t2;
            func_003E2630(&t2, m->map);
            end = t2;
        }
        while (PNe_E2150(it.p, end.p)) {
            DelL_E2150(it.p->val);
            std_red_black_tree_1_increment(&it);
        }
    }
    DelM_E2150(m->map);
    m->map = 0;
    while (m->alCount > m->x4E60) {
        o = m->alHead->val;
        std_list_imp_voidPtr_remove_if(&m->alCount, MakePred_E2150(&o));
        {
            void* p = o;
            AllocGuard g;
            cScriptInterpreter_SymbolTable_dtor(p, -1);
            cMemMan_Deallocate(0, p, D_004BD4C0, 0x88);
        }
    }
    {
        unsigned int n = m->x4E64;
        if (n < 5001) {
            nArray_InitSlots_intP_int_int_intR(m->fa.a, m->fa.n, n - 1, &D_004938D8);
            m->fa.n = n;
        } else {
            cArray_FixedCapacity_int_5000_ResizeActual(&m->fa, 5000, &D_004938E0);
        }
    }
    for (i = 0; i < m->objs.count; i++)
    {
        void* p = *std_vector_cGroupPtr_opIndex(&m->objs, i);
        AllocGuard g;
        if (p) { if (p) { if (p) { if (p) std_vector_deleter_cObjectId_dtor(p, 0); } } }
        cMemMan_Deallocate(0, p, D_004BD4C0, 0x92);
    }
    while (*(volatile int*)&m->strs.count > 0)
        cScriptInterpreter_removeString(m, Back_E2150(&m->strs));
    std_vector_pod_int_reserve(&m->strs, 0x80);
    m->objs.count = 0;
    std_vector_pod_int_reserve(&m->objs, 0x100);
    m->x4E70 = m->x4E6C + m->x4E78;
    m->x4E7C = 0;
    m->x4E90 = 0;
    m->x4E98 = 0;
    m->b4E94 = 0;
    m->x4E9C = 0;
    m->x4EA0 = 0;
    m->x4E84 = 0;
    m->x4E80 = 0;
    cScriptBase_FreeScriptSyms();
    {
        int r;
        int first;
        int last;
        last = (int)&m->x4;
        first = m->x8;
        std_list_deleter_PopVar_erase(&r, m, &first, &last);
    }
}
static inline void merge_flush_func_003E2150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E2150 */
