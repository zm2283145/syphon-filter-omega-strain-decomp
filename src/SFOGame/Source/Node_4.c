/*
 * SFOGame/Source/Node: 2 files, 0015C2F0-0015C390
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015C2F0 */
#pragma push /* merge_units */
#include "types.h"
extern void cGOBJ_ReceiveDamage();
extern void cGOBJ_NextFrame();
extern void cGOBJ_CriticalNextFrame();
extern void cGOBJ_UpdateMotion();
extern void cGOBJ_CriticalUpdateMotion();
extern void cGOBJ_Die();
extern void cGOBJ_Disable();
extern void cGOBJ_IsEnabled();
extern void cGOBJ_Enable();
extern void cGOBJ_Activate();
extern void cGOBJ_CreateXform();
extern void cGOBJ_ScriptGetRealObj();
extern void cNode_getSOBJClassId();
extern void cNode_ScriptHandleMessage();
extern void cNode_Init();
extern void cNode_Load();
extern void cNode_v34();
extern void cNode_GetTranslation();
extern void cNode_GetActivationPoint();
extern void cNode_GetCenterOfMass();
extern void cNode_v38();
extern void cNode_v39();
extern void cNode_v3B();
extern void cSystem_ScriptGetObjectId();
extern void cSystem_SendCreated();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cGOBJ_GetFloorPlane();
extern void cGOBJ_GetBBox();
extern void func_00140E90();
extern void cGOBJ_GetHealthState();
extern void cGOBJ_IsGeneratorCreated();
extern void cGOBJ_GetTargetPosition();
extern void cGOBJ_GetLosPosition();
extern void cGOBJ_HasHeadset();
extern void cGOBJ_SetStatus();
extern void cGOBJ_GetStatus();
extern void cGOBJ_GetChildList_void();
extern void cGOBJ_GetChildList_void_2();
extern void cGOBJ_ScaleBBox();
extern void cGOBJ_GetTargetPriority();
extern void cGOBJ_GetMovementState();
extern void cGOBJ_GetSubTargetAimAdjust();
extern void cGOBJ_GetNumSubTargets();
extern void cGOBJ_IsAimed();
extern void cGOBJ_InitNetwork();
extern void cGOBJ_IsNetworked();
extern void cGOBJ_CheckBullet();
extern void cGOBJ_GetCameraCollisionReferencePoint();
extern void cGOBJ_SetTranslation_ResetPhysics();
extern void cGOBJ_SetRotation_ResetPhysics();
extern void cGOBJ_SetTransform_ResetPhysics();
extern void cGOBJ_ApplyTranslation();
extern void cGOBJ_ApplyLocalRotation();
extern void cGOBJ_ApplyTransform();
extern void cGOBJ_SetTranslation();
extern void cGOBJ_SetRotation();
extern void cGOBJ_SetTransform();
extern void cGOBJ_Deactivate();
extern void cGOBJ_NetDeactivate();
extern void cGOBJ_NetActivate();
extern void cGOBJ_Render();
extern void cGOBJ_ProcessMessage();
extern void cGOBJ_HandleMessage();
extern void * const cNode_vtable[];
extern void std_vector_deleter_tNodeLink_clear(void* p);
extern void std_vector_deleter_tNodeLink_dtor(void* p, int flag);
extern void cGOBJ_dtor(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_C2F0;
#pragma opt_common_subs off
S_C2F0* cNode_dtor(S_C2F0* self, short flag)
{
    if (self) {
        void* m;
        self->vt = ((char*)cNode_vtable);
        std_vector_deleter_tNodeLink_clear((char*)self + 0x68);
        m = (char*)self + 0x68;
        if (m) {
            if (m) {
                if (m)
                    std_vector_deleter_tNodeLink_dtor(m, 0);
            }
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma opt_common_subs reset
void * const cNode_vtable[68] = { (void*)0x0, (void*)0x0, (void*)cNode_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cNode_getSOBJClassId, (void*)cNode_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cNode_Init, (void*)cNode_Load, (void*)cGOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cNode_v34, (void*)cNode_GetTranslation, (void*)cNode_GetActivationPoint, (void*)cNode_GetCenterOfMass, (void*)cNode_v38, (void*)cNode_v39, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cNode_v3B, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die };
static inline void merge_flush_func_0015C2F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015C2F0 */

/* merge_units: begin func_0015C390 */
#pragma push /* merge_units */
// cNode::cNode(cPopulation&, int) (prototype locals numLinks/levelID/itemID/... ). The link count is read as the last argument of an inline
// whose earlier parameter is the default tNodeLink() temp: args are evaluated right to left but the temp's reference parameter is numbered first,
// which gives it s1 and the count s0 as in retail.
#pragma cplusplus on
#pragma inline_depth(8)
struct VN {
    float x, y, z, w;
    VN() {}
    VN(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    VN(const VN& o) { VN* d = this; const VN* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    VN& operator=(const VN& o) { VN* d = this; const VN* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct MtxN {
    VP r[4];
    MtxN() {}
    MtxN(const MtxN& o) { const MtxN* s = &o; MtxN* d = this; __int128 qa, qb; asm volatile { lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
};
struct ReaderN { int version; int a, b; char* cur; };
struct Elem8 { int a, b; };
static inline void CopyVP(VP* d, const VP* s) { __int128 q; asm volatile { lq q, 0x0(s); sq q, 0x0(d) } }
struct Vec8 { int capacity; unsigned int count; Elem8* data; inline void resize(int n, const Elem8& e = Elem8()); };
struct RelN { Vec8 v; unsigned char d; };
struct NodeN {
    void* vt;
    char pad4[8];
    int idC;
    char pad10[0x1D];
    unsigned char x2D;
    char pad2E[0x32];
    void* x60;
    int x64;
    RelN x68;
    int x78;
    int x7C;
    VP pos;
};
extern "C" {
extern char D_004EA770[];
extern MtxN g_IdentityMatrix;
void cGOBJ_ctor(NodeN* self, int* id, int n, char* name);
void std_vector_tNodeLink_ctor(RelN* r);
void std_vector_imp_tNodeLink_resize(Vec8* v, unsigned int n, const Elem8* value);
void* nGobjManager_LookupGOBJ_int_int(int region, int id);
void cMatrix_SetAxes(MtxN* m, VP* a, VP* b, VP* c);
void cMatrix_SetTranslation(MtxN* m, VP* t);
float Math_Acos(float x);
double SoftFloat_FloatToDouble(float f);
int _dpfge(double a, double b);
NodeN* cNode_ctor_cPopulationR_int(NodeN* self, ReaderN* r, int arg);
}
static inline int ReadI(ReaderN* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt(ReaderN* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline float ReadF(ReaderN* r) { float v = *(float*)r->cur; r->cur += 4; return v; }
static inline void ReadP(ReaderN* r, VP* v)
{
    float x = ReadF(r);
    float y = ReadF(r);
    float z = ReadF(r);
    v->w = 1.0f;
    v->x = x;
    v->y = y;
    v->z = z;
}
static inline void ReadV(ReaderN* r, VP* v, float w)
{
    float x = ReadF(r);
    float y = ReadF(r);
    float z = ReadF(r);
    v->x = x;
    v->w = w;
    v->y = y;
    v->z = z;
}
static inline void MulM(VN* v, MtxN* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline VN Xform(const VN& p, MtxN& m) { VN t = p; VN* tp = &t; MulM(tp, &m); return *tp; }
static inline VN& Unit(VN& v) { VN* p = &v; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); return v; }
static inline float Dot(const VN& a, const VN& b)
{
    float r;
    int t;
    const VN* ap = &a;
    const VN* bp = &b;
    asm { mtc1 zero, r }
    asm {
        lqc2 vf1, 0(ap)
        lqc2 vf2, 0(bp)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
inline void Vec8::resize(int n, const Elem8& e) { std_vector_imp_tNodeLink_resize(this, n, &e); }

static inline void ReadRels(ReaderN* r, Vec8* v, int n)
{
    int i;
    v->resize(n);
    for (i = 0; i < n; i++) {
        Elem8* e = &v->data[i];
        ReadInt(r, &e->a);
        ReadInt(r, &e->b);
    }
}
static inline void ReadRels2(ReaderN* r, Vec8* v, const Elem8& e, int n)
{
    int i;
    std_vector_imp_tNodeLink_resize(v, n, &e);
    for (i = 0; i < n; i++) {
        Elem8* l = &v->data[i];
        ReadInt(r, &l->a);
        ReadInt(r, &l->b);
    }
}NodeN* cNode_ctor_cPopulationR_int(NodeN* self, ReaderN* r, int arg)
{
    int numLinks;
    union { int i; } id;
    int gid = -1;
    cGOBJ_ctor(self, &gid, 10, D_004EA770);
    self->vt = (void*)cNode_vtable;
    { RelN* rl = &self->x68; std_vector_tNodeLink_ctor(rl); rl->d = 1; }
    {
        VP r0, r1, r2, t;
        MtxN m = g_IdentityMatrix;
        float a;
        int hi = ReadI(r);
        int lo = ReadI(r);
        id.i = lo | (hi << 16);
        self->idC = id.i;
        self->x60 = 0;
        if (r->version >= 0x40) {
            int c = ReadI(r);
            if (c >= 0)
                self->x60 = nGobjManager_LookupGOBJ_int_int(hi, c);
        }
        ReadInt(r, &self->x64);
        ReadP(r, &t);
        ReadV(r, &r0, 0.0f);
        ReadV(r, &r1, 0.0f);
        ReadV(r, &r2, 0.0f);
        cMatrix_SetAxes(&m, &r0, &r1, &r2);
        cMatrix_SetTranslation(&m, &t);
        {
            VN dir = Xform(VN(0.0f, 1.0f, 0.0f, 0.0f), m);
            dir.z = 0.0f;
            Unit(dir);
            a = Math_Acos(Dot(dir, VN(0.0f, 1.0f, 0.0f, 0.0f)));
            if (a != 0.0f && a != 3.1415927f) {
                if (!(dir.x < 0.0f))
                    a = 3.1415927f + (3.1415927f - a);
            }
        }
        if (_dpfge(SoftFloat_FloatToDouble(a), 6.2))
            a = 0.0f;
        CopyVP(&self->pos, &t);
        *(float*)&self->pos.w = a;
    }
    self->x78 = arg;
    ReadInt(r, &self->x7C);
    ReadRels2(r, &self->x68.v, Elem8(), ReadI(r));
    self->x2D = 0;
    return self;
}
static inline void merge_flush_func_0015C390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015C390 */
