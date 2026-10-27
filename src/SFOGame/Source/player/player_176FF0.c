/*
 * main/player: range (2 files, 00176FF0-00177060)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00176FF0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char p0[0x10]; V4 a; V4 b; char p1[0x10]; V4 c; char p2[0x10]; V4 d; char p3[0x10]; V4 e; } O_6FF0;
#define ADD1(D) { V4* d_ = D; asm { lqc2 vf1, 0x0(d_); lqc2 vf2, 0x0(v); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d_) } }
#define ADD2(D) { V4* d_; V4* e_; e_ = D; d_ = D; asm { lqc2 vf1, 0x0(e_); lqc2 vf2, 0x0(v); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d_) } }
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cSplinedMotion_cVector_TeleportByDelta(O_6FF0* o, V4* v) {
    ADD1(&o->a)
    ADD2(&o->b)
    ADD2(&o->c)
    ADD1(&o->d)
    ADD1(&o->e)
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176FF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176FF0 */

/* merge_units: begin func_00177060 */
#pragma push /* merge_units */
#pragma cplusplus on
class Obj_7060 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Attach(int on);
    virtual void Detach(int on);
};
struct S_7060 { char pad[0x1A4]; Obj_7060* obj; };
extern "C" {
void nGobjManager_RemoveGOBJ(Obj_7060* o);
void cSystem_ActualScheduleDelete(float t, Obj_7060* o);
void nGobjManager_AddGOBJ(Obj_7060* o);
}
extern "C" void cPlayer_AtmosphericParticleEffect(S_7060* self, Obj_7060* o)
{
    if (self->obj) {
        self->obj->Detach(1);
        nGobjManager_RemoveGOBJ(self->obj);
        cSystem_ActualScheduleDelete(0.1f, self->obj);
        self->obj = 0;
    }
    if (o) {
        self->obj = o;
        nGobjManager_AddGOBJ(o);
        o->Attach(1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00177060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00177060 */
