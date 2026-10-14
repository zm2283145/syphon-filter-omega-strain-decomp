#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rebuildconditionals off

struct V_A {
    float x, y, z, w;
    V_A() {}
    V_A(const V_A& o) { V_A* d = this; const V_A* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V_A& operator=(const V_A& o) { V_A* d = this; const V_A* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    void Sub3(const V_A& a, const V_A& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(&a), "r"(&b) : "memory"); }
    void Sub(const V_A& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&b), "r"(this) : "memory"); }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
    void Normalize() {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory");
    }
    float Dot(const V_A& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));

struct M_A { V_A r[4]; const V_A& Up() const { return r[1]; } };

struct HObj_A { char pad[0xC]; int id; };

struct Actor_A {
    VPAD32(p) VPAD8(q) VPAD4(r) VPAD2(s)
    virtual V_A GetPos(int which);
    VPAD8(t) VPAD1(u)
    virtual M_A GetMtx();
    VPAD4(w) VPAD2(x) VPAD1(y)
    virtual unsigned char GetState();
    char pad04[0x14 - 4];
    unsigned char b14;
    char pad15[0x38 - 0x15];
    int x38;
    char pad3C[0x3204 - 0x3C];
    int x3204;
    char pad3208[0x354C - 0x3208];
    HObj_A* hobj;
    int hid;
};

struct Npc_A {
    VPAD32(p) VPAD32(q) VPAD16(r) VPAD4(s) VPAD2(t) VPAD1(u)
    virtual int IsActive();
    char pad04[0x30 - 4];
    Actor_A* actor;
    char pad34[0x114 - 0x34];
    int x114;
};

struct Cam_A {
    VPAD16(p) VPAD4(q)
    virtual void Update();
    char pad04[0x40 - 4];
    V_A pos;
    unsigned char b50;
};
struct CamHolder_A { char pad[0x50]; Cam_A* cam; };

struct Node_A { Node_A* prev; Node_A* next; Npc_A* npc; };
struct ItP_A { Node_A* p; };
struct It_A { ItP_A q; };
struct NpcList_A { int count; };

extern "C" {
extern NpcList_A D_004EA370;
extern char D_004FFC14[];
extern float D_0053834C;
extern unsigned char D_005721C8;
void func_00159580(It_A* out, NpcList_A* l);
void func_0014ABE0(It_A* out, NpcList_A* l);
It_A* func_0014ABD0(It_A* dst, It_A* src);
CamHolder_A** func_00159560(void* v);
int func_00159570(void* v);
Actor_A* PlayerSlots_Get(int i);
float Math_Cos(float a);
}

static inline bool Eq(int x, int y) { return x == y; }
static inline bool HOk(Actor_A* a)
{
    return !a->hobj || Eq(a->hobj->id, a->hid);
}
static inline Actor_A* WeakGet(Actor_A* a)
{
    return HOk(a) ? (Actor_A*)a->hobj : 0;
}

#define AVAIL(n) (!WeakGet((n)->actor) && ((n)->x114 != 7 || !(((n)->actor->x3204 >> 7) & 1)))


extern "C" bool Npc_IsDeadRemovalAllowed(Npc_A* self)
{
    bool result = false;
    if (self->actor->GetState() == 3 && self->IsActive() && AVAIL(self)) {
        bool ok = true;
        Actor_A* found = 0;
        NpcList_A* l = &D_004EA370;
        if (l->count > 3) {
            It_A it;
            It_A b;
            It_A e;
            It_A bi;
            It_A ei;
            func_00159580(&bi, l);
            func_0014ABD0(&b, &bi);
            it = b;
            goto cond;
            do {
                {
                    Npc_A* n = it.q.p->npc;
                    if (n->IsActive() && AVAIL(n)) {
                        found = it.q.p->npc->actor;
                        break;
                    }
                }
                it.q.p = it.q.p->next;
            cond:
                func_0014ABE0(&ei, &D_004EA370);
                func_0014ABD0(&e, &ei);
            } while (it.q.p != e.q.p);
        }
        if (found != self->actor) {
            float maxSq = D_0053834C * D_0053834C;
            V_A pos = self->actor->GetPos(-1);
            Cam_A* c = (func_00159570(D_004FFC14) ? *func_00159560(D_004FFC14) : 0)->cam;
            if (c->b50)
                c->Update();
            pos.Sub(c->pos);
            float d = pos.LenSq();
            if (d < 400.0f || (self->actor->x38 != 0x80 && d < maxSq)) {
                ok = false;
            } else if (D_005721C8) {
                for (int i = 0; i < 4; i++) {
                    Actor_A* p = PlayerSlots_Get(i);
                    if (p && !p->b14) {
                        pos = self->actor->GetPos(-1);
                        pos.Sub3(pos, p->GetPos(-1));
                        if (pos.LenSq() < 400.0f) {
                            ok = false;
                            break;
                        }
                        if (pos.LenSq() < maxSq) {
                            V_A fwd = p->GetMtx().Up();
                            pos.Normalize();
                            if (!(fwd.Dot(pos) + (1.0f - Math_Cos(0.7853982f)) <= 1.0f)) {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        result = ok;
    }
    return result;
}
