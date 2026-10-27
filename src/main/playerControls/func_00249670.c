#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator*(float k) const { V r; V* rp = &r; const V* tp = this; __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(tp), "r"(rp), "f"(k) : "memory"); return r; }
    V operator+(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
} __attribute__((aligned(16)));

struct CamView { char pad[0x10]; V dir; char pad20[0x10]; V pos; };
struct Cam { char pad[0xDA0]; CamView view; };

extern "C" {
extern unsigned char g_IsMultiplayer;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern char D_004E0140[];
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void cPlayerControls_NetSetManualTarget(void* s, void* actor, V* v);
}

struct MsgB {
    void* vt; char base[0x1C]; unsigned char b20; char p21[3]; int type; unsigned char kind; char p29[3];
    MsgB() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgB() { vt = D_004E0840; cMessage_dtor(this, 0); }
    void Send(void* to) { b20 = 1; QueueMessage_cMessageR_cSystemP_int(this, to, 1); }
    void Init(int t, unsigned char k) { cMessage_ctor_cMessageNameR(this, g_ActorActionMsgClass); vt = D_004E0840; type = t; kind = k; }
};
struct MsgPt : MsgB { char p2C[4]; V pt; MsgPt(const V& v) { MsgPt* p = this; p->Init(0x39, 4); p->vt = D_004E0140; p->pt = v; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgPt() {} };

extern "C" void cPlayerControls_SetManualAimWeaponTargetInHuman(void* s, Cam* cam, void* actor)
{
    CamView* cv = &cam->view;
    V pos = cv->pos;
    V dir = cv->dir;
    float k = 100.0f;
    V pt = pos + dir * k;
    MsgPt(pt).Send(actor);
    if (g_IsMultiplayer) cPlayerControls_NetSetManualTarget(s, actor, &pt);
}



