/*
 * SFOGame/Source/hotbox: 2 files, 00170DB0-00170E20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00170DB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Eq_0DB0 {};
struct Pred_0DB0 { Eq_0DB0 op; int* ref; Pred_0DB0(const Eq_0DB0& e, int* r) : op(e), ref(r) {} };
struct S_0DB0 { char pad[0x28]; char list[4]; };
extern "C" {
extern char g_HotboxList[];
void std_list_imp_voidPtr_remove_if(void* list, Pred_0DB0 p);
}
extern "C" void cHotboxMan_RemoveHotbox(S_0DB0* self, int id)
{
    Eq_0DB0 e1;
    Eq_0DB0 e2;
    std_list_imp_voidPtr_remove_if(g_HotboxList, Pred_0DB0(e1, &id));
    std_list_imp_voidPtr_remove_if(self->list, Pred_0DB0(e2, &id));
}
static inline void merge_flush_func_00170DB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170DB0 */

/* merge_units: begin func_00170E20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* cHotboxMan_CreateInteractBox: create a runtime hotbox sized from an actor's bounds and register it */
struct V4H { float x, y, z, w; V4H() {} // 128-bit lq/sq quadword copy idiom
    V4H& operator=(const V4H& o) { V4H* d = this; const V4H* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); return *this; } V4H(const V4H& o) { V4H* d = this; const V4H* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); } } __attribute__((aligned(16)));
struct BoxH { V4H lo; V4H hi; BoxH() {} BoxH& operator=(const BoxH& o) { __int128 a; __int128 b; BoxH* d = this; const BoxH* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); sq %1, 0x10(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); return *this; } };
struct HotboxH {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void Activate(int on);
    char p4[0x70 - 4];
    BoxH box;
};
extern "C" {
extern signed char D_004E1D88;
extern V4H D_004E1D90;
extern char D_0049C878[];
void nGobjManager_GetNextId(int* id, int kind);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
/* the two V4 parameters are by value: the caller passes pointers to its own copies */
HotboxH* cHotbox_ctor_cObjectIdR_int_cVector_cVector(void* self, int* gid, unsigned char type, V4H* mn, V4H* mx);
BoxH CalculateInteractBoxDimensionsAndLocation(void* o, int flag);
void cLList_cHotboxPtr_PushBackActual(void* list, HotboxH** h);
void nGobjManager_AddGOBJ(void* o);
void cHotbox_AddTarget(HotboxH* h, void* o);
HotboxH* cHotboxMan_CreateInteractBox(void* unused, void* o, int flag, int big);
}
static inline V4H& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f;
        D_004E1D88 = 1;
    }
    return D_004E1D90;
}
HotboxH* cHotboxMan_CreateInteractBox(void* unused, void* o, int flag, int big)
{

    int id;
    int kind;
    void* p;
    HotboxH* h;
    nGobjManager_GetNextId(&id, 244);
    if (big) { kind = 18; } else { kind = 8; asm { .set reorder } }
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, 0xB0, D_0049C878, 0x391);
    }
    h = (HotboxH*)p;
    if (h) {
        V4H mx;
        V4H mn;
        V4H* pn;
        V4H* px;
        /* argument copies; each address is formed right after its copy like retail (the int round
         * trip keeps MW from folding it into the call setup) */
        mn = Zero();
        pn = (V4H*)(int)&mn;
        mx = Zero();
        px = (V4H*)(int)&mx;
        h = cHotbox_ctor_cObjectIdR_int_cVector_cVector(h, &id, kind, pn, px);
    }
    h->box = CalculateInteractBoxDimensionsAndLocation(o, flag);
    {
        HotboxH* t = h;
        cLList_cHotboxPtr_PushBackActual(g_HotboxList, &t);
    }
    nGobjManager_AddGOBJ(h);
    cHotbox_AddTarget(h, o);
    h->Activate(0);
    return h;
}
static inline void merge_flush_func_00170E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170E20 */
