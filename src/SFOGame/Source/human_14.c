/*
 * SFOGame/Source/human: 2 files, 00186830-00186950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00186830 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Ctl_6830 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); };
struct Hum_6830 { char pad[0x14]; unsigned char alive; char pad15[0x43]; Ctl_6830* ctl; char pad5c[0x33A8 - 0x5C]; float blind; };
struct Msg_6830 { void* vt; char pad[0x1C]; unsigned char kind; char pad21[3]; int id; unsigned char sub; char pad29[3]; float v; };
extern "C" {
void ScreenFx_Start(void*, int, float, float, float, float);
void cMessage_ctor_cMessageNameR(Msg_6830*, void*);
void QueueMessage_cMessageR_cSystemP_int(Msg_6830*, void*, int);
void cMessage_dtor(Msg_6830*, int);
extern void* g_VisionFxMan;
extern float D_0048A2C8;
extern unsigned char g_IsMultiplayer;
extern char g_ActorActionMsgClass[];
extern char D_004E01C0[];
extern char D_004E0840[];
}
static inline unsigned char IsPlayer_6830(Hum_6830* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
/* blind an actor: store the amount, flash the screen for the player, broadcast */
#pragma push
#pragma opt_propagation off
extern "C" void cHuman_SetBlinded(Hum_6830* h, int silent, float v)
{
    h->blind = v;
    if (h->alive && IsPlayer_6830(h)) ScreenFx_Start(g_VisionFxMan, 1, 0.0f, D_0048A2C8, v, v);
    if (g_IsMultiplayer && !silent) {
        Msg_6830 m;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.id = 0x45;
        m.sub = 3;
        m.vt = D_004E01C0;
        m.kind = 4;
        m.v = v;
        QueueMessage_cMessageR_cSystemP_int(&m, h, 0);
        m.vt = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}
#pragma pop
static inline void merge_flush_func_00186830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00186830 */

/* merge_units: begin func_00186950 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* cHuman::HandleBlast: work out where a blast came from relative to the body; a blast from
   behind keeps the given death type, one from the front bumps it to the next type and turns the
   target heading towards the blast. */
/* lq/sq quadword copies: 128-bit moves have no C equivalent */
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct cMatrix { cVector r[4]; cMatrix() {} };
struct cEulerAngle_T { float x, y, z; cEulerAngle_T() { x = 0.0f; y = 0.0f; z = 0.0f; } };
struct cTargetZRotationStackSlot { int id; float angle; };
struct cHuman {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual cVector GetTargetPosition(int sub) const;
    VPAD8(e) VPAD4(f) virtual cMatrix GetMatrix() const;
    char pad4[0x3030 - 4];
    char motionParams[0x58];        /* 0x3030 */
    char zRotationStack[0x14];      /* 0x3088 */
};
extern "C" {
int GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(const cMatrix& m, const cVector& p, cEulerAngle_T* out);
float Libc_Atan2f(float y, float x);
double SoftFloat_FloatToDouble(float f);
cTargetZRotationStackSlot* cArray_cTargetZRotationStackSlot_opIndex(void* a, int i);
void cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(void* p, float d);
unsigned char cHuman_HandleBlast(cHuman* self, const cVector* blastOrigin, unsigned char deathTypeFromBehind);
}
/* abs.s: no C equivalent */
static inline float AbsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Atan2(float a, float b) { return Libc_Atan2f(a, b); }
static inline float ZAngle(const cMatrix& m)
{
    cVector x = m.r[0];
    cVector y = m.r[1];
    float yz = y.z;
    if (x.z < yz)
        return Atan2(x.y, x.x);
    return Libc_Atan2f(-y.x, y.y);
}

unsigned char cHuman_HandleBlast(cHuman* self, const cVector* blastOrigin, unsigned char deathTypeFromBehind)
{
    cEulerAngle_T result;
    if (blastOrigin) {
        cMatrix mat = self->GetMatrix();
        mat.r[3] = self->GetTargetPosition(-1);
        GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(mat, *blastOrigin, &result);
    }
    /* fabsf(z) > 1.57 in double; the float-to-double helper is named explicitly (MW calls it fptodp) */
    if (SoftFloat_FloatToDouble(AbsZ(result.z)) > 1.57) {
        if (result.z > 0.0f)
            result.z -= 3.14f;
        else
            result.z += 3.14f;
    } else {
        deathTypeFromBehind = deathTypeFromBehind + 1;
    }
    if (AbsZ(result.z) > 0.3f) {
        float baseZAngle = ZAngle(self->GetMatrix()); baseZAngle += result.z;
        cArray_cTargetZRotationStackSlot_opIndex(self->zRotationStack, *(int*)(self->zRotationStack + 16))->angle = baseZAngle;
        cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(self->motionParams, 0.5f);
    }
    return deathTypeFromBehind;
}
static inline void merge_flush_func_00186950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00186950 */
