#pragma optimization_level 0
#pragma schedule on
#pragma peephole on
#pragma inline_depth(8)
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    V operator-(const V& o) const { V r; SubV(&r, this, &o); return r; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float LenSq(const V* a) { int t; float r = 0.0f; __asm__("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline float LenSqV(V v) { return LenSq(&v); }

class Obj_2423 {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    VPAD8(f)
    virtual unsigned char GetKind();
    char pad4[0x28];
    unsigned char b2C, b2D, b2E;
    bool Shown() { return !b2E; }
};
struct Player_2423 { char pad0[0x30]; Obj_2423* obj; };
struct Elem_2423 { char pad0[0x70]; int x70; };
struct Ent_2423 { int key; float timer; int id; Elem_2423* elem; char pad10[4]; float distSq; unsigned char b18; };
struct Node_2423 { Node_2423* prev; Node_2423* next; Ent_2423* ent; };
struct It_2423 { Node_2423* n; };
struct Sub_2423 { char pad0[0xD4]; int xD4; };
struct Hud_2423 { char pad0[0x6A0]; int x6A0; Sub_2423* x6A4; unsigned char b6A8; unsigned char b6A9; char pad6AA[0x6E8 - 0x6AA]; char list[4]; };

extern "C" {
extern unsigned char D_004FFBB7;
extern int D_004F7D90;
extern Player_2423* g_LocalPlayer;
void std_list_deleter_voidPtr_begin_void(It_2423* out, char* l);
void std_list_tCalloutPtr_end_void(It_2423* out, char* l);
void cLListIterator_tCalloutPtr_ctor(It_2423* out, It_2423* in);
void std_list_tCalloutPtr_generic_iterator_ctor(It_2423* out, It_2423* in);
int Hud_IsGuiFocused(Hud_2423* s);
void cInterfaceElement_Activate(Elem_2423* e, int v);
Obj_2423* nGobjManager_LookupGOBJ_cObjectIdR(Ent_2423* e);
int cHud_ClearCallout(Hud_2423* o, Ent_2423* key, int id, signed char flag, int send);
}

static inline bool Visible(Obj_2423* o)
{
    bool ok = 0;
    bool vis = 0;
    if (o->b2D) { if (o->b2C) vis = 1; }
    if (vis) { if (o->Shown()) ok = 1; }
    return ok;
}
static inline void Begin_(It_2423* out, char* l) { It_2423 t; std_list_deleter_voidPtr_begin_void(&t, l); std_list_tCalloutPtr_generic_iterator_ctor(out, &t); }
static inline void End_(It_2423* out, char* l) { It_2423 t; std_list_tCalloutPtr_end_void(&t, l); cLListIterator_tCalloutPtr_ctor(out, &t); }

extern "C" void cHud_UpdateCallouts(Hud_2423* self, float dt)
{
    It_2423 it;
    It_2423 e;
    It_2423 b;
    Begin_(&b, self->list);
    for (it = b; End_(&e, self->list), it.n != e.n; ) {
        Ent_2423* ent = it.n->ent;
        if (ent->elem) {
            if (D_004FFBB7 || (Hud_IsGuiFocused(self) && self->x6A4->xD4 != 1)) {
                cInterfaceElement_Activate(ent->elem, 0);
                it.n = it.n->next;
                continue;
            }
            if (self->b6A9) {
                Elem_2423* el = ent->elem;
                if (el->x70 == D_004F7D90) {
                    cInterfaceElement_Activate(el, 0);
                    it.n = it.n->next;
                    continue;
                }
            }
            cInterfaceElement_Activate(ent->elem, 1);
            {
                Obj_2423* o = nGobjManager_LookupGOBJ_cObjectIdR(ent);
                if (!o || !Visible(o)) {
                    cInterfaceElement_Activate(ent->elem, 0);
                } else if (ent->b18 && o->GetKind() == 3) {
                    it.n = it.n->next;
                    cHud_ClearCallout(self, ent, ent->id, 0, 0);
                    continue;
                } else if (!self->x6A0 || !self->b6A9) {
                    Player_2423* p = g_LocalPlayer;
                    if (p && p->obj) {
                        V d = p->obj->GetPos() - o->GetPos();
                        ent->distSq = LenSq(&d);
                        if (!(ent->distSq <= 8100.0f))
                            cInterfaceElement_Activate(ent->elem, 0);
                    }
                }
            }
        }
        float z = 0.0f;
        float t = ent->timer;
        if (t > z) {
            t -= dt;
            ent->timer = t;
            if (t <= z) {
                it.n = it.n->next;
                cHud_ClearCallout(self, ent, ent->id, 0, 0);
            } else {
                it.n = it.n->next;
            }
        } else {
            it.n = it.n->next;
        }

    }
}
