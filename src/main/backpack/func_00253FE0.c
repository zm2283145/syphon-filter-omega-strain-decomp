#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* cBackpack_Render (draw): while the backpack is free (no ready holder, no
 * contents) it fades by its age, tracks the shared drop-marker position and
 * draws its model. Helpers follow cBackpack_v10 (backpack_2542E0.c) and
 * cGrenade_Render (grenade/cGrenade_Render.c). */
#pragma always_inline on
#pragma inline_depth(8)
struct V_3FE0 { float x, y, z, w; V_3FE0() {} } __attribute__((aligned(16)));
struct Sub_3FE0 {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0x4C];
    unsigned char f50;
};
struct Tgt_3FE0 { char pad[0xC]; int id; char pad10[0x1C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; };
struct Hnd_3FE0 { Tgt_3FE0* p; int id; };
struct Item_3FE0 { char pad0[0xD0]; int obj; };
struct Bp_3FE0 {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d)
    virtual V_3FE0 GetPos();
    char pad4[0x34];
    int x38;
    char pad3C[0x14];
    Sub_3FE0* sub;
    char pad54[0x60 - 0x54];
    Item_3FE0 items[3];
    char pad2DC[0x2E4 - 0x2DC];
    int hasItems;
    int nItems;
    char pad2EC[0x2F8 - 0x2EC];
    Tgt_3FE0* t2F8;
    int pad2FC;
    Hnd_3FE0 h;
    char pad308[0x314 - 0x308];
    float age;
};
struct Model_3FE0 { char pad[0x416]; signed char alpha; };
struct WeaponDb_3FE0 { char pad[0xB8]; Model_3FE0* backpack; };
extern "C" {
extern WeaponDb_3FE0* g_WeaponDatabase;
extern float D_0048AF18;
extern V_3FE0 D_00535D40;
extern unsigned char D_00535D60;
extern unsigned char D_00535D61;
void gunList_GunRender(void* a, int b, void* c, int d);
}
static inline bool IdEq(Tgt_3FE0* p, Hnd_3FE0* h) { return p->id == h->id; }
static inline Tgt_3FE0* HGet(Hnd_3FE0* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(Tgt_3FE0* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
static inline unsigned char eq4_(V_3FE0* a, V_3FE0* b) {
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
/* cvt.w.s+mfc1: a C (int) cast compiles to trunc.w.s */
static inline int F2I(float f) { int r; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }

extern "C" void cBackpack_Render(Bp_3FE0* self)
{
    Tgt_3FE0* t = self->t2F8;
    if (t && Ready(t)) {
        if (!HGet(&self->h) || !Ready(HGet(&self->h))) {
            int n = self->hasItems ? self->nItems : 0;
            int empty = n <= 0;
            int i;
            for (i = 0; empty && i < 3; i++) {
                if (self->items[i].obj)
                    empty = 0;
            }
            if (!empty) {
                WeaponDb_3FE0* w = g_WeaponDatabase;
                Model_3FE0* m = w->backpack;
                int a = -1;
                if (!(self->age <= 0.0f))
                    a = F2I(127.0f * ((D_0048AF18 - self->age) / D_0048AF18));
                m->alpha = a;
                {
                    V_3FE0 p = self->GetPos();
                    if ((eq4_(&D_00535D40, &p) != 0) ^ 1) {
                        /* 16-byte copy (lq/sq copy idiom); volatile asm, as the sibling cBackpack_v10 has, keeps MW from turning the Ready() flag tests into sltu forms */
                        { const V_3FE0* s = &p; V_3FE0* d = &D_00535D40; __int128 q; asm volatile { .set reorder; lq q, 0(s) } asm volatile { sq q, 0(d) } }
                        D_00535D60 = 1; D_00535D61 = 1;
                    }
                }
                {
                    Sub_3FE0* r = self->sub;
                    if (r->f50) r->Sync();
                    gunList_GunRender(m, self->x38, (void*)((int)r + 0x10), 0);
                }
            }
        }
    }
}
