/*
 * main/GuiAgentCreate: range (2 files, 0028D300-0028D4E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
void *memcpy();
int strcmp(const void *, const void *);

/* merge_units: begin func_0028D300 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_D4E0;
typedef struct { char pad[0x130]; V4_D4E0 v; } O_D4E0;
void func_0028D4E0(O_D4E0* o, float z); /* gsynth: defined below */
typedef struct { char name[16]; } P_Name;
typedef struct { float x, y, z, w; } P_Sc;
typedef struct { unsigned int count; P_Name e[24]; P_Sc* sc[1]; } P_Tbl;
typedef struct { char pad0[4]; char bones[0x10]; unsigned char hasMorph; char pad15[3]; char morph[4]; } P_Skl;
typedef struct { char pad0[0xA0]; char name[0x2BC4]; P_Skl* skel; } P_App;
typedef struct { char pad0[0x70]; P_App* app; } P_Obj;
extern P_Tbl D_00571300;
extern float* func_0028D5F0(void*, int);
extern void* SkelNodes_GetAt(void*, int);
extern void func_0028D580(void*, float);
extern void func_0028D530(void*, float);
#if 0 /* merge_units */
extern void func_0028D4E0(void*, float);
#endif /* merge_units */
#define func_0028D4E0(a0, a1) (func_0028D4E0((void *)(a0), (a1))) /* merge_units */


void func_0028D300(P_Obj* o) {
    unsigned int preset;
    int i;
    for (preset = 0; preset < D_00571300.count; preset++) {
        if (!strcmp(o->app->name, D_00571300.e[preset].name)) break;
    }
    preset++;
    if (preset >= D_00571300.count) preset = 0;
    memcpy(o->app->name, D_00571300.e[preset].name, 0xF);
    for (i = 0; i < 0x15; i++) {
        P_Skl* k;
        float v;
        v = D_00571300.sc[preset][i].x; k = o->app->skel;
        func_0028D5F0(k->bones, i)[0] = v;
        if (k->hasMorph) func_0028D580(SkelNodes_GetAt(k->morph, i), v);
        v = D_00571300.sc[preset][i].y; k = o->app->skel;
        func_0028D5F0(k->bones, i)[1] = v;
        if (k->hasMorph) func_0028D530(SkelNodes_GetAt(k->morph, i), v);
        v = D_00571300.sc[preset][i].z; k = o->app->skel;
        func_0028D5F0(k->bones, i)[2] = v;
        if (k->hasMorph) func_0028D4E0(SkelNodes_GetAt(k->morph, i), v);
    }
}
#undef func_0028D4E0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028D300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028D300 */

/* merge_units: begin func_0028D4E0 */
#pragma push /* merge_units */
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void func_0028D4E0(O_D4E0* o, float z) {
    V4_D4E0 r; V4_D4E0 t;
    V4_D4E0* d2;
    V4_D4E0* d3;
    V4_D4E0* d1;
    float b; float c; float d; float a;
    d1 = &t; *d1 = o->v; d2 = &t; d2->z = z; d3 = &r; *d3 = *d2;
    d = r.w; c = r.z; b = r.y; a = r.x;
    o->v.x = a; o->v.y = b; o->v.z = c; o->v.w = d;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028D4E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028D4E0 */
