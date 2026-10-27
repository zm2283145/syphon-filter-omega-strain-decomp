/*
 * Libs/SFOLib/Source/shadows: 2 files, 003D40D0-003D4300
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D40D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies and VU0 math as GCC-style volatile asm; the unused xx locals keep retail's dead addius.
   V2 gives the XformPt copy its own pointer-local order (dst before src) without disturbing the other V copies. */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct Box { V mn; V mx; V Sum() const; };
struct Mdl { int x0; char* x4; };
class XV {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
};
struct Xf { void* vt; char pad4[0xC]; M world; unsigned char dirty; };
struct Obj { char pad0[0x38]; int x38; char pad3C[0x14]; Xf* x50; char pad54[0x14]; Mdl* x68; };
struct Ent { Obj* obj; char pad4[0x6C]; V c; };
struct Shadow { char pad0[0x4D0]; Ent ent[0x200]; char pad104D0[8]; int count; };
extern "C" int g_DrawMode;
static inline void Add(V* r, const V* a, const V* b);
static inline void Add(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
inline V Box::Sum() const { V c; Add(&c, &mn, &mx); return c; }
static inline V Scale(V v, float k) { __int128 z = 0; /* dead paddub */ V r; int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(&v), "r"(&r), "f"(k) : "memory"); return r; }
static inline void MulM(V* v, M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
struct V2 : V { V2(const V& o) { void* xx = this; V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); } } __attribute__((aligned(16)));
static inline V XformPt2(const V& v, M* mm) { const V* sv = &v; V2 p(*sv); V* pp = &p; MulM(pp, mm); return *pp; }
static inline V XformPt(const V& v, M* m) { M* mm = m; return XformPt2(v, mm); }
static inline int HasModel(Obj* o) { return o->x68->x0 ? 1 : 0; }
extern "C" int cShadowMan_AddReceiver(Shadow* sh, Obj* o, int force)
{
    int idx = -1;
    if ((g_DrawMode & 0x60) || force) {
        if (sh->count < 0x200 && o->x38 != 0x80 && HasModel(o)) {
            if (force) {
                int i;
                for (i = 0; i < sh->count; i++) {
                    if (sh->ent[i].obj == o) return i;
                }
            }
            {
                Ent* e;
                Xf* x;
                idx = sh->count;
                sh->count = idx + 1;
                e = &sh->ent[idx];
                e->obj = o;
                Box* b = (Box*)(o->x68->x4 + 0x30);
                e->c = Scale(b->Sum(), 0.5f);
                x = o->x50;
                if (x) {
                    if (x->dirty) ((XV*)x)->Refresh();
                    e->c = XformPt(e->c, &x->world);
                }
            }
        }
    }
    return idx;
}
static inline void merge_flush_func_003D40D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D40D0 */

/* merge_units: begin func_003D4300 */
#pragma push /* merge_units */
typedef struct { int f; char p[0x7C]; } C1E_3D43;
typedef struct { char pad[0x534]; C1E_3D43 e[511]; char pad2[0x24]; int count; } C1S_3D43;
void cShadowMan_ClearReceivers(C1S_3D43* s)
{
    int i;
    for (i = 0; i < s->count; i++)
        s->e[i].f = 0;
    s->count = 0;
}
static inline void merge_flush_func_003D4300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D4300 */
