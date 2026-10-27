/*
 * main/particle: range (2 files, 00397AB0-00397B20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int strcmp(const void *, const void *);

/* merge_units: begin func_00397AB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct P397AB0 { char pad[0x8F4]; int f8F4; };
class O397AB0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual P397AB0* get();
    char pad[0x5C];
    float f60;
    float f64;
};
extern "C" bool cParticleBase_Done(O397AB0* o, float x) {
    return !o->get()->f8F4 && (x - o->f64 > o->f60);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00397AB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00397AB0 */

/* merge_units: begin func_00397B20 */
#pragma push /* merge_units */
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
typedef struct { char* name; int pad4; int count; int** refs; } E397B20;
typedef struct { int pad0; int count; E397B20** items; } L397B20;
typedef struct { char pad[0x1C]; unsigned char loaded; } S397B20;
extern void cFileMan_ctor_void(void*);
extern void cFileMan_dtor(void*, int);
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(void*, char*, int, int);
extern void cParticleSystem_Load_cFileManR(S397B20*, void*);
extern int cParticleSystem_GetEffectID(void*, char*);
extern void cTimerDisable_ctor(int* g);
extern void cTimerDisable_dtor(int* g, int del);
extern void cEffectRequest_dtor(E397B20*, int);
extern void cArray_cEffectRequestPtr_dtor(L397B20*, int);
extern char D_004BC5D0[];
extern char D_004BC5E0[];
extern char D_004BC600[];
extern char D_004BC618[];
extern char D_004BC630[];
extern char D_0053B540[];
extern int D_0053B5A0;
extern int D_0053B5A8;
extern int D_0053B5B0;
extern int D_0053B5B8;
extern L397B20* D_0053BB58;

void cParticleSystem_LoadRequestedEffects(S397B20* self, int arg1)
{
    char buf[0xA0];
    int i;
    cFileMan_ctor_void(buf);
    for (i = 0; i < D_0053BB58->count; i++) {
        E397B20* e = D_0053BB58->items[i];
        int id;
        int j;
        cFileMan_EncodeFilename_charP_cHogFileR_bool(buf, e->name, arg1, 0);
        cParticleSystem_Load_cFileManR(self, buf);
        id = cParticleSystem_GetEffectID(D_0053B540, e->name);
        if (strcmp(e->name, D_004BC5E0) == 0) {
            D_0053B5A0 = id;
        } else if (strcmp(e->name, D_004BC600) == 0) {
            D_0053B5A8 = id;
        } else if (strcmp(e->name, D_004BC618) == 0) {
            D_0053B5B0 = id;
        } else if (strcmp(e->name, D_004BC630) == 0) {
            D_0053B5B8 = id;
        }
        for (j = 0; j < e->count; j++) {
            *e->refs[j] = id;
        }
        {
            int g[1];
            cTimerDisable_ctor(g);
            cEffectRequest_dtor(e, -1);
            cMemMan_Deallocate(0, e, D_004BC5D0, 0x11E1);
            cTimerDisable_dtor(g, -1);
        }
    }
    {
        L397B20* l = D_0053BB58;
        int g[1];
        cTimerDisable_ctor(g);
        cArray_cEffectRequestPtr_dtor(l, -1);
        cMemMan_Deallocate(0, l, D_004BC5D0, 0x11E4);
        cTimerDisable_dtor(g, -1);
    }
    D_0053BB58 = 0;
    self->loaded = 1;
    cFileMan_dtor(buf, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00397B20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00397B20 */
