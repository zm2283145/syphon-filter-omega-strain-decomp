#pragma cplusplus on
#include "alloc_guard.h"
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off
static inline void V4Copy(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void V4CopySD(void* d0, const void* s0) { const void* s = s0; __int128 q; void* d = d0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void V4StoreVF0(void* d) { asm { sqc2 vf0, 0(d) } }
#define NAME_COPY(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        char* ckc_s = (src); \
        for (; ckc_i < 0x2F; ckc_i++) { \
            if (ckc_s[ckc_i] == 0) ckc_end = 1; \
            if (ckc_end) ckc_c = 0; else ckc_c = ckc_s[ckc_i]; \
            (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }


typedef struct { char d[0x9C]; } Str_L;
typedef struct {
    char pad0[0x48];
    Str_L s48;
    Str_L sE4;
    char pad180[0x10];
} __attribute__((aligned(16))) Req_L;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_L s78;
    Str_L s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Snd_L;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_L s78;
    Str_L s114;
    char pad1B0[0x20];
} __attribute__((aligned(16))) Snd2_L;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Q_L;
typedef struct { Q_L q; Q_L p; } Plc_L;
typedef struct { Q_L q; Q_L p; Q_L r; } Plc3_L;
typedef struct { float m[4][4]; } __attribute__((aligned(16))) Mtx_L;
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_L;
typedef struct { char pad[0x160]; int f160; } Root_L;
typedef struct { char pad[0xC]; int fC; } Lnk_L;
typedef struct { char pad[0x24]; int type; } Ev_L;
typedef struct {
    char pad0[0x14]; unsigned char f14; char pad15[3]; char mode[0x38 - 0x18]; int f38; char pad3C[0xDD - 0x3C];
    unsigned char bDD; char padDE[0xE4 - 0xDE]; float fE4; char padE8[0x374 - 0xE8];
    float f374; char pad378[0x3D0 - 0x378]; unsigned char b3D0; char pad3D1[2]; unsigned char b3D3;
    char pad3D4[0x9C0 - 0x3D4]; unsigned char b9C0;
} Phys_L;

struct Ctl_L {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsPlayer();
};

typedef struct Act_L {
    char pad0[0x14]; unsigned char b14; char pad15[0x58 - 0x15];
    Ctl_L* ctl; char pad5C[0x2EC0 - 0x5C];
    char sys[0x3204 - 0x2EC0];
    int f3204; char pad3208[4];
    char prio[4]; int f3210; char pad3214[0x3248 - 0x3214];
    int f3248; int f324C; char pad3250[0x326B - 0x3250];
    unsigned char b326B; char pad326C[0x3290 - 0x326C];
    Root_L* r3290; Root_L* r3294; char pad3298[0x3310 - 0x3298];
    union { Phys_L* phys; void* physv; }; char pad3314[0x33CC - 0x3314];
    int id; char f33D0[0x33E0 - 0x33D0]; float f33E0; unsigned char f33E4; char pad33E5[3]; unsigned char b33E8; char pad33E9[0x3474 - 0x33E9];
    void* f3474; Lnk_L* f3478; int f347C; char pad3480[0x3524 - 0x3480];
    int inv;
} Act_L;

#define MSG_HDR \
    void* vtable; int f04; int f08; int f0C; int f10; int f14; int f18; int f1C; signed char f20; char pad21[3]
typedef struct { MSG_HDR; int f24; int f28; void* f2C; } Msg4_L;

extern "C" {
extern char g_Game[];
extern char D_004DAE30[];
extern char D_004DADF0[];
extern char g_CasEventMsgClass[];
extern char D_004DA950[];
extern char D_0049E1C8[]; extern char D_0049D920[]; extern char D_0049E1D0[]; extern char D_0049E1E0[];
extern char D_0049E1E8[]; extern char D_0049E1F8[];
extern char D_004F24B0[]; extern char D_004F1E30[];
extern char D_0049DD50[];
extern int D_0049D040; extern int D_0049D048;
extern signed char D_0049D023;
extern float D_004A03E0; extern float g_NegFltMax;
extern int g_NoneWord;
void cSndFx_ctor_int_charP_cGOBJP_int(Req_L* r, int a, char* b, int c, int d);
void cPlaySoundMsg_ctor_cSndFxR(void* e, void* r, void* owner);
void cStopSoundMsg_ctor_cSndFxR_cGOBJP(Snd2_L* e, void* r, void* owner);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* tgt, int n);
void cFileMan_dtor(Str_L* s, int flag);
void cMessage_dtor(void* m, int flag);
void cMessage_ctor_cMessageNameR(void* m, void* t);
unsigned char AnimPriority_Helper3(void* bits, int index);
void AnimPriority_Helper2(void* p, int index, int v);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void cModeSwitch_WithHistory_12_ActivateMode_uint_2(void* p, int b);
void cModeSwitch_WithHistory_12_DeactivateMode(void* p, int b);
void cHumanCollisionRoutine_GetWaterDepth(Phys_L* p);
void cGameSystem_PopWeaponCam(void* w);
void* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
int* nSfxLoader_GetHandle(int k);
void* cSKM_GOBJ_GetSkeleton_void(void* o);
void SfxParticleEffect_int_cVectorR_cVectorR(int def, void* a, void* b);
Q_L* cSkaAnimAnchor_GetRotation(Root_L* r);
void cSkaAnimAnchor_TreeNode_SetTransformRotation_WorldSpace(Root_L* r, const void* q);
void cSkaAnimAnchor_SetRotation(Root_L* r, const Q_L& q);
Root_L* cHuman_GetFloorAnchor_void(Act_L* a);
Root_L* cHuman_GetLedgeAnchor_void_2(Act_L* a);
Q_L cQuaternion_GetRotated(Q_L* b, const Q_L* c);
float Libc_Cosf(float);
float Libc_Sinf(float);
void cWeapon_StoreWeapon_void(int inv);
void cWeapon_DrawLastWeaponUsed(int inv);
void cWeapon_Throw(int inv, float a, int* id, void* p);
void cWeapon_ReloadThrow(int inv);
void cGameSystem_PopCamera(void* w);
void* cSkaSystem_GetAnimation(void* s, Name_L* n);
void* cSkaParams_Skeleton(void* p);
int cSkeleton_GetSkeletonData(void* p);
Plc_L cSkaAnim_GetLastFrameRootTransform(void* node, int k);
void cQuatVec_ctor_cQuatVecR(Plc_L* d, Plc_L* s);
void cQuatVec_GetUnit(Plc_L* p);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(Root_L* r);
Q_L* cQuatVec_Rotation(void* p);
void* cMatrix_GetXAxis(Mtx_L* m);
void* func_0019D190(Mtx_L* m);
void cVector_ctor_cVectorR(Q_L* d, void* s);
float cVector_Z_void(Q_L* v);
float nSFOMath_GetZRotationFromXAxis(Q_L* v);
float nSFOMath_GetZRotationFromYAxis(Q_L* v);
void cHuman_LadderClearOneRungOff(Act_L* a);
void cHuman_HandleLadderStepEvent(Act_L* a);
void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(Root_L* r, Plc_L* p);
Plc_L* cSkaAnimAnchor_GetTransform(Root_L* r);
void cSkaParams_SetSliderValue_int_float(float f, void* ch, int k);
void* cSkaSystem_GetAnchor(void* sys, int* key);
void cSkaAnimAnchor_DetachChildren(void* r);
void cSkaAnimAnchor_AttachChild(void* a, void* b, int f);
int cMatrix_GetYAxis(void* p);
void cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(int* it, int v);
void cArray_cTreeNode_cSkaSystemPtrPtr_End_void(int* it, int v);
int cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(int* a, int* b);
void cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(int* a);
int* cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(int* a);
void** cTreeNode_cSkaSystemPtr_Data(int v);
void Actor_EnterDeadState(Act_L* a);
void cSkeleton_GetBoneToWorldMatrix(Plc3_L* out, void* m, signed char k);
}

static inline void Prio_L(char* p, signed char k, int v)
{
    char* q = p;
    unsigned char on;
    on = AnimPriority_Helper3(q + 0xC, k);
    AnimPriority_Helper2(q + 4, k, v);
    AnimPriority_Helper1(q);
    AnimPriority_Helper0(q, k, on);
}

#define SND(T, NAME, IMM) \
    { \
        Req_L req; \
        Snd_L ev; \
        cSndFx_ctor_int_charP_cGOBJP_int(&req, T, NAME, 0, 0); \
        cPlaySoundMsg_ctor_cSndFxR(&ev, &req, a); \
        ev.flag = 1; \
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, IMM); \
        ev.vt = D_004DAE30; \
        cFileMan_dtor(&ev.s114, -1); \
        cFileMan_dtor(&ev.s78, -1); \
        cMessage_dtor(&ev, 0); \
        cFileMan_dtor(&req.sE4, -1); \
        cFileMan_dtor(&req.s48, -1); \
    }
