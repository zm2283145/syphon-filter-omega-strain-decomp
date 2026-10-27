#pragma cplusplus on
#include "types.h"
#include "cmessage.h"
#include "vslot_pad.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
};
// VU0 macro-mode matrix * vector (COP2)
static inline void MulV(V* v, M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }

struct Tgt {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual V GetPos(int k);
};
struct Iface {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22();
    virtual void GetMatrix(M* m, int a, bool b);
};
struct Sub { char pad[0xF4]; float fF4; };
struct Actor { char pad[0x58]; Iface* p58; char pad5C[0x3524 - 0x5C]; Sub* p3524; };
struct Def { char pad[0x3C]; int i3C; };
struct HeldItem { Def* def; Actor* actor; unsigned char state; };

extern "C" {
extern unsigned char g_IsMultiplayer;
extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
}
struct DartMsg {
    CMSG_HEADER;
    unsigned char b24;
    char pad25[3];
    Tgt* tgt;
    int pad2C;
    unsigned char b30;
    char pad31[3];
    int i34;
    int pad38[2];
    V v;
    DartMsg(Tgt* tgt, bool a, int b, V v) {
        DartMsg* m = this;
        cMessage_ctor_cMessageNameR(m, D_00504050);
        m->vtable = D_004DCF10;
        m->vtable = D_004DCDA0;
        m->b24 = 0;
        m->tgt = tgt;
        m->b30 = a;
        m->i34 = b;
        m->v = v;
    }
};

extern "C" {
extern unsigned char g_IsMultiplayer;
extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
void cAirTaser_Shoot_cGOBJP_bool_int_cVector(HeldItem* self, Tgt* tgt, bool a, int b, V v);
}

extern "C" bool cAirTaser_Shoot_cGOBJP_bool_int(HeldItem* self, Tgt* tgt, bool a, int b) {
    bool fired = false;
    if (!self->state) {
        V v(0.0f, 0.0f, 0.0f, 1.0f);
        if (!tgt || a) {
            float f;
            M m;
            if (a) f = self->actor->p3524->fF4;
            else f = (float)self->def->i3C;
            self->actor->p58->GetMatrix(&m, 0, a);
            v.y = f;
            MulV(&v, &m);
        } else {
            v = tgt->GetPos(b);
        }
        cAirTaser_Shoot_cGOBJP_bool_int_cVector(self, tgt, a, b, v);
        fired = true;
        if (g_IsMultiplayer) {
            DartMsg msg(tgt, a, b, v);
            msg.kind = 4;
            msg.flags = 0x40;
            QueueMessage_cMessageR_cSystemP_int(&msg, self->actor, 0);
            msg.vtable = D_004DCF10;
            cMessage_dtor(&msg, 0);
        }
    }
    return fired;
}
