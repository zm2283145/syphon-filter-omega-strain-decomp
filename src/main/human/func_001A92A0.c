#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct VR { float x, y, z, w; VR() {} VR(const VR& o) { x = o.x; y = o.y; z = o.z; w = o.w; } } __attribute__((aligned(16)));
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Key30;
typedef struct { char c[0x40]; } __attribute__((aligned(16))) Ev40;
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Ev30;
typedef struct { char c[0x50]; } __attribute__((aligned(16))) Ev50;
typedef struct { char c[0x60]; } __attribute__((aligned(16))) Ev60;
typedef struct { char c[0x70]; } __attribute__((aligned(16))) Ev70;
typedef struct { char c[0xA0]; } __attribute__((aligned(16))) Buf_A0;
typedef struct { char c[0xC0]; } __attribute__((aligned(16))) Buf_C0;
typedef struct { char c[0x20]; } __attribute__((aligned(16))) Buf_20;
typedef struct { char c[0x100]; } __attribute__((aligned(16))) Buf_100;
typedef struct { char c[0x200]; } __attribute__((aligned(16))) Buf_200;
typedef struct { char c[0x400]; } __attribute__((aligned(16))) Buf_400;
typedef struct { int a, b; } Y2;
typedef struct { float x, y, z; } V4u;

class Ctl_L { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };

#define AI(o) (*(int*)(a + (o)))
#define AU(o) (*(unsigned int*)(a + (o)))
#define AB(o) (*(unsigned char*)(a + (o)))
#define AF(o) (*(float*)(a + (o)))
#define AP(o) (*(char**)(a + (o)))
#define MI(o) (*(int*)(m + (o)))
#define MU(o) (*(unsigned int*)(m + (o)))
#define MB(o) (*(unsigned char*)(m + (o)))
#define MSB(o) (*(signed char*)(m + (o)))
#define MF(o) (*(float*)(m + (o)))
#define MP(o) (*(char**)(m + (o)))
#define PI(p, o) (*(int*)((char*)(p) + (o)))
#define PB(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define PF(p, o) (*(float*)((char*)(p) + (o)))
#define PP(p, o) (*(char**)((char*)(p) + (o)))
#define VF(o, off, T) (*(T*)(*(char**)(o) + (off)))
struct VO {
    virtual void x00();
    virtual void f01(void*);
    virtual void x02();
    virtual void x03();
    virtual void x04();
    virtual void x05();
    virtual void f06();
    virtual void x07();
    virtual void x08();
    virtual void x09();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17();
    virtual void x18();
    virtual void x19();
    virtual void f20();
    virtual void f21(int);
    virtual void x22();
    virtual void x23();
    virtual void x24();
    virtual void x25();
    virtual void x26();
    virtual void x27();
    virtual void x28();
    virtual void x29();
    virtual void x30();
    virtual void x31();
    virtual void x32();
    virtual void x33();
    virtual void x34();
    virtual void x35();
    virtual void x36();
    virtual void x37();
    virtual void x38();
    virtual void x39();
    virtual void x40();
    virtual void x41();
    virtual void x42();
    virtual void x43();
    virtual void x44();
    virtual void x45();
    virtual VR f46(int);
    virtual void x47();
    virtual void x48();
    virtual void x49();
    virtual void x50();
    virtual void x51();
    virtual void x52();
    virtual void x53();
    virtual VR f54();
    virtual void x55();
    virtual void x56();
    virtual void x57();
    virtual void x58();
    virtual void x59();
    virtual void x60();
    virtual void x61();
    virtual void x62();
    virtual void x63();
    virtual int f64();
};
#define VO_(o) ((VO*)(o))

extern "C" {
extern unsigned char g_IsMultiplayer;
extern int g_HumanActorClassKey;
extern float g_DefaultMotionTransition;
extern char D_0049D048[], D_0049DBC0[], D_0049E080[], D_0049E4A0[], D_0049E4D0[], D_0049E500[], D_0049E520[];
extern char D_0049E540[], D_0049E558[], D_0049E570[], D_0049E590[], D_0049E5B0[], D_0049E5C8[], D_0049E5E0[];
extern char D_0049E600[], D_0049E620[], D_0049E640[];
extern char D_004D9180[], D_004D9360[], D_004DA930[], D_004DA950[], D_004DCC70[], D_004E00E0[], D_004E01A0[];
extern char D_004E0840[], g_LosCheckService[], D_004FF2B0[], g_Game[], D_00542B60[], g_LosRequestMsgClass[], g_CasEventMsgClass[];
extern char g_ActorActionMsgClass[], g_TeleportMsgClass[];
extern signed char D_004EED58;
extern char D_004EED60[];

void cHuman_SetBlinded(char* a, int f, float t);
void cHuman_SetDeaf(char* a, int f, float t);
void cHumanMotionParams_RequestMotion_cVectorR_float_float_bool(char* p, char* v, int f, float x, float y);
void cHuman_AimWeapon(char* a, int mode);
void cHuman_CoverEyes(char* a, char* m);
char* cHuman_GetFloorAnchor_void_2(char* a);
void cHuman_HandleDeath(char* a, char* m);
void cHuman_ShootWeapon(char* a, void* b);
void Actor_HandleLedgeAction(char* a, char* m);
void Actor_HandleObjectAction(char* a, char* m);
int cHumanCollisionRoutine_CanClimbUpFromHang(char* a);
void Actor_Ignite(char* a, int f, char* o, int x, int y, float t);
void cHuman_HandleJumpInit(char* a, char* m);
void cHuman_UnCoverEyes(char* a, char* m);
void cHuman_HandleRunningJumpOffLedge(char* a, char* m);
void cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(void* sel, int* out, void* y, void* model);
void cMan_SetEyeTarget(char* l, char* o);
void cHuman_Fall(char* a);
float cSkaParams_GetSliderValue(void* c, int i);
void cSkaRequestStream_AddRequest(void* ctl, int id, int mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void cSkaAnimEndedMessage_ctor_void(void* e);
void cSkaAnimEndedMessage_ctor_cSkaAnimEndedMessageR(void* d, void* s);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper2(void* p, int index, int v);
unsigned char AnimPriority_Helper3(void* bits, int index);
V4* cSkaCrossFadeDuration_ctor_float(void* p, float f);
void BitArray_Assign(void* p, int i, int v);
unsigned char cHuman_cStates_CheckState(void* p, int i);
void cString16N_3_ctor_charP(void* k, char* s);
void cMessage_ctor_cMessageNameR(void* e, char* t);
void QueueMessage_cMessageR_cSystemP_int(void* e, char* t, int f);
unsigned char cWeapon_GetPoseType(char* w);
void cHuman_HandleGetOffLadderMessage(char* a, char* m);
void LookCtl_ClearSlot(char* l, int s, int f);
void cHumanIkRoutine_SetAimAtPoint(char* l, int s, void* p);
float Libc_Atan2f(float y, float x);
float Libc_Cosf(float x);
float COS(float x);
float Libc_Sinf(float x);
float SIN(float x);
float cSkaAnimationSet_DefaultCrossFadeDuration(void* m);
void cString16N_3_ctor_cString16NR(void* d, void* n);
void cSkaSystem_RequestTransition_ctor(void* d, void* s);
void cSkaSystem_RequestTransition_ConvertAnimationNameToAnimationPointer(void* d, char* lib);
int cSkaAnimationSet_GetNode_cString16NR(char* lib, char* name);
void* cMatrix_GetUnit(void);
char* nGobjManager_LookupGOBJ_cObjectIdR(void* id);
void cModeSwitch_WithHistory_12_DeactivateMode(char* p, int b);
char* cArray_FixedSize_cFinalLedgeSearchInfo_9_opIndex(char* p, int i);
void cHumanCollisionRoutine_cFinalLedgeSearchInfo_RequestSearch(char* s, int v);
void cModeSwitch_WithHistory_12_ActivateMode_uint_2(char* p, int b);
void* cQuatVec_ctor_cQuaternionR_cVectorR(void* d, void* a, void* b);
float* cQuatVec_Translation(void* p);
void cVector_ctor_void(void* p);
char** cTreeNode_cSkaSystemPtr_Data(char* p);
void cSkaAnimAnchor_AttachChild(char* r, char* c, int f);
float* cSkaAnimAnchor_GetPosition(char* r);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(char* r);
void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(char* r, void* p);
unsigned char Secondary_RequestOneShot(char* s, void* k, int f, void* e);
char* cSystemContainer_GetSystem(char* a, char* b);
V4* cVector_ctor_cVectorR(void* d, void* s);
void cVector_opAssign(void* d, void* s, void* t);
void cVector_Copy_WSet1(void* d, void* s);
V4* cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(void* d, void* s);
void cAxisAngle_ctor_cVectorR_float(void* d, void* s, float f);
void cVector_VU0Subtract(void* d, void* a, void* b);
char* cSafePtr_cHuman_GetPtr(void* r);
int cWeapon_CanReload(char* w);
void cWeapon_StoreWeapon_void(char* w);
void cWeapon_Reload(char* w);
void cAIGOBJMsg_ctor(void* e, char* t, char* o);
void cAIGOBJMsg_dtor(void* e, int f);
void cMessage_ctor_cMessageR(void* e, char* m);
void cCharActionMsg_ctor_cCharActionMsgR(void* e, char* m);
void cMessage_dtor(void* e, int f);
int printf(const char* f, ...);
void cCollisionFace_dtor(void* p, int f);
void cCollisionFace_ctor_void(void* p);
void cCharActionMsg_dtor(void* p, int f);
void cMatrix_ctor_cMatrixR_cVectorR(void* d, void* m, void* p);
int func_0014D410(int v);
int func_0014D450(int v);
int func_0014D460(char* a);
void cObjectId_ctor_cObjectIdR(void* d, void* s);
void cSkaAnimCheckpoints_dtor(void* p, int f);
void func_00189FD0(void* p, int f);
void cArray_FixedSize_cSkaAnimEvent_7_dtor(void* p, int f);
void cSkaAnimEndedMessage_dtor(void* p, int f);
int cSkaRequestStream_AnimationPacket_GetInstruction(void* s);
void* cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(void* s);
float cSkaRequestStream_AnimationPacket_GetDuration(void* s);
float func_0018A2C0(void* s);
void cSkaPlaybackGroupId_ctor_int(void* p, int v);
void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(void* d, void* s);
void cString16N_3_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void nSka_GetPlaybackGroupId(void* y, int m);
void* func_0018C6A0(void* s);
void* cSkaAnimCheckpoints_ScheduleEvent(void* x, void* r, int a, char* b);
void* cSkaTimeSpan_Normalized_ctor_float_float_bool(void* r, float a, float b, int k);
char* cSkaSystem_GetAnchor(char* r, char* n);
void cSkaAnimCheckpoints_ctor_void(void* p);
int cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(void* a, void* b);
void cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(void* a);
char** cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(void* a);
void cArray_cTreeNode_cSkaSystemPtrPtr_End_void(void* d, int v);
void cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(void* d, int v);
int cMatrix_GetYAxis(char* p);
int cHuman_CanTeleportToResyncRemotePlayer(char* a);
void cInteractParams_ctor_cInteractParamsR(void* d, char* s);
void cSkaCrossFadeDuration_ctor_float_float(void* d, float f, float g);
char* cGobjController_Gobj(char* p);
void cTreeNode_cSkaSystemPtr_AttachChild(char* a, char* b);
void cSkaAnimAnchor_SetTransform(char* r, void* p);
void cVector_VU0Negate(void* d, void* s);
void cSafePtr_cHuman_Set(char* a, char* b);
void cPointer_cSkaNode_dtor(void* p, int f);
void cSkaSystem_RequestTransition_dtor(void* p, int f);
void* cSkaSystem_RequestTransition_CrossFadeDuration(void* p);
void* cSkaSystem_RequestTransition_CrossFadeOutDuration(void* p);
void* cSkaSystem_RequestTransition_EndOfTransitionCallback(void* p);
void cSkaSystem_RequestTransition_GetPlaybackGroupId(void* d, void* s);
void* cSkaSystem_RequestTransition_CrossFadeInDuration(void* p);
int cPointer_cSkaNode_opMul(int v);
int func_001ADD60(void* p);
void* func_001ADD70(void* p);
int cSkaSystem_RequestTransition_HasAnim(void* p);
void cPointer_cSkaNode_ctor_cSkaNodeP(void* p, int v);
void* cSkaRequestStream_opShl(void* d, void* s);
void* cSkaTimeSpan_Normalized_ctor_float_bool(void* d, int k, float f);
void* func_001AE050(void* x, int i, int id, char* a);
int func_001AE0B0(char* p, int v);
int cHuman_CheckState(char* a, int v);
char* func_001AE140(char* a);
void MEMCPY16(void* d, void* s, int n);
int cString16N_3_Empty(void* k);
void* func_001AE260(int v);
int func_001AE270(int v);
void MEMCLEAR16(void* k, int n);
void LosProvider_SeedRegion(int s, int v);
int func_001AE360(char* s);
void cLosRequestMessage_MakeSureWValuesAreCorrect(void* e);
void cHumanMotionParams_RequestMotion_cVectorR_float_float(char* p, char* v, float x, float y);
void cBackpack_RemoveInteractBox(char* p);
int cDME_GetTime(int v);
}

static inline unsigned char IsLoc(char* a)
{
    unsigned char r = 0;
    Ctl_L* c = *(Ctl_L**)(a + 0x58);
    if (c && c->IsLocal()) r = 1;
    return r;
}
static inline void QCp(void* d, const void* s) { const void* ss = s; void* dd = d; __int128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
#define NETFLAG(bit, on) \
    if (g_IsMultiplayer) { unsigned char* np = (unsigned char*)AP(0x3584); if (np && AB(0x14)) { if (on) np[0x50] |= (bit); else np[0x50] &= ~(bit); } }
/* NAME_COPY_N: the empty asm in the else arm is a scheduling barrier that keeps the zero store unhoisted. */
#define NAME_COPY_N(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i; \
        for (ckc_i = 0; ckc_i < 0x2F; ckc_i++) { \
            if ((src)[ckc_i] == 0) ckc_end = 1; \
            { char ckc_c = 0; if (ckc_end) asm { .set reorder } else ckc_c = (src)[ckc_i]; (dst)[ckc_i] = ckc_c; } \
        } \
        (dst)[ckc_i] = 0; \
    }
typedef struct { unsigned char kind; char pad[3]; char pairs[0x38]; char tail[0x10]; } XS;
static inline void XInit(XS* x) { x->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(x->pairs); cArray_cTimedEvent_ctor_void(x->tail); }
static inline void XDtor(XS* x) { func_00189FD0(x->tail, -1); cArray_FixedSize_cSkaAnimEvent_7_dtor(x->pairs, -1); }
#define FwdMsg(a, m, f) { \
    Ev30 c; \
    char* ep = c.c; \
    cMessage_ctor_cMessageR(ep, m); \
    PP(ep, 0) = D_004E0840; \
    PI(ep, 0x24) = MI(0x24); \
    *(signed char*)(ep + 0x28) = *(signed char*)(m + 0x28); \
    PB(&c, 0x20) = 4; \
    PI(&c, 0x1C) = 0x40; \
    QueueMessage_cMessageR_cSystemP_int(ep, a, f); \
    PP(&c, 0) = D_004E0840; \
    cMessage_dtor(ep, 0); \
}
typedef void (*FnPV)(char*, void*);
typedef void (*FnP)(char*);
typedef void (*FnPI)(char*, int);
typedef int (*FnRP)(char*);
typedef void (*FnSR)(void*, char*);
typedef void (*FnSRF)(void*, char*, float);
typedef unsigned char (*FnRB)(char*);
typedef void (*FnOut)(void*, char*, int);
typedef void (*FnOut0)(void*, char*);

