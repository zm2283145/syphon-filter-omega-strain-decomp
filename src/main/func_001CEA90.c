#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies as GCC-style volatile asm; the unused xx in Plc's copy ctor reproduces retail's dead addiu (it survives only after an earlier GCC asm) */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Plc;
extern "C" void VecPair_Copy(Plc* d, const Plc* s);
struct Plc { V rot; V pos; Plc() {} Plc(const Plc& o) { VecPair_Copy(this, &o); void* xx = this; } };
struct Src { V a; V b; signed char c; };
struct Key { unsigned char a; unsigned char b; };
struct Pair { Key key; char pad2[0xE]; Src v[2]; };
struct MNode { MNode* l; MNode* r; int pad[2]; Pair p; };
struct Ent { char pad[0x10]; Src s; char pad2[0x20]; };
struct MIter { MNode* n; };
struct Self { unsigned char type; unsigned char active; signed char b2; signed char b3; signed char b4; signed char b5; };
extern "C" {
extern signed char D_004E1D80;
extern Plc D_00497F00;
extern Ent* D_004F2D80;
extern void* D_004F2D88;
extern float D_0049F720;
void Quat_SetIdentity(V* q);
void Vec4_SetOrigin(V* v);
void Placement_GetIdentity(Plc* p, V* q, V* v);
void func_001DE2D0(MIter* out, void* t, const Key* k);
void func_001CEE10(MIter* out, void* t);
MIter* func_001CEE00(MIter* d, MIter* s);
void* func_001CAB40(void* base, int index);
void SecondaryAim_SetLayerSource(void* self, float w, Src* src);
void func_001CEA90(Self* s, void* aim);
}
static inline void MkKey(Key* k, int a, int b)
{
    k->a = (unsigned char)a < (unsigned char)b ? a : b;
    k->b = (unsigned char)a > (unsigned char)b ? a : b;
}
static inline int Eq(const MIter& a, const MIter& b) { return a.n == b.n; }
static inline Pair* Deref(const MIter& i) { return &i.n->p; }
static inline Ent* At(Ent* a, unsigned char i) { return &a[i]; }
static inline bool Ne(const MIter& a, const MIter& b) { return !Eq(a, b); }
static inline Plc Ident()
{
    if (!D_004E1D80) {
        V q; V v;
        Quat_SetIdentity(&q);
        Vec4_SetOrigin(&v);
        Placement_GetIdentity(&D_00497F00, &q, &v);
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
void func_001CEA90(Self* s, void* aim)
{
    if (s->active) {
        Src* src = 0;
        signed char mode = -1;
        switch (s->type) {
        case 0:
            break;
        case 2: {
            MIter it;
            Key k;
            MIter e;
            MIter f;
            MIter t;
            MkKey(&k, s->b2, s->b3);
            func_001DE2D0(&f, D_004F2D88, &k);
            it = f;
            func_001CEE10(&t, D_004F2D88);
            func_001CEE00(&e, &t);
            if (Ne(it, e)) {
                mode = s->b5;
                src = Deref(it)->v;
            }
            break;
        }
        case 1:
            mode = s->b4;
            src = &At(D_004F2D80, s->b2)->s;
            break;
        case 3:
            mode = s->b5;
            src = &At(D_004F2D80, s->b3)->s;
            break;
        }
        if (src) {
            if (mode == 0 || mode == 2) {
                SecondaryAim_SetLayerSource(func_001CAB40(aim, 0), D_0049F720, src);
            } else {
                Src t;
                Plc p = Ident();
                t.a = p.rot;
                t.b = p.pos;
                t.c = 0x13;
                SecondaryAim_SetLayerSource(func_001CAB40(aim, 0), D_0049F720, &t);
            }
            if (mode == 1 || mode == 2) {
                Src* s1p = src + 1;
                SecondaryAim_SetLayerSource(func_001CAB40(aim, 1), D_0049F720, s1p);
            } else {
                Src t;
                Plc p = Ident();
                t.a = p.rot;
                t.b = p.pos;
                t.c = 0x14;
                SecondaryAim_SetLayerSource(func_001CAB40(aim, 1), D_0049F720, &t);
            }
        }
        s->active = 0;
    }
}



