/*
 * main/gobj: range (2 files, 003CE810-003CE850)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_003CE810 */
#pragma push /* merge_units */
#pragma cplusplus on
class C3CE810 { public: VPAD16(a) virtual void f(); };
struct O3CE810 { char pad[0x2D]; unsigned char b2D; char pad2[0x2A]; C3CE810* m; };
extern "C" void func_003CE810(O3CE810* self)
{
    self->b2D = 1;
    C3CE810* m = self->m;
    if (m)
        m->f();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE810 */

/* merge_units: begin func_003CE850 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma cplusplus on
struct V4_850 { float x, y, z, w; V4_850() {} } __attribute__((aligned(16)));
class Obj_850 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual V4_850 GetPos(int);
};
extern "C" {
Obj_850* Player_GetCached(void);
Obj_850* PlayerSlots_Get(int);
}
static inline void VSub_850(V4_850* a, V4_850* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
}
static inline float LenSq_850(V4_850* a) {
    int rv0;
    float ret;
    asm { mtc1 $zero, ret } /* pins retail's dead zero-init of ret (documented idiom) */
    asm {
        lqc2 vf1, 0x0(a)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
extern "C" Obj_850* Object_ClosestPlayerDistSq(Obj_850* self, float* outDist)
{
    Obj_850* best = Player_GetCached();
    float bestD = 1e8f;
    int i = 0;
    goto test;
loop:
    {
        Obj_850* p = PlayerSlots_Get(i);
        if (p) {
            V4_850 a = self->GetPos(-1);
            V4_850 b = p->GetPos(-1);
            { V4_850* pa = &a; V4_850* pb = &b; VSub_850(pa, pb); }
            float d = LenSq_850(&a);
            if (d < bestD) {
                bestD = d;
                best = p;
            }
        }
    }
    i++;
test:
    if ((unsigned)i != 4) goto loop;
    if (outDist)
        *outDist = bestD;
    return best;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE850 */