#define SNDP(PRESET) \
    { \
        Snd_L ev; \
        void* pr = PRESET; \
        cPlaySoundMsg_ctor_cSndFxR(&ev, pr, a); \
        ev.flag = 1; \
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0); \
        ev.vt = D_004DAE30; \
        cFileMan_dtor(&ev.s114, -1); \
        cFileMan_dtor(&ev.s78, -1); \
        cMessage_dtor(&ev, 0); \
    }

static inline void SendC_L(Act_L* a, int kind)
{
    Msg4_L m;
    Msg4_L* p = &m;
    cMessage_ctor_cMessageNameR(p, g_CasEventMsgClass);
    p->vtable = D_004DA950;
    p->f24 = kind;
    p->f28 = -1;
    p->f2C = 0;
    QueueMessage_cMessageR_cSystemP_int(p, a->ctl, 0);
    m.vtable = D_004DA950;
    cMessage_dtor(&m, 0);
}
static inline void SendCI_L(Act_L* a, int kind)
{
    Msg4_L m;
    Msg4_L* p = &m;
    cMessage_ctor_cMessageNameR(p, g_CasEventMsgClass);
    p->vtable = D_004DA950;
    p->f24 = kind;
    p->f28 = -1;
    p->f2C = 0;
    { int one = 1; m.f20 = one; QueueMessage_cMessageR_cSystemP_int(&m, a->ctl, one); }
    m.vtable = D_004DA950;
    cMessage_dtor(&m, 0);
}
static inline void SendL_L(Act_L* a, int kind, Act_L* arg)
{
    Msg4_L m;
    Msg4_L* p = &m;
    cMessage_ctor_cMessageNameR(p, g_CasEventMsgClass);
    p->vtable = D_004DA950;
    p->f24 = kind;
    p->f28 = -1;
    p->f2C = arg;
    { int one = 1; m.f20 = one; QueueMessage_cMessageR_cSystemP_int(&m, a->f3474, one); }
    m.vtable = D_004DA950;
    cMessage_dtor(&m, 0);
}
struct MsgT_L {
    Msg4_L m;
    MsgT_L(int kind, void* arg) { Msg4_L* p = &m; cMessage_ctor_cMessageNameR(p, g_CasEventMsgClass); p->vtable = D_004DA950; p->f24 = kind; p->f28 = -1; p->f2C = arg; }
    void SendLnk(Act_L* a) { int one = 1; m.f20 = one; QueueMessage_cMessageR_cSystemP_int(&m, a->f3474, one); }
    void SendCtl(Act_L* a) { int one = 1; m.f20 = one; QueueMessage_cMessageR_cSystemP_int(&m, a->ctl, one); }
    void SendCtlN(Act_L* a) { QueueMessage_cMessageR_cSystemP_int(&m, a->ctl, 1); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgT_L() { m.vtable = D_004DA950; cMessage_dtor(&m, 0); }
};
static inline bool IsPlayer_L(Act_L* a) { unsigned char r = 0; Ctl_L* c = a->ctl; if (c && c->IsPlayer()) r = 1; return r; }
static inline bool PhysOn_L(Act_L* a) { unsigned char r = 0; Phys_L* p = *(Phys_L* volatile*)&a->phys; if (p && p->bDD) r = 1; return r; }

static inline void CopyQ_L(Q_L* d, const Q_L& s) { V4Copy(d, &s); }
static inline Q_L* CopyQR_L(Q_L* d, const Q_L& s) { V4Copy(d, &s); return d; }
static inline void SetIdent_L(Q_L* d) { Q_L t; V4StoreVF0(&t); CopyQR_L(d, t); }
static inline Q_L QIdent_L() { Q_L t; V4StoreVF0(&t); return t; }
static inline void Reset_L(Root_L* r, Act_L* a, const Q_L* off) { cSkaAnimAnchor_SetRotation(r, cQuaternion_GetRotated(cSkaAnimAnchor_GetRotation(cHuman_GetLedgeAnchor_void_2(a)), off)); }
static inline void Reset3_L(Root_L* r, Act_L* a, const Q_L* off) { Reset_L(r, a, off); }
static inline void Reset2_L(Root_L* r, Act_L* a, const Q_L* off) { Reset3_L(r, a, off); }
static inline void EdgeAlign_L(Act_L* a, const Q_L& off)
{
    const Q_L* o = &off;
    Reset2_L(cHuman_GetFloorAnchor_void(a), a, &off);
}
struct V3_L { float x, y, z, w; V3_L(float a, float b, float c) { x = a; y = b; z = c; w = 0.0f; } } __attribute__((aligned(16)));
struct AA_L {
    float x, y, z, a;
    AA_L(const V3_L& v, float an) { x = v.x; y = v.y; z = v.z; a = an; }
    AA_L(float vx, float vy, float vz, float an) { x = vx; y = vy; z = vz; a = an; }
} __attribute__((aligned(16)));
struct QA_L {
    float x, y, z, w;
    QA_L(const AA_L& aa) {
        float h = 0.5f * aa.a;
        float c = Libc_Cosf(h);
        float s = Libc_Sinf(h);
        w = c;
        x = s * aa.x;
        y = s * aa.y;
        z = s * aa.z;
    }
} __attribute__((aligned(16)));
struct Act_L;
static inline void Chan05_L(Act_L* x) { char* sys = x->sys; cSkaParams_SetSliderValue_int_float(0.5f, sys + 0x10, 0xE); }

static inline bool LnkIsA_L(Lnk_L* l, Act_L* a) { return l->fC == a->f347C; }
static inline bool LinkOk_L(Act_L* a) { return !a->f3478 || LnkIsA_L(a->f3478, a); }
static inline Lnk_L* Link_L(Act_L* a) { return LinkOk_L(a) ? a->f3478 : 0; }
static inline void SetOri_L(Root_L* r, const QA_L& q) { cSkaAnimAnchor_TreeNode_SetTransformRotation_WorldSpace(r, &q); }
static inline void VPC_L(Plc_L* d, const Plc_L& s) { cQuatVec_ctor_cQuatVecR(d, (Plc_L*)&s); }
static inline void NodeQ_L(Q_L* out, Act_L* a)
{
    char* sys = a->sys;
    Plc_L plc;
    Name_L nm;
    NAME_COPY(nm.c, D_0049DD50)
    void* nd = cSkaSystem_GetAnimation(sys, &nm);
    if (nd) {
        VPC_L(&plc, cSkaAnim_GetLastFrameRootTransform(nd, cSkeleton_GetSkeletonData(cSkaParams_Skeleton(sys + 0x10))));
    } else {
        cQuatVec_GetUnit(&plc);
    }
    CopyQ_L(out, plc.q);
}
static inline Q_L QMul_L(const Q_L* pq, const Q_L* lp)
{
    Q_L t;
    Q_L* tp = &t;
    asm {
        lqc2 vf1, 0x0(pq)
        lqc2 vf2, 0x0(lp)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(tp)
    }
    return t;
}
static inline void QMulTo_L(Q_L* out, const Q_L* pq, const Q_L& l)
{
    Q_L t;
    Q_L* tp = &t;
    const Q_L* lp = &l;
    asm {
        lqc2 vf1, 0x0(pq)
        lqc2 vf2, 0x0(lp)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(tp)
    }
    CopyQ_L(out, t);
}
static inline void Rel_L(Q_L* rq, Root_L* r1, const Q_L& lq) { const Q_L* q = cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r1)); QMulTo_L(rq, q, lq); }
static inline float Yaw_L(const Q_L* rp)
{
    Mtx_L m;
    Mtx_L* mp = &m;
    asm {
        lqc2 vf1, 0x0(rp)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(mp)
        sqc2 vf8, 0x0(mp)
        sqc2 vf9, 0x10(mp)
        sqc2 vf10, 0x20(mp)
    }
    {
        Q_L va;
        Q_L vb;
        cVector_ctor_cVectorR(&va, cMatrix_GetXAxis(mp));
        cVector_ctor_cVectorR(&vb, func_0019D190(mp));
        if (cVector_Z_void(&va) < cVector_Z_void(&vb)) return nSFOMath_GetZRotationFromXAxis(&va);
        return nSFOMath_GetZRotationFromYAxis(&vb);
    }
}

