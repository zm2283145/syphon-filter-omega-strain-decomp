/* Actor_UpdateStealthLight: for every active actor, relight its model at its
 * current position and store a 0..100 visibility level derived from the
 * gathered light colour (0 when below the darkness threshold or when the
 * actor's flashlight is on). */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Model {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad[0x4C];
    unsigned char dirty;
};
struct Ctl { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); };
struct Actor {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d)
    virtual V GetPos();
    char p04[0x28];
    bool enabled, activated, removed; char p2F[0x15];
    int light; char p48[0x10]; Ctl* ctrl; char p5C[0x2E78 - 0x5C]; Model* model;
};
struct It {
    Actor** p;
    bool operator==(const It& o) const { Actor** b = o.p; return p == b; }
    bool operator!=(const It& o) const { return !(*this == o); }
};
struct Vec { int n; Actor** data; };
extern "C" {
extern Vec* g_ActorList;
extern V D_00535D40;
extern unsigned char D_00535D60;
extern unsigned char D_00535D61;
extern V D_00537D80;
extern char g_LightMgr[];
extern int DarknessDecreaser;
extern int NpcDarknessDecreaser;
void* cObjList_cHumanPtr_GetList(Vec* v);
void cArray_cHumanPtr_Begin(It* out, void* v);
void cArray_cHumanPtr_End(It* out, void* v);
It* cArray_cHumanPtr_ConstIterator_ctor(It* d, It* s);
void LightMgr_GatherModelLights(void* m, unsigned int mask, unsigned int flags, void* out);
int Actor_IsFlashlightOn(Actor* a);
void Actor_UpdateStealthLight(void);
}
/* VU0 compare / length: macro-mode VU0 ops have no C equivalent (asm). */
static inline unsigned char Eq4(V* a, V* b) {
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline float Len(V* a) {
    int rv0; float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
static inline bool Alive(Actor* p) { bool r = 0; if (p->activated && p->enabled) r = 1; return r; }
static inline bool Live(Actor* p) { return !p->removed; }
static inline void Scale(V* r, const V& v, float k) { r->z = v.z / k; r->y = v.y / k; r->x = v.x / k; r->w = 0.0f; }
static inline bool Active(Actor* p) { bool r = 0; if (Alive(p) && Live(p)) r = 1; return r; }
static inline bool Player(Ctl* c) { bool yes = false; if (c) if (c->IsPlayer()) yes = true; return yes; }
static inline void Begin(It* o, Vec* v) { It t; cArray_cHumanPtr_Begin(&t, cObjList_cHumanPtr_GetList(v)); cArray_cHumanPtr_ConstIterator_ctor(o, &t); }
static inline void End(It* o, Vec* v) { It t; cArray_cHumanPtr_End(&t, cObjList_cHumanPtr_GetList(v)); cArray_cHumanPtr_ConstIterator_ctor(o, &t); }

void Actor_UpdateStealthLight(void)
{
    Vec* list = g_ActorList;
    It end;
    It it;
    End(&end, list);
    Begin(&it, list);
    for (; it != end; it.p++) {
        Actor* a = *it.p;
        if (Active(a)) {
            V c; V s;
            V p = a->GetPos();
            if ((Eq4(&D_00535D40, &p) != 0) ^ 1) {
                D_00535D40 = p;
                D_00535D60 = 1;
                D_00535D61 = 1;
            }
            Model* m = a->model;
            if (m->dirty) m->Update();
            LightMgr_GatherModelLights(g_LightMgr, 23, 3, (char*)m + 0x10);
            c = D_00537D80;
            Scale(&s, c, 128.0f);
            int lvl = (int)(100.0f * (1.0f - Len(&s)));
            int dec = !Player(a->ctrl) ? NpcDarknessDecreaser : DarknessDecreaser;
            if (lvl < dec)
                lvl = 0;
            else
                lvl = (int)(100.0f / (float)(100 - dec) * (float)(lvl - dec));
            if (Actor_IsFlashlightOn(a)) lvl = 0;
            a->light = lvl;
        }
    }
}
