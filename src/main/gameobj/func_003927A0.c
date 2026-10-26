#pragma cplusplus on
#include "types.h"
typedef __int128 Q3927A0;
struct Def3927A0 { char pad0[0x70]; Q3927A0 key; char pad80[0x2C04 - 0x80]; void* ctx; char pad2C08[8]; signed char preset; char pad2C11[0x2DF0 - 0x2C11]; };
struct Skel3927A0 { char pad0[0x50]; int x50; char pad54[0xC]; Def3927A0 def; char ctx[0x10]; };
struct Sc3927A0 { float a, b, c, d, e; };
struct Prm3927A0 { void* model; int x; int pad[2]; Sc3927A0 sc; };
extern "C" {
extern char D_0053BB70[];
void* Skel_Find(void* tab, Q3927A0* key);
void ModelCtx_Init(void* ctx, Prm3927A0* p);
void Skel_ApplyScalePreset(Def3927A0* d, int preset);
}
/* 16-byte block copy loop (lq/sq), as in cMan_dtor. */
static inline void QMove_3927A0(void* d0, void* s, int n0) {
    int n = n0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline long QCmp_3927A0(Q3927A0 a, Q3927A0 b) { register Q3927A0 r; asm { pceqw r, a, b
 ppach r, r, r } return (long)r; }
extern "C" void Skel_Rebind(Skel3927A0* s, Def3927A0* def)
{
    Q3927A0 oldKey = s->def.key;
    int oldPreset = s->def.preset;
    QMove_3927A0(&s->def, def, 0x2DF);
    s->def.ctx = s->ctx;
    if (QCmp_3927A0(oldKey, s->def.key) != -1) {
        Sc3927A0 sc;
        Prm3927A0 p;
        void* m = Skel_Find(D_0053BB70, &s->def.key);
        sc.a = 1.0f; sc.b = 0.5f; sc.c = 0.2f; sc.d = 0.2f; sc.e = 0.2f;
        p.x = s->x50;
        p.sc = sc;
        p.model = m;
        ModelCtx_Init(s->ctx, &p);
    }
    if (oldPreset != s->def.preset) Skel_ApplyScalePreset(&s->def, s->def.preset);
}

