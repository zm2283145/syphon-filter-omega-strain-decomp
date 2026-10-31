#pragma cplusplus on
#pragma always_inline on
#include "types.h"
static inline float Fabs(float x) { float r; asm { abs.s r, x } return r; }
typedef int long128 __attribute__((mode(TI)));

typedef union { float f[4]; long128 q; } U4;
struct V4 { float x, y, z, w; V4& operator=(const V4& o) { *(U4*)this = *(const U4*)&o; return *this; } V4* P() { return this; } void SetZ(const V4& o) { long128* dst; long128 q; const long128* src; src = (const long128*)&o; dst = (long128*)this; __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst)); q = *src; *dst = q; } void Set(const V4& o) { long128* dst = (long128*)this; long128 q; const long128* src = (const long128*)&o; __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst)); q = *src; *dst = q; } void Cp(const V4& o) { const long128* src = (const long128*)&o; long128* dst = (long128*)this; long128 q; __asm__ volatile("lq %0, 0x0(%1)\n\tsq %0, 0x0(%2)" : "=&r"(q) : "r"(src), "r"(dst)); } void SetB(const V4& o) { const long128* src = (const long128*)&o; long128* dst = (long128*)this; long128 q; __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst)); Cp(o); } void SetC(const V4& o) { const long128* src = (const long128*)&o; long128* dst = (long128*)this; long128 q; __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst)); __asm__ volatile("lq %0, 0x0(%1)" : "=r"(q) : "r"(src)); *dst = q; } void Zero() { __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(this)); } } __attribute__((aligned(16)));
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Ev30;
typedef struct { char c[0x40]; } __attribute__((aligned(16))) Ev40;
typedef struct { char c[0x50]; } __attribute__((aligned(16))) Ev50;
typedef struct { char c[0x80]; } __attribute__((aligned(16))) Ev80;
typedef struct { char c[0x60]; } __attribute__((aligned(16))) Ev60;
typedef struct { char c[0x50]; } __attribute__((aligned(16))) Ev50m;
typedef struct { char c[0x70]; } __attribute__((aligned(16))) Ev70;
struct MtxR { char c[0x40]; MtxR(const MtxR&); } __attribute__((aligned(16)));
typedef struct { char c[0x40]; } __attribute__((aligned(16))) Mtx;
typedef struct { char c[0x190]; } __attribute__((aligned(16))) Snd;
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Ev30b;

struct Vec2f {
    float x, y;
    inline Vec2f(int a, int b);
    inline Vec2f(const Vec2f& o);
    Vec2f(float a, float b) { x = a; y = b; }
    Vec2f& operator=(const Vec2f& o) { x = o.x; y = o.y; return *this; }
};
struct VZ {
    float x, y, z, w;
    inline VZ(float a, float b, float c, float d);
} __attribute__((aligned(16)));
extern "C" { Vec2f* cJoyXYVector_ctor_int_int(Vec2f*, int, int); Vec2f* cJoyXYVector_ctor_cJoyXYVectorR(Vec2f*, const Vec2f*); VZ* cVector_ctor_float_float_float_float(VZ*, float, float, float, float); }
inline Vec2f::Vec2f(int a, int b) { cJoyXYVector_ctor_int_int(this, a, b); }
inline Vec2f::Vec2f(const Vec2f& o) { cJoyXYVector_ctor_cJoyXYVectorR(this, &o); }
inline VZ::VZ(float a, float b, float c, float d) { cVector_ctor_float_float_float_float(this, a, b, c, d); }
extern signed char D_004E1D88;
extern VZ D_004E1D90;

#define SI(o) (*(int*)(s + (o)))
#define SU(o) (*(unsigned int*)(s + (o)))
#define SB(o) (*(unsigned char*)(s + (o)))
#define SF(o) (*(float*)(s + (o)))
#define SP(o) (*(char**)(s + (o)))
#define AI(o) (*(int*)(a + (o)))
#define AB(o) (*(unsigned char*)(a + (o)))
#define AF(o) (*(float*)(a + (o)))
#define AP(o) (*(char**)(a + (o)))
#define PI(p, o) (*(int*)((char*)(p) + (o)))
#define PB(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define PF(p, o) (*(float*)((char*)(p) + (o)))
#define PP(p, o) (*(char**)((char*)(p) + (o)))
#define PU(p, o) (*(unsigned int*)((char*)(p) + (o)))
#define PV(p, o) (*(V4*)((char*)(p) + (o)))

#define VP1(n) virtual void n();
#define VP4(n) VP1(n##a) VP1(n##b) VP1(n##c) VP1(n##d)
template <class R> struct VO {
    VP4(p0) VP4(p1) VP4(p2) VP4(p3) VP4(p4)
    virtual void v58();
    VP1(q0) VP1(q1)
    virtual void v64(void*, int, int);
    VP4(r0) VP4(r1) VP4(r2) VP4(r3) VP4(r4) VP4(r5) VP4(r6) VP1(r7) VP1(r8) VP1(r9)
    virtual V4 vE4();
    virtual Ev40 vE8();
    VP1(s0) VP1(s1)
    virtual R vF4();
};
typedef VO<Ev40> VOb;
typedef void (*FnP)(char*);
typedef void (*FnOut)(void*, char*);
typedef void (*FnE4)(void*, char**);
typedef void (*Fn64)(char**, void*, int, int);

extern char D_0055A300[], g_ActorActionMsgClass[], D_0055D4D8[];
extern char D_004E0840[], D_004E0180[], D_004E0120[], D_004E0200[], D_004D9320[], D_004D9DA0[], D_004DAE30[];
extern char g_Game[], g_CameraObject[], D_004A75A0[], D_004A77B8[], D_004A77C8[], D_004A77D8[], D_004A77E8[], D_004A77F0[];
extern char g_NoneWord[];
extern char* g_Hud;
extern float D_004BBE10, D_004BBE18, D_004FFB98, D_0048AE58, D_0048AE60, D_0048AE68, D_0048AE80, D_0048AE88;
extern float D_004A7548, D_004A7560, D_004A7568, D_004A7588, D_004A7598;
extern unsigned char g_LoadoutPending, g_GameState, D_005721C0, g_IsMultiplayer, D_0048AE90, D_0048AE98;
extern int g_HumanActorClassKey, g_HotboxTracker, D_004FFC10, g_TimerAccum;
extern long g_TickCounter64;
extern signed char D_0049D02C;

