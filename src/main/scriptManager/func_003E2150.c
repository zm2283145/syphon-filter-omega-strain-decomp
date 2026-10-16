#pragma cplusplus on
#include "types.h"
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
void Mem_Free(int, void*, char*, int);
void func_0012F530(G_E2150* g, int f);
void func_00136DA0(G_E2150* g);
void Script_ClearSchedules_3DFB20(void);
void func_003E2640(It_E2150*, void*);
void func_003E2630(It_E2150*, void*);
void Tree_Successor(It_E2150*);
void func_003E18A0(void*, int);
void func_003E25C0(void*, int);
void ActiveList_EraseMatching(void*, Pred_E2150);
void func_003DC8A0(void*, int);
void func_001633D0(int*, int, int, int*);
void func_003E2520(FA_E2150*, unsigned int, int*);
void** func_003E2510(PV_E2150*, int);
void func_00175240(void*, int);
void ScriptStr_Release(Mgr_E2150*, void*);
void PtrVec_Reserve(PV_E2150*, int);
void func_003D7960(void);
void func_003E3320(int*, Mgr_E2150*, int*, int*);
}
struct G_E2150 { char c; G_E2150() { func_00136DA0(this); } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~G_E2150() { func_0012F530(this, -1); } };
static inline int PNe_E2150(Node_E2150* a, Node_E2150* b) { return (a == b) ^ 1; }
static inline bool ItEq_E2150(const It_E2150& a, const It_E2150& b) { return a.p == b.p; }
static inline bool ItNe_E2150(const It_E2150& a, const It_E2150& b) { return !ItEq_E2150(a, b); }
static inline Pred_E2150 MakePred_E2150(void** p) { Cmp_E2150 c; return Pred_E2150(c, p); }
static inline void D3_E2150(void* p) { if (p) func_00175240(p, 0); }
static inline void D2_E2150(void* p) { if (p) D3_E2150(p); }
static inline void D1_E2150(void* p) { if (p) D2_E2150(p); }
static inline void D0_E2150(void* p) { if (p) D1_E2150(p); }
static inline void* Back_E2150(PV_E2150* v) { return v->data[v->count - 1]; }
static inline void DelL0_E2150(void* l) { G_E2150 g; func_003E18A0(l, -1); Mem_Free(0, l, D_004BD4C0, 0x7F); }
static inline void DelM0_E2150(void* mp) { G_E2150 g; func_003E25C0(mp, -1); Mem_Free(0, mp, D_004BD4C0, 0x81); }
static inline void DelL_E2150(void* l) { DelL0_E2150(l); }
static inline void DelM_E2150(void* l) { DelM0_E2150(l); }
static inline void DelO_E2150(void* p) { AllocGuard g; func_003DC8A0(p, -1); Mem_Free(0, p, D_004BD4C0, 0x88); }
static inline void DelS_E2150(void* p) { AllocGuard g; if (p) { if (p) { if (p) { if (p) func_00175240(p, 0); } } } Mem_Free(0, p, D_004BD4C0, 0x92); }

static inline void ListClear_E2150(Mgr_E2150* m)
{
    int r;
    int first;
    int last;
    last = (int)&m->x4;
    first = m->x8;
    func_003E3320(&r, m, &first, &last);
}

extern "C" void Script_Cleanup(Mgr_E2150* m)
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
            Tree_Successor(&it);
        }
    }
    DelM_E2150(m->map);
    m->map = 0;
    while (m->alCount > m->x4E60) {
        o = m->alHead->val;
        ActiveList_EraseMatching(&m->alCount, MakePred_E2150(&o));
        {
            void* p = o;
            AllocGuard g;
            func_003DC8A0(p, -1);
            Mem_Free(0, p, D_004BD4C0, 0x88);
        }
    }
    {
        unsigned int n = m->x4E64;
        if (n < 5001) {
            func_001633D0(m->fa.a, m->fa.n, n - 1, &D_004938D8);
            m->fa.n = n;
        } else {
            func_003E2520(&m->fa, 5000, &D_004938E0);
        }
    }
    for (i = 0; i < m->objs.count; i++)
    {
        void* p = *func_003E2510(&m->objs, i);
        AllocGuard g;
        if (p) { if (p) { if (p) { if (p) func_00175240(p, 0); } } }
        Mem_Free(0, p, D_004BD4C0, 0x92);
    }
    while (*(volatile int*)&m->strs.count > 0)
        ScriptStr_Release(m, Back_E2150(&m->strs));
    PtrVec_Reserve(&m->strs, 0x80);
    m->objs.count = 0;
    PtrVec_Reserve(&m->objs, 0x100);
    m->x4E70 = m->x4E6C + m->x4E78;
    m->x4E7C = 0;
    m->x4E90 = 0;
    m->x4E98 = 0;
    m->b4E94 = 0;
    m->x4E9C = 0;
    m->x4EA0 = 0;
    m->x4E84 = 0;
    m->x4E80 = 0;
    func_003D7960();
    {
        int r;
        int first;
        int last;
        last = (int)&m->x4;
        first = m->x8;
        func_003E3320(&r, m, &first, &last);
    }
}