#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
/* Hotbox_CreateRuntime: create a runtime hotbox sized from an actor's bounds and register it */
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
extern char g_HotboxList[];
void IdMgr_Allocate(int* id, int kind);
void* Mem_Alloc(int pool, int size, char* file, int line);
/* the two V4 parameters are by value: the caller passes pointers to its own copies */
HotboxH* cHotbox_ctor2(void* self, int* gid, unsigned char type, V4H* mn, V4H* mx);
BoxH Hotbox_ComputeNpcBounds(void* o, int flag);
void Hotbox_AddToGlobalList(void* list, HotboxH** h);
void Object_Register(void* o);
void cHotbox_AddTarget(HotboxH* h, void* o);
HotboxH* Hotbox_CreateRuntime(void* unused, void* o, int flag, int big);
}
static inline V4H& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f;
        D_004E1D88 = 1;
    }
    return D_004E1D90;
}
HotboxH* Hotbox_CreateRuntime(void* unused, void* o, int flag, int big)
{

    int id;
    int kind;
    void* p;
    HotboxH* h;
    IdMgr_Allocate(&id, 244);
    if (big) { kind = 18; } else { kind = 8; asm { .set reorder } }
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0xB0, D_0049C878, 0x391);
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
        h = cHotbox_ctor2(h, &id, kind, pn, px);
    }
    h->box = Hotbox_ComputeNpcBounds(o, flag);
    {
        HotboxH* t = h;
        Hotbox_AddToGlobalList(g_HotboxList, &t);
    }
    Object_Register(h);
    cHotbox_AddTarget(h, o);
    h->Activate(0);
    return h;
}