extern "C" {
int cSafePtr_cGOBJ_opCast_cGOBJPtr(char*);
void cCharActionMsg_ctor_int_eParamType(void*, int, int);
int cBackpack_NewBackpack_cHumanP_bool_cObjectIdP(char*, int, int);
bool BitArray_Test(char*, int);
int cHuman_cStates_CheckState(char*, int);
void cHumanCollisionRoutine_RequestSearchForLedge(char*, int, int);
void EffectMsg_WrapRequest(void*, void*);
void cMessage_ctor_cMessageNameR(void*, char*);
void QueueMessage_cMessageR_cSystemP_int(void*, char*, int);
void cHuman_ToggleGadgetState(char*);
void cGameSystem_Restart(char*, int);
void cGameSystem_PauseGame(char*, int);
void cHuman_CycleGadgetState(char*);
char** cSafePtr_cGOBJ_GetPtr_void(char*);
char* cHotboxMan_CanInteract(int, int);
void SeedPlayerLos(char*, char*);
void cHud_DeactivateObjectiveMenu(char*);
void cHud_ClearTargetNow(char*);
void cHud_Message(char*, int);
void cHud_SetArmor(char*, int, int);
void cHud_SetHealth(char*, int, int);
unsigned char cHud_SetScope(char*, unsigned char, unsigned char, char*, char*);
int nGlobalization_GetString_charP(char*);
float Libc_Atan2f(float, float);
static inline float At2Y(float x, float y) { float b = y; float a = x; return Libc_Atan2f(a, b); }
float COS(float);
float Deg2Rad(float);
float Math_Fabs(float);
float MAX(float, float);
float Math_MinF(float, float);
float SIN(float);
void LimitManualAimAngularAcceleration_ByScale(V4*, V4*, V4*, float, float, float, float, float);
void* cMemMan_Allocate(int, int, char*, int);
void cSkeleton_GetBoneToWorldTranslation(V4*, int, signed char);
void* cMotionParams_ctor(void*, V4*, float, float, int);
void cMatrix_Set_ColumnMajorForm(Mtx*, float, float, float, float, float, float, float, float, float);
void cMatrix_ctor_cMatrixR(void*, Mtx*);
int cMatrix_GetUnit();
void cVector_VU0PostMultiply(V4*, Mtx*, V4*);
void cSafePtr_cGOBJ_opAssign_cGOBJP(void*, int);
int ObjMan_GetService();
void cJoyPad_GetStickPosition(char*, Vec2f*, Vec2f*, int);
int cPickupMenu_Draw(char*, char*);
int cPickupMenu_AcceptChoices(char*, char*);
void cTargetInfo_ctor_cObjectIdR_int_bool_cVectorR_etc(void*, void*, int, int, V4*, float);
int cPlayerControls_CanChangeWeapon(char*, char*);
V4 PlayerInput_GetLookOffset(V4*, unsigned char, unsigned char);
void cPlayerControls_HandleCrouchButtonPress(char*, char*, float);
void cPlayerControls_HandleInteractButtonPress(char*, char*, float);
void cPlayerControls_NetShootWeapon(char*, char*);
void cPlayerControls_UpdateTarget(char*, char*, char*, bool, bool, float);
void cPlayerControls_DetectForAndHandle180Turn(char*, float, V4*, char*, char*);
void cModeSwitch_12_DeactivateMode(char*, int);
void cModeSwitch_12_opAssign(char*, char*);
void cModeSwitch_12_ActivateMode(char*, int);
int cModeSwitch_12_IsModeActivated(char*, int);
void cVector_ctor_void(V4*);
unsigned char cHumanIkRoutine_IsWeaponAimed(int);
void cModeSwitch_2_opAssign(char*, char*);
void cSndFx_SetSndFx(void*, int, char*, int, int);
void cGrenade_CalculateArcPoints(V4*, char*, float, float);
float cGrenade_FigureThrowAngle(float);
float cGrenade_FigureThrowDist(float);
void cVector_ctor_cVectorR(V4*, V4*);
float cVector_Z_void(V4*);
void cVector_opMul(float, V4*, V4*);
void cVector_VU0Scale(V4*, V4*, float);
void cVector_VU0Add(V4*, V4*, V4*);
int cWeapon_CanChangeWeapon(char*);
void cWeapon_SelectNext(char*, int);
int cWeapon_GetClipAmmo(char*, int);
int cWeapon_GetEquipmentType(char*);
char* cWeapon_GetWeaponEntry(char*);
char* cWeapon_GetGoggleEntry(char*);
int cWeapon_GetAmmo(char*, int);
int cWeapon_IsFullyAutomatic(char*);
void cWeapon_RetractTaser(char*);
float cWeapon_GetFOV(float, float, char*, int, int);
void cMessage_dtor(void*, int);
void cTimerDisable_dtor(void*, int);
int cSKM_GOBJ_GetSkeleton_void(char*);
void cString_dtor(void*, int);
void cTimerDisable_ctor(void*);
void cCharActionMsg_dtor(void*, int);
void cMatrix_ctor_cMatrixR_cVectorR(void*, int, void*);
int* cLList_cCAMERA_GOBJPtr_Front(char*);
int func_00159570(char*);
void cVector_Copy_WSet0(void*, V4*);
void cObjectId_ctor_cObjectIdR(void*, char*);
int cSplinedMotion_cQuaternion_IsTransitionInProgress(char*);
float Math_Clampf(float, float, float);
float nSFOMath_GetZRotationFromYAxis(V4*);
float nSFOMath_GetZRotationFromXAxis(V4*);
V4* func_0019D190(char*);
V4* cMatrix_GetXAxis(char*);
void cSafePtr_cGOBJ_ctor_void(void*);
void cObjectiveMan_DeactivateObjectiveScreen(int);
int Hud_IsGuiFocused(char*);
void cHud_ToggleMap(char*);
void cHud_ActivateObjectiveMenu(char*);
void cPlayerControls_KillPickup(char*);
void cPlayerControls_UpdateCharacterZRotation(char*, char*, unsigned char, float);
char* cSystem_GetObjectID_void_2(int);
void cPlayerControls_NetSelectNextWeapon(char*, char*);
void cPlayerControls_HandleManualAimButtonPress(char*, char*, char*, float);
void cPlayerControls_HandleReloadButtonPress(char*, bool, char*);
void cGameCamera_SetDesiredFOV(char*, float);
void cSafePtr_cGOBJ_Set(char*, int);
void cVector_VU0PostRotate(V4*, V4*, V4*);
int func_0024FD50(char*, int);
int func_0024FD80(int, int);
int func_0024FD90(char*);
V4 nSFOMath_ExpressAngleAsValueBetweenNegAndPos180_cEulerAngleTR(V4*);
void cMatrix_Set_float_float_float_float_etc(void*, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
void* func_00250190(void*, float, float, float);
int cSafePtr_cHuman_opCast_cHumanPtr(char*);
V4* func_00250310();
float cGameCamera_GetFollowDistance(char*);
void PlayerInput_SmoothAimVector(V4*, V4*, char*, float, float, float);
void cPickupMenu_PrevWeapon(char*);
void PickupMenu_OnRight(char*);
void cPickupMenu_Prev(char*);
void cPickupMenu_Next(char*);
char* cPickupMenu_ctor(char*, int, int, char*, int, int);
void cBackpack_InitForDropping(int, int);
void cMap_MapUserInterface(char*, char*);
int cJoystick_IsDormant(char*);
void cJoystick_Debounce(char*);
void cFileMan_dtor(void*, int);
void cFileMan_ctor_void(void*);
unsigned char GuiGameScreen_IsChooseMenuActive(char*);
void GuiGameScreen_UpdateMenuPosition(char*, V4*);
void GuiGameScreen_ActivateWeaponSelect(char*, int);
int GuiGameScreen_InteractActive(char*);
void GuiGameScreen_ClearInteract(char*, int);
void GuiGameScreen_ShowInteract(char*, int, int, int);
}

static inline float LenSq(void* v)
{
    int r;
    float f = 0.0f;
    asm {
        lqc2 vf1, 0x0(v)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni r, vf4
        mtc1 r, f
    }
    return f;
}
static inline void Normalize(void* v)
{
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(v)
    }
}
static inline float MulK(float a, float b) { float x = a; float y = b; return x * y; }
static inline void ZeroQ(V4* p) { __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(p)); }
static inline void ZeroM(V4* p) { __asm__("sq $zero, 0x0(%1)" : "=m"(*p) : "r"(p)); }
static inline float Remap(float s) { return s != 0.0f ? (s - 0.3333f) / 0.6667f : 0.0f; }
static inline void ClampUnit(V4* v)
{
    if (!(LenSq(v) <= 1.0f)) {
        Normalize(v);
    }
}
static inline float Len(void* v)
{
    int r;
    float f;
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni r, vf4
        mtc1 r, f
    }
    return f;
}
static inline float NormLen(void* v)
{
    int r;
    float f;
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        vdiv Q, vf0w, vf4x
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(v)
        qmfc2.ni r, vf4
        mtc1 r, f
    }
    return f;
}
static inline void NormLenP(void* v, float* out)
{
    int r;
    int* o = (int*)out;
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        vdiv Q, vf0w, vf4x
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(v)
        qmfc2.ni r, vf4
    }
    *o = r;
}
static inline unsigned char IsZero3(void* v)
{
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline unsigned char IsZero4(void* v)
{
    int k, f, r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline unsigned char IsZero4N(void* v)
{
    int k, f, r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
        nop
    done:
        .set reorder
    }
    return r;
}
extern float D_004A7560, D_004A7568;
static inline bool InR(float a) { bool r = 0; if (!(a < D_004A7560) && a <= D_004A7568) r = 1; return r; }
static inline bool IsZero4B(void* v)
{
    int k, f; bool r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline float Clampf(float v, float lo, float hi)
{
    float r = 0.0f;
    asm {
        max.s r, v, lo
        min.s r, r, hi
    }
    return r;
}
static inline void CpV(void* d, const void* p) { int t; asm { lq t, 0(p) 
 sq t, 0(d) } }
static inline __int128 Dup(int v) { __int128 r; __asm__ volatile("pcpyld %0, %1, %1" : "=r"(r) : "r"(v)); return r; }
static inline float ClampG(float v, float lo, float hi) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2; min.s %0, %0, %3" : "+f"(r) : "f"(v), "f"(lo), "f"(hi)); return r; }
static inline unsigned char QuietF(unsigned char q, unsigned char tilt, unsigned char flat) { return q && !flat; }
static inline float Minf(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float Maxf(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float MinfR(float b, float a) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float MaxfR(float b, float a) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float Cp0(float v, float lo, float hi) { float r = 0.0f; asm { max.s r, v, lo
 min.s r, r, hi } return r; }
static inline float Cp1(float v, float hi, float lo) { float r = 0.0f; asm { max.s r, v, lo
 min.s r, r, hi } return r; }
static inline float Cp2(float lo, float v, float hi) { float r = 0.0f; asm { max.s r, v, lo
 min.s r, r, hi } return r; }
static inline float Cp3(float lo, float hi, float v) { float r = 0.0f; asm { max.s r, v, lo
 min.s r, r, hi } return r; }
static inline float Cp4(float hi, float v, float lo) { float r = 0.0f; asm { max.s r, v, lo
 min.s r, r, hi } return r; }
static inline float Cp5(float hi, float lo, float v) { float r = 0.0f; asm { max.s r, v, lo
 min.s r, r, hi } return r; }
static inline float Sq(float x) { return x * x; }
static inline void CpD(V4* d, const V4* src) { long128 q; __asm__ volatile("lq %0, 0x0(%2)\n\tsq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(src)); }
static inline void CpE(V4* d, const V4* src) { long128 q; __asm__ volatile("lq %0, 0x0(%2)\n\tsq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(src)); }
static inline unsigned char NZ(float x) { return x != 0.0f; }
static inline bool NZB(float x) { return x != 0.0f; }
static inline float Min0(float a) { float r = 0.0f; float z = 0.0f; asm { min.s r, a, z } return r; }
static inline float Max0(float a) { float r = 0.0f; float z = 0.0f; asm { max.s r, a, z } return r; }
struct SArr { char pad[0xA4]; unsigned char a[24]; };
static inline unsigned char NZq(float f) { return f != 0.0f; }
static inline unsigned char NZr(float f) { return 0.0f != f; }
static inline float U2F(unsigned int v) { return (float)v; }
static inline const VZ& ZeroV()
{
    if (!D_004E1D88) { cVector_ctor_float_float_float_float(&D_004E1D90, 0.0f, 0.0f, 0.0f, 0.0f); D_004E1D88 = 1; }
    return D_004E1D90;
}
static inline int Tick()
{
    int bit;
    long d;
    int q;
    int i;
    long n;
    int sh;
    int c = (int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f);
    n = g_TickCounter64;
    n += c;
    sh = 30;
    d = 100;
    bit = 1 << sh;
    d <<= sh;
    q = 0;
    sh++;
    for (i = 0; i < sh; i++) {
        long r = n - d;
        if (r >= 0) {
            n = r;
            q += bit;
        }
        d >>= 1;
        bit >>= 1;
    }
    return q;
}
static inline bool Pk98(char* p) { return PI(p, 0x98); }
static inline unsigned char IWA(char* a) { char* sec = AP(0x3314); return sec ? cHumanIkRoutine_IsWeaponAimed((int)sec) : 0; }
static inline int NotAB(char* s) { return !SB(0xAB); }
static inline int GateOk()
{
    return g_IsMultiplayer ? D_005721C0 : 1;
}
static inline Vec2f StickL(char* p)
{
    Vec2f l(0, 0);
    Vec2f r(0, 0);
    cJoyPad_GetStickPosition(p, &l, &r, 0);
    return l;
}
static inline Vec2f StickR(char* p)
{
    Vec2f l(0, 0);
    Vec2f r(0, 0);
    cJoyPad_GetStickPosition(p, &l, &r, 0);
    return r;
}
static inline float Bounds(char* t)
{
    V4 lo, hi;
    float z;
    cVector_ctor_cVectorR(&lo, cMatrix_GetXAxis(t));
    cVector_ctor_cVectorR(&hi, func_0019D190(t));
    z = cVector_Z_void(&lo);
    return z < cVector_Z_void(&hi) ? nSFOMath_GetZRotationFromXAxis(&lo) : nSFOMath_GetZRotationFromYAxis(&hi);
}
static inline float BoundsW(char* t) { return Bounds(t); }
static inline float MaxP(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "+f"(r) : "f"(a), "f"(b)); return r; }
static inline float AbsP(float a) { float r = 0.0f; __asm__ volatile("abs.s %0, %1" : "+f"(r) : "f"(a)); return r; }
static inline float FabsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float AbsMax(float a, float b) { return FabsZ(a) > FabsZ(b) ? a : b; }
static inline float AbsMaxR(float b, float a) { return FabsZ(a) > FabsZ(b) ? a : b; }
static inline float LenG(void* v)
{
    int t;
    float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(v) : "memory");
    return r;
}
struct V4f : V4 {
    V4f(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
struct V4c : V4 {
    V4c(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Box80 {
    char c[0x40];
    Box80(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l)
    {
        cMatrix_Set_float_float_float_float_etc(this, a, b, c, d, e, f, g, h, i, j, k, l, 0.0f, 0.0f, 0.0f, 1.0f);
    }
} __attribute__((aligned(16)));
struct V3 { float x, y, z; };
struct VC {
    float x, y, z, w;
    VC() { cVector_ctor_void((V4*)this); }
    VC(const VC& o) { cVector_ctor_cVectorR((V4*)this, (V4*)&o); }
    V4* Flat() { z = 0.0f; return (V4*)this; }
} __attribute__((aligned(16)));
extern "C" void cPlayerControls_UpdateCamera(char*, char*, char*, VC, VC, VC, V4*);
static inline VC MulV(V4* v, float k)
{
    VC t;
    cVector_VU0Scale((V4*)&t, v, k);
    return t;
}
static inline VC SubC(V4* a, V4* b)
{
    VC d;
    cVector_VU0Add((V4*)&d, a, b);
    return d;
}
static inline void SendEv_(char* dst, int id, int fl, int f)
{
    Ev30 e;
    char* ep = e.c;
    cMessage_ctor_cMessageNameR(ep, g_ActorActionMsgClass);
    PP(ep, 0) = D_004E0840;
    PI(ep, 0x24) = id;
    PB(ep, 0x28) = 0;
    if (fl) PB(&e, 0x20) = 1;
    QueueMessage_cMessageR_cSystemP_int(ep, dst, f);
    PP(&e, 0) = D_004E0840;
    cMessage_dtor(ep, 0);
}
static inline void SendEvN_(char* dst, int id, int f)
{
    Ev30 e;
    char* ep = e.c;
    cMessage_ctor_cMessageNameR(ep, g_ActorActionMsgClass);
    PP(ep, 0) = D_004E0840;
    PI(ep, 0x24) = id;
    PB(ep, 0x28) = 0;
    QueueMessage_cMessageR_cSystemP_int(ep, dst, f);
    PP(&e, 0) = D_004E0840;
    cMessage_dtor(ep, 0);
}
static inline void SendEvF_(char* dst, int id, int f)
{
    Ev30 e;
    char* ep = e.c;
    cMessage_ctor_cMessageNameR(ep, g_ActorActionMsgClass);
    PP(ep, 0) = D_004E0840;
    PI(ep, 0x24) = id;
    PB(ep, 0x28) = 0;
    PB(&e, 0x20) = 1;
    QueueMessage_cMessageR_cSystemP_int(ep, dst, f);
    PP(&e, 0) = D_004E0840;
    cMessage_dtor(ep, 0);
}
static inline void SendCas_(char* dst, int k, int n, char* vt, unsigned char* b)
{
    Ev30 e;
    char* ep = e.c;
    cCharActionMsg_ctor_int_eParamType(ep, k, n);
    PP(ep, 0) = vt;
    PB(ep, 0x2C) = *b;
    PB(&e, 0x20) = 1;
    QueueMessage_cMessageR_cSystemP_int(ep, dst, 1);
    PP(&e, 0) = vt;
    cCharActionMsg_dtor(ep, 0);
}
#define SendEv(dst, id, fl, f) SendEv_((dst), (id), (fl), (f))
#define SendEvN(dst, id, f) SendEvN_((dst), (id), (f))
#define SendEvF(dst, id, f) SendEvF_((dst), (id), (f))
#define SendCas(dst, k, n, vt, b) SendCas_((dst), (k), (n), (vt), (b))

struct In {
    float f[24];
    In() {
        int i;
        for (i = 0; i < 24; i++) {
            *(int*)&f[i] = 0;
        }
    }
};

struct Ax {
    float f[12];
};
static inline float AxR(char* p, int o) { return U2F(PU(p, o)) / D_004BBE18; }
static inline unsigned char IsSt(char* s, int n) { return SI(0x38) == n; }
static inline unsigned char IsK(char* o, int k) { return PI(o, 0x4C) == k; }
static inline unsigned char IsA(char* o) { return IsK(o, g_HumanActorClassKey); }

static inline void SendFx(Snd* sd)
{
    Ev80 em;
    EffectMsg_WrapRequest(&em, sd);
    QueueMessage_cMessageR_cSystemP_int(&em, g_Game, 1);
    PP(&em, 0) = D_004DAE30;
    cString_dtor(em.c + 0x30, -1);
    cMessage_dtor(&em, 0);
}
static inline void MenuPos(char* h, char* fp)
{
    V4 pos;
    pos.Cp(PV(fp, 0x40));
    GuiGameScreen_UpdateMenuPosition(h, &pos);
}
static inline void SelB(char* a) { char* h = PP(g_Hud, 0x6A4); char* fp = AP(0x50); if (PB(fp, 0x50)) { ((VOb*)fp)->v58(); } { V4 pos; pos.Cp(PV(fp, 0x40)); GuiGameScreen_UpdateMenuPosition(h, &pos); } }
static inline void SendObj(char* o, char* s, int z)
{
    Ev40 e;
    char* ep = e.c;
    cCharActionMsg_ctor_int_eParamType(ep, 0x17, 6);
    PP(ep, 0) = D_004E0180;
    cObjectId_ctor_cObjectIdR(ep + 0x2C, s + 0x28);
    PI(ep, 0x30) = z;
    PB(&e, 0x20) = 1;
    QueueMessage_cMessageR_cSystemP_int(ep, o, 0);
    PP(&e, 0) = D_004E0180;
    cCharActionMsg_dtor(ep, 0);
}
static inline void Do180(float dt, char* s, V4* ls, char* a, char* c)
{
    V4 t;
    t.Cp(*ls);
    { V4* tp = &t; cPlayerControls_DetectForAndHandle180Turn(s, dt, tp, a, c); }
}

static inline void SendMot(char* o, V4* mv, float m, float ly, int quiet)
{
    Ev50m e;
    char* ep = e.c;
    cCharActionMsg_ctor_int_eParamType(ep, 0, 0xC);
    cMotionParams_ctor(ep + 0x30, mv, m, ly, quiet);
    PP(ep, 0) = D_004E0120;
    PB(&e, 0x20) = 1;
    QueueMessage_cMessageR_cSystemP_int(ep, o, 1);
    PP(&e, 0) = D_004E0120;
    cCharActionMsg_dtor(ep, 0);
}
static inline void UpdCam(char* s, char* c, char* a, float rate, V4* acc, V4* off, V4* rot, V4* cam)
{
    cPlayerControls_UpdateCamera(s, c, a, MulV(rot, 40.0f), MulV(off, 40.0f), MulV(acc, rate), cam);
}
static inline void SendRot(char* o, Mtx* m)
{
    Ev70 e;
    char* ep = e.c;
    cMessage_ctor_cMessageNameR(ep, D_0055D4D8);
    PP(ep, 0) = D_004D9DA0;
    PB(ep, 0x24) = 4;
    cMatrix_ctor_cMatrixR(ep + 0x30, m);
    QueueMessage_cMessageR_cSystemP_int(ep, o, 1);
    PP(&e, 0) = D_004D9DA0;
    cMessage_dtor(ep, 0);
}

static inline V4 DriftV(float k, V4* dr, V4* p)
{
    V4 d;
    cVector_opMul(k, &d, dr);
    cVector_VU0PostRotate(&d, p, &d);
    return d;
}
static inline void MkXf(char* p, int id, V4* dd)
{
    V4 tm;
    cVector_Copy_WSet0(&tm, dd);
    cMatrix_ctor_cMatrixR_cVectorR(p + 0x30, id, &tm);
}
static inline void RotE(V4& dd, V4& d, const Ev40& m, float k, V4* dr)
{
    cVector_opMul(k, &d, dr);
    V4* q = &d;
    cVector_VU0PostRotate(q, (V4*)m.c, q);
    dd.Cp(*q);
}
static inline void DriftV2(char* o, float k, V4* dr, V4& dd)
{
    V4 d;
    RotE(dd, d, ((VOb*)o)->vE8(), k, dr);
}
static inline void SendXf(char* o, V4* dd)
{
    Ev70 e;
    char* ep = e.c;
    int id;
    cMessage_ctor_cMessageNameR(ep, D_0055D4D8);
    PP(ep, 0) = D_004D9DA0;
    PB(ep, 0x24) = 3;
    id = cMatrix_GetUnit();
    MkXf(ep, id, dd);
    QueueMessage_cMessageR_cSystemP_int(ep, o, 1);
    PP(&e, 0) = D_004D9DA0;
    cMessage_dtor(ep, 0);
}
static inline void SetThrow(char* s)
{
    V4f t(0.0f, cGrenade_FigureThrowDist(SF(0x100)), 0.0f, 0.0f);
    PV(s, 0xD0).Cp(t);
}
static inline void TgtPos(char* s, char** h)
{
    V4* t = ((VOb*)h)->vE4().P();
    PV(s, 0xD0).Cp(*t);
}
static inline void Aim7(char* s, Mtx* m, char* inv)
{
    V4 t;
    t.y = PF(inv, 0xF4);
    t.w = 1.0f;
    t.x = 0.0f;
    t.z = 0.0f;
    cVector_VU0PostMultiply(&t, m, &t);
    PV(s, 0xD0).Cp(t);
}

static inline void Aim7b(char* s, Mtx* m)
{
    V4 t;
    t.y = 200.0f;
    t.z = 4.0f;
    t.x = 0.0f;
    t.w = 1.0f;
    cVector_VU0PostMultiply(&t, m, &t);
    PV(s, 0xD0).Cp(t);
}

static inline unsigned char OkF(char* inv, int ammo, char* s) { unsigned char ok = 1; unsigned char fa = cWeapon_IsFullyAutomatic(inv) && ammo; if (!fa && !NotAB(s)) { ok = 0; } return ok; }
static inline unsigned char OkF2(char* inv, int ammo, char* s) { return OkF(inv, ammo, s); }
static inline void OkG(char* inv, int ammo, char* s, unsigned char* fire) { unsigned char ok = 1; unsigned char fa = cWeapon_IsFullyAutomatic(inv) && ammo; if (!fa && !NotAB(s)) { ok = 0; } if (ok) { *fire = 1; } }
static inline void OkG2(char* inv, int ammo, char* s, unsigned char* fire) { OkG(inv, ammo, s, fire); }
static inline unsigned char FaF(char* inv, int ammo) { return cWeapon_IsFullyAutomatic(inv) && ammo; }
static inline void MakeTI(char* ep, V4 tgt, float pw, int ex, int ref, unsigned char aim)
{
    cCharActionMsg_ctor_int_eParamType(ep, 0x3B, 0xB);
    PP(ep, 0) = D_004E0200;
    cTargetInfo_ctor_cObjectIdR_int_bool_cVectorR_etc(ep + 0x30, ref ? cSystem_GetObjectID_void_2(ref) : g_NoneWord, ex, aim, &tgt, pw);
}

static inline void MakeTI3(char* ep, char* s, int aim)
{
    V4 tgt; tgt.Cp(PV(s, 0xD0));
    float pw = SF(0xE0);
    int ex = SI(0xE4);
    int ref = cSafePtr_cGOBJ_opCast_cGOBJPtr(s + 0xC0);
    cCharActionMsg_ctor_int_eParamType(ep, 0x3B, 0xB);
    PP(ep, 0) = D_004E0200;
    { V4* tp = &tgt; cTargetInfo_ctor_cObjectIdR_int_bool_cVectorR_etc(ep + 0x30, ref ? cSystem_GetObjectID_void_2(ref) : g_NoneWord, ex, aim, tp, pw); }
}
static inline void MakeTI4(char* ep, char* s, unsigned char aim)
{
    V4 tgt = PV(s, 0xD0);
    float pw = SF(0xE0);
    int ex = SI(0xE4);
    int ref = cSafePtr_cGOBJ_opCast_cGOBJPtr(s + 0xC0);
    cCharActionMsg_ctor_int_eParamType(ep, 0x3B, 0xB);
    PP(ep, 0) = D_004E0200;
    cTargetInfo_ctor_cObjectIdR_int_bool_cVectorR_etc(ep + 0x30, ref ? cSystem_GetObjectID_void_2(ref) : g_NoneWord, ex, aim, &tgt, pw);
}
static inline void SetX(V4* d, const V4& o) { long128* dst = (long128*)d; long128 q; const long128* src = (const long128*)&o; __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst)); q = *src; *dst = q; }
static inline void SetX2(V4* d, const V4& o) { const long128* src = (const long128*)&o; long128* dst = (long128*)d; long128 q; __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst)); q = *src; *dst = q; }
static inline void LookOff2(V4& cam, V4* rs, char* s) { SetX2(&cam, PlayerInput_GetLookOffset(rs, SB(0x125), SB(0x126))); }
static inline void SetX3(V4* d, const V4& o) { const long128* src = (const long128*)&o; long128 q; long128* dst = (long128*)d; __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst)); q = *src; *dst = q; }
static inline void LookOff3(V4& cam, V4* rs, char* s) { SetX3(&cam, PlayerInput_GetLookOffset(rs, SB(0x125), SB(0x126))); }
static inline void SetXP(V4* d, const V4& o) { const long128* src = (const long128*)&o; long128* dst = (long128*)d; long128 q; __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst)); q = *src; *dst = q; }
static inline void LookOffP(V4& cam, V4* rs, char* s) { SetXP(&cam, PlayerInput_GetLookOffset(rs, SB(0x125), SB(0x126))); }
static inline void SetXZ(V4* d, const V4& o) { long128* dst; long128 q; const long128* src; src = (const long128*)&o; dst = (long128*)d; __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst)); q = *src; *dst = q; }
static inline void LookOffZ(V4& cam, V4* rs, char* s) { SetXZ(&cam, PlayerInput_GetLookOffset(rs, SB(0x125), SB(0x126))); }
static inline void LookOff(V4& cam, V4* rs, char* s) { SetX(&cam, PlayerInput_GetLookOffset(rs, SB(0x125), SB(0x126))); }
static inline float H2a(char* a, float hgt)
{
    float h2;
    char* bp;
    bp = ((VO<Ev40>*)a)->vF4().c;
    Box80 m(PF(bp, 0), PF(bp, 4), PF(bp, 8), PF(bp, 0xC), PF(bp, 0x10), PF(bp, 0x14), PF(bp, 0x18), PF(bp, 0x1C), PF(bp, 0x20), PF(bp, 0x24), PF(bp, 0x28), PF(bp, 0x2C));
    h2 = Bounds(m.c);
    return h2;
}
static inline void H2b(V4& ang3, float d)
{
    V4 t;
    const long128* src = (const long128*)&t;
    long128* dst = (long128*)&ang3;
    long128 q;
    __asm__ volatile("paddub %0, $0, $0" : "=r"(q) : "r"(src), "r"(dst));
    t.z = d; t.x = 0.0f; t.y = 0.0f;
    q = *(const long128*)&t; *dst = q;
    ang3.SetZ(nSFOMath_ExpressAngleAsValueBetweenNegAndPos180_cEulerAngleTR(&ang3));
}
static inline void Set3(V4& v, float a, float b, float c) { v.x = a; v.y = b; v.z = c; }
static inline void Set3z(V4& v, float a, float b, float c) { v.z = c; v.x = a; v.y = b; }
static inline void H2(char* a, V4& ang3, float hgt)
{
    float h2;
    char* bp;
    bp = ((VO<Ev40>*)a)->vF4().c;
    Box80 m(PF(bp, 0), PF(bp, 4), PF(bp, 8), PF(bp, 0xC), PF(bp, 0x10), PF(bp, 0x14), PF(bp, 0x18), PF(bp, 0x1C), PF(bp, 0x20), PF(bp, 0x24), PF(bp, 0x28), PF(bp, 0x2C));
    h2 = Bounds(m.c);
    ang3.SetB(V4c(0.0f, 0.0f, hgt - h2));
    ang3.Set(nSFOMath_ExpressAngleAsValueBetweenNegAndPos180_cEulerAngleTR(&ang3));
}
static inline void CpN(V4* d, const V4* src) { long128 q; __asm__ volatile("lq %0, 0x0(%1)\n\tsq %0, 0x0(%2)" : "=r"(q) : "r"(src), "r"(d)); }
static inline void FlatSub(V4& out, V4* a, V4* b) { VC t = SubC(a, b); V4* p = (V4*)&t; p->z = 0.0f; CpN(&out, p); }
static inline void Cp2(V4* d0, V4* s0, V4* d1, V4* s1) { long128 q; __asm__ volatile("lq %0, 0x0(%2)\n\tsq %0, 0x0(%1)\n\tlq %0, 0x0(%4)\n\tsq %0, 0x0(%3)" : "=&r"(q) : "r"(d0), "r"(s0), "r"(d1), "r"(s1)); }
extern "C" void PlayerInput_Update(char* s, float dt, char* c, char* o)
{
    char* a;
    char* pd;
    unsigned char isA;
    isA = 0;
    if (!o) goto skip;
    if (!IsA(o)) goto skip;
    isA = 1;
skip:
    if (isA) a = o; else a = 0;
    pd = D_0055A300;
    float x0 = U2F(PU(pd, 0x36C));
    float x1 = U2F(PU(pd, 0x374));
    float x2 = U2F(PU(pd, 0x370));
    float x3 = U2F(PU(pd, 0x378));
    float x4 = U2F(PU(pd, 0x364)) / D_004BBE18;
    float x5 = U2F(PU(pd, 0x35C));
    float x6 = U2F(PU(pd, 0x368));
    float x7 = U2F(PU(pd, 0x360));
    float x8 = U2F(PU(pd, 0x358));
    float x9 = U2F(PU(pd, 0x354));
    float x10 = U2F(PU(pd, 0x350));
    float x11 = U2F(PU(pd, 0x34C));
    float t = x4;
    In b;
    V4 ls, rs, ls2, rs2;
    float k, dz, sc, rate;
    unsigned char moving, still2, aim8, menu, pause, hudAct, hasSel;
    float clampY;
    {
        {
            unsigned int fl = PU(pd, 0x14C);
            float a1 = AxR(pd, 0x1AC);
            float a2 = AxR(pd, 0x1B4);
            float a3 = AxR(pd, 0x1B0);
            float a4 = AxR(pd, 0x1B8);
            float a5 = AxR(pd, 0x1A4);
            float a6 = AxR(pd, 0x19C);
            float a7 = AxR(pd, 0x1A8);
            float a8 = AxR(pd, 0x1A0);
            float a9 = AxR(pd, 0x198);
            float a10 = AxR(pd, 0x194);
            float a11 = AxR(pd, 0x190);
            float a12 = AxR(pd, 0x18C);
            unsigned int q0 = (fl & 0x100) != 0;
            unsigned int q21 = (fl & 0x800) != 0;
            unsigned int q22 = (fl & 0x400) != 0;
            b.f[0] = U2F(q0);
            b.f[4] = a3;
            b.f[7] = a7;
            b.f[8] = a5;
            b.f[12] = a10;
            b.f[1] = a11;
            b.f[14] = a11;
            b.f[2] = a12;
            b.f[15] = a12;
            b.f[3] = a9;
            b.f[13] = a9;
            b.f[5] = a1;
            b.f[20] = a1;
            b.f[6] = a8;
            b.f[19] = a8;
            b.f[9] = a6;
            b.f[18] = a6;
            b.f[10] = a4;
            b.f[16] = a4;
            b.f[11] = a2;
            b.f[17] = a2;
            b.f[21] = U2F(q21);
            b.f[22] = U2F(q22);
            b.f[23] = t;
        }
    }
    Vec2f l = StickL(pd + 0x40);
    Vec2f r = StickR(pd + 0x40);
    {
        float d = D_004BBE10;
        k = 1.0f / d;
        dz = 0.34906584f;
        sc = 1.0f / (1.5707964f - dz);
        rate = 2.2514746f;
        ls.z = 0.0f;
        ls.w = 0.0f;
        rs.z = 0.0f;
        rs.w = 0.0f;
        ls.y = -l.y * k;
        ls.x = l.x * k;
        rs.y = -r.y * k;
        rs.x = r.x * k;
    }
    {
        Vec2f l = StickL(pd + 0x200);
        Vec2f r = StickR(pd + 0x200);
        ls2.z = 0.0f;
        ls2.w = 0.0f;
        rs2.z = 0.0f;
        rs2.w = 0.0f;
        ls2.y = -l.y * k;
        ls2.x = l.x * k;
        rs2.y = -r.y * k;
        rs2.x = r.x * k;
    }
    {
        unsigned char lt = Math_Fabs(cGameCamera_GetFollowDistance(c)) < 4.0f;
        moving = !lt;
    }
    still2 = !moving && !(cSplinedMotion_cQuaternion_IsTransitionInProgress(c) != 0);
    aim8 = SI(0x38) == 8;
    if (SB(0) || g_LoadoutPending || Hud_IsGuiFocused(g_Hud) || g_GameState == 0x13) {
        unsigned char m1 = PI(PP(g_Hud, 0x6A4), 0xD4) == 1;
        b.f[10] = 0.0f;
        b.f[11] = 0.0f;
        b.f[4] = 0.0f;
        b.f[5] = 0.0f;
        if (!m1 && !PB(g_Hud, 0x6A9)) {
            b.f[8] = 0.0f;
        }
        b.f[9] = 0.0f;
        b.f[7] = 0.0f;
        b.f[6] = 0.0f;
        b.f[3] = 0.0f;
        b.f[1] = 0.0f;
        b.f[2] = 0.0f;
        b.f[0] = 0.0f;
        b.f[21] = 0.0f;
        b.f[22] = 0.0f;
        if (!m1) {
            l = Vec2f(0.0f, 0.0f);
            r = Vec2f(0.0f, 0.0f);
            ls.Zero();
            rs.Zero();
        }
    }
    menu = PB(g_Hud, 0x6A9);
    pause = PB(g_Hud, 0x6A8);
    hudAct = PB(g_Hud, 0x6AA);
    hasSel = GuiGameScreen_IsChooseMenuActive(PP(g_Hud, 0x6A4));
    if (!menu && !pause && g_GameState == 0xF && D_004FFB98 && cJoystick_IsDormant(pd)) {
        if (!g_IsMultiplayer || (g_IsMultiplayer && GateOk())) {
            SF(4) += dt;
            float lim = D_004FFB98;
            if (!(SF(4) <= lim)) {
                cGameSystem_Restart(g_Game, 2);
            }
        }
    } else {
        SF(4) = 0.0f;
    }
    if (menu || pause || hudAct) {
        b.f[10] = 0.0f;
        b.f[11] = 0.0f;
        b.f[4] = 0.0f;
        b.f[5] = 0.0f;
        b.f[0] = 0.0f;
        b.f[3] = 0.0f;
        b.f[2] = 0.0f;
        if (b.f[9] && !SB(0xAD) && pause) {
            cObjectiveMan_DeactivateObjectiveScreen(ObjMan_GetService());
            cGameSystem_PauseGame(g_Game, 0);
        }
        b.f[9] = 0.0f;
        b.f[7] = 0.0f;
        b.f[6] = 0.0f;
        {
            float z0 = 0.0f;
            if (menu && !IsSt(s, 7)) {
                l.y = z0;
                ls.y = z0;
                ls.z = z0;
                ls.x = ls.x;
            } else {
                l.x = 0.0f;
                l.y = 0.0f;
                ls.x = 0.0f;
                ls.y = 0.0f;
                ls.z = 0.0f;
            }
        }
        r.x = 0.0f;
        r.y = 0.0f;
        rs.x = 0.0f;
        rs.y = 0.0f;
        rs.z = 0.0f;
        b.f[22] = 0.0f;
    } else {
        if (cModeSwitch_12_IsModeActivated(s + 0x38, 0xB)) {
            b.f[5] = 0.0f;
            b.f[4] = 0.0f;
            b.f[11] = 0.0f;
            b.f[10] = 0.0f;
            b.f[8] = 0.0f;
            b.f[9] = 0.0f;
            b.f[7] = 0.0f;
            b.f[6] = 0.0f;
            b.f[3] = 0.0f;
            b.f[1] = 0.0f;
            b.f[2] = 0.0f;
            b.f[0] = 0.0f;
            b.f[22] = 0.0f;
            l = Vec2f(0.0f, 0.0f);
            ls.Zero();
        }
    }
    {
        float cy = 5.0f * (-b.f[11] + b.f[10]);
        clampY = ClampG(cy, -1.0f, 1.0f);
    }
    {
        V4 acc;
        V4 mv;
        V4 drift;
        V4 rot;
        V4 off;
        V4 mv3;
        V4 cam;
        float lookY;
        float spd;
        float hgt;
        float w0;
        unsigned char bigWalk;
        unsigned char moved;
        int quiet;
        V4* cp;
        float n;
        bigWalk = 0;
        acc.x = 0.0f; acc.y = 0.0f; acc.z = 0.0f; acc.w = 0.0f;
        mv.x = 0.0f; mv.y = 0.0f;
        lookY = 0.0f;
        hgt = 0.0f;
        mv.z = 0.0f; mv.w = 0.0f;
        w0 = 0.0f;
        CpV(&drift, &ZeroV());
        rot.x = 0.0f; rot.y = 0.0f;
        quiet = 0;
        rot.z = 0.0f; rot.w = 0.0f;
        off.x = 0.0f; off.y = 0.0f; off.z = 0.0f; off.w = 0.0f;
        spd = 0.0f;
        mv3 = *(V4*)&ZeroV();
        cp = func_00250310();
        cam.x = cp->x;
        cam.y = cp->y;
        cam.z = cp->z;
        moved = 0;
        cModeSwitch_12_opAssign(s + 0x30, s + 0x38);
        cModeSwitch_12_opAssign(s + 0x38, s + 0x40);
        cModeSwitch_2_opAssign(s + 0x48, s + 0x50);
        cModeSwitch_2_opAssign(s + 0x50, s + 0x58);
        if (SI(0x134) > 0 && cSafePtr_cHuman_opCast_cHumanPtr(a + 0x3478)) {
            Ev30 e;
            char* ep = e.c;
            cMessage_ctor_cMessageNameR(ep, g_ActorActionMsgClass);
            PP(ep, 0) = D_004E0840;
            PI(ep, 0x24) = 0x2C;
            PB(ep, 0x28) = 0;
            PB(&e, 0x20) = 1;
            QueueMessage_cMessageR_cSystemP_int(ep, a, 1);
            PP(&e, 0) = D_004E0840;
            cMessage_dtor(ep, 0);
        }
        {
            char* pk = SP(0x128);
            if (pk) {
                if (b.f[12] && !SB(0xB0)) {
                    cPickupMenu_Prev(pk);
                } else if (b.f[13] && !SB(0xB1)) {
                    cPickupMenu_Next(pk);
                } else if (b.f[14] && !SB(0xB2)) {
                    cPickupMenu_PrevWeapon(pk);
                } else if (b.f[15] && !SB(0xB3)) {
                    PickupMenu_OnRight(pk);
                }
                if (b.f[9] && !SB(0xAD)) {
                    Snd sd;
                    SB(0xAD) = 1;
                    cPlayerControls_KillPickup(s);
                    b.f[9] = 0.0f;
                    cJoystick_Debounce(D_0055A300);
                    {
                        char* q = sd.c;
                        int none;
                        cSafePtr_cGOBJ_ctor_void(q + 0x20);
                        cVector_ctor_void((V4*)(q + 0x30));
                        cFileMan_ctor_void(q + 0x48);
                        cFileMan_ctor_void(q + 0xE4);
                        none = -1;
                        PI(q, 0) = none;
                        *(__int128*)(q + 0x10) = Dup(none);
                        cSafePtr_cGOBJ_opAssign_cGOBJP(q + 0x20, 0);
                        func_00250190(q + 0x30, 0.0f, 0.0f, 0.0f);
                        *(short*)(q + 0x184) = -1;
                        PI(q, 0x180) = 0;
                        *(unsigned char*)(q + 0x186) = 0;
                    }
                    cSndFx_SetSndFx(&sd, 3, D_004A77B8, 0, 0);
                    SendFx(&sd);
                    cFileMan_dtor(sd.c + 0xE4, -1);
                    cFileMan_dtor(sd.c + 0x48, -1);
                } else if (b.f[8]) {
                    SB(0x2D) = 1;
                    if (!SB(0xAC)) {
                        SB(0xAC) = 1;
                        if (cPickupMenu_AcceptChoices(SP(0x128), a)) {
                            cPlayerControls_KillPickup(s);
                        }
                    }
                }
            }
        }
        if (hasSel) {
            SelB(a);
        } else if (!b.f[8]) {
            SB(0x2D) = 0;
        }
        ClampUnit(&ls);
        ClampUnit(&rs);
        ClampUnit(&ls2);
        ClampUnit(&rs2);
        if (!cModeSwitch_12_IsModeActivated(s + 0x38, 1) && !cModeSwitch_12_IsModeActivated(s + 0x38, 7) && !hasSel && !SP(0x128) &&
            b.f[3] && !SB(0xA7) && !pause && !menu) {
            char* inv = AP(0x3524);
            unsigned char sl = PB(inv, 0x84);
            int id = sl != 6 ? ((int(*)[4])(inv + 8))[sl][0] : -1;
            if (id > -1) {
                int h = *(int*)PP(g_Hud, 0x54);
                int bp = cBackpack_NewBackpack_cHumanP_bool_cObjectIdP(a, 0, 0);
                char* p;
                int tmp;
                cBackpack_InitForDropping(bp, id);
                cTimerDisable_ctor(&tmp);
                p = (char*)cMemMan_Allocate(0, 0xB8, D_004A75A0, 0x31E);
                cTimerDisable_dtor(&tmp, -1);
                if (p) {
                    p = cPickupMenu_ctor(p, h, bp, a, 0, 1);
                }
                SP(0x128) = p;
            }
        }
        if (!menu && !pause && !hudAct && !cModeSwitch_12_IsModeActivated(s + 0x38, 7)) {
            if (b.f[2]) {
                if (!SB(0xA6)) {
                    SF(0x104) = 0.0f;
                } else if (SF(0x104) < D_0048AE88) {
                    SF(0x104) += dt;
                    if (!(SF(0x104) <= D_0048AE88)) {
                        cHuman_CycleGadgetState(a);
                    }
                }
            } else if (SB(0xA6) && SF(0x104) < D_0048AE88) {
                cHuman_ToggleGadgetState(a);
            }
        }
        if (!SB(0xA4) && b.f[0]) {
            if (cPlayerControls_CanChangeWeapon(s, a) && cWeapon_CanChangeWeapon(AP(0x3524))) {
                SB(0x108) = 1;
                SI(0x10C) = Tick() + 200;
            }
        } else if (SB(0xA4) && b.f[0]) {
            if (SB(0x108)) {
                if ((int)Tick() >= SI(0x10C)) {
                    GuiGameScreen_ActivateWeaponSelect(PP(g_Hud, 0x6A4), 1);
                    SB(0x108) = 0;
                }
            }
        } else {
            SB(0x108) = 0;
        }
        if (SB(0xA4) && !b.f[0] && PI(PP(g_Hud, 0x6A4), 0xD4) != 1 && cPlayerControls_CanChangeWeapon(s, a)) {
            char* pk = SP(0x128);
            cWeapon_SelectNext(AP(0x3524), !(pk && Pk98(pk)));
            if (g_IsMultiplayer) {
                cPlayerControls_NetSelectNextWeapon(s, a);
            }
        }
        if (!SB(0xB9) && b.f[21]) {
            if (SP(0x128)) {
                cPlayerControls_KillPickup(s);
            }
            if (PB(g_Hud, 0x6A8)) {
                cHud_DeactivateObjectiveMenu(g_Hud);
                cGameSystem_PauseGame(g_Game, 0);
            } else {
                cHud_ActivateObjectiveMenu(g_Hud);
            }
        }
        if (a) {
            cPlayerControls_HandleReloadButtonPress(s, b.f[22] && !SB(0xBA), a);
        }
        if (a) {
            char* hud = g_Hud;
            if (cModeSwitch_12_IsModeActivated(s + 0x38, 1)) {
                int cur = func_00159570(g_CameraObject) ? *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject) : 0;
                if (D_004FFC10 != cur) {
                    cHud_ClearTargetNow(hud);
                }
            } else {
                SeedPlayerLos(a, s);
                cPlayerControls_UpdateTarget(s, c, a, b.f[4] > 0.0f, b.f[5] > 0.0f && !SB(0xB8), dt);
            }
            cHud_SetHealth(hud, AF(0x40), AI(0x3398));
            cHud_SetArmor(hud, AI(0x33A0), AI(0x339C));
        }
        if (o) {
            if (!cModeSwitch_12_IsModeActivated(s + 0x38, 6) && !cModeSwitch_12_IsModeActivated(s + 0x38, 8) && !cModeSwitch_12_IsModeActivated(s + 0x38, 1) &&
                b.f[6]) {
                SendEvN(o, 8, 1);
            }
            if (SI(0x38) == 8) {
                if (b.f[17]) {
                    SendEvF(o, 0xB, 0);
                } else if (b.f[16]) {
                    SendEvF(o, 0xC, 0);
                } else {
                    SendEvF(o, 0xD, 0);
                }
            } else {
                SendEvF(o, 0xD, 0);
            }
            if (SB(0x26)) {
                SendObj(o, s, SB(0x27));
            }
        }
        if (a) {
            if (AI(0x320C) == 1) {
                cModeSwitch_12_ActivateMode(s + 0x40, 0xA);
            } else {
                cModeSwitch_12_DeactivateMode(s + 0x40, 0xA);
            }
            if (AI(0x320C) == 4 || AI(0x320C) == 5) {
                cModeSwitch_12_ActivateMode(s + 0x40, 9);
            } else {
                cModeSwitch_12_DeactivateMode(s + 0x40, 9);
            }
        }
        if (a) {
            Do180(dt, s, &ls, a, c);
        }
        if (SI(0x38) != 0) {
            SB(0x2C) = 0;
        }
        switch (SI(0x38)) {
        case 0:
        case 4: {
            V4 z1, z0, z2, dir;
            float ang, ang2, l31, l30, l29, yaw, m;
            z1.Zero();
            z0.Zero();
            LookOffZ(cam, &rs, s);
            z2.Zero();
            dir.Cp(ls);
            ang = IsZero4(&dir) ? 0.0f : At2Y(Fabs(dir.x), Fabs(dir.y));
            ang2 = IsZero4(&dir) ? 0.0f : Libc_Atan2f(Fabs(dir.x), dir.y);
            if (a) {
                bool inR = InR(ang2);
                quiet = BitArray_Test(a + 0x3204, 0) && ((IsZero4B(&dir) && IsZero4B(&z2) && z0.x != 0.0f) || inR) &&
                        IsZero4B(&z1) && clampY == 0.0f;
            }
            l31 = Len(&z2);
            l30 = Len(&dir);
            l29 = Len(&z1);
            {
                char* ph = AP(0x3310);
                unsigned char hp = 0;
                if (ph && PB(ph, 0xDD)) {
                    hp = 1;
                }
                if (hp && AI(0x320C) == 0) {
                    if ((!quiet && l30 > 0.0f) || l31 > 0.0f || l29 > 0.0f || clampY != 0.0f) {
                        cam.z *= D_0048AE80;
                    }
                }
            }
            if (quiet) {
                SB(0x2C) = 0;
            } else if (!SB(0x2C)) {
                if (!(ang2 <= 2.3561945f) || (!(ang2 <= 1.5707964f) && cHuman_cStates_CheckState(a + 0x3200, 0))) {
                    SB(0x2C) = 1;
                }
            } else if (ang2 < 1.5707964f) {
                SB(0x2C) = 0;
            }
            if (quiet || l30 == 0.0f) {
                yaw = 0.0f;
            } else if (!SB(0x2C)) {
                yaw = MAX(0.001f, dir.y);
            } else {
                yaw = Math_MinF(-0.001f, dir.y);
            }
            ang2 = SB(0x2C) ? 3.1415927f - ang2 : ang2;
            if (!quiet) {
                float t = 0.0f;
                float z = t;
                float d = ang2 - dz;
                t = Maxf(t, d);
                m = sc * t * (z != clampY ? Len(&dir) : 1.0f);
            } else {
                m = Len(&dir);
            }
            if (!(dir.x < 0.0f)) {
                { float v = -z0.x - m; float lo = -1.0f; float hi = 1.0f; lookY = Clampf(v, lo, hi); }
            } else {
                { float v = m - z0.x; float lo = -1.0f; float hi = 1.0f; lookY = Cp3(lo, hi, v); }
            }
            if (!quiet) {
                V4 cur, tgt;
                cur = *(V4*)&ZeroV();
                cur.z = SF(0x80);
                tgt.Cp(*(V4*)&ZeroV());
                tgt.z = lookY;
                { float e2 = 1.0000001e-6f; float k1 = 13.0f; float e1 = 1.0000001e-6f; float k2 = 13.0f; LimitManualAimAngularAcceleration_ByScale(&tgt, &tgt, &cur, k1, k2, e1, e2, dt); }
                lookY = tgt.z;
            }
            acc.y = 0.0f;
            acc.x = -z0.y;
            if (!quiet) {
                spd = MaxP(MaxP(MaxP(FabsZ(clampY), l31), l30), l29);
                spd = Math_MinF(1.0f, spd);
                mv.z = 0.0f;
                mv.x = clampY + z2.x;
                mv.y = yaw + z2.y;
                mv.x += z1.x;
                mv.y += z1.y;
                if (!IsZero3(&mv)) {
                    Normalize(&mv);
                }
                cVector_VU0Scale(&mv, &mv, spd);
                if (clampY == 0.0f && IsZero4(&z2) && IsZero4(&z1) && yaw != 0.0f) {
                    float d = 1.5707964f - ang; float v = 0.1f + 30.0f * d * dt;
                    float f = Clampf(v, 0.1f, 1.0f);
                    if (f != 1.0f) {
                        { float x = mv.x; mv.x = SF(0xA0) + f * (x - SF(0xA0)); }
                        if (!IsZero3(&mv)) {
                            Normalize(&mv);
                        }
                        cVector_VU0Scale(&mv, &mv, spd);
                    }
                }
                moved = 1;
                SF(0xA0) = mv.x;
            } else {
                SB(0x2C) = 0;
                ZeroM(&mv);
                spd = mv.z;
            }
            break;
        }
        case 5: {
            char* t = PP(c, 0x50);
            V4 ang3, g, d0, d1;
            float la, lb;
            unsigned char q3, q2, q1;
            if (PB(t, 0x50)) {
                ((VOb*)t)->v58();
            }
            t += 0x10; hgt = BoundsW(t);
            bigWalk = 1;
            ang3.x = 0.0f;
            ang3.y = 0.0f;
            ang3.z = 0.0f;
            if (cSafePtr_cGOBJ_GetPtr_void(s + 0xC8) && PI(cSafePtr_cGOBJ_GetPtr_void(s + 0xC8), 0x50)) {
                float h2 = H2a(a, hgt);
                H2b(ang3, hgt - h2);
            }
            g.x = ang3.x;
            g.y = ang3.y;
            g.z = ang3.z;
            g.x = g.x * 0.63661975f;
            g.x = ClampG(g.x, -1.0f, 1.0f);
            g.y = g.y * 0.63661975f;
            g.y = ClampG(g.y, -1.0f, 1.0f);
            g.z = g.z * 0.63661975f;
            g.z = ClampG(g.z, -1.0f, 1.0f);
            d0 = ls;
            d1.Cp(*(V4*)&ZeroV());
            la = LenG(&d0);
            lb = LenG(&d1);
            q1 = 0;
            q2 = 0;
            q3 = 0;
            if ((unsigned char)cHuman_cStates_CheckState(a + 0x3200, 0) && la == 0.0f) q1 = 1;
            if (q1 && lb == 0.0f) q2 = 1;
            if (q2 && clampY == 0.0f) q3 = 1;
            {
                unsigned char q = q3;
                unsigned char tilt = ang3.x > 0.0f && ang3.x < 0.34906584f;
                unsigned char flat = FabsZ(ang3.z) <= 0.0f;
                quiet = q && !flat;
            }
            lookY = 0.0f;
            if (!quiet && !cModeSwitch_12_IsModeActivated(s + 0x38, 1)) {
                spd = Maxf(Maxf(FabsZ(clampY), la), lb);
                spd = Math_MinF(1.0f, spd);
                Set3(mv, clampY + d1.x + d0.x, d0.y + d1.y, 0.0f);
                if (!IsZero3(&mv)) {
                    Normalize(&mv);
                }
                cVector_VU0Scale(&mv, &mv, spd);
            } else {
                ZeroQ(&mv);
                spd = 0.0f;
            }
            moved = 1;
            SF(0xA0) = mv.x;
            break;
        }
        case 8: {
            char* t = PP(c, 0x50);
            V4 d0, d1, f4;
            float vx, f;
            if (PB(t, 0x50)) {
                ((VOb*)t)->v58();
            }
            t += 0x10; hgt = BoundsW(t);
            bigWalk = 1;
            d0 = ls;
            d1 = rs;
            FlatSub(f4, &d0, &d1);
            n = 0.0f;
            if (!IsZero4N(&f4)) {
                NormLenP(&f4, &n);
            }
            if (n < 1.0f) {
                cVector_VU0Scale(&f4, &f4, Sq(Sq(n)) + 0.3f * (1.0f - Sq(2.0f * n - 1.0f)));
            }
            vx = SB(0x124) ? f4.y : -f4.y;
            mv3.x = vx;
            mv3.y = 0.0f;
            mv3.z = -f4.x;
            mv3.x *= D_0048AE58;
            mv3.z *= D_0048AE58;
            f = D_004A7548 * (2.0f * PF(c, 0x60));
            mv3.x *= f;
            mv3.z *= f;
            PlayerInput_SmoothAimVector(&mv3, &mv3, s + 0x90, IsZero4(&mv3) ? D_0048AE68 : D_0048AE60, MulK(0.0f, f * f), dt);
            CpE(&acc, &mv3);
            lookY = *(volatile float*)&mv3.z;
            lookY = 0.0f;
            if (cModeSwitch_12_IsModeActivated(s + 0x38, 1)) {
                ZeroQ(&acc);
                lookY = 0.0f;
            }
            quiet = (unsigned char)cHuman_cStates_CheckState(a + 0x3200, 0) && lookY != 0.0f;
            ZeroQ(&mv);
            spd = 0.0f;
            break;
        }
        case 11: {
            LookOffZ(cam, &rs, s);
            break;
        }
        case 1:
        case 2:
        case 3:
        case 9:
        case 10: {
            LookOffZ(cam, &rs, s);
            break;
        }
        case 7: {
            V4 d, z;
            float x, y;
            LookOffP(cam, &rs, s);
            { V4* dp = &d; *dp = ls; }
            z = *(V4*)&ZeroV();
            x = AbsMaxR(z.x, d.x);
            x = AbsMaxR(clampY, x);
            y = AbsMaxR(z.y, d.y);
            mv.x = x;
            mv.y = 0.0f;
            mv.z = 0.0f;
            spd = FabsZ(mv.x);
            if (!(y <= 0.9f)) {
                SendEvF(o, 0x11, 0);
            } else if (y < -0.9f) {
                SendEvF(o, 0x13, 0);
            }
            break;
        }
        case 6: {
            V4 d, z;
            float y, lo, hi;
            int ev;
            LookOffP(cam, &rs, s);
            { V4* dp = &d; *dp = ls; }
            z = *(V4*)&ZeroV();
            y = AbsMaxR(z.y, d.y);
            mv.z = y;
            spd = FabsZ(mv.z);
            { float dx = d.x; lo = FabsZ(Min0(Minf(Minf(dx, z.x), -b.f[11]))); }
            hi = FabsZ(Max0(Maxf(Maxf(d.x, z.x), b.f[10])));
            ev = -1;
            if (0.0f != b.f[8]) {
                ev = 0x1F;
            } else if (lo < 0.5f && hi < 0.5f) {
                if (mv.z < 0.0f) {
                    ev = 0x1F;
                } else if (!(mv.z <= 0.0f)) {
                    ev = 0x20;
                }
            } else {
                if (lo > hi) {
                    ev = 0x21;
                } else {
                    ev = 0x22;
                }
            }
            if ((signed char)ev != -1) {
                SendEvF(o, (signed char)ev, 1);
            }
            break;
        }
        }
        if (o && a) {
            float m;
            SendCas(o, 3, 1, D_004D9320, &D_0048AE90);
            SendCas(o, 4, 1, D_004D9320, &D_0048AE98);
            m = Remap(spd);
            SendMot(o, &mv, m, lookY * rate, quiet);
            cPlayerControls_UpdateCharacterZRotation(s, a, bigWalk, hgt);
        }
        UpdCam(s, c, a, rate, &acc, &off, &rot, &cam);
        {
            char* hud = g_Hud;
            if (b.f[1] && !SB(0xA5) && !SP(0x128) && !pause && !hudAct) {
                cHud_ToggleMap(hud);
            }
            if (PB(hud, 0x6A9)) {
                cMap_MapUserInterface(PP(hud, 0x6A0), pd);
            }
            if (SP(0x128) && a) {
                GuiGameScreen_ClearInteract(PP(hud, 0x6A4), 0);
                if (cPickupMenu_Draw(SP(0x128), a) == 0) {
                    cPlayerControls_KillPickup(s);
                }
            } else if (!hasSel) {
                char* hb = cHotboxMan_CanInteract(g_HotboxTracker, 0);
                if (cSafePtr_cHuman_opCast_cHumanPtr(a + 0x3478)) {
                    char* gs = PP(hud, 0x6A4);
                    GuiGameScreen_ShowInteract(gs, nGlobalization_GetString_charP(D_004A77C8), 1, 0);
                } else if (!cModeSwitch_12_IsModeActivated(s + 0x38, 1) && (hb || SI(0x130)) && !cModeSwitch_12_IsModeActivated(s + 0x38, 8) &&
                           AI(0x320C) != 0x13) {
                    unsigned char hint;
                    if (!GuiGameScreen_InteractActive(PP(hud, 0x6A4)) && hb && PI(hb, 0x90) == 0xC) {
                        cHud_Message(hud, nGlobalization_GetString_charP(D_004A77D8));
                    }
                    hint = 0;
                    if (func_0024FD80(func_0024FD90(a + 0x320C), 0x14) && func_0024FD50(a + 0x320C, 0x20)) {
                        hint = 1;
                    }
                    if (hint) {
                        char* gs = PP(hud, 0x6A4);
                        GuiGameScreen_ShowInteract(gs, nGlobalization_GetString_charP(D_004A77E8), 1, 0);
                    } else if (!GuiGameScreen_InteractActive(PP(hud, 0x6A4))) {
                        int txt;
                        if (!hb || !(txt = PI(hb, 0xA0))) {
                            txt = nGlobalization_GetString_charP(D_004A77F0);
                        }
                        GuiGameScreen_ShowInteract(PP(hud, 0x6A4), txt, 1, 0);
                    }
                } else {
                    GuiGameScreen_ClearInteract(PP(hud, 0x6A4), 0);
                }
            } else {
                GuiGameScreen_ClearInteract(PP(hud, 0x6A4), 0);
            }
        }
        if (SI(0x50) != 1 && o) {
            float r = rate * dt;
            if (w0) {
                float sn = SIN(w0 * r);
                float cs = COS(w0 * r);
                Mtx m;
                cMatrix_Set_ColumnMajorForm(&m, cs, -sn, 0.0f, sn, cs, 0.0f, 0.0f, 0.0f, 1.0f);
                SendRot(o, &m);
                SendEvN(o, 0x13, 1);
                SendEvN(o, 0x24, 1);
            }
            if (!IsZero3(&drift)) {
                float k = 15.0f * dt;
                V4 dd;
                DriftV2(o, k, &drift, dd);
                SendXf(o, &dd);
                SendEvN(o, 0x13, 1);
                SendEvN(o, 0x24, 1);
            }
        }
        if (a) {
            unsigned char held = b.f[7] != 0.0f;
            char* inv = AP(0x3524);
            int cls = cWeapon_GetEquipmentType(inv);
            int aimH; unsigned char canFire, thr, fire;
            {
                unsigned char h = 0;
                if (aim8) {
                    unsigned char t = 1;
                    if (((unsigned char)cls) != 1 && !still2) {
                        t = 0;
                    }
                    if (t) {
                        h = 1;
                    }
                }
                aimH = h;
            }
            {
                unsigned char t = 1;
                if (((unsigned char)cls) != 0 && ((unsigned char)cls) != 5) {
                    t = 0;
                }
                canFire = !(t != 0) || IWA(a);
            }
            {
                unsigned int d = ((unsigned char)cls) - 3;
                unsigned char t = 0;
                if (d < 8 && ((1 << d) & 0x83)) {
                    t = 1;
                }
                thr = t;
            }
            if (SB(0xAB)) {
                SF(0x100) = SF(0x100) + dt;
            } else {
                SF(0x100) = 0.0f;
            }
            if (((unsigned char)cls) == 1) {
                fire = !held && SB(0xAB);
                if (held) {
                    SF(0xE0) = cGrenade_FigureThrowAngle(SF(0x100));
                    if (aimH) {
                        float pw = PI(cWeapon_GetWeaponEntry(inv), 0x104);
                        V4 np;
                        cSkeleton_GetBoneToWorldTranslation(&np, cSKM_GOBJ_GetSkeleton_void(a), D_0049D02C);
                        cGrenade_CalculateArcPoints(&np, s + 0xD0, SF(0xE0), pw);
                    }
                }
            } else if (thr || ((unsigned char)cls) == 0xB) {
                fire = held && !SB(0xAB);
            } else if (((unsigned char)cls) == 5) {
                fire = held && !(unsigned char)cModeSwitch_12_IsModeActivated(s + 0x38, 1);
            } else {
                int ammo = cWeapon_GetAmmo(inv, 6) + cWeapon_GetClipAmmo(inv, 6);
                fire = held && ((cWeapon_IsFullyAutomatic(inv) && ammo) || !SB(0xAB));
            }
            if (cModeSwitch_12_IsModeActivated(s + 0x38, 1) && !held) {
                cModeSwitch_12_DeactivateMode(s + 0x40, 1);
                cWeapon_RetractTaser(inv);
            }
            if (fire || (canFire && !(SF(0x120) <= 0.0f))) {
                unsigned char noAmmo = 0;
                if (((unsigned char)cls) == 1) {
                    noAmmo = 1;
                    if (aimH) {
                        cSafePtr_cGOBJ_Set(s + 0xC0, 0);
                    } else if (!cSafePtr_cGOBJ_GetPtr_void(s + 0xC0)) {
                        MtxR mat = ((VO<MtxR>*)a)->vF4();
                        SetThrow(s);
                    } else {
                        char** h = cSafePtr_cGOBJ_GetPtr_void(s + 0xC0);
                        TgtPos(s, h);
                    }
                } else if (((unsigned char)cls) == 7) {
                    noAmmo = 1;
                    if (aimH) {
                        Mtx m;
                        char** g;
                        cSafePtr_cGOBJ_Set(s + 0xC0, 0);
                        g = (char**)PP(o, 0x58);
                        ((VOb*)g)->v64(&m, 0, 1);
                        Aim7(s, &m, inv);
                    } else if (!cSafePtr_cGOBJ_GetPtr_void(s + 0xC0)) {
                        MtxR mat = ((VO<MtxR>*)a)->vF4();
                        Aim7b(s, (Mtx*)&mat);
                    }
                }
                if (canFire) {
                    if (((unsigned char)cls) == 5) {
                        noAmmo = 1;
                        cModeSwitch_12_ActivateMode(s + 0x40, 1);
                    }
                    {
                        Ev60 e;
                        V4 padx[0x14];
                        if (0) cVector_ctor_void(padx);
                        char* ep = e.c;
                        MakeTI3(ep, s, aimH);
                        PB(&e, 0x20) = 1;
                        if (!noAmmo && cWeapon_GetClipAmmo(inv, 6)) {
                            cPlayerControls_NetShootWeapon(s, o);
                        }
                        QueueMessage_cMessageR_cSystemP_int(e.c, o, 0);
                        SF(0x120) = 0.0f;
                        PP(&e, 0) = D_004E0200;
                        cCharActionMsg_dtor(&e, 0);
                    }
                } else if (((unsigned char)cls) == 0 || ((unsigned char)cls) == 5) {
                    SF(0x120) = D_004A7598;
                }
                SF(0x11C) = D_004A7588;
            }
            SF(0x120) = MAX(0.0f, SF(0x120) -= dt);
            SB(0xAB) = held;
        }
        if (a) {
            if (AI(0x320C) != 2 || func_0024FD50(a + 0x320C, 3)) {
                unsigned char sq = NZq(b.f[5]);
                if (SP(0x128) || (b.f[4] != 0.0f && !cModeSwitch_12_IsModeActivated(s + 0x38, 8))) {
                    sq = 0;
                }
                cPlayerControls_HandleManualAimButtonPress(s, a, c, (float)sq);
                if (!cModeSwitch_12_IsModeActivated(s + 0x38, 8) && !cModeSwitch_12_IsModeActivated(s + 0x38, 1)) {
                    cPlayerControls_HandleInteractButtonPress(s, a, b.f[9]);
                }
            }
            if (!SB(0x2D)) {
                cPlayerControls_HandleCrouchButtonPress(s, a, b.f[8]);
            }
            {
                char* it = cWeapon_GetWeaponEntry(AP(0x3524));
                char* gg = 0;
                if (AB(0x346F)) {
                    gg = cWeapon_GetGoggleEntry(AP(0x3524));
                }
                AB(0x346E) = cHud_SetScope(g_Hud, aim8, moving, it, gg);
            }
        }
        {
            int dir;
            float fov, lo;
            if (b.f[18]) {
                dir = 1;
            } else if (b.f[19]) {
                dir = -1;
            } else {
                dir = 0;
            }
            fov = cWeapon_GetFOV(PF(c, 0xC64), dt, AP(0x3524), SI(0x38) == 8, dir);
            lo = Deg2Rad(0.01f);
            PF(c, 0xC64) = Math_Clampf(fov, lo, Deg2Rad(179.99f));
            cGameCamera_SetDesiredFOV(c, PF(c, 0xC64));
        }
        if (AP(0x3310)) {
            cHumanCollisionRoutine_RequestSearchForLedge(AP(0x3310), 7, 1);
        }
        if (AP(0x3310)) {
            cHumanCollisionRoutine_RequestSearchForLedge(AP(0x3310), 8, 1);
        }
        SB(0x25) = SB(0x24);
        Cp2(&PV(s, 0x60), &ls, &PV(s, 0x70), &acc);
        SF(0x80) = lookY;
        if (SI(0x38) == 8) {
            PV(s, 0x90).Cp(mv3);
        } else {
            PV(s, 0x90).Cp(acc);
        }
        {
            int i;
            for (i = 0; i < 24; i++) {
                *(unsigned char*)(s + i + 0xA4) = b.f[i] != 0.0f;
            }
        }
        if (!moved) {
            SF(0xA0) = 0.0f;
        }
    }
}
