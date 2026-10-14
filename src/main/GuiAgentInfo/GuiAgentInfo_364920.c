/*
 * main/GuiAgentInfo: range (2 files, 00364920-00364A20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00364920 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
struct B5kRef { char pad[0x10]; float end; };
class B5kObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetRate();
    int a;
    int b8;
    int bc;
    float b10;
    int b14;
    int b18;
    char pad[0x20 - 0x1C];
    float out0;
    float out1;
    float scale;
    char pad2[0x30 - 0x2C];
    B5kRef* ref;
    float cur;
};
extern "C" void func_0017CA90(void* p, int n);
extern "C" void* func_00139BC0(int kind, void* p);
extern "C" void func_0017CA00(void* p, float s, void* a, void* b, void* c, float* r);
static inline int B5kIsZero(float f) { return 0.0f == f; }
extern "C" void func_00364920(B5kObj* o) {
    unsigned char flag = 0;
    if (o->cur == o->ref->end && !(o->scale <= 0.0f)) {
        flag = 1;
    }
    if (flag) {
        float r = o->GetRate();
        void* p;
        func_0017CA90(&o->b18, -1);
        p = func_00139BC0(0x18, &o->b18);
        if (p) {
            func_0017CA00(p, o->scale, &o->b8, &o->bc, &o->b10, &r);
        }
    } else if ((B5kIsZero(o->cur) ^ 1)) {
        float r = o->GetRate();
        float s = o->scale;
        o->out0 = o->b10;
        o->out1 = r * s;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364920(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364920 */

/* merge_units: begin func_00364A20 */
#pragma push /* merge_units */
#pragma cplusplus on
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_4A20b { float v; float s; Key_4A20b() {} };
struct Crv_4A20b { Key_4A20b k[2]; float dur; float inv; };
/* two-key curve: keys (*v0, *s0 * dur) and (*v1, *s1 * dur), duration and inverse */
#pragma push
#pragma opt_unroll_loops off
extern "C" Crv_4A20b* func_00364A20(Crv_4A20b* c, float* v0, float* s0, float* v1, float* s1, float dur)
{
    float vs0; float vs1;
    vs1 = *s1 * dur; vs0 = *s0 * dur;
    { Key_4A20b* e = c->k; do { new (e) Key_4A20b; } while (++e != c->k + 2); }
    c->k[0].v = *v0;
    c->k[0].s = vs0;
    c->k[1].v = *v1;
    c->k[1].s = vs1;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364A20 */