struct NameC_L {
    char c[0x30];
    NameC_L(char* s) { NAME_COPY(c, s) }
} __attribute__((aligned(16)));
struct PlcR_L {
    Q_L q;
    Q_L p;
    PlcR_L() { cQuatVec_GetUnit((Plc_L*)this); }
    PlcR_L(const Plc_L& s) { cQuatVec_ctor_cQuatVecR((Plc_L*)this, (Plc_L*)&s); }
    PlcR_L(void* nd, int m) { Set(nd, m); }
    void Set(void* nd, int m) { VPC_L((Plc_L*)this, cSkaAnim_GetLastFrameRootTransform(nd, m)); }
};
static inline PlcR_L NodePlc_L(char* sys, const NameC_L& nm)
{
    void* nd = cSkaSystem_GetAnimation(sys, (Name_L*)&nm);
    if (nd) return PlcR_L(nd, cSkeleton_GetSkeletonData(cSkaParams_Skeleton(sys + 0x10)));
    return PlcR_L();
}
struct MtxQ_L {
    float m[4][4];
    MtxQ_L(const Q_L& q)
    {
        MtxQ_L* mp = this;
        const Q_L* rp = &q;
        asm {
            lqc2 vf1, 0x0(rp)
            vadd.xyzw vf2, vf1, vf1
            vaddw.xyz vf3, vf0, vf0w
            vmulx.w vf8, vf0, vf0x
            vmulx.w vf9, vf0, vf0x
            vmuly.xyzw vf5, vf1, vf2y
            vmulz.xyzw vf6, vf1, vf2z
            vmulx.xyzw vf4, vf1, vf2x
            vmulx.w vf10, vf0, vf0x
            vsubay.x ACC, vf3, vf5y
            vmsubz.x vf8, vf3, vf6z
            vsubw.x vf9, vf5, vf6w
            vaddw.x vf10, vf6, vf5w
            vaddw.y vf8, vf4, vf6w
            vsubax.y ACC, vf3, vf4x
            vmsubz.y vf9, vf3, vf6z
            vsubw.y vf10, vf6, vf4w
            vsubw.z vf8, vf4, vf5w
            vaddw.z vf9, vf5, vf4w
            vsubax.z ACC, vf3, vf4x
            vmsuby.z vf10, vf3, vf5y
            sqc2 vf0, 0x30(mp)
            sqc2 vf8, 0x0(mp)
            sqc2 vf9, 0x10(mp)
            sqc2 vf10, 0x20(mp)
        }
    }
    float Yaw()
    {
        Q_L va;
        Q_L vb;
        cVector_ctor_cVectorR(&va, cMatrix_GetXAxis((Mtx_L*)this));
        cVector_ctor_cVectorR(&vb, func_0019D190((Mtx_L*)this));
        if (cVector_Z_void(&va) < cVector_Z_void(&vb)) return nSFOMath_GetZRotationFromXAxis(&va);
        return nSFOMath_GetZRotationFromYAxis(&vb);
    }
} __attribute__((aligned(16)));

