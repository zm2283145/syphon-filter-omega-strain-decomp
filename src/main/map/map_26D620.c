/*
 * main/map: range (2 files, 0026D620-0026D6D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vc_copy.h"

/* merge_units: begin func_0026D620 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Q_26D620 { float a, b, c, d; Q_26D620& operator=(const Q_26D620& o) { Q_26D620* pd = this; const Q_26D620* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; } } __attribute__((aligned(16)));
struct R2_26D620 { char pad[0x68]; int x68; };
struct R_26D620 { char pad[8]; R2_26D620* x8; };
struct S_26D620 {
    int x0;
    int x4;
    int x8;
    char padC[0x54];
    int x60;
    char pad64[0xC];
    Q_26D620 x70;
    Q_26D620 x80;
    float x90;
    float x94;
};
extern "C" {
R_26D620* func_00272AC0(int a);
void func_0026D040(S_26D620* s, float t);
void func_003E79C0(int h, float t);
void func_0026D620(S_26D620* s, float dt);
}
void func_0026D620(S_26D620* s, float dt)
{
    if (s->x94 > 0.0f) {
        s->x94 -= dt;
        if (s->x94 <= 0.0f) {
            R_26D620* r = func_00272AC0(s->x0);
            if (r && r->x8) {
                s->x60 = r->x8->x68;
                s->x80 = s->x70;
                s->x90 = 0.0f;
            }
            s->x94 = 0.0f;
        }
    }
    func_0026D040(s, dt);
    func_003E79C0(s->x8, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026D620(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026D620 */

/* merge_units: begin func_0026D6D0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int c; } C_D6D0;
typedef struct { char pad[0x30]; C_D6D0* p30; } B_D6D0;
typedef struct { char pad[0x60]; int t60; int t64; char pad68[8]; __int128 q70; __int128 q80; char pad90[4]; int x94; } A_D6D0;
extern B_D6D0* D_004FFC0C;
static inline int* ref_D6D0(C_D6D0* c) { return &c->c; }
#pragma push
#pragma peephole off
#pragma opt_propagation off
void func_0026D6D0(A_D6D0* a) {
    __int128* s; __int128* d;
    a->x94 = 0;
    d = &a->q80; s = &a->q70;
    a->t64 = a->t60;
    *d = *s;
    { int* pc = &D_004FFC0C->p30->c; a->t60 = *pc; }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026D6D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026D6D0 */