static inline void APri(char* a, int k, int on)
{
    char* p = a + 0x320C;
    unsigned char o = AnimPriority_Helper3(p + 0xC, k);
    AnimPriority_Helper2(p + 4, k, on);
    AnimPriority_Helper1(p);
    AnimPriority_Helper0(p, k, o);
}
static inline void PlaySlotI(char* a, XS* xp, V4* rp, int mode)
{
    int s;
    char* c;
    int id;
    Ev40 e1, e2;
    s = AI(0x326C);
    a = a + 0x2EC0;
    cSkaAnimEndedMessage_ctor_void(&e1);
    cSkaAnimEndedMessage_ctor_void(&e2);
    c = (char*)func_0018C6A0(a);
    id = func_001AE270(s);
    cSkaRequestStream_AddRequest(c, id, mode, rp, func_001AE260(s), &e1, &e2, xp, -1.0f, 0.0f);
    cSkaAnimEndedMessage_dtor(&e2, -1);
    cSkaAnimEndedMessage_dtor(&e1, -1);
}
#define PlaySlot(a, mode) PST(a, RT(g_DefaultMotionTransition), XT(), mode)
static inline void PlayNamed(char* a, void* x, void* name, V4* r, int mode)
{
    int id;
    char* c = a + 0x2EC0;
    id = cSkaAnimationSet_GetNode_cString16NR(AP(0x2EC0), (char*)name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        c = (char*)func_0018C6A0(c);
        nSka_GetPlaybackGroupId(&y, id);
        cSkaRequestStream_AddRequest(c, id, mode, r, &y, &e1, &e2, x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void PlayNamedL(char* a, void* x, void* name, V4* r, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = cSkaAnimationSet_GetNode_cString16NR(AP(0x2EC0), (char*)name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        a = (char*)func_0018C6A0(c);
        nSka_GetPlaybackGroupId(&y, id);
        cSkaRequestStream_AddRequest(a, id, mode, r, &y, &e1, &e2, x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline unsigned char IsDown(char* a)
{
    unsigned char k = VO_(a)->f64();
    return k == 3 || k == 2;
}
static inline void FailInit(char* p)
{
    cMessage_ctor_cMessageNameR(p, g_CasEventMsgClass);
    PP(p, 0) = D_004DA950;
    PI(p, 0x24) = 9;
    PI(p, 0x28) = -1;
    PI(p, 0x2C) = 0;
}
static inline void EvInit(char* p, int id, unsigned char b)
{
    cMessage_ctor_cMessageNameR(p, g_ActorActionMsgClass);
    PP(p, 0) = D_004E0840;
    PI(p, 0x24) = id;
    PB(p, 0x28) = b;
}
struct FailEv {
    char c[0x40];
    FailEv() {
        cMessage_ctor_cMessageNameR(this, g_CasEventMsgClass);
        PP(this, 0) = D_004DA950;
        PI(this, 0x24) = 9;
        PI(this, 0x28) = -1;
        PI(this, 0x2C) = 0;
    }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~FailEv() {
        PP(this, 0) = D_004DA950;
        cMessage_dtor(this, 0);
    }
};
#define FailMsg(a) { \
    Ev40 e; \
    char* p = e.c; \
    FailInit(p); \
    QueueMessage_cMessageR_cSystemP_int(p, AP(0x58), 1); \
    PP(&e, 0) = D_004DA950; \
    cMessage_dtor(p, 0); \
}
struct CtlS { void Sel(Buf_A0* selp, V4* rtp); void Sel2(Buf_A0* rsel, Buf_A0* selp, V4* rtp); void Lnk(CtlS* o) { char* oc = (char*)o; char* ctl = (char*)this; cTreeNode_cSkaSystemPtr_AttachChild(oc + 0x100, ctl + 0x100); } float Cur(int ch) { char* ctl = (char*)this; return cSkaParams_GetSliderValue(ctl + 0x10, ch); } };
#define LATCH(i) cHumanCollisionRoutine_cFinalLedgeSearchInfo_RequestSearch(cArray_FixedSize_cFinalLedgeSearchInfo_9_opIndex(AP(0x3310) + 0x3E0, (i)), 0)
#define KEYFILL(k, s) \
    { Key30 kf; cString16N_3_ctor_charP(&kf, (s)); if (!cString16N_3_Empty(&(k)) || !cString16N_3_Empty(&kf)) MEMCPY16(&(k), &kf, 3); }

static inline void PlaySlotBI(char* a, XS* xp, V4* rp, int mode)
{
    int s;
    char* c;
    int id;
    Ev40 e1, e2;
    s = AI(0x326C);
    a = a + 0x2EC0;
    cSkaAnimEndedMessage_ctor_void(&e1);
    cSkaAnimEndedMessage_ctor_void(&e2);
    c = (char*)func_0018C6A0(a);
    id = func_001AE270(s);
    cSkaRequestStream_AddRequest(c, id, mode, rp, func_001AE260(s), &e1, &e2, xp, -1.0f, 0.0f);
    cSkaAnimEndedMessage_dtor(&e2, -1);
    cSkaAnimEndedMessage_dtor(&e1, -1);
}
#define PlaySlotB(a, mode) PSBT(a, RT2(g_DefaultMotionTransition), XT(), mode)
static inline void SelCtor(char* p, int id, unsigned char f, void* xp)
{
    PB(p, 0) = 2;
    cString16N_3_ctor_void(p + 0x10);
    PI(p, 0x44) = id;
    PB(p, 0x48) = f;
    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p + 0x4C, xp);
    PF(p, 0x98) = -1.0f;
    PI(p, 0x9C) = 0;
}
inline void CtlS::Sel(Buf_A0* selp, V4* rtp)
{
    char* ctl = (char*)this;
    unsigned char* s;
    int out;
    Y2 y;
    char* q = ctl + 0x34;
    s = (unsigned char*)cSkaRequestStream_opShl(q, cSkaCrossFadeDuration_ctor_float(rtp, g_DefaultMotionTransition));
    cSkaPlaybackGroupId_ctor_int(&y, -1);
    cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(selp, &out, &y, *(void**)s);
    if (out) {
        V4 t, rr;
        Ev40 e1, e2;
        int md;
        void* pp;
        float g0;
        V4* rp = s[5] ? (V4*)(s + 8) : cSkaCrossFadeDuration_ctor_float(&t, cSkaAnimationSet_DefaultCrossFadeDuration(*(void**)s));
        cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&rr, rp);
        s[5] = 0;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        md = cSkaRequestStream_AnimationPacket_GetInstruction(selp);
        pp = cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(selp);
        g0 = cSkaRequestStream_AnimationPacket_GetDuration(selp);
        cSkaRequestStream_AddRequest(s, out, md, &rr, &y, &e1, &e2, pp, g0, func_0018A2C0(selp));
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
inline void CtlS::Sel2(Buf_A0* rsel, Buf_A0* selp, V4* rtp)
{
    char* ctl = (char*)this;
    unsigned char* s;
    int out;
    Y2 y;
    char* q = ctl + 0x34;
    s = (unsigned char*)cSkaRequestStream_opShl(q, cSkaCrossFadeDuration_ctor_float(rtp, g_DefaultMotionTransition));
    cSkaPlaybackGroupId_ctor_int(&y, -1);
    cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(rsel, &out, &y, *(void**)s);
    if (out) {
        V4 t, rr;
        Ev40 e1, e2;
        int md;
        void* pp;
        float g0;
        V4* rp = s[5] ? (V4*)(s + 8) : cSkaCrossFadeDuration_ctor_float(&t, cSkaAnimationSet_DefaultCrossFadeDuration(*(void**)s));
        cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&rr, rp);
        s[5] = 0;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        md = cSkaRequestStream_AnimationPacket_GetInstruction(selp);
        pp = cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(selp);
        g0 = cSkaRequestStream_AnimationPacket_GetDuration(selp);
        cSkaRequestStream_AddRequest(s, out, md, &rr, &y, &e1, &e2, pp, g0, func_0018A2C0(selp));
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
struct SelT {
    char c[0xA0];
    SelT(int id, unsigned char fl, void* xp) {
        char* p = c;
        PB(p, 0) = 2;
        cString16N_3_ctor_void(p + 0x10);
        PI(p, 0x44) = id;
        PB(p, 0x48) = fl;
        cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p + 0x4C, xp);
        PF(p, 0x98) = -1.0f;
        PI(p, 0x9C) = 0;
    }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SelT() { cSkaAnimCheckpoints_dtor(c + 0x4C, -1); }
} __attribute__((aligned(16)));
#define PlaySel(a, xp, id, fl) { \
    V4 rt; \
    Buf_A0 sel; \
    int idv = (id); \
    char* p = sel.c; \
    PB(p, 0) = 2; \
    cString16N_3_ctor_void(p + 0x10); \
    PI(p, 0x44) = idv; \
    PB(p, 0x48) = (fl); \
    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p + 0x4C, (xp)); \
    PF(p, 0x98) = -1.0f; \
    PI(p, 0x9C) = 0; \
    ((CtlS*)(a + 0x2EC0))->Sel(&sel, &rt); \
    cSkaAnimCheckpoints_dtor(sel.c + 0x4C, -1); \
}
#define PlaySelP(a, xp, id, fl) { \
    V4 rt; \
    Buf_A0 sel; \
    int idv = (id); \
    char* p = sel.c; \
    PB(p, 0) = 2; \
    cString16N_3_ctor_void(p + 0x10); \
    PI(p, 0x44) = idv; \
    PB(p, 0x48) = (fl); \
    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p + 0x4C, (xp)); \
    PF(p, 0x98) = -1.0f; \
    PI(p, 0x9C) = 0; \
    ((CtlS*)(a + 0x2EC0))->Sel((Buf_A0*)p, &rt); \
    cSkaAnimCheckpoints_dtor(sel.c + 0x4C, -1); \
}
#define PlaySelP2(a, xp, id, fl) { \
    V4 rt; \
    Buf_A0 sel; \
    int idv = (id); \
    char* p = sel.c; \
    PB(p, 0) = 2; \
    cString16N_3_ctor_void(p + 0x10); \
    PI(p, 0x44) = idv; \
    PB(p, 0x48) = (fl); \
    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p + 0x4C, (xp)); \
    PF(p, 0x98) = -1.0f; \
    PI(p, 0x9C) = 0; \
    ((CtlS*)(a + 0x2EC0))->Sel2((Buf_A0*)p, &sel, &rt); \
    cSkaAnimCheckpoints_dtor(sel.c + 0x4C, -1); \
}
static inline void AttachAll(char* a)
{
    char* b = a + 0x2EC0;
    int it, end;
    char* r;
    cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(&it, cMatrix_GetYAxis(b + 0x100));
    cArray_cTreeNode_cSkaSystemPtrPtr_End_void(&end, cMatrix_GetYAxis(b + 0x100));
    r = cSkaSystem_GetAnchor(b, D_0049D048);
    while (cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(&it, &end)) {
        cSkaAnimAnchor_AttachChild(r, cSkaSystem_GetAnchor(*cTreeNode_cSkaSystemPtr_Data(*cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(&it)), D_0049D048), 1);
        cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(&it);
    }
}
inline bool BTn(void* p, int i) { return !(cHuman_cStates_CheckState(p, i) != 0); }
inline bool BIs(unsigned char v) { return v != 0; }
inline bool NB2(char* o, int off) { return !(PB(o, off) != 0); }
struct MRT;
static inline void PlayMR(char* a, const MRT& mr)
{
    Buf_A0 mc;
    char* s5;
    int s4;
    s4 = AI(0x326C);
    s5 = a + 0x2EC0;
    cSkaSystem_RequestTransition_ctor(&mc, (void*)&mr);
    cSkaSystem_RequestTransition_ConvertAnimationNameToAnimationPointer(&mc, *(char**)s5);
    if (cSkaSystem_RequestTransition_HasAnim(&mc)) {
        Ev40 e1;
        Ev50 e2;
        void* c;
        int id;
        void* rg;
        Y2 y;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimCheckpoints_ctor_void(&e2);
        c = func_001ADD70(s5 + 0x10);
        id = cPointer_cSkaNode_opMul(func_001ADD60(&mc));
        rg = cSkaSystem_RequestTransition_CrossFadeInDuration(&mc);
        cSkaSystem_RequestTransition_GetPlaybackGroupId(&y, &mc);
        cSkaRequestStream_AddRequest(c, id, 1, rg, &y, cSkaSystem_RequestTransition_EndOfTransitionCallback(&mc), &e1, &e2, -1.0f, 0.0f);
        cSkaAnimCheckpoints_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
    {
        Ev40 e3, e5;
        Ev50 e4;
        int got;
        void* m2;
        void* rg;
        int md;
        void* c;
        int id;
        cSkaAnimEndedMessage_ctor_void(&e3);
        got = 0;
        cSkaAnimCheckpoints_ctor_void(&e4);
        if (cSkaSystem_RequestTransition_HasAnim(&mc)) {
            cSkaAnimEndedMessage_ctor_void(&e5);
            got = 1;
            m2 = &e5;
        } else {
            m2 = cSkaSystem_RequestTransition_EndOfTransitionCallback(&mc);
        }
        if (cSkaSystem_RequestTransition_HasAnim(&mc)) rg = cSkaSystem_RequestTransition_CrossFadeOutDuration(&mc); else rg = cSkaSystem_RequestTransition_CrossFadeDuration(&mc);
        if (cSkaSystem_RequestTransition_HasAnim(&mc)) md = 0; else md = 1;
        s5 = (char*)func_001ADD70(s5 + 0x10);
        id = func_001AE270(s4);
        cSkaRequestStream_AddRequest(s5, id, md, rg, func_001AE260(s4), &e3, m2, &e4, -1.0f, 0.0f);
        cSkaAnimCheckpoints_dtor(&e4, -1);
        if (got) cSkaAnimEndedMessage_dtor(&e5, -1);
        cSkaAnimEndedMessage_dtor(&e3, -1);
    }
    cSkaSystem_RequestTransition_dtor(&mc, -1);
}
static inline void SubTo(V4* d, V4* x, V4* y)
{
    V4 t;
    cVector_ctor_void(&t);
    cVector_VU0Subtract(&t, x, y);
    cVector_ctor_cVectorR(d, &t);
}
static inline void SetPt(char* p, void* mx, char* src)
{
    V4 cp;
    cVector_Copy_WSet1(&cp, src);
    {
        char* d = p;
        // Empty scheduling barrier: keep the destination address before the matrix argument.
        asm { .set noat }
        cMatrix_ctor_cMatrixR_cVectorR(d, mx, &cp);
    }
}
static inline void SetLook(char* a, int slot, void* src)
{
    V4 v;
    cHumanIkRoutine_SetAimAtPoint(AP(0x3314), slot, cVector_ctor_cVectorR(&v, src));
}

struct XT {
    unsigned char kind; char pad[3]; char pairs[0x38]; char tail[0x10];
    XT() { XT* q = this; q->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(q->pairs); cArray_cTimedEvent_ctor_void(q->tail); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~XT() { func_00189FD0(tail, -1); cArray_FixedSize_cSkaAnimEvent_7_dtor(pairs, -1); }
    XT* p() { return this; }
};
struct RT { float x, y, z, w; RT(float f) { cSkaCrossFadeDuration_ctor_float(this, f); } } __attribute__((aligned(16)));
struct RT2 { float x, y, z, w; RT2(float f) { cSkaCrossFadeDuration_ctor_float_float(this, f, 0.0f); } } __attribute__((aligned(16)));
struct KT { char c[0x30]; KT(char* s) { cString16N_3_ctor_charP(this, s); } } __attribute__((aligned(16)));
static inline void PNT(char* a, const KT& name, const RT& r, void* x, int mode)
{
    int id;
    char* c = a + 0x2EC0;
    id = cSkaAnimationSet_GetNode_cString16NR(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        c = (char*)func_0018C6A0(c);
        nSka_GetPlaybackGroupId(&y, id);
        cSkaRequestStream_AddRequest(c, id, mode, (V4*)&r, &y, &e1, &e2, x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void PNLT(char* a, const KT& name, const RT& r, void* x, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = cSkaAnimationSet_GetNode_cString16NR(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        a = (char*)func_0018C6A0(c);
        nSka_GetPlaybackGroupId(&y, id);
        cSkaRequestStream_AddRequest(a, id, mode, (V4*)&r, &y, &e1, &e2, x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void PNLTr(char* a, char*& c, const KT& name, const RT& r, void* x, int mode)
{
    int id;
    c = a + 0x2EC0;
    id = cSkaAnimationSet_GetNode_cString16NR(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        a = (char*)func_0018C6A0(c);
        nSka_GetPlaybackGroupId(&y, id);
        cSkaRequestStream_AddRequest(a, id, mode, (V4*)&r, &y, &e1, &e2, x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void PNLT2(char* a, const KT& name, const RT2& r, void* x, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = cSkaAnimationSet_GetNode_cString16NR(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        a = (char*)func_0018C6A0(c);
        nSka_GetPlaybackGroupId(&y, id);
        cSkaRequestStream_AddRequest(a, id, mode, (V4*)&r, &y, &e1, &e2, x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void PNLT3(char* a, const KT& name, const RT& r, const XT& x, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = cSkaAnimationSet_GetNode_cString16NR(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        a = (char*)func_0018C6A0(c);
        nSka_GetPlaybackGroupId(&y, id);
        cSkaRequestStream_AddRequest(a, id, mode, (V4*)&r, &y, &e1, &e2, (void*)&x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void PNLT4(char* a, const KT& name, const RT2& r, const XT& x, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = cSkaAnimationSet_GetNode_cString16NR(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        a = (char*)func_0018C6A0(c);
        nSka_GetPlaybackGroupId(&y, id);
        cSkaRequestStream_AddRequest(a, id, mode, (V4*)&r, &y, &e1, &e2, (void*)&x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void PST(char* a, const RT& r, const XT& x, int mode)
{
    int s;
    char* c;
    int id;
    Ev40 e1, e2;
    s = AI(0x326C);
    a = a + 0x2EC0;
    cSkaAnimEndedMessage_ctor_void(&e1);
    cSkaAnimEndedMessage_ctor_void(&e2);
    c = (char*)func_0018C6A0(a);
    id = func_001AE270(s);
    cSkaRequestStream_AddRequest(c, id, mode, (V4*)&r, func_001AE260(s), &e1, &e2, (void*)&x, -1.0f, 0.0f);
    cSkaAnimEndedMessage_dtor(&e2, -1);
    cSkaAnimEndedMessage_dtor(&e1, -1);
}
static inline void PSBT(char* a, const RT2& r, const XT& x, int mode)
{
    int s;
    char* c;
    int id;
    Ev40 e1, e2;
    s = AI(0x326C);
    a = a + 0x2EC0;
    cSkaAnimEndedMessage_ctor_void(&e1);
    cSkaAnimEndedMessage_ctor_void(&e2);
    c = (char*)func_0018C6A0(a);
    id = func_001AE270(s);
    cSkaRequestStream_AddRequest(c, id, mode, (V4*)&r, func_001AE260(s), &e1, &e2, (void*)&x, -1.0f, 0.0f);
    cSkaAnimEndedMessage_dtor(&e2, -1);
    cSkaAnimEndedMessage_dtor(&e1, -1);
}
struct RTU { float x, y, z, w; RTU() {} } __attribute__((aligned(16)));
struct ST {
    char c[0xA0];
    ST(char*& p, int id, unsigned char fl, void* xp) {
        p = c;
        PB(p, 0) = 2;
        cString16N_3_ctor_void(p + 0x10);
        PI(p, 0x44) = id;
        PB(p, 0x48) = fl;
        cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p + 0x4C, xp);
        PF(p, 0x98) = -1.0f;
        PI(p, 0x9C) = 0;
    }
    ST(int id, unsigned char fl, void* xp) {
        char* p = c;
        PB(p, 0) = 2;
        cString16N_3_ctor_void(p + 0x10);
        PI(p, 0x44) = id;
        PB(p, 0x48) = fl;
        cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p + 0x4C, xp);
        PF(p, 0x98) = -1.0f;
        PI(p, 0x9C) = 0;
    }
    ST(int id, unsigned char fl, const XT& x) {
        char* p = c;
        PB(p, 0) = 2;
        cString16N_3_ctor_void(p + 0x10);
        PI(p, 0x44) = id;
        PB(p, 0x48) = fl;
        cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p + 0x4C, (void*)&x);
        PF(p, 0x98) = -1.0f;
        PI(p, 0x9C) = 0;
    }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ST() { cSkaAnimCheckpoints_dtor(c + 0x4C, -1); }
} __attribute__((aligned(16)));
struct CtlT { void SelX(const RTU& rtr, const ST& sr); void SelX2(const RTU& rtr, const ST& sr); };
#define PlaySelT(a, x, id, fl) ((CtlT*)((a) + 0x2EC0))->SelX(RTU(), ST((id), (fl), x))
#define PlaySelT2(a, x, id, fl) ((CtlT*)((a) + 0x2EC0))->SelX2(RTU(), ST((id), (fl), x))
#define PlaySelT2R(a, x, id, fl, pv) ((CtlT*)((a) + 0x2EC0))->SelX2(RTU(), ST(pv, (id), (fl), x))
inline void CtlT::SelX(const RTU& rtr, const ST& sr)
{
#define selp ((Buf_A0*)&sr)
#define rtp ((V4*)&rtr)
    char* ctl = (char*)this;
    unsigned char* s;
    int out;
    Y2 y;
    char* q = ctl + 0x34;
    s = (unsigned char*)cSkaRequestStream_opShl(q, cSkaCrossFadeDuration_ctor_float(rtp, g_DefaultMotionTransition));
    cSkaPlaybackGroupId_ctor_int(&y, -1);
    cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(selp, &out, &y, *(void**)s);
    if (out) {
        V4 rr, t;
        Ev40 e1, e2;
        int md;
        void* pp;
        float g0;
        V4* rp = s[5] ? (V4*)(s + 8) : cSkaCrossFadeDuration_ctor_float(&t, cSkaAnimationSet_DefaultCrossFadeDuration(*(void**)s));
        cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&rr, rp);
        s[5] = 0;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        md = cSkaRequestStream_AnimationPacket_GetInstruction(selp);
        pp = cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(selp);
        g0 = cSkaRequestStream_AnimationPacket_GetDuration(selp);
        cSkaRequestStream_AddRequest(s, out, md, &rr, &y, &e1, &e2, pp, g0, func_0018A2C0(selp));
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
inline void CtlT::SelX2(const RTU& rtr, const ST& sr)
{
#define rsel ((Buf_A0*)&sr)
#define selp ((Buf_A0*)&sr)
#define rtp ((V4*)&rtr)
    char* ctl = (char*)this;
    unsigned char* s;
    int out;
    Y2 y;
    char* q = ctl + 0x34;
    s = (unsigned char*)cSkaRequestStream_opShl(q, cSkaCrossFadeDuration_ctor_float(rtp, g_DefaultMotionTransition));
    cSkaPlaybackGroupId_ctor_int(&y, -1);
    cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(rsel, &out, &y, *(void**)s);
    if (out) {
        V4 rr, t;
        Ev40 e1, e2;
        int md;
        void* pp;
        float g0;
        V4* rp = s[5] ? (V4*)(s + 8) : cSkaCrossFadeDuration_ctor_float(&t, cSkaAnimationSet_DefaultCrossFadeDuration(*(void**)s));
        cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&rr, rp);
        s[5] = 0;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        md = cSkaRequestStream_AnimationPacket_GetInstruction(selp);
        pp = cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(selp);
        g0 = cSkaRequestStream_AnimationPacket_GetDuration(selp);
        cSkaRequestStream_AddRequest(s, out, md, &rr, &y, &e1, &e2, pp, g0, func_0018A2C0(selp));
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
#undef selp
#undef rtp
#undef rsel
struct OSE0 { char c[0x40];
    OSE0(char* a) { char* ep = c; cMessage_ctor_cMessageNameR(ep, D_00542B60); PP(ep, 0) = D_004DA930; PI(ep, 0x24) = 0; PB(ep, 0x28) = 0; PP(ep, 0x2C) = a; PB(ep, 0x30) = 0; PI(ep, 0x34) = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~OSE0() { PP(this, 0) = D_004DA930; cMessage_dtor(this, 0); } } __attribute__((aligned(16)));
struct MRT { char c[0xA0];
    MRT(Key30* k, const RT& r2, const RT& r1, const OSE0& ev) { char* mp = c; cString16N_3_ctor_cString16NR(mp, k); cPointer_cSkaNode_ctor_cSkaNodeP(mp + 0x30, 0); cSkaPlaybackGroupId_ctor_int(mp + 0x34, -1); cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(mp + 0x3C, (void*)&r2); cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(mp + 0x4C, (void*)&r1); cSkaAnimEndedMessage_ctor_cSkaAnimEndedMessageR(mp + 0x5C, (void*)&ev); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MRT() { cSkaAnimEndedMessage_dtor(c + 0x5C, -1); cPointer_cSkaNode_dtor(c + 0x30, -1); }
    char* q() { return c; } } __attribute__((aligned(16)));
struct V4T { float x, y, z, w; V4T(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
static inline void QCpT(void* d, const V4T& s) { QCp(d, (void*)&s); }
struct VP { float x, y, z, w; VP(const float* s) { cVector_ctor_cVectorR(this, (void*)s); } } __attribute__((aligned(16)));
struct VC { float x, y, z, w; VC() { cVector_ctor_void(this); } VC(const VC& o) { cVector_ctor_cVectorR(this, (void*)&o); } } __attribute__((aligned(16)));
static inline VC DirOf(V4* v) { VC t; cVector_VU0Negate(&t, v); return t; }
static inline float Yaw(const VC& d) { return Libc_Atan2f(-d.x, d.y); }
struct AA { float x, y, z, w; AA(V4* ax, float f) { cAxisAngle_ctor_cVectorR_float(this, ax, f); } } __attribute__((aligned(16)));
static inline void QAA(V4* q, const AA& w) { float hf = 0.5f * w.w; float c = COS(hf); float sn = SIN(hf); q->w = c; q->x = sn * w.x; q->y = sn * w.y; q->z = sn * w.z; }
static inline void* PlId(V4* q, V4* p) { Buf_20 pl; return cQuatVec_ctor_cQuaternionR_cVectorR(&pl, q, p); }
struct FT { char c[0x30];
    FT() { char* p = c; FailInit(p); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~FT() { PP(this, 0) = D_004DA950; cMessage_dtor(this, 0); }
    char* q() { return c; } } __attribute__((aligned(16)));
static inline void ESend(const FT& e, char* d, int f) { QueueMessage_cMessageR_cSystemP_int((char*)&e, d, f); }
struct OSE { char c[0x40];
    OSE(char* a) { char* ep = c; cMessage_ctor_cMessageNameR(ep, D_00542B60); PP(ep, 0) = D_004DA930; PI(ep, 0x24) = 1; PB(ep, 0x28) = 0; PP(ep, 0x2C) = a; PB(ep, 0x30) = 0; PI(ep, 0x34) = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~OSE() { PP(this, 0) = D_004DA930; cMessage_dtor(this, 0); }
    void* p() { return this; } } __attribute__((aligned(16)));
static inline unsigned char ROS(char* s, Key30* k, int f, const OSE& e) { return Secondary_RequestOneShot(s, k, f, (void*)&e); }
struct FireT { char c[0x30]; FireT(char* p) { cObjectId_ctor_cObjectIdR(this, p); PI(this, 4) = PI(p, 4); PB(this, 8) = PB(p, 8); cVector_ctor_cVectorR(c + 0x10, p + 0x10); PF(this, 0x20) = PF(p, 0x20); } } __attribute__((aligned(16)));
static inline void HFire(char* a, const FireT& f) { cHuman_ShootWeapon(a, (void*)&f); }
#undef KEYFILL
static inline void KF(Key30* k, const KT& kf) { if (!cString16N_3_Empty(k) || !cString16N_3_Empty((void*)&kf)) MEMCPY16(k, (void*)&kf, 3); }
#define KEYFILL(k, s) KF(&(k), KT(s));


#define DirTail(a, m) { QCp(a + 0x30B0, m + 0x30); AF(0x30C0) = MF(0x50); QCpT(a + 0x30D0, V4T(-Libc_Sinf(AF(0x30C0)), Libc_Cosf(AF(0x30C0)), 0.0f, 0.0f)); }

static inline void DirTailP(char* a, char* m, V4* d, char* dp)
{
    float c;
    QCp(a + 0x30B0, m + 0x30);
    AF(0x30C0) = MF(0x50);
    c = Libc_Cosf(AF(0x30C0));
    d->x = -Libc_Sinf(AF(0x30C0));
    d->y = c;
    d->z = 0.0f;
    d->w = 0.0f;
    QCp(dp, d);
}

#define NETFP(bit, src) \
    { unsigned char* op = (unsigned char*)(src); if (g_IsMultiplayer) { unsigned char* np = (unsigned char*)AP(0x3584); if (np && AB(0x14)) { if (*op) np[0x50] |= (bit); else np[0x50] &= ~(bit); } } }
static inline void SetA0(char* w, unsigned char v) { w[0xA0] = v; }
static inline void LnkF(char* x, char* y) { char* xc = x; char* yc = y; cTreeNode_cSkaSystemPtr_AttachChild(xc + 0x100, yc + 0x100); }
static inline void QCp2(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%0)" : "=r"(q) : "0"(s) : "memory"); void* dd = d; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(dd) : "memory"); }
static inline void LnkH(char* y, char* x) { char* xc; char* yc; yc = y; xc = x; cTreeNode_cSkaSystemPtr_AttachChild(xc + 0x100, yc + 0x100); }
static inline bool IsCls2(char* p) { int d = g_HumanActorClassKey; int k = PI(p, 0x4C); return k == d; }
static inline bool NotB(unsigned char v) { return !v; }
static inline VC FlPos(char* a) { return *(const VC*)cSkaAnimAnchor_GetPosition(cHuman_GetFloorAnchor_void_2(a)); }
static inline unsigned char AtFlY(char* m, const VC& fl) { V4* mp; unsigned char e, e2; mp = (V4*)(m + 0x30); e = 0; e2 = 0; if (MF(0x30) == fl.x && mp->y == fl.y) e2 = 1; if (e2 && mp->z == fl.z) e = 1; return e; }
static inline unsigned char AtFlX(char* m, const V4& fl) { V4* mp; unsigned char e, e2; mp = (V4*)(m + 0x30); e = 0; e2 = 0; if (MF(0x30) == fl.x && mp->y == fl.y) e2 = 1; if (e2 && mp->z == fl.z) e = 1; return e; }
extern "C" unsigned char cHuman_HandleActionRequest(char* a, char* m)
{
    unsigned char r = 1;
    switch (MI(0x24)) {
    case 0x0:
        switch (MB(0x28)) {
        case 12:
            if (MB(0x48) != 2) {
                { float y = MF(0x44); unsigned char b = MB(0x48) == 1; float x = MF(0x40); cHumanMotionParams_RequestMotion_cVectorR_float_float_bool(a + 0x3030, m + 0x30, b, x, y); }
            } else {
                { char* v = m + 0x30; float y = MF(0x44); float x = MF(0x40); cHumanMotionParams_RequestMotion_cVectorR_float_float(a + 0x3030, v, x, y); }
            }
            AB(0x30AC) = 0;
            AB(0x30AD) = 0;
            break;
        case 13:
            if (g_IsMultiplayer) {
                if (!AB(0x14) && IsLoc(a)) {
                    if (MU(0xC) < AU(0x3594)) {
                        printf(D_0049E4A0, MU(0xC), AU(0x3594));
                    } else {
                        int t = cDME_GetTime(0);
                        if (t - AI(0x3580) >= 150 && cHuman_CanTeleportToResyncRemotePlayer(a) && IsLoc(a)) {
                            if (!AtFlY(m, FlPos(a))) {
                                V4 p1, p2, f1, f2, d1, d2;
                                Buf_A0 h1, h2;
                                Ev60 ev1, ev2;
                                Ev70 ev3;
                                char* svc;
                                int v;
                                QCp(&p1, m + 0x30);
                                QCp(&p2, m + 0x30);
                                p1.z += 4.5f;
                                p2.z += 2.5f;
                                cVector_ctor_cVectorR(&f1, cSkaAnimAnchor_GetPosition(cHuman_GetFloorAnchor_void_2(a)));
                                cVector_ctor_cVectorR(&f2, cSkaAnimAnchor_GetPosition(cHuman_GetFloorAnchor_void_2(a)));
                                f1.z += 4.5f; f2.z += 2.5f; f1.w = 1.0f; f2.w = 1.0f;
                                SubTo(&d1, &p1, &f1);
                                SubTo(&d2, &p2, &f2);
                                d1.w = 0.0f;
                                d2.w = 0.0f;
                                { char* hp = h1.c; cVector_ctor_void(hp + 0x10); cCollisionFace_ctor_void(hp + 0x20); }
                                { char* hp = h2.c; cVector_ctor_void(hp + 0x10); cCollisionFace_ctor_void(hp + 0x20); }
                                {
                                char* ep = ev1.c;
                                cMessage_ctor_cMessageNameR(ep, g_LosRequestMsgClass);
                                PP(ep, 0) = D_004D9180;
                                PI(ep, 0x24) = 0;
                                PI(ep, 0x28) = 0;
                                PP(ep, 0x2C) = h1.c;
                                cVector_ctor_cVectorR(ep + 0x30, &f1);
                                cVector_ctor_cVectorR(ep + 0x40, &d1);
                                PP(ep, 0x50) = a;
                                PI(ep, 0x54) = 0;
                                PI(ep, 0x58) = 4;
                                PB(ep, 0x5C) = 0;
                                cLosRequestMessage_MakeSureWValuesAreCorrect(ep);
                                }
                                {
                                char* ep = ev2.c;
                                cMessage_ctor_cMessageNameR(ep, g_LosRequestMsgClass);
                                PP(ep, 0) = D_004D9180;
                                PI(ep, 0x24) = 0;
                                PI(ep, 0x28) = 0;
                                PP(ep, 0x2C) = h2.c;
                                cVector_ctor_cVectorR(ep + 0x30, &f2);
                                cVector_ctor_cVectorR(ep + 0x40, &d2);
                                PP(ep, 0x50) = a;
                                PI(ep, 0x54) = 0;
                                PI(ep, 0x58) = 4;
                                PB(ep, 0x5C) = 0;
                                cLosRequestMessage_MakeSureWValuesAreCorrect(ep);
                                }
                                svc = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
                                v = func_0014D410(func_0014D450(func_0014D460(a)));
                                if (v) LosProvider_SeedRegion(func_001AE360(svc), v);
                                VO_(svc)->f01(&ev1);
                                VO_(svc)->f01(&ev2);
                                if ((*(unsigned char*)h1.c || *(unsigned char*)h2.c) && IsLoc(a)) {
                                    char* ep; char* src; void* mx;
                                    ep = ev3.c; src = m + 0x30;
                                    cMessage_ctor_cMessageNameR(ep, g_TeleportMsgClass);
                                    PP(ep, 0) = D_004D9360;
                                    PB(ep, 0x24) = 0;
                                    mx = cMatrix_GetUnit();
                                    SetPt(ep + 0x30, mx, src);
                                    PB(&ev3, 0x20) = 1;
                                    QueueMessage_cMessageR_cSystemP_int(ep, a, 1);
                                    PP(&ev3, 0) = D_004D9360;
                                    cMessage_dtor(ep, 0);
                                }
                                AI(0x3580) = t;
                                PP(&ev2, 0) = D_004D9180;
                                cMessage_dtor(&ev2, 0);
                                PP(&ev1, 0) = D_004D9180;
                                cMessage_dtor(&ev1, 0);
                                cCollisionFace_dtor(h2.c + 0x20, -1);
                                cCollisionFace_dtor(h1.c + 0x20, -1);
                            }
                        }
                        {
                            char* dp;
                            { QCp(a + 0x30B0, m + 0x30); AF(0x30C0) = MF(0x50); QCpT(dp = a + 0x30D0, V4T(-Libc_Sinf(AF(0x30C0)), Libc_Cosf(AF(0x30C0)), 0.0f, 0.0f)); }
                            AF(0x30E0) = 1.0f;
                            cVector_opAssign(a + 0x3570, m + 0x40, dp);
                            if (!AB(0x14)) AB(0x30AC) = 1;
                        }
                    }
                } else {
                    char* p;
                    DirTail(a, m);
                    AF(0x30E0) = MF(0x54);
                    AB(0x30AC) = 1;
                    if (IsLoc(a)) { float f = MF(0x54); p = AP(0x3584); if (p) PF(p, 0x3C) = f; }
                    if (AB(0x14)) { float f = MF(0x50); p = AP(0x3584); if (p) PF(p, 0x40) = f; }
                }
            } else {
                DirTail(a, m);
                AF(0x30E0) = MF(0x54);
                AB(0x30AC) = 1;
            }
            break;
        }
        break;
    case 0x1:
    {
        char* p = AP(0x3310);
        unsigned char ok = 0;
        if (p && PB(p, 0xDD)) ok = 1;
        if (ok) {
            BitArray_Assign(a + 0x3248, 0, 1);
            NETFLAG(1, 1)
        }
        break;
    }
    case 0x2:
        BitArray_Assign(a + 0x3248, 0, 0);
        NETFLAG(1, 0)
        break;
    case 0x9:
        BitArray_Assign(a + 0x3248, 1, 1);
        break;
    case 0xA:
        BitArray_Assign(a + 0x3248, 1, 0);
        break;
    case 0x3:
        AB(0x31B3) = MB(0x2C);
        NETFP(4, m + 0x2C)
        break;
    case 0x4:
        AB(0x31B4) = MB(0x2C);
        NETFP(8, m + 0x2C)
        break;
    case 0x6:
        AB(0x3539) = 1;
        break;
    case 0x7:
    {
        int on = MI(0x2C);
        char* pr = a + 0x320C;
        if (!((AI(0x3210) >> 27) & 1) && !((AI(0x3210) >> 31) & 1)) {
            if (on) {
                unsigned char o = AnimPriority_Helper3(pr + 0xC, 0x1A);
                AnimPriority_Helper2(pr + 4, 0x1A, 1);
                AnimPriority_Helper1(pr);
                AnimPriority_Helper0(pr, 0x1A, o);
                if (!D_004EED58) {
                    NAME_COPY_N(D_004EED60, D_0049E080)
                    D_004EED58 = 1;
                }
                {
                    PNLT3(a, *(KT*)D_004EED60, RT(0.1f), XT(), 1);
                }
            } else if (AI(0x320C) == 0x1A) {
                unsigned char o = AnimPriority_Helper3(pr + 0xC, 0x1A);
                AnimPriority_Helper2(pr + 4, 0x1A, 0);
                AnimPriority_Helper1(pr);
                AnimPriority_Helper0(pr, 0x1A, o);
                PlaySlot(a, 0);
            }
        }
        break;
    }
    case 0x39:
        switch (MB(0x28)) {
        case 1:
            cHuman_AimWeapon(a, MB(0x2C));
            break;
        case 4:
        {
            char* q = m + 0x30;
            if (AP(0x3314)) {
                cHuman_AimWeapon(a, 1);
                SetLook(a, 0, q);
            }
            break;
        }
        case 11:
        {
            char* o = nGobjManager_LookupGOBJ_cObjectIdR(m + 0x30);
            if (o) {
                VR t = VO_(o)->f46(MI(0x34));
                if (AP(0x3314)) {
                    cHuman_AimWeapon(a, 1);
                    SetLook(a, 0, &t);
                }
            }
            break;
        }
        case 5:
        {
            char* o = nGobjManager_LookupGOBJ_cObjectIdR(m + 0x2C);
            if (o) {
                VR t = VO_(o)->f54();
                if (AP(0x3314)) {
                    cHuman_AimWeapon(a, 1);
                    SetLook(a, 0, &t);
                }
            }
            break;
        }
        }
        break;
    case 0x3A:
        cHuman_AimWeapon(a, 0);
        break;
    case 0x3B:
    {
        char* p = m + 0x30;
        HFire(a, FireT(p));
        break;
    }
    case 0x3C:
        if (AI(0x320C) != 0x14 && AI(0x320C) != 0x1B && AI(0x320C) != 0x1A && AI(0x320C) != 0x1F &&
            !((AI(0x3210) >> 4) & 1) && !((AI(0x3210) >> 5) & 1) && !((AI(0x3210) >> 8) & 1) &&
            !((AI(0x3210) >> 7) & 1) && !((AI(0x3210) >> 16) & 1) && cWeapon_CanReload(AP(0x3524))) {
            Key30 k;
            unsigned char ok = 1;
            MEMCLEAR16(&k, 3);
            if (cWeapon_GetPoseType(AP(0x3524)) == 1 || cWeapon_GetPoseType(AP(0x3524)) == 3) {
                KEYFILL(k, D_0049E4D0)
            } else if (cWeapon_GetPoseType(AP(0x3524)) == 2 || cWeapon_GetPoseType(AP(0x3524)) == 4) {
                KEYFILL(k, D_0049E4D0)
            } else if (cWeapon_GetPoseType(AP(0x3524)) == 5 || cWeapon_GetPoseType(AP(0x3524)) == 6) {
                KEYFILL(k, D_0049E4D0)
            } else {
                ok = 0;
            }
            if (AP(0x3314) && ok) {
                unsigned char s;
                s = ROS(AP(0x3314), &k, 1, OSE(a));
                if (s) {
                    SetA0(AP(0x3524), 1);
                    cWeapon_Reload(AP(0x3524));
                }
            }
        }
        break;
    case 0x3D:
        switch (MB(0x28)) {
        case 1:
            if (!MB(0x2C)) {
                char* l = AP(0x3314);
                if (l) LookCtl_ClearSlot(l, 1, 1);
            }
            break;
        case 4:
            if (AP(0x3314)) {
                SetLook(a, 1, m + 0x30);
            }
            break;
        case 11:
        {
            char* o = nGobjManager_LookupGOBJ_cObjectIdR(m + 0x30);
            VR t = VO_(o)->f46(MI(0x34));
            if (AP(0x3314)) {
                SetLook(a, 1, &t);
            }
            break;
        }
        case 5:
        {
            char* o = nGobjManager_LookupGOBJ_cObjectIdR(m + 0x2C);
            if (o) {
                VR t = VO_(o)->f54();
                if (AP(0x3314)) {
                    SetLook(a, 1, &t);
                }
            }
            break;
        }
        }
        break;
    case 0x3E:
        { char* o = nGobjManager_LookupGOBJ_cObjectIdR(m + 0x2C); cMan_SetEyeTarget(func_001AE140(a), o); }
        break;
    case 0x3F:
        cMan_SetEyeTarget(func_001AE140(a), 0);
        break;
    case 0x8:
        if (AI(0x320C) == 0) {
            unsigned char ok = 0;
            if (AI(0x3234) == 0 && AI(0x3220) == 0) ok = 1;
            if (ok) {
                unsigned char h = 0;
                unsigned char g = 0;
                if (cHuman_CheckState(a, 4) && AP(0x3310)) g = 1;
                if (g && func_001AE0B0(AP(0x3310), 0)) h = 1;
                if (!h) {
                    float cur = ((CtlS*)(a + 0x2EC0))->Cur(0xF);
                    unsigned char f3 = 0;
                    unsigned char f2 = 0;
                    int kind;
                    unsigned char b3;
                    float f21, f20;
                    if (!(AF(0x309C) < 1.0f) && BTn(a + 0x3200, 3)) f2 = 1;
                    if (f2 && BTn(a + 0x3200, 4)) f3 = 1;
                    b3 = f3;
                    if (cur < 0.125f) {
                        if (b3) kind = 2; else kind = 6;
                    } else if (cur < 0.3f) {
                        kind = 4;
                    } else if (cur < 0.7f) {
                        kind = 1;
                    } else if (cur < 0.875f) {
                        kind = 5;
                    } else {
                        if (b3) kind = 3; else kind = 6;
                    }
                    switch ((unsigned char)kind) {
                    case 1: f21 = 0.325f; f20 = 0.55f; break;
                    case 2: f21 = 0.325f; f20 = 0.55f; break;
                    case 3: f21 = 0.325f; f20 = 0.55f; break;
                    case 4: f21 = 0.325f; f20 = 0.55f; break;
                    case 5: f21 = 0.325f; f20 = 0.55f; break;
                    case 6: f21 = 0.425f; f20 = 0.55f; break;
                    }
                    {
                        V4u b1, b2;
                        char* pv;
                        PlaySelT2R(a, cSkaAnimCheckpoints_ScheduleEvent(cSkaAnimCheckpoints_ScheduleEvent(func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 1, a), 1, 2, a), 3, 5, a), 5, 6, a), 6, 7, a), cSkaTimeSpan_Normalized_ctor_float_bool(&b1, 0, f21), 3, a), cSkaTimeSpan_Normalized_ctor_float_bool(&b2, 0, f20), 4, a), ((int*)(a + 0x326C))[(unsigned char)kind], 1, pv);
                    }
                    {
                        PlaySelT(a, XT(), AI(0x326C), 0);
                    }
                }
            }
        }
        break;
    case 0xB:
        if (AI(0x320C) == 0 && !((AI(0x3248) >> 30) & 1)) {
            BitArray_Assign(a + 0x3248, 0x1F, 0);
            BitArray_Assign(a + 0x3248, 0x1E, 1);
            if (g_IsMultiplayer) { char* np = AP(0x3584); if (np && AB(0x14)) np[0x51] = 0xB; }
        }
        break;
    case 0xC:
        if (AI(0x320C) == 0 && !((AI(0x3248) >> 31) & 1)) {
            BitArray_Assign(a + 0x3248, 0x1E, 0);
            BitArray_Assign(a + 0x3248, 0x1F, 1);
            if (g_IsMultiplayer) { char* np = AP(0x3584); if (np && AB(0x14)) np[0x51] = 0xC; }
        }
        break;
    case 0xD:
        BitArray_Assign(a + 0x3248, 0x1E, 0);
        BitArray_Assign(a + 0x3248, 0x1F, 0);
        if (g_IsMultiplayer) { char* np = AP(0x3584); if (np && AB(0x14)) np[0x51] = 0xD; }
        break;
    case 0xE:
        if (AI(0x320C) == 0) {
            Key30 k;
            float f21, f20;
            MEMCLEAR16(&k, 3);
            if (cHuman_cStates_CheckState(a + 0x3200, 4)) {
                KEYFILL(k, D_0049E500)
                f21 = 0.2f;
                f20 = 0.2f;
            } else if (cHuman_cStates_CheckState(a + 0x3200, 3)) {
                KEYFILL(k, D_0049E500)
                f21 = 0.2f;
                f20 = 0.4f;
            } else {
                KEYFILL(k, D_0049E520)
                f21 = 0.2f;
                f20 = f21;
            }
            PlayMR(a, MRT(&k, RT(f21), RT(f20), OSE0(a)));
            APri(a, 3, 1);
        }
        break;
    case 0xF:
        if (AP(0x3310) && AI(0x320C) == 0) {
            if (!AB(0x14) || !IsLoc(a) || !PB(AP(0x3524), 0xA0)) {
                LATCH(2);
                LATCH(3);
                LATCH(8);
                if (AB(0x31B1)) LATCH(4);
            }
        }
        break;
    case 0x10:
        if (!((AI(0x3248) >> 4) & 1) && AP(0x3310) && AI(0x320C) == 0) {
            if (AB(0x14) || !IsLoc(a)) LATCH(1);
        }
        break;
    case 0x11:
        if (AP(0x3310) && !IsDown(a) &&
            (((AI(0x320C) == 7 || AI(0x320C) == 8) && cHumanCollisionRoutine_CanClimbUpFromHang(AP(0x3310))) || (!AB(0x14) && IsLoc(a)))) {
            if (g_IsMultiplayer && AB(0x14) && IsLoc(a)) FwdMsg(a, m, 0);
            {
                PNT(a, KT(D_0049E540), RT(g_DefaultMotionTransition), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x2E, a), 1, 0x2F, a), 3, 0x30, a), 5, 0x31, a), 6, 0x32, a), 1);
            }
            PlaySlot(a, 0);
            APri(a, 1, 1);
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(AP(0x3310) + 0x18, 5);
            cModeSwitch_WithHistory_12_ActivateMode_uint_2(AP(0x3310) + 0x18, 3);
        } else {
            QueueMessage_cMessageR_cSystemP_int(FT().q(), AP(0x58), 1);
        }
        break;
    case 0x13:
        if (!IsDown(a)) {
            if (((AI(0x3210) >> 7) & 1) || ((AI(0x3210) >> 8) & 1) || (!AB(0x14) && IsLoc(a))) {
                if (g_IsMultiplayer && AB(0x14) && IsLoc(a)) FwdMsg(a, m, 0);
                BitArray_Assign(a + 0x3248, 0xA, 0);
                BitArray_Assign(a + 0x3248, 0xB, 0);
                BitArray_Assign(a + 0x3248, 0xC, 0);
                BitArray_Assign(a + 0x3248, 0xD, 0);
                cHuman_Fall(a);
            }
        }
        break;
    case 0x14:
    case 0x15:
    case 0x16:
        cHuman_HandleJumpInit(a, m);
        break;
    case 0x17:
        cHuman_HandleRunningJumpOffLedge(a, m);
        break;
    case 0x1A:
        if (!((AI(0x3210) >> 16) & 1) && AP(0x3310)) {
            if (AB(0x14) || !IsLoc(a)) {
                LATCH(7);
                LATCH(8);
            }
        }
        break;
    case 0x1B:
        if (!((AI(0x3210) >> 16) & 1) && AP(0x3310)) {
            if (AB(0x14) || !IsLoc(a)) LATCH(7);
        }
        break;
    case 0x1C:
    {
        char* p = AP(0x3310);
        if (p && PB(p, 0x9A5)) {
            AB(0x31B5) = 1;
            NETFLAG(0x20, 1)
        }
        break;
    }
    case 0x1D:
        AB(0x31B5) = 0;
        NETFLAG(0x20, 0)
        break;
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
        cHuman_HandleGetOffLadderMessage(a, m);
        break;
    case 0x24:
        int* st = (int*)(a + 0x320C);
        if ((st[1] >> 16) & 1) {
            if (st[0] == 0x10) PlaySlot(a, 1);
            APri(a, 0xC, 0);
            APri(a, 0xD, 0);
            APri(a, 0xE, 0);
            APri(a, 0xF, 0);
            APri(a, 0x10, 0);
            if (AP(0x3310)) {
                cModeSwitch_WithHistory_12_DeactivateMode(AP(0x3310) + 0x18, 6);
                cModeSwitch_WithHistory_12_DeactivateMode(AP(0x3310) + 0x18, 7);
                cModeSwitch_WithHistory_12_DeactivateMode(AP(0x3310) + 0x18, 8);
                cModeSwitch_WithHistory_12_DeactivateMode(AP(0x3310) + 0x18, 9);
            }
        }
        break;


    case 0x2B:
        if (!IsDown(a) && !((AI(0x324C) >> 1) & 1) && (!AB(0x14) || AI(0x320C) == 0) &&
            !cSafePtr_cHuman_GetPtr(a + 0x3478) && MB(0x28) == 5) {
            char* o;
            char* t;
            if ((t = nGobjManager_LookupGOBJ_cObjectIdR(m + 0x2C)) && IsCls2(t)) { o = t; if (!AB(0x14) || PI(o, 0x320C) == 0x1F) {
                V4 ax, pos, v, q;
                char* s3;
                char* pa;
                cSafePtr_cHuman_Set(a + 0x3478, o);
                unsigned char g = 0;
                unsigned char h = 0;
                if (PB(o, 0x2D) && PB(o, 0x2C)) h = 1;
                if (h && NB2(o, 0x2E)) g = 1;
                if (!g) {
                    if (PB(o, 0x14)) VO_(o)->f21(1);
                    else VO_(o)->f06();
                }
                cWeapon_StoreWeapon_void(AP(0x3524));
                if (PP(o, 0x3464)) cBackpack_RemoveInteractBox(PP(o, 0x3464));
                ax.x = 0.0f;
                ax.y = 0.0f;
                ax.z = 1.0f;
                ax.w = 0.0f;
                QCp2(&pos, cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(PP(o, 0x3290))));
                s3 = PP(o, 0x50);
                if (PB(s3, 0x50)) VO_(s3)->f20();
                { char* sub = s3 + 0x10; QCp(&v, sub + 0x20); }
                {
                    float ang = Yaw(DirOf(&v));
                    QAA(&q, AA(&ax, ang - 1.5707964f));
                }
                pa = AP(0x3294);
                cSkaAnimAnchor_SetTransform(pa, PlId(&q, &pos));
                LnkH(o + 0x2EC0, a + 0x2EC0);
                AttachAll(a);
                {
                    Ev30 e;
                    char* ep = e.c;
                    EvInit(ep, 0x2E, 0);
                    PB(&e, 0x20) = 1;
                    QueueMessage_cMessageR_cSystemP_int(ep, o, 1);
                    PP(&e, 0) = D_004E0840;
                    cMessage_dtor(ep, 0);
                }
                if (IsLoc(a) && AB(0x14)) {
                    Ev30 e;
                    char* ep = e.c;
                    cAIGOBJMsg_ctor(ep, D_004FF2B0, cGobjController_Gobj(AP(0x58)));
                    PP(ep, 0) = D_004DCC70;
                    PB(ep, 0x28) = 1;
                    PB(&e, 0x20) = 2;
                    QueueMessage_cMessageR_cSystemP_int(ep, o, 0);
                    PP(&e, 0) = D_004DCC70;
                    cAIGOBJMsg_dtor(ep, 0);
                }
                {
                    V4u rr;
                    PNT(a, KT(D_0049E558), RT(g_DefaultMotionTransition), cSkaAnimCheckpoints_ScheduleEvent(func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x71, a), 1, 0x72, a), 3, 0x74, a), 5, 0x75, a), 6, 0x76, a), cSkaTimeSpan_Normalized_ctor_float_float_bool(&rr, 0.12f, 0.12f, 0), 0x73, a), 1);
                }
                {
                    PNT(a, KT(D_0049E570), RT(g_DefaultMotionTransition), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x77, a), 1, 0x78, a), 3, 0x79, a), 5, 0x7A, a), 6, 0x7B, a), 0);
                }
                if (g_IsMultiplayer && AB(0x14)) {
                    Ev30 c;
                    char* ep = c.c;
                    cCharActionMsg_ctor_cCharActionMsgR(ep, m);
                    PP(ep, 0) = D_004E01A0;
                    cObjectId_ctor_cObjectIdR(ep + 0x2C, m + 0x2C);
                    PB(&c, 0x20) = 4;
                    PI(&c, 0x1C) = 0x40;
                    QueueMessage_cMessageR_cSystemP_int(ep, a, 1);
                    PP(&c, 0) = D_004E01A0;
                    cCharActionMsg_dtor(ep, 0);
                }
            } }
        }
        break;
    case 0x2C:
    case 0x2D:
        if (!IsDown(a) && !((AI(0x324C) >> 4) & 1) && (!AB(0x14) || !((AI(0x324C) >> 2) & 1))) {
            if (AB(0x14)) {
                unsigned char dc = 0;
                char* p = AP(0x3310);
                if (p && PB(p, 0xDC)) dc = 1;
                if (dc) break;
            }
            {
                unsigned char done = 0;
                if ((!AB(0x14) || ((AI(0x324C) >> 3) & 1)) && cSafePtr_cHuman_GetPtr(a + 0x3478) &&
                    (!AB(0x14) || ((PI(cSafePtr_cHuman_GetPtr(a + 0x3478), 0x324C) >> 6) & 1))) {
                    Key30 k;
                    signed char ev;
                    if (PF(AP(0x3294), 0xD0) == 0.0f) {
                        void* w = cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(AP(0x3290));
                        char* r = AP(0x3294);
                        cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(r, w);
                        PI(r, 0x160) = 0;
                    }
                    AttachAll(a);
                    MEMCLEAR16(&k, 3);
                    switch (MI(0x24)) {
                    case 0x2C:
                        ev = 0x2F;
                        KEYFILL(k, D_0049E590)
                        break;
                    case 0x2D:
                        ev = 0x30;
                        KEYFILL(k, D_0049E5B0)
                        break;
                    }
                    {
                        Ev30 e;
                        char* ep = e.c;
                    EvInit(ep, ev, 0);
                        PB(&e, 0x20) = 1;
                        QueueMessage_cMessageR_cSystemP_int(ep, cSafePtr_cHuman_GetPtr(a + 0x3478), 1);
                        PP(&e, 0) = D_004E0840;
                        cMessage_dtor(ep, 0);
                    }
                    {
                        PNT(a, *(KT*)&k, RT(g_DefaultMotionTransition), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x7C, a), 1, 0x7D, a), 3, 0x7E, a), 5, 0x7F, a), 6, 0x80, a), 1);
                    }
                    PlaySlotB(a, 0);
                    done = 1;
                    if (g_IsMultiplayer && AB(0x14)) FwdMsg(a, m, 1);
                }
                if (!done && cSafePtr_cHuman_GetPtr(a + 0x3478)) {
                    PlaySelT(a, XT(), AI(0x326C), 1);
                    if (g_IsMultiplayer && AB(0x14)) FwdMsg(a, m, 1);
                }
            }
        }
        break;
    case 0x2E:
        if (!((AI(0x324C) >> 5) & 1)) {
            {
                PNT(a, KT(D_0049E5C8), RT(g_DefaultMotionTransition), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x81, a), 1, 0x82, a), 3, 0x83, a), 5, 0x84, a), 6, 0x85, a), 1);
            }
            {
                char* c;
                PNLTr(a, c, KT(D_0049E5E0), RT(g_DefaultMotionTransition), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x86, a), 1, 0x87, a), 3, 0x89, a), 5, 0x88, a), 6, 0x8A, a), 0);
            }
        }
        break;
    case 0x2F:
    case 0x30:
        if (!((AI(0x324C) >> 7) & 1)) {
            Key30 k1, k2;
            MEMCLEAR16(&k1, 3);
            MEMCLEAR16(&k2, 3);
            switch (MI(0x24)) {
            case 0x2F:
                KEYFILL(k1, D_0049E600)
                KEYFILL(k2, D_0049E620)
                break;
            case 0x30:
                KEYFILL(k1, D_0049E640)
                KEYFILL(k2, D_0049DBC0)
                break;
            }
            {
                PNT(a, *(KT*)&k1, RT(g_DefaultMotionTransition), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x8B, a), 1, 0x8C, a), 3, 0x8D, a), 5, 0x8E, a), 6, 0x8F, a), 1);
            }
            {
                PNLT4(a, *(KT*)&k2, RT2(g_DefaultMotionTransition), XT(), 0);
            }
        }
        break;
    case 0x28:
        { int t = AI(0x320C); if (t == 0x14 || t == 0x11 || t == 0x12 || t == 0x13)
        {
            unsigned char v = 1;
            if (MB(0x28) == 1) v = MB(0x2C);
            else if (MB(0x28) == 2) v = MI(0x2C) != 0;
            if (v || (AI(0x324C) & 1)) {
                Ev30 e;
                char* ep = e.c;
                    EvInit(ep, 0x29, 0);
                PB(&e, 0x20) = 5;
                PI(&e, 0x1C) = 0x40;
                QueueMessage_cMessageR_cSystemP_int(ep, a, 0);
                PP(&e, 0) = D_004E0840;
                cMessage_dtor(ep, 0);
            }
        }
        }
        break;
    case 0x29:
        if (!IsDown(a)) {
            PlaySelT(a, XT(), AI(0x326C), 1);
        }
        break;
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x31:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x37:
    case 0x38:
        Actor_HandleObjectAction(a, m);
        break;
    case 0x32:
    case 0x36:
        if (!((AI(0x3210) >> 27) & 1) && !((AI(0x3210) >> 31) & 1)) PlaySlot(a, 1);
        break;
    case 0x2A:
        if (!IsDown(a) && PF(AP(0x3294), 0xD0) == 0.0f && MB(0x28) == 0xE) {
            if (g_IsMultiplayer && AB(0x14) && IsLoc(a)) {
                struct { char c[0x60]; } __attribute__((aligned(16))) c;
                char* ep = c.c;
                cCharActionMsg_ctor_cCharActionMsgR(ep, m);
                cInteractParams_ctor_cInteractParamsR(ep + 0x30, m + 0x30);
                PP(ep, 0) = D_004E00E0;
                PB(&c, 0x20) = 4;
                PI(&c, 0x1C) = 0x40;
                QueueMessage_cMessageR_cSystemP_int(ep, a, 0);
                PP(&c, 0) = D_004E00E0;
                cCharActionMsg_dtor(ep, 0);
            }
            Actor_HandleLedgeAction(a, m);
        }
        break;
    case 0x40:
        cHuman_CoverEyes(a, m);
        break;
    case 0x41:
        cHuman_UnCoverEyes(a, m);
        break;
    case 0x42:
        cHuman_HandleDeath(a, m);
        break;
    case 0x43:
    {
        unsigned char v = MB(0x2C);
        if (AP(0x3310)) {
            PB(AP(0x3310), 0x12) = v;
            PB(AP(0x3310), 0x13) = v;
        }
        NETFLAG(0x40, NotB(v))
        break;
    }
    case 0x44:
        if (MU(0xC) > AU(0x3594)) { char* ip = m + 0x2C; int f = MI(0x30); Actor_Ignite(a, f != 0, nGobjManager_LookupGOBJ_cObjectIdR(ip), 0, 1, -1.0f); }
        break;
    case 0x45:
        cHuman_SetBlinded(a, 1, MF(0x2C));
        break;
    case 0x46:
        cHuman_SetDeaf(a, 1, MF(0x2C));
        break;

    default:
        r = 0;
        break;
    }
    return r;
}
