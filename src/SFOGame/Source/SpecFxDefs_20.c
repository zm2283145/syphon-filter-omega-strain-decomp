/*
 * SFOGame/Source/SpecFxDefs: 2 files, 00234110-002345D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00234110 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)

#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V4& operator=(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void OpS(V4* pr, const V4* pa, const V4* pb)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
}
static inline V4 operator-(const V4& a, const V4& b) { V4 r; OpS(&r, &a, &b); return r; }
static inline float Max(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float Min(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }

struct Box0 { V4 lo, hi; };
struct Box : Box0 {
    Box() {
        lo.x = 3.4028235e38f; lo.y = 3.4028235e38f; lo.z = 3.4028235e38f; lo.w = 1.0f;
        hi.x = -3.4028235e38f; hi.y = -3.4028235e38f; hi.z = -3.4028235e38f; hi.w = 1.0f;
    }
    void Extend(V4* p) { V4* l = &lo; V4* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(p) : "memory"); }
    void Reset() {
        lo = V4(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
        hi = V4(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    }
    unsigned char Empty() const { return lo.x > hi.x; }
    V4 Size() const { return Empty() ? V4(0.0f, 0.0f, 0.0f, 0.0f) : hi - lo; }
};

/* Intersection of two boxes in x/y (z from b), widened in x and y to at least 16 units inside b. */
extern "C" Box func_00234110(Box0* a, Box0* b)
{
    V4 p;
    Box r;
    r.Reset();
    p.x = Max(a->lo.x, b->lo.x);
    p.y = Max(a->lo.y, b->lo.y);
    p.z = b->lo.z;
    r.Extend(&p);
    p.x = Min(a->hi.x, b->hi.x);
    p.y = Min(a->hi.y, b->hi.y);
    p.z = b->hi.z;
    r.Extend(&p);
    if (r.Size().x < 16.0f) {
        float d = 16.0f - r.Size().x;
        p.x = Max(a->lo.x - d, b->lo.x);
        r.Extend(&p);
        p.x = Min(a->hi.x + d, b->hi.x);
        r.Extend(&p);
    }
    if (r.Size().y < 16.0f) {
        float d = 16.0f - r.Size().y;
        p.y = Max(a->lo.y - d, b->lo.y);
        r.Extend(&p);
        p.y = Min(a->hi.y + d, b->hi.y);
        r.Extend(&p);
    }
    return r;
}
static inline void merge_flush_func_00234110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00234110 */

/* merge_units: begin func_002345D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004A6E38[];
extern char D_004A6F38[];
extern char SnowField_vtable[];
extern char D_004DF860[];
void cGOBJ_dtor(void* p, int flag);
void cParticle_dtor(void* p, int flag);
void operator_delete(void* p);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}
struct E_345D0 { void* a; };
struct LNode_345D0 { LNode_345D0* prev; LNode_345D0* next; E_345D0* value; };
struct It_345D0 { LNode_345D0* n; };
struct List_345D0 { int x0; int x4; LNode_345D0* x8; };
extern "C" {
void std_list_cElementPtr_end_void(It_345D0* out, List_345D0* list);
It_345D0* cLListIterator_cElementPtr_ctor_listR(It_345D0* dst, It_345D0* src);
void std_list_cElementPtr_begin_void(It_345D0* out, List_345D0* list);
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(It_345D0* out, List_345D0* list, LNode_345D0** first, int** last);
void std_list_cElementPtr_dtor_void(List_345D0* l, int flag);
}
struct S_345D0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(int a);
    char pad4[0x28]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2f[0x74 - 0x2F]; List_345D0 list;
};
struct F_345D0 { float f; };
#pragma opt_propagation off
#pragma opt_common_subs off
static inline bool Ok(S_345D0* s) { return s->b2D && s->b2C && !s->b2E; }
static inline void Beg1(It_345D0* out, List_345D0* l) { It_345D0 t; std_list_cElementPtr_begin_void(&t, l); cLListIterator_cElementPtr_ctor_listR(out, &t); }
static inline void End1(It_345D0* out, List_345D0* l) { It_345D0 t; std_list_cElementPtr_end_void(&t, l); cLListIterator_cElementPtr_ctor_listR(out, &t); }
static inline void Beg2(It_345D0* out, List_345D0* l) { Beg1(out, l); }
static inline void End2(It_345D0* out, List_345D0* l) { End1(out, l); }
static inline void Kill2(E_345D0* e) { void* q = e->a; if (q) { AllocGuard g2; cParticle_dtor(q, -1); cMemMan_Deallocate(0, q, D_004A6F38, 0x14F); } }
extern "C" S_345D0* cSnowEffect_dtor(S_345D0* self, short flag)
{
    if (self) {
        *(char**)self = SnowField_vtable;
        {
            It_345D0 it;
            It_345D0 t2;
            It_345D0 end;
            Beg2(&t2, &self->list);
            { F_345D0* s = (F_345D0*)&t2; F_345D0* d = (F_345D0*)&it; *d = *s; }
            for (; End2(&end, &self->list), it.n != end.n; it.n = it.n->next) {
                E_345D0* e = it.n->value;
                AllocGuard g;
                if (e) {
                    Kill2(e);
                }
                cMemMan_Deallocate(0, e, D_004A6E38, 0x382);
            }
        }
        {
            It_345D0 r; LNode_345D0* first; int* last;
            last = &self->list.x4;
            first = self->list.x8;
            std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, &self->list, &first, &last);
        }
        {
            List_345D0* l = &self->list;
            if (l) std_list_cElementPtr_dtor_void(l, 0);
        }
        if (self) {
            *(char**)self = D_004DF860;
            if (Ok(self)) self->v22(1);
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_002345D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002345D0 */
