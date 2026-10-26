/*
 * main/gameCamera: range (2 files, 001807A0-00180820)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"

/* merge_units: begin func_001807A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V1807A0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q1807A0 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub1807A0 { char pad[0x10]; Q1807A0 pos; };
struct T1807A0 { V1807A0 v; char pad4[0xC]; Sub1807A0 sub; char pad40[0x20]; unsigned char b50; };
struct A1807A0 { char pad[0x50]; T1807A0* t; char pad54[0x10]; float heading; };
extern "C" {
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A1807A0* a, float dt);
}
extern "C" void cCAMERA_GOBJ_NextFrame(A1807A0* a, float dt)
{
    T1807A0* t = a->t;
    Q1807A0 p;
    if (t->b50)
        t->v.v20();
    Sub1807A0* s = (Sub1807A0*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001807A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001807A0 */

/* merge_units: begin func_00180820 */
#pragma push /* merge_units */
/* cGameCamera deleting destructor, written as plain C with explicit vtable stores:
 * each inline member dtor stores the derived then base vtable, guarded by its address. */
typedef struct { void* vt; } VO;
extern char D_004DA580[], D_004DA2F0[], D_004DA3E0[], D_004DA380[], D_004DA410[], D_004DA3B0[];
extern char D_004DA440[], D_004DA350[], D_004DAD70[], D_004DA330[], D_004DAD90[], D_004DA470[];
void cActivationTracker_dtor(void*, int);
void cCollisionModelList_dtor(void*, int);
void func_0017ED20(void*, int);
void cCameraShake_cPulsedShakeMagnitude_dtor(void*, int);
void cSplinedMotion_Scalar_dtor_void(void*, int);
void std_vector_deleter_cVector_dtor(void*, int);
void cGOBJ_dtor(void*, int);
void operator_delete(void*);

static inline void BaseD(VO* o, void* vt) { if (o) o->vt = vt; }
static inline void CrvD(VO* o, void* vt, void* bvt) { if (o) { o->vt = vt; BaseD(o, bvt); } }
static inline void S1D(void* o) { if (o) std_vector_deleter_cVector_dtor(o, 0); }
static inline void S2D(void* o) { if (o) S1D(o); }
static inline void S3D(void* o) { if (o) S2D(o); }

void* cGameCamera_dtor(char* self, short flag)
{
    if (self) {
        ((VO*)self)->vt = D_004DA580;
        if ((VO*)(self + 0xC70)) {
            ((VO*)(self + 0xC70))->vt = D_004DA2F0;
            cActivationTracker_dtor(self + 0xCB0, -1);
            cCollisionModelList_dtor(self + 0xC70, 0);
        }
        if ((VO*)(self + 0xB20)) {
            func_0017ED20(self + 0xBA0, -1);
            cCameraShake_cPulsedShakeMagnitude_dtor(self + 0xB58, -1);
            cSplinedMotion_Scalar_dtor_void(self + 0xB20, -1);
        }
        CrvD((VO*)(self + 0xA90), D_004DA3E0, D_004DA380);
        CrvD((VO*)(self + 0x9D0), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x910), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x850), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x780), D_004DA440, D_004DA350);
        CrvD((VO*)(self + 0x6C0), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x600), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x530), D_004DA440, D_004DA350);
        CrvD((VO*)(self + 0x460), D_004DA440, D_004DA350);
        CrvD((VO*)(self + 0x3A0), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x2E0), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x210), D_004DA440, D_004DA350);
        CrvD((VO*)(self + 0x170), D_004DAD70, D_004DA330);
        if ((VO*)(self + 0x70)) {
            ((VO*)(self + 0x70))->vt = D_004DAD90;
            S3D(self + 0xA0);
            BaseD((VO*)(self + 0x70), D_004DA330);
        }
        if (self) {
            ((VO*)self)->vt = D_004DA470;
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00180820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00180820 */
