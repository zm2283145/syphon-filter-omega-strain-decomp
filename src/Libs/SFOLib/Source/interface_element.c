/*
 * Libs/SFOLib/Source/interface_element: 6 files, 003E7EB0-003E8180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E7EB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern float cTextArea_SetText(int, int);

void cInterfaceElement_SetGobj(Unk3E7EB0* self, int value) {
    self->unk78 = value;
}

float cInterfaceElement_SetText(Unk3E7EB0* self, int a1) {
    return cTextArea_SetText(self->unk74, a1);
}
static inline void merge_flush_func_003E7EB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E7EB0 */

/* merge_units: begin func_003E7ED0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "interface_element_types.h"

extern int cInterfaceModel_NumFrames(int owner);

/* Forward to cInterfaceModel_NumFrames on the element's owner. */
int cInterfaceElement_NumFrames(IfElement* elem) {
    return cInterfaceModel_NumFrames(elem->owner);
}
static inline void merge_flush_func_003E7ED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E7ED0 */

/* merge_units: begin func_003E7EE0 */
#pragma push /* merge_units */
typedef struct { char pad[0x1A]; unsigned char r, g, b, a; } O_E7EE0;
void cInterfaceElement_SetFilterColor(O_E7EE0* o, float* c)
{
    unsigned char g = (unsigned int)(255.0f * c[1]);
    unsigned char b = (unsigned int)(255.0f * c[2]);
    unsigned char a = (unsigned int)(255.0f * c[3]);
    o->r = (unsigned int)(255.0f * c[0]);
    o->g = g;
    o->b = b;
    o->a = a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E7EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E7EE0 */

/* merge_units: begin func_003E8040 */
#pragma push /* merge_units */
typedef struct { __int128 a, b, c, d; } M_8040;
typedef struct { char pad[0x30]; M_8040 m; } S_8040;
#pragma peephole off
void cInterfaceElement_SetView(S_8040* s, M_8040* m)
{
    M_8040* d = &s->m;
    __int128 t0, t1;
    t0 = m->a; t1 = m->b;
    d->a = t0; t0 = m->c;
    d->b = t1; t1 = m->d;
    d->c = t0;
    d->d = t1;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E8040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E8040 */

/* merge_units: begin func_003E8070 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { __int128 q[4]; } M4_E070;
typedef struct { char pad[0x30]; M4_E070 m; } Elem_E070;
extern "C" {
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(M4_E070* m, float, float, float, float, float, float, float, float, float);
void cInterfaceElement_SetRotation(Elem_E070* e, float* r);
}
static inline void GQR(void* d0, void* s0) { void* d = d0; __int128 qa; __int128 qb; void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
void cInterfaceElement_SetRotation(Elem_E070* e, float* r)
{
    M4_E070 m;
    float y = r[1];
    float z = r[2];
    float x = r[0];
    float cy = COS(y);
    float sy = SIN(y);
    float cz = COS(z);
    float sz = SIN(z);
    float cx = COS(x);
    float sx = SIN(x);
    cMatrix_Set_ColumnMajorForm(&m, cy * cz, -sz, sy * cz, sz * (cx * cy) + sx * sy, cx * cz, sz * (cx * sy) - sx * cy, cy * (sx * sz) - cx * sy, sx * cz, sz * (sx * sy) + cx * cy);
    GQR(&e->m, &m);
}
static inline void merge_flush_func_003E8070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8070 */

/* merge_units: begin func_003E8180 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct { char pad[0x20]; Q v; } Obj20;

/* Copies a quadword into the object's field at +0x20. */
void cInterfaceElement_SetLocation(Obj20* obj, Q* v)
{
    obj->v = *v;
}
static inline void merge_flush_func_003E8180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8180 */
