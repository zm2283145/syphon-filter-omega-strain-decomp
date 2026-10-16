#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct V_AC5 { float x, y, z, w; V_AC5() {} } __attribute__((aligned(16)));
struct R_AC5 {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad[0x4C];
    unsigned char x50;
};
struct Q_AC5 { char pad[0x11C]; void* x11C; char pad2[0x1C]; void* x13C; };
struct O_AC5 {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d)
    virtual V_AC5 GetPos();
    char pad[0x34];
    int x38;
    char pad3C[0x14];
    R_AC5* x50;
    char pad54[0x90];
    unsigned char xE4;
    char padE5[0x3B];
    Q_AC5* x120;
};
extern "C" {
extern V_AC5 D_00535D40;
extern unsigned char D_00535D60;
extern unsigned char D_00535D61;
void func_003836B0(void* a, int b, void* c, int d);
void ThrownProjectile_Draw(O_AC5* o);
}
static inline unsigned char eq4_(V_AC5* a, V_AC5* b) {
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
#pragma push
#pragma bool off
#pragma opt_common_subs off

void ThrownProjectile_Draw(O_AC5* o)
{
    if (!o->xE4) {
        void* m; R_AC5* r; V_AC5 p = o->GetPos();
        if ((eq4_(&D_00535D40, (V_AC5*)&p) != 0) ^ 1) {
            { const V_AC5* s = &p; V_AC5* d = &D_00535D40; __int128 t; asm { .set reorder; lq t, 0(s) } asm { sq t, 0(d) } }
            D_00535D60 = 1; D_00535D61 = 1;
        }
        /* empty barrier keeps the then-block (b over the else) like retail */
        { Q_AC5* q = o->x120; m = q->x11C; if (m) { asm { .set reorder } } else m = q->x13C; }
        if (m) {
            r = o->x50;
            if (r->x50) r->Update();
            func_003836B0(m, o->x38, (void*)((int)r + 0x10), 0);
        }
    }
}
#pragma pop