static inline void RelW_L(Q_L* rq, Root_L* r1, const Q_L& lq) { Rel_L(rq, r1, lq); }
extern "C" int AnimToken_Handle(Act_L* a, Ev_L* e)
{
    switch (e->type) {
    case 0x1:
    case 0x2:
        Prio_L(a->prio, 2, 1);
        if (((a->f3204 >> 2) & 1) || ((a->f3204 >> 1) & 1)) {
            a->f3248 &= ~4;
        } else {
            a->f3248 |= 4;
        }
        a->f3248 &= ~8;
        if (a->phys) a->phys->f38 |= 2;
        break;
    case 0x3:
        if (a->phys) {
            if (PhysOn_L(a)) {
                Phys_L* p = a->phys;
                bool mv = p->fE4 != g_NegFltMax;
                cHumanCollisionRoutine_GetWaterDepth(a->phys);
                if (!mv) {
                    SND(1, ((a->f3248 >> 2) & 1) == 0 ? D_0049E1C8 : D_0049D920, 0)
                }
                if (mv) SND(0, D_0049E1D0, 0)
            }
        }
        break;
    case 0x4:
        a->f3248 |= 8;
        break;
    case 0x5:
        if (a->phys) a->phys->f38 |= 4;
        break;
    case 0x6:
    case 0x7:
        Prio_L(a->prio, 2, 0);
        a->f3248 &= ~4;
        a->f3248 &= ~8;
        if (a->phys) {
            a->phys->f38 &= ~2;
            a->phys->f38 &= ~4;
        }
        break;
    case 0x9:
    case 0xA:
        Prio_L(a->prio, 4, 1);
        break;
    case 0xB:
        SND(1, D_0049E1E0, 1)
        break;
    case 0xC:
        a->f3248 |= 0x4000;
        break;
    case 0xF:
        a->f3248 &= ~0x4000;
        if (a->phys) a->phys->b9C0 = 0;
    case 0xD:
        if (e->type != 0xF) break;
    case 0xE:
        Prio_L(a->prio, 4, 0);
        break;
    case 0x10:
        Prio_L(a->prio, 5, 1);
        break;
    case 0x11:
    case 0x13:
        if (a->phys) a->phys->b9C0 = 0;
        if (e->type != 0x13) break;
    case 0x12:
        Prio_L(a->prio, 5, 0);
        if (a->phys) a->phys->f374 = D_004A03E0;
        break;
    case 0x94:
        Prio_L(a->prio, 0x17, 1);
        break;
    case 0x95:
    case 0x97:
        Prio_L(a->prio, 0x17, 0);
        if (e->type != 0x97) break;
    case 0x96:
        { Phys_L* p = a->phys; p->b3D0 = 1; }
        cGameSystem_PopWeaponCam(g_Game);
        a->b33E8 = 0;
        break;
    case 0x98: {
        void* o;
        if ((o = nGobjManager_LookupGOBJ_cObjectIdR(&a->id)) != 0) {
            int def = *nSfxLoader_GetHandle(0x19);
            Q_L dir;
            Plc3_L t;
            Q_L pos;
            cSkeleton_GetBoneToWorldMatrix(&t, cSKM_GOBJ_GetSkeleton_void(o), D_0049D023);
            V4CopySD(&pos, &t.p);
            if (def > -1) SfxParticleEffect_int_cVectorR_cVectorR(def, &dir, &pos);
            SNDP(D_004F24B0)
        }
        break;
    }
    case 0x99:
        SNDP(D_004F1E30)
        break;
    case 0x14:
        Prio_L(a->prio, 7, 1);
        Prio_L(a->prio, 6, 1);
        if (a->phys) {
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 5);
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 1);
        }
        QueueMessage_cMessageR_cSystemP_int(&MsgT_L(6, 0).m, a->ctl, 0);
        break;
    case 0x15: {
        void* q = cSkaAnimAnchor_GetRotation(a->r3294);
        Root_L* r = a->r3290;
        cSkaAnimAnchor_TreeNode_SetTransformRotation_WorldSpace(r, q);
        r->f160 = 0;
        break;
    }
    case 0x16:
    case 0x18:
        Prio_L(a->prio, 7, 0);
        Prio_L(a->prio, 6, 0);
        if (a->phys) {
            cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 5);
            cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 1);
        }
        if (e->type != 0x18) break;
    case 0x17:
        break;
    case 0x19:
        Prio_L(a->prio, 8, 1);
        Prio_L(a->prio, 6, 1);
        if (a->phys) {
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 5);
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 1);
        }
        break;
    case 0x1A:
    case 0x1C:
        Prio_L(a->prio, 8, 0);
        Prio_L(a->prio, 6, 0);
        if (a->phys) {
            cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 5);
            cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 1);
        }
        if (e->type != 0x1C) break;
    case 0x1B:
        break;
    case 0x1D:
        Prio_L(a->prio, 9, 1);
        break;
    case 0x1E:
    case 0x20:
        Prio_L(a->prio, 9, 0);
        break;
    case 0x21:
        Prio_L(a->prio, 0xA, 1);
        break;
    case 0x22:
    case 0x24:
        Prio_L(a->prio, 0xA, 0);
        break;
    case 0x25:
        Prio_L(a->prio, 0xB, 1);
        if (a->phys) a->phys->b9C0 = 0;
        break;
    case 0x26:
    case 0x28:
        Prio_L(a->prio, 0xB, 0);
        a->f3248 |= 0x8000;
        if (e->type != 0x28) break;
    case 0x27:
        a->f3248 &= ~0x8000;
        break;
    case 0x3D:
        Prio_L(a->prio, 0x13, 1);
        if (a->phys) {
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 5);
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 3);
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 2);
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 0xB);
        }
        cWeapon_StoreWeapon_void(a->inv);
        break;
    case 0x29:
    case 0x2E:
    case 0x33:
    case 0x38:
        Prio_L(a->prio, 1, 1);
        switch (e->type) {
        case 0x29:
            if (a->b14) {
                if (IsPlayer_L(a)) {
                    if (a->phys) a->phys->b3D3 = 1;
                }
            }
            break;
        case 0x2E:
            a->f3248 |= 0x20;
            if (a->b14) {
                if (IsPlayer_L(a)) {
                    if (a->phys) a->phys->b3D3 = 1;
                }
            }
            break;
        case 0x38:
            a->f3248 |= 0x80;
            break;
        case 0x33:
            a->f3248 |= 0x40;
            break;
        }
        break;
    case 0x2A:
    case 0x2F:
    case 0x34:
    case 0x39:
    case 0x3E:
    case 0x42:
        if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 3);
        switch (e->type) {
        case 0x39:
        case 0x3E:
            EdgeAlign_L(a, QIdent_L());
            break;
        case 0x2A:
            EdgeAlign_L(a, QIdent_L());
            break;
        case 0x2F:
            EdgeAlign_L(a, QIdent_L());
            break;
        case 0x34: {
            float an = 3.1415927f;
        QA_L q(AA_L(V3_L(0.0f, 0.0f, 1.0f), an));
            EdgeAlign_L(a, *(Q_L*)&q);
            break;
        }
        case 0x42: {
            Root_L* r0 = a->r3290;
            Root_L* r1 = a->r3294;
            char* sys = a->sys;
            Q_L lq;
            Q_L rq;
            CopyQ_L(&lq, NodePlc_L(sys, NameC_L(D_0049DD50)).q);
            RelW_L(&rq, r1, lq);
            SetOri_L(r0, QA_L(AA_L(0.0f, 0.0f, 1.0f, MtxQ_L(rq).Yaw())));
            r0->f160 = 0;
            break;
        }
        }
        break;
    case 0x2B:
    case 0x2D:
    case 0x30:
    case 0x32:
    case 0x35:
    case 0x37:
    case 0x3A:
    case 0x3C:
    case 0x3F:
    case 0x41:
    case 0x43:
    case 0x45:
        switch (e->type) {
        case 0x2B: case 0x30: case 0x35: case 0x3A: case 0x2D: case 0x32: case 0x37: case 0x3C:
            Prio_L(a->prio, 1, 0);
            break;
        case 0x3F: case 0x43: case 0x41: case 0x45:
            Prio_L(a->prio, 0x13, 0);
            break;
        }
        a->f3248 |= 0x10;
        switch (e->type) {
        case 0x35: case 0x37:
            a->f3248 &= ~0x40;
            break;
        case 0x30: case 0x32:
            a->f3248 &= ~0x20;
            break;
        case 0x3A: case 0x3C:
            a->f3248 &= ~0x80;
            break;
        }
        switch (e->type) {
        case 0x35: case 0x43: case 0x37: case 0x45:
            if (a->phys) {
                cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 5);
                cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 2);
                cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 0xB);
            }
            break;
        case 0x3A: case 0x3F: case 0x3C: case 0x41:
            if (a->phys) {
                cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 2);
                cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 0xB);
            }
            break;
        case 0x2B: case 0x30: case 0x2D: case 0x32:
            if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 5);
            break;
        }
        if (a->f3474) {
            signed char k;
            switch (e->type) {
            case 0x2B: case 0x30: case 0x35: case 0x3A: case 0x3F: case 0x43:
                k = 0xF;
                break;
            case 0x2D: case 0x32: case 0x37: case 0x3C: case 0x41: case 0x45:
                k = 0xD;
                break;
            default:
                k = 0xF;
                break;
            }
            MsgT_L(k, a).SendLnk(a);
            a->f3474 = 0;
        }
        if (a->b326B) {
            if (IsPlayer_L(a) && a->b14) {
                cGameSystem_PopCamera(g_Game);
                a->b326B = 0;
            }
        }
        switch (e->type) {
        case 0x2B: case 0x30: case 0x35: case 0x3A: case 0x2D: case 0x32: case 0x37: case 0x3C:
            break;
        case 0x3F: case 0x43: case 0x41: case 0x45:
            cWeapon_DrawLastWeaponUsed(a->inv);
            break;
        }
        if (e->type != 0x2D && e->type != 0x32 && e->type != 0x37 && e->type != 0x3C && e->type != 0x41 && e->type != 0x45) break;
    case 0x2C:
    case 0x31:
    case 0x36:
    case 0x3B:
    case 0x40:
    case 0x44:
        a->f3248 &= ~0x10;
        if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 3);
        break;
    case 0x63:
    case 0x64:
        Prio_L(a->prio, 0x14, 1);
        if (a->phys) {
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 0xB);
            if (e->type == 0x64) a->phys->f38 |= 8;
        }
        cWeapon_StoreWeapon_void(a->inv);
        break;
    case 0x67:
        if (a->f3474) MsgT_L(0xE, 0).SendLnk(a);
        break;
    case 0x6B:
        Prio_L(a->prio, 0x11, 1);
        if (a->phys) cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 0xB);
        cWeapon_StoreWeapon_void(a->inv);
        break;
    case 0x6C:
        Prio_L(a->prio, 0x12, 1);
        if (a->phys) cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 0xB);
        cWeapon_StoreWeapon_void(a->inv);
        break;
    case 0x66:
        EdgeAlign_L(a, QIdent_L());
        break;
    case 0x6D: {
        float an = 3.1415927f;
        QA_L q(AA_L(V3_L(0.0f, 0.0f, 1.0f), an));
        EdgeAlign_L(a, *(Q_L*)&q);
        break;
    }
    case 0x68:
    case 0x6A:
    case 0x6E:
    case 0x70:
        switch (e->type) {
        case 0x68: case 0x6A:
            Prio_L(a->prio, 0x14, 0);
            a->f324C &= ~1;
            if (a->phys) a->phys->f38 &= ~8;
            break;
        case 0x6E: case 0x70:
            Prio_L(a->prio, 0x11, 0);
            Prio_L(a->prio, 0x12, 0);
            if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 5);
            break;
        }
        if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 0xB);
        switch (e->type) {
        case 0x6E: case 0x70:
            break;
        case 0x68:
            if (a->f3474) {
                MsgT_L(0xF, a).SendLnk(a);
                a->f3474 = 0;
            }
            break;
        case 0x6A:
            if (a->f3474) {
                MsgT_L(0xD, a).SendLnk(a);
                a->f3474 = 0;
            }
            break;
        }
        if (IsPlayer_L(a) && a->b14 && a->b326B) {
            cGameSystem_PopCamera(g_Game);
            a->b326B = 0;
        }
        cWeapon_DrawLastWeaponUsed(a->inv);
        switch (e->type) {
        case 0x6A:
            break;
        }
        break;
    case 0x46:
        Prio_L(a->prio, 0x10, 1);
        Prio_L(a->prio, 0xC, 1);
        if (a->phys) cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 9);
        MsgT_L(0xA, 0).SendCtlN(a);
        cWeapon_StoreWeapon_void(a->inv);
        cHuman_LadderClearOneRungOff(a);
        break;
    case 0x48:
    case 0x4A:
        if ((a->f3210 >> 0x10) & 1) {
            a->f3248 |= 0x10000;
            a->f3248 &= ~0x20000;
            a->f3248 |= 0x800000;
            a->f3248 &= ~0x1000000;
            MsgT_L(0xB, 0).SendCtlN(a);
        }
        Prio_L(a->prio, 0x10, 0);
        Prio_L(a->prio, 0xC, 0);
        a->f3248 |= 0x200000;
        if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 9);
        if (e->type != 0x4A) break;
    case 0x49:
        a->f3248 &= ~0x200000;
        break;
    case 0x4B:
        Prio_L(a->prio, 0x10, 1);
        Prio_L(a->prio, 0xD, 1);
        a->f3248 |= 0x400000;
        if (a->phys) cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 9);
        break;
    case 0x4C:
        a->f3248 &= ~0x400000;
        break;
    case 0x4D:
    case 0x4F:
        Prio_L(a->prio, 0x10, 0);
        Prio_L(a->prio, 0xD, 0);
        if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 9);
        if (e->type != 0x4F) break;
    case 0x4E:
        break;
    case 0x50:
    case 0x55:
        Prio_L(a->prio, 0x10, 1);
        Prio_L(a->prio, 0xE, 1);
        if (a->phys) {
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 9);
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 8);
        }
        break;
    case 0x56:
        SND(0, D_0049E1E8, 1)
        break;
    case 0x52:
    case 0x54:
    case 0x57:
    case 0x59:
        if ((a->f3210 >> 0x10) & 1) {
            a->f3248 &= ~0x80000;
            a->f3248 &= ~0x40000;
            a->f3248 &= ~0x100000;
        }
        Prio_L(a->prio, 0x10, 0);
        Prio_L(a->prio, 0xE, 0);
        if (a->phys) {
            cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 9);
            cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 8);
        }
        if (e->type == 0x57 || e->type == 0x59) {
            Req_L req;
            Snd2_L ev;
            cSndFx_ctor_int_charP_cGOBJP_int(&req, 0, D_0049E1E8, 0, 0);
            cStopSoundMsg_ctor_cSndFxR_cGOBJP(&ev, &req, a);
            ev.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
            ev.vt = D_004DADF0;
            cFileMan_dtor(&ev.s114, -1);
            cFileMan_dtor(&ev.s78, -1);
            cMessage_dtor(&ev, 0);
            cFileMan_dtor(&req.sE4, -1);
            cFileMan_dtor(&req.s48, -1);
        }
        if (e->type != 0x54 && e->type != 0x59) break;
    case 0x53:
    case 0x58:
        if (e->type == 0x53 || e->type == 0x58) cHuman_HandleLadderStepEvent(a);
        break;
    case 0x5A:
    case 0x5B:
        if (e->type == 0x5B) {
            a->f3248 |= 0x800000;
        } else if (e->type == 0x5A) {
            a->f3248 |= 0x1000000;
        }
        break;
    case 0x5C:
        cHuman_HandleLadderStepEvent(a);
        break;
    case 0x5D:
    case 0x5E:
    case 0x62:
        Prio_L(a->prio, 0x10, 1);
        Prio_L(a->prio, 0xF, 1);
        if (e->type == 0x62) a->f3248 |= 0x20000000;
        if (a->phys) {
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 9);
            if (e->type == 0x5D) {
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 6);
            } else if (e->type == 0x5E) {
                cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 6);
            }
        }
        break;
    case 0x5F:
    case 0x61:
        Prio_L(a->prio, 0x10, 0);
        Prio_L(a->prio, 0xF, 0);
        a->f3248 &= ~0x20000000;
        a->f3248 |= 0x10000000;
        if (a->phys) {
            int t = e->type;
            if (t == 0x5F) {
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 7);
            } else if (t == 0x61) {
                cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 6);
            }
        }
        if (e->type != 0x61) break;
    case 0x60:
        a->f3248 &= ~0x10000000;
        if (a->phys) {
            cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 9);
            cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 7);
        }
        break;
    case 0x71:
        Prio_L(a->prio, 0x15, 1);
        a->f324C |= 2;
        if (a->phys) cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 0xA);
        break;
    case 0x72: {
        Prio_L(a->prio, 0x15, 1);
        Root_L* r = a->r3290;
        cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(r, cSkaAnimAnchor_GetTransform(a->r3294));
        r->f160 = 0;
        Chan05_L(a);
        if (Link_L(a)) Chan05_L((Act_L*)Link_L(a));
        break;
    }
    case 0x73:
        SND(1, D_0049E1F8, 1)
        break;
    case 0x74:
    case 0x76:
        Prio_L(a->prio, 0x15, 0);
        a->f324C |= 4;
        if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 0xA);
        if (e->type != 0x76) break;
    case 0x75:
        a->f324C &= ~2;
        a->f324C &= ~4;
        cSkaAnimAnchor_DetachChildren(cSkaSystem_GetAnchor(a->sys, &D_0049D048));
        break;
    case 0x77: {
        Prio_L(a->prio, 0x15, 1);
        char* sys = a->sys;
        a->f324C |= 8;
        int it;
        int end;
        cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(&it, cMatrix_GetYAxis(sys + 0x100));
        cArray_cTreeNode_cSkaSystemPtrPtr_End_void(&end, cMatrix_GetYAxis(sys + 0x100));
        void* root = cSkaSystem_GetAnchor(sys, &D_0049D040);
        while (cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(&it, &end)) {
            cSkaAnimAnchor_AttachChild(root, cSkaSystem_GetAnchor(*cTreeNode_cSkaSystemPtr_Data(*cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(&it)), &D_0049D040), 1);
            cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(&it);
        }
        break;
    }
    case 0x78:
        Prio_L(a->prio, 0x15, 1);
        break;
    case 0x79:
    case 0x7B:
        Prio_L(a->prio, 0x15, 0);
        if (e->type != 0x7B) break;
    case 0x7A:
        a->f324C &= ~8;
        break;
    case 0x7C:
        Prio_L(a->prio, 0x15, 1);
        a->f324C |= 0x10;
        if (a->phys) cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 0xA);
        break;
    case 0x7D:
        Prio_L(a->prio, 0x15, 1);
        cSkaAnimAnchor_DetachChildren(cSkaSystem_GetAnchor(a->sys, &D_0049D040));
        break;
    case 0x7E:
    case 0x80:
        if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 0xA);
        if (e->type != 0x80) break;
    case 0x7F:
        Prio_L(a->prio, 0x15, 0);
        a->f324C &= ~0x10;
        cSkaAnimAnchor_DetachChildren(cSkaSystem_GetAnchor(a->sys, &D_0049D048));
        break;
    case 0x81:
        Prio_L(a->prio, 0x16, 1);
        a->f324C |= 0x20;
        if (a->phys) cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 0xA);
        break;
    case 0x82:
        Prio_L(a->prio, 0x16, 1);
        break;
    case 0x83:
    case 0x85:
        Prio_L(a->prio, 0x16, 0);
        if (e->type != 0x85) break;
    case 0x84:
        a->f324C &= ~0x20;
        if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 0xA);
        break;
    case 0x86:
        Prio_L(a->prio, 0x16, 1);
        a->f324C |= 0x40;
        if (a->phys) cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 0xC);
        break;
    case 0x87:
        Prio_L(a->prio, 0x16, 1);
        break;
    case 0x89:
    case 0x8A:
        Prio_L(a->prio, 0x16, 0);
        if (e->type != 0x8A) break;
    case 0x88:
        a->f324C &= ~0x40;
        if (a->phys) cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 0xC);
        break;
    case 0x8B:
        Prio_L(a->prio, 0x16, 1);
        a->f324C |= 0x80;
        if (a->phys) {
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(a->phys->mode, 0xA);
            { Phys_L* p = a->phys; p->f14 = 3; }
        }
        break;
    case 0x8C:
        Prio_L(a->prio, 0x16, 1);
        break;
    case 0x8D:
    case 0x8F:
        Prio_L(a->prio, 0x16, 0);
        if (e->type != 0x8F) break;
    case 0x8E:
        a->f324C &= ~0x80;
        if (a->phys) {
            cModeSwitch_WithHistory_12_DeactivateMode(a->phys->mode, 0xA);
            if (!IsPlayer_L(a) || !a->b14) { Phys_L* p = a->phys; p->f14 = 1; }
        }
        break;
    case 0x91:
        Prio_L(a->prio, 0x1C, 0);
        Prio_L(a->prio, 0x1D, 1);
        break;
    case 0x90:
        Prio_L(a->prio, 0x1C, 0);
        Prio_L(a->prio, 0x1E, 1);
        break;
    case 0x92:
        Actor_EnterDeadState(a);
        break;
    case 0x93:
        Actor_EnterDeadState(a);
        Prio_L(a->prio, 0x1F, 0);
        break;
    case 0x9E:
    case 0x9F:
        Prio_L(a->prio, 0x18, 1);
        a->f324C |= 0x200;
        break;
    case 0xA0:
        a->f324C &= ~0x200;
        cWeapon_Throw(a->inv, a->f33E0, &a->id, a->f33D0);
        a->id = g_NoneWord;
        a->f33E4 = 2;
        break;
    case 0xA1:
    case 0xA3:
        Prio_L(a->prio, 0x18, 0);
        if ((*(volatile int*)&a->f324C >> 9) & 1) {
            a->f324C &= ~0x200;
            cWeapon_Throw(a->inv, a->f33E0, &a->id, a->f33D0);
            a->id = g_NoneWord;
            a->f33E4 = 2;
        }
        cWeapon_ReloadThrow(a->inv);
        a->f33E4 = 0;
        break;
    case 0x0:
    case 0x1F:
    case 0x23:
    case 0x47:
    case 0x51:
    case 0x65:
    case 0x69:
    case 0x6F:
    case 0xA2:
        break;
    default:
        return 0;
    }
    return 1;
}
