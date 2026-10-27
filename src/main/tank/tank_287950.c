/*
 * main/tank: range (2 files, 00287950-00287A20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00287950 */
#pragma push /* merge_units */
#pragma opt_propagation off
typedef struct Handle {
    int ptr;
    int id;
} Handle;

typedef struct Turret {
    int a0;
    int a4;
    int a8;
    int aC;
    int x10;
    int x14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    int x30;
    int x34;
    int x38;
    int x3C;
    int x40;
    int x44;
    int x48;
    int pad4C;
    float f50;
    unsigned char b54;
    unsigned char b55;
    char pad56[2];
    int x58;
    Handle h;
    int pad64;
    int x68;
} Turret;

Turret* cTurret_ctor(Turret* t, int a, int b, int c, int d, int e)
{
    int tmp;
    int* pt;
    t->h.id = -2;
    t->h.ptr = 0;
    t->a0 = a;
    t->a4 = b;
    t->a8 = c;
    t->aC = d ? d : b;
    t->h.ptr = 0;
    tmp = -1;
    pt = &tmp;
    t->h.id = *pt;
    t->x68 = 0;
    t->x30 = 0;
    t->x34 = 0;
    t->x38 = 0;
    t->x3C = 0;
    t->x10 = 0;
    t->x14 = 0;
    t->f50 = 0.1f;
    t->f18 = -0.06f;
    t->f1C = 0.03f;
    t->f20 = -2.0f;
    t->f24 = -2.0f;
    t->f28 = 10.0f;
    t->f2C = 0.5f;
    t->x58 = e;
    t->x48 = 0;
    t->x44 = 0;
    t->x40 = 0;
    t->b55 = 0;
    t->b54 = 0;
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00287950(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00287950 */

/* merge_units: begin func_00287A20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct TgtA20 { char pad[0x14]; float x; float y; };
struct EntA20 { TgtA20* p; float x; float y; };
struct OwnA20 { char pad[0x144]; float t; };
struct SelfA20 { void* obj; OwnA20* own; EntA20 e[2]; int n; float last; unsigned char on; };
extern float D_0048B3D0;
extern "C" unsigned char cTread_ctor(SelfA20*);
extern "C" void cTread_NextFrame(SelfA20* s)
{
    int i;
    if (cTread_ctor(s)) {
        float d;
        float t;
        t = s->own->t;
        d = t - s->last;
        s->last = t;
        d = d * D_0048B3D0;
        for (i = 0; i < s->n; i++) {
            TgtA20* p = s->e[i].p;
            float a = d * s->e[i].x;
            float b = d * s->e[i].y;
            p->x = a;
            p->y = b;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00287A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00287A20 */
