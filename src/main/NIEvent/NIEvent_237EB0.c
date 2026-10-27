/*
 * main/NIEvent: range (3 files, 00237EB0-00238780)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#include "vc_copy.h"
#include "net_local_id.h"

/* merge_units: begin func_00237EB0 */
#pragma push /* merge_units */
typedef struct {
    float value;
    int pad4;
    int count;
    float* keys;
    int pad10;
    int pad14;
    int time;
    unsigned char active;
    char pad1D[3];
} LightTrack237EB0;

typedef struct {
    char pad0[0x24];
    int kind;
} LightEv237EB0;

typedef struct {
    char pad0[0x170];
    LightTrack237EB0 a;
    LightTrack237EB0 b;
} LightObj237EB0;

extern int* cMessage_Name(LightEv237EB0* ev);
extern int D_004F7C28;
extern void cNIEventBase_HandleMessage(LightObj237EB0* self, LightEv237EB0* ev);

static inline void LightTrack_Rewind(LightTrack237EB0* t) {
    t->time = 0;
    if (t->count > 0) {
        t->value = t->keys[1];
    }
}

void cNIEventLight_HandleMessage(LightObj237EB0* self, LightEv237EB0* ev) {
    int t = *cMessage_Name(ev);
    if (t == D_004F7C28) {
        switch (ev->kind) {
        case 0:
            self->a.active = 1;
            self->b.active = 1;
            break;
        case 2:
            LightTrack_Rewind(&self->a);
            LightTrack_Rewind(&self->b);
            break;
        }
    }
    cNIEventBase_HandleMessage(self, ev);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237EB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237EB0 */

/* merge_units: begin func_00237F80 */
#pragma push /* merge_units */
#pragma opt_rotateloops off
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}
struct V4_7F80 { float x, y, z, w; V4_7F80() {} } __attribute__((aligned(16)));
struct V4P_7F80 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat_7F80 { V4P_7F80 r[4]; };
struct E64_7F80 { float a; float pad4[3]; V4_7F80 pos; float b[4]; float c[4]; };
struct E8_7F80 { float t; unsigned char on; };
struct V64_7F80 { int cap; int count; E64_7F80* data; };
struct V8_7F80 { int cap; int count; E8_7F80* data; E8_7F80& operator[](int i) { return data[i]; } };
struct OwnedVec_7F80 { int w[4]; };
struct Track_7F80 { float cur; OwnedVec_7F80 vec; char pad14[0xC]; void Init(); };
struct Reader_7F80 { int version; int a, b; char* cur; };
struct Light_7F80 {
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void v60(int on, V4_7F80* pos);   /* +0x60 */
    VPAD8(d) VPAD2(e) VPAD1(f)
    virtual void SetFrame(Mat_7F80* m, int f); /* +0x90 */
    VPAD32(g) VPAD8(h)
    virtual void v134(float t);              /* +0x134 */
    char pad4[8];
    int idC;
    int id10;
    char pad14[0x4C];
    int f60;
    char pad64[0x30];
    int f94;
    char pad98[0x14];
    V64_7F80 keys;
    int fB8;
    int fBC;
    int fC0;
    V8_7F80 flags;
    int fD0;
    int fD4;
    int fD8;
    unsigned char bDC;
    char padDD[3];
    V4_7F80 posE0;
    Mat_7F80 mF0;
    unsigned char b130;
    char pad131[0xF];
    int f140;
    float f144;
    float f148;
    float f14C;
    unsigned char b150;
    unsigned char b151;
    char pad152[2];
    float f154;
    float f158;
    int pad15C;
    float f160;
    float f164;
    float f168;
    float f16C;
    Track_7F80 t170;
    Track_7F80 t190;
};
extern "C" {
extern char D_004F7C98[];
extern char D_004DBED0[];
void cNIEventBase_ctor(Light_7F80* self, int kind, void* info);
void cArray_FloatKey_ctor(OwnedVec_7F80* v);
void cNetObj_AddSystem(int id, int owner, Light_7F80* o);
void cNIEventFloatTrack_Init_cPopulationR(Track_7F80* t, Reader_7F80* r);
void cNIEventFloatTrack_Init_float(Track_7F80* t, float v);
void std_vector_imp_VectorKey_resize(V64_7F80* v, int n, const E64_7F80& fill);
static inline void Assign64_7F80(V64_7F80* v, int n, const E64_7F80& fill) { E64_7F80 t; std_vector_imp_VectorKey_resize(v, 0, t); std_vector_imp_VectorKey_resize(v, n, fill); }
void std_vector_imp_VisKey_resize(V8_7F80* v, int n, const E8_7F80& fill);
static inline void Resize8_7F80(V8_7F80* v, int n, const E8_7F80& f = E8_7F80()) { std_vector_imp_VisKey_resize(v, n, f); }
static inline void Assign8_7F80(V8_7F80* v, int n, const E8_7F80& fill) { Resize8_7F80(v, 0); Resize8_7F80(v, n, fill); }
int nGobjManager_LookupGOBJ_int_int(int region, int id);
void cTerrain_AddActivation(int found, Light_7F80* o, int a, int b);
void cGOBJ_DestroyXform(Light_7F80* o);
}
static inline int RdI_7F80(Reader_7F80* r) { int t = *(int*)r->cur; r->cur += 4; return t; }
static inline float RdF_7F80(Reader_7F80* r) { float t = *(float*)r->cur; r->cur += 4; return t; }
static inline void ReadF_7F80(Reader_7F80* r, float* out) { *out = *(float*)r->cur; r->cur += 4; }
static inline void ReadId_7F80(Reader_7F80* r, int* out)
{
    int hi = RdI_7F80(r);
    int lo = RdI_7F80(r);
    *out = lo | (hi << 16);
}
static inline void Align_7F80(Reader_7F80* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
inline void Track_7F80::Init() { Track_7F80* t = this; cArray_FloatKey_ctor(&t->vec); }
static inline void VCX_7F80(void* d0, const void* s0) { const void* s = s0; void* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
static inline E8_7F80* Fl_7F80(V8_7F80* v) { E8_7F80** pd = &v->data; return *pd; }
static inline void MC2_7F80(void* d, const void* s) {
    __int128 qa, qb;
    __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory");
}
extern "C" Light_7F80* cNIEventLight_ctor(Light_7F80* self, Reader_7F80* r)
{
    volatile int id;
    int n;
    int i;
    cNIEventBase_ctor(self, 0x11, D_004F7C98);
    *(void**)self = D_004DBED0;
    self->t170.Init();
    self->t190.Init();
    self->f60 = 7;
    ReadId_7F80(r, (int*)&id);
    self->idC = id;
    if (g_IsMultiplayer) {
        self->id10 = self->idC;
        {
            int t = self->id10;
            int a = D_005721A8; int rr = 0;
            if (*(volatile unsigned char*)&g_IsMultiplayer) { if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a); rr = D_00494178; } else { asm { .set reorder } }
            cNetObj_AddSystem(t, rr, self);
        }
    }
    if (r->version >= 0x46) {
        cNIEventFloatTrack_Init_cPopulationR(&self->t170, r);
        cNIEventFloatTrack_Init_cPopulationR(&self->t190, r);
    } else {
        float a = RdF_7F80(r);
        float b = RdF_7F80(r);
        cNIEventFloatTrack_Init_float(&self->t170, a);
        cNIEventFloatTrack_Init_float(&self->t190, b);
    }
    ReadF_7F80(r, &self->f144);
    ReadF_7F80(r, &self->f148);
    ReadF_7F80(r, &self->f14C);
    if (r->version >= 0x42) {
        self->b151 = *(unsigned char*)r->cur;
        r->cur++;
        Align_7F80(r);
        self->b150 = *(unsigned char*)r->cur;
        r->cur++;
        Align_7F80(r);
    } else {
        self->b151 = 0;
        self->b150 = 0;
    }
    if (r->version >= 0x45) {
        ReadF_7F80(r, &self->f160);
        ReadF_7F80(r, &self->f164);
        ReadF_7F80(r, &self->f168);
        ReadF_7F80(r, &self->f154);
        ReadF_7F80(r, &self->f158);
    } else {
        self->f154 = 0.0f;
        self->f158 = 0.0f;
        self->f160 = 0.0f;
        self->f164 = 0.0f;
        self->f168 = 0.0f;
        self->f16C = 0.0f;
    }
    n = RdI_7F80(r);
    if (n)
        self->fBC = (int)(RdF_7F80(r) - 1.0f);
    Assign64_7F80(&self->keys, n, E64_7F80());
    for (i = 0; i < n; i++) {
        ReadF_7F80(r, &self->keys.data[i].a);
        ReadF_7F80(r, &self->keys.data[i].pos.x);
        ReadF_7F80(r, &self->keys.data[i].pos.y);
        ReadF_7F80(r, &self->keys.data[i].pos.z);
        *(int*)&self->keys.data[i].pos.w = 0x3F800000;
        ReadF_7F80(r, &self->keys.data[i].b[0]);
        ReadF_7F80(r, &self->keys.data[i].b[1]);
        ReadF_7F80(r, &self->keys.data[i].b[2]);
        ReadF_7F80(r, &self->keys.data[i].c[0]);
        ReadF_7F80(r, &self->keys.data[i].c[1]);
        ReadF_7F80(r, &self->keys.data[i].c[2]);
    }
    n = RdI_7F80(r);
    if (n) {
        self->fD4 = (int)(RdF_7F80(r) - 1.0f);
        {
            Assign8_7F80(&self->flags, n, E8_7F80());
        }
        int j;
        for (j = 0; j < n; j++) {
            ReadF_7F80(r, &self->flags.data[j].t);
            self->flags[j].on = RdF_7F80(r) != 0.0f;
        }
    } else {
        self->fD4 = -1;
        {
            Assign8_7F80(&self->flags, 1, E8_7F80());
        }
        self->flags[0].t = 0.0f;
        self->flags[0].on = 1;
    }
    {
    int k;
    int cnt = RdI_7F80(r);
    for (k = 0; k < cnt; k++) {
        int a = RdI_7F80(r);
        int b = RdI_7F80(r);
        int found = nGobjManager_LookupGOBJ_int_int(a, b);
        if (found)
            cTerrain_AddActivation(found, self, 1, found);
    }
    }
    self->f94 = 0;
    self->f140 = 0;
    V4_7F80* pp = &self->posE0;
    VCX_7F80(pp, &self->keys.data[0].pos);
    self->bDC = Fl_7F80(&self->flags)->on;
    self->v60(1, pp);
    cGOBJ_DestroyXform(self);
    {
        Mat_7F80 m;
        VCX_7F80(&m.r[3], &self->posE0);
        { Mat_7F80* dst = &self->mF0; Mat_7F80* src = &m; MC2_7F80(dst, src); }
        self->SetFrame(&m, 0);
    }
    self->b130 = 0;
    self->fC0 = 0;
    self->fD8 = 0;
    self->v134(0.0f);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237F80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237F80 */

/* merge_units: begin func_00238780 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int cGOBJ_dtor(char **, int);                              
int std_vector_cNIEventBasePtr_dtor(char * , int);                         
int std_vector_deleter_VectorKey_dtor(char * , int);                         
int std_vector_deleter_VisKey_dtor(int, int);                            
int operator_delete(char **);                            
extern void cGOBJ_ReceiveDamage();
extern void cGOBJ_UpdateMotion();
extern void cGOBJ_CriticalUpdateMotion();
extern void cGOBJ_Die();
extern void cGOBJ_Disable();
extern void cGOBJ_IsEnabled();
extern void cGOBJ_Enable();
extern void cGOBJ_Activate();
extern void cGOBJ_CreateXform();
extern void cGOBJ_ScriptGetRealObj();
extern void cGOBJ_getSOBJClassId();
extern void cGOBJ_ScriptHandleMessage();
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
extern void cGOBJ_ScaleBBox();
extern void cGOBJ_GetTargetPriority();
extern void cGOBJ_GetMovementState();
extern void cGOBJ_GetSubTargetAimAdjust();
extern void cGOBJ_GetNumSubTargets();
extern void cGOBJ_IsAimed();
extern void cGOBJ_InitNetwork();
extern void cGOBJ_CheckBullet();
extern void cNIEventBase_UpdateAll();
extern void cNIEventBase_UpdatePos();
extern void cNIEventBase_UpdateVis();
extern void cNIEventBase_ForceMatUpdate();
extern void cNIEventBase_SetEndState();
extern void cNIEventBase_Reset();
extern void cNIEventBase_Stop();
extern void cNIEventBase_Play();
extern void cNIEventBase_HandleMessage();
extern void cNIEventBase_CriticalNextFrame();
extern void cNIEventBase_NextFrame();
extern void cNIEventBase_ProcessNextFrame();
extern void cNIEventBase_GetVUM();
extern void cNIEventBase_GetChildList_void();
extern void cNIEventBase_GetChildList_void_2();
extern void cNIEventBase_IsNetworked();
extern void cGOBJ_GetTransform_ForFloorTravel();
extern void cGOBJ_GetCameraCollisionReferencePoint();
extern void cGOBJ_GetTransform_ForCameraTracking();
extern void cGOBJ_GetTransform_ForTeleporting();
extern void cGOBJ_GetCenterOfMass();
extern void cGOBJ_GetActivationPoint();
extern void cGOBJ_v35();
extern void cGOBJ_GetMatrix();
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
extern void cGOBJ_Load();
extern void cGOBJ_Init();
extern void cGOBJ_ProcessMessage();
extern void * const D_004DC190[];

char **cNIEventBase_dtor(char **arg0, long long arg1) {
    int temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_a0 = (int)((char *)arg0 + 0xC4);
        *arg0 = &(*(char*)D_004DC190);
        if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
            std_vector_deleter_VisKey_dtor(temp_a0, 0);
        }
        temp_a0_2 = (char *)arg0 + 0xAC;
        if ((temp_a0_2 != NULL) && (temp_a0_2 != NULL) && (temp_a0_2 != NULL)) {
            std_vector_deleter_VectorKey_dtor(temp_a0_2, 0);
        }
        temp_a0_3 = (char *)arg0 + 0x9C;
        if (temp_a0_3 != NULL) {
            std_vector_cNIEventBasePtr_dtor(temp_a0_3, -1);
        }
        cGOBJ_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DC190[80] = { (void*)0x0, (void*)0x0, (void*)cNIEventBase_dtor, (void*)cNIEventBase_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cNIEventBase_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_getSOBJClassId, (void*)cGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cNIEventBase_NextFrame, (void*)cNIEventBase_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cNIEventBase_GetChildList_void_2, (void*)cNIEventBase_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)cNIEventBase_ProcessNextFrame, (void*)cNIEventBase_Play, (void*)cNIEventBase_Stop, (void*)cNIEventBase_Reset, (void*)cNIEventBase_ForceMatUpdate, (void*)cNIEventBase_GetVUM, (void*)cNIEventBase_SetEndState, (void*)cNIEventBase_UpdatePos, (void*)cNIEventBase_UpdateVis, (void*)cNIEventBase_UpdateAll, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00238780(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00238780 */
