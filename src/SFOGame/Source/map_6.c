/*
 * SFOGame/Source/map: 6 files, 0026D030-0026D620
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026D030 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_cVUM_GOBJPtr_opIndex_uint(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_0026D030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026D030 */

/* merge_units: begin func_0026D040 */
#pragma push /* merge_units */
// cMap::UpdateModelPerspective(float). First matrix product via MulMat wrapper w/ locals po,pb,pa; cameraPos copy = asm w/ __int128 q=0 (dead paddub);
// Scale locals t,q,v; cos easing via named local c; Identity2 w/ named this ptr for cameraOffsetMat.
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float ax, float ay, float az, float aw) { void* xx = this; x = ax; y = ay; z = az; w = aw; }
    cVector(const cVector& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    cVector& operator=(const cVector& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
    void Set0(const cVector& o) { void* d = this; __int128 q = 0; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    void Negate() { __asm__ volatile("lqc2 vf1, 0x0(%1); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(this) : "memory"); }
    void Scale(float k) { int t; cVector* q = this; const cVector* v = this; asm { .set noreorder; lqc2 vf1, 0x0(v); mfc1 t, k; qmtc2.ni t, vf2; vmulx.xyz vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder } }
} __attribute__((aligned(16)));

struct XAx : cVector { XAx() { x = 1.0f; y = 0.0f; z = 0.0f; w = 0.0f; } };
struct XAx2 : cVector { XAx2() { void* xx = this; x = 1.0f; y = 0.0f; z = 0.0f; w = 0.0f; } };
struct VP : cVector { VP(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; } };
struct TM;
extern "C" void cMatrix_ctor_void(TM* m);
extern "C" void cMatrix_SetWithAxisAngle(TM* m, float x, float y, float z, float a);

struct cMatrix {
    float m[4][4];
    cMatrix() {}
    cMatrix(const cMatrix& o) { cMatrix* d = this; __int128 t0, t1; const cMatrix* s = &o; __asm__ volatile("lq %0,0(%2)\n\tlq %1,16(%2)\n\tsq %0,0(%3)\n\tlq %0,32(%2)\n\tsq %1,16(%3)\n\tlq %1,48(%2)\n\tsq %0,32(%3)\n\tsq %1,48(%3)" : "=&r"(t0), "=&r"(t1) : "r"(s), "r"(d) : "memory"); }
    cMatrix& operator=(const cMatrix& o) { cMatrix* d = this; const cMatrix* s = &o; __int128 t0, t1; __asm__ volatile("lq %0,0(%2)\n\tlq %1,16(%2)\n\tsq %0,0(%3)\n\tlq %0,32(%2)\n\tsq %1,16(%3)\n\tlq %1,48(%2)\n\tsq %0,32(%3)\n\tsq %1,48(%3)" : "=&r"(t0), "=&r"(t1) : "r"(s), "r"(d) : "memory"); return *this; }

    void Identity() { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(this) : "memory"); }
    void Identity2() { cMatrix* p = this; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
    void SetTranslation(const cVector& v) { *(cVector*)m[3] = v; }
} __attribute__((aligned(16)));
struct TM { cMatrix m; };
extern "C" void cMatrix_Rotate(cMatrix* a, TM* b);

static inline void Rotate4(cMatrix* m, const cVector& ax, float a)
{
    TM t;
    cMatrix_ctor_void(&t);
    cMatrix_SetWithAxisAngle(&t, ax.x, ax.y, ax.z, a);
    cMatrix_Rotate(m, &t);
}
static inline void Rotate3(cMatrix* m, const cVector& ax, float a) { Rotate4(m, ax, a); }
static inline void Rotate2(cMatrix* m, const cVector& ax, float a) { Rotate3(m, ax, a); }
static inline void Rotate(cMatrix* m, const cVector& ax, float a) { Rotate2(m, ax, a); }


static inline cMatrix operator*(const cMatrix& a, const cMatrix& b) {
    cMatrix o;

    __asm__ volatile("lqc2 vf4, 0x0(%0)\n\tlqc2 vf5, 0x10(%0)\n\tlqc2 vf6, 0x20(%0)\n\tlqc2 vf7, 0x30(%0)\n\tlqc2 vf8, 0x0(%2)\n\tlqc2 vf9, 0x10(%2)\n\tlqc2 vf10, 0x20(%2)\n\tlqc2 vf11, 0x30(%2)\n\tvmulax.xyzw ACC, vf4, vf8x\n\tvmadday.xyzw ACC, vf5, vf8y\n\tvmaddaz.xyzw ACC, vf6, vf8z\n\tvmaddw.xyzw vf12, vf7, vf8w\n\tvmulax.xyzw ACC, vf4, vf9x\n\tvmadday.xyzw ACC, vf5, vf9y\n\tvmaddaz.xyzw ACC, vf6, vf9z\n\tvmaddw.xyzw vf13, vf7, vf9w\n\tvmulax.xyzw ACC, vf4, vf10x\n\tvmadday.xyzw ACC, vf5, vf10y\n\tvmaddaz.xyzw ACC, vf6, vf10z\n\tvmaddw.xyzw vf14, vf7, vf10w\n\tvmulax.xyzw ACC, vf4, vf11x\n\tvmadday.xyzw ACC, vf5, vf11y\n\tvmaddaz.xyzw ACC, vf6, vf11z\n\tvmaddw.xyzw vf15, vf7, vf11w\n\tsqc2 vf12, 0x0(%1)\n\tsqc2 vf13, 0x10(%1)\n\tsqc2 vf14, 0x20(%1)\n\tsqc2 vf15, 0x30(%1)" : : "r"(&a), "r"(&o), "r"(&b) : "memory");
    return o;
}
static inline cMatrix MulMat(const cMatrix& a, const cMatrix& b) {
    cMatrix o;
    cMatrix* po = &o; const cMatrix* pb = &b; const cMatrix* pa = &a;
    __asm__ volatile("lqc2 vf4, 0x0(%0)\n\tlqc2 vf5, 0x10(%0)\n\tlqc2 vf6, 0x20(%0)\n\tlqc2 vf7, 0x30(%0)\n\tlqc2 vf8, 0x0(%2)\n\tlqc2 vf9, 0x10(%2)\n\tlqc2 vf10, 0x20(%2)\n\tlqc2 vf11, 0x30(%2)\n\tvmulax.xyzw ACC, vf4, vf8x\n\tvmadday.xyzw ACC, vf5, vf8y\n\tvmaddaz.xyzw ACC, vf6, vf8z\n\tvmaddw.xyzw vf12, vf7, vf8w\n\tvmulax.xyzw ACC, vf4, vf9x\n\tvmadday.xyzw ACC, vf5, vf9y\n\tvmaddaz.xyzw ACC, vf6, vf9z\n\tvmaddw.xyzw vf13, vf7, vf9w\n\tvmulax.xyzw ACC, vf4, vf10x\n\tvmadday.xyzw ACC, vf5, vf10y\n\tvmaddaz.xyzw ACC, vf6, vf10z\n\tvmaddw.xyzw vf14, vf7, vf10w\n\tvmulax.xyzw ACC, vf4, vf11x\n\tvmadday.xyzw ACC, vf5, vf11y\n\tvmaddaz.xyzw ACC, vf6, vf11z\n\tvmaddw.xyzw vf15, vf7, vf11w\n\tsqc2 vf12, 0x0(%1)\n\tsqc2 vf13, 0x10(%1)\n\tsqc2 vf14, 0x20(%1)\n\tsqc2 vf15, 0x30(%1)" : : "r"(pa), "r"(po), "r"(pb) : "memory");
    return o;
}



static inline cVector Lerp(const cVector& a, const cVector& b, float t) {
    cVector r;
    __asm__ volatile(
        "lqc2 vf1, 0x0(%1)\n\tlqc2 vf2, 0x0(%2)\n\tqmtc2.ni %3, vf3\n\t"
        "vaddax.xyzw ACC, vf1, vf0x\n\tvmaddax.xyzw ACC, vf2, vf3x\n\tvmsubx.xyzw vf4, vf1, vf3x\n\t"
        "sqc2 vf4, 0x0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b), "r"(t) : "memory");
    return r;
}


struct cObjectId {
    int id;
    cObjectId() {}
    cObjectId(int i) { id = i; }
    bool operator==(const cObjectId& o) const { return id == o.id; }
    bool operator!=(const cObjectId& o) const { return id != o.id; }
};

struct cGOBJ {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual cVector GetPosition();
    char pad4[8];
    cObjectId mObjectId;
};

struct cCAMERA_GOBJ { char pad[0x64]; float zAngle; };
struct cPlayerHolder { char pad[0x30]; cGOBJ* obj; };

struct cMap {
    char pad0[0x20];
    cMatrix mModelPerspective;
    cObjectId mCurrentTarget;
    cObjectId mPreviousTarget;
    char pad68[8];
    cVector mCurrentTargetPosition;
    cVector mPreviousTargetPosition;
    float mSeekTime;
    float mSeekCountdown;
};

extern "C" {
extern char g_CameraObject[];
extern cPlayerHolder* g_LocalPlayer;
extern float D_004FF080;
extern float D_004FF084;
extern float D_004FF088;
extern float D_004FF070;
extern float D_0048B278;
extern cMatrix D_0055A290;
int func_00159570(void* l);
cCAMERA_GOBJ** cLList_cCAMERA_GOBJPtr_Front(void* l);
cGOBJ* nGobjManager_LookupGOBJ_cObjectIdR(const cObjectId& id);
float Libc_Cosf(float);
}

extern "C" void cMap_UpdateModelPerspective(cMap* self, float timeStep)
{
    cCAMERA_GOBJ* camera = func_00159570(g_CameraObject) ? *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject) : 0;
    float angleZ = camera->zAngle;
    cVector cameraLocalTrans(D_004FF080, D_004FF084, D_004FF088, 1.0f);

    cMatrix invCameraMat;
    invCameraMat.Identity();
    cameraLocalTrans.Negate();
    invCameraMat.SetTranslation(cameraLocalTrans);
    cMatrix rotMat;
    rotMat.Identity();
    Rotate(&rotMat, cVector(0.0f, 0.0f, 1.0f, 0.0f), angleZ);
    angleZ = D_004FF070;
    Rotate(&rotMat, XAx(), angleZ);
    cVector cameraPos;
    cameraPos.x = 0.0f; cameraPos.y = 0.0f; cameraPos.z = 0.0f; cameraPos.w = 1.0f;

    cMatrix cameraOffsetMat;
    cameraOffsetMat.Identity2();
    {
        cGOBJ* currentObj = nGobjManager_LookupGOBJ_cObjectIdR(self->mCurrentTarget);
        if (!currentObj) {
            currentObj = g_LocalPlayer->obj;
            self->mCurrentTarget = currentObj->mObjectId;
        }
        self->mCurrentTargetPosition = currentObj->GetPosition();
    }
    if (self->mPreviousTarget == cObjectId(0)) {
        self->mPreviousTarget = self->mCurrentTarget;
        self->mPreviousTargetPosition = self->mCurrentTargetPosition;
    }
    if (self->mCurrentTarget != self->mPreviousTarget) {
        float t = self->mSeekTime += timeStep;
        if (t < 0.5f) {
            float c = Libc_Cosf(3.1415927f * (t / 0.5f));
            t = (2.0f - (1.0f + c)) / 2.0f;
            self->mCurrentTargetPosition = Lerp(self->mPreviousTargetPosition, self->mCurrentTargetPosition, t);
        } else {
            self->mPreviousTarget = self->mCurrentTarget;
            self->mPreviousTargetPosition = self->mCurrentTargetPosition;
            self->mSeekTime = 0.0f;
        }
    }
    cameraPos.Set0(self->mCurrentTargetPosition);
    cameraPos.Scale(D_0048B278);
    cameraPos.Negate();
    cameraOffsetMat.SetTranslation(cameraPos);
    self->mModelPerspective = MulMat(invCameraMat, rotMat) * cameraOffsetMat;
    {
        cMatrix tmp = self->mModelPerspective;
        float k = D_0048B278;
        tmp.m[0][0] *= k; tmp.m[0][1] *= k; tmp.m[0][2] *= k;
        tmp.m[1][0] *= k; tmp.m[1][1] *= k; tmp.m[1][2] *= k;
        tmp.m[2][0] *= k; tmp.m[2][1] *= k; tmp.m[2][2] *= k;
        D_0055A290 = tmp;
    }
}
static inline void merge_flush_func_0026D040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026D040 */

/* merge_units: begin func_0026D620 */
#pragma push /* merge_units */
#include "vc_copy.h"

#pragma cplusplus on
struct Q_26D620 { float a, b, c, d; Q_26D620& operator=(const Q_26D620& o) { Q_26D620* pd = this; const Q_26D620* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; } } __attribute__((aligned(16)));
struct R2_26D620 { char pad[0x68]; int x68; };
struct R_26D620 { char pad[8]; R2_26D620* x8; };
struct S_26D620 {
    int x0;
    int x4;
    int x8;
    char padC[0x54];
    int x60;
    char pad64[0xC];
    Q_26D620 x70;
    Q_26D620 x80;
    float x90;
    float x94;
};
extern "C" {
R_26D620* cHudTargetManager_GetObjectiveTarget(int a);
#if 0 /* merge_units */
void cMap_UpdateModelPerspective(S_26D620* s, float t);
#endif /* merge_units */
#define cMap_UpdateModelPerspective(a0, a1) (cMap_UpdateModelPerspective((cMap *)(a0), (a1))) /* merge_units */

void cInterface_NextFrame(int h, float t);
void cMap_NextFrame(S_26D620* s, float dt);
}
void cMap_NextFrame(S_26D620* s, float dt)
{
    if (s->x94 > 0.0f) {
        s->x94 -= dt;
        if (s->x94 <= 0.0f) {
            R_26D620* r = cHudTargetManager_GetObjectiveTarget(s->x0);
            if (r && r->x8) {
                s->x60 = r->x8->x68;
                s->x80 = s->x70;
                s->x90 = 0.0f;
            }
            s->x94 = 0.0f;
        }
    }
    cMap_UpdateModelPerspective(s, dt);
    cInterface_NextFrame(s->x8, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026D620(void) {}
#undef cMap_UpdateModelPerspective /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026D620 */

/* merge_units: begin func_0026D6D0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int c; } C_D6D0;
typedef struct { char pad[0x30]; C_D6D0* p30; } B_D6D0;
typedef struct { char pad[0x60]; int t60; int t64; char pad68[8]; __int128 q70; __int128 q80; char pad90[4]; int x94; } A_D6D0;
#if 0 /* merge_units */
extern B_D6D0* g_LocalPlayer;
#endif /* merge_units */
#define g_LocalPlayer (*(B_D6D0 **)&g_LocalPlayer) /* merge_units */

static inline int* ref_D6D0(C_D6D0* c) { return &c->c; }
#pragma push
#pragma peephole off
#pragma opt_propagation off
void cMap_StopSeekCountdown(A_D6D0* a) {
    __int128* s; __int128* d;
    a->x94 = 0;
    d = &a->q80; s = &a->q70;
    a->t64 = a->t60;
    *d = *s;
    { int* pc = &g_LocalPlayer->p30->c; a->t60 = *pc; }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026D6D0(void) {}
#undef g_LocalPlayer /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026D6D0 */

/* merge_units: begin func_0026D710 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "map_types.h"

void cMap_StartSeekCountdown(MapView* self) {
    self->unk94 = 0.25f;
}
static inline void merge_flush_func_0026D710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026D710 */

/* merge_units: begin func_0026D720 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Cam26D720 {
    char pad[0x100];
    char x100[0x504];
    unsigned char x604;
    char pad605[0xF];
    float x614;
    float x618;
    float x61C;
    float x620;
    float x624;
};

struct Self26D720 {
    char pad[8];
    int* x8;
    void* xC;
};

extern "C" {
extern Cam26D720* g_Hud;
extern float D_004FF030;
extern float D_004FF038;
extern float D_004FF040;
extern float D_004FF048;
extern float D_004FF050;
extern unsigned char D_004FF060;
void cIE_GOBJ_AnimateOff(void* p);
void cMap_ClearCallouts(Self26D720* self);
void cInterfaceModel_Activate(int a, int b, int c);
void cInfoBar_ClearPriorityMessages(void* p, int a, int b);
void* Gui_Canvas(void);
void GuiWidget_SendMessage(void* a, void* b, int c, int d, int e);
}

inline void SetA_26D720(Cam26D720* c, float a, float b) { c->x620 = a; c->x624 = b; }
inline void SetB_26D720(Cam26D720* c, float x, float y, float z) { c->x614 = x; c->x618 = y; c->x61C = z; }
extern "C" void cMap_Deactivate(Self26D720* self) {
    Cam26D720* cam;
    if (self->xC) {
        cIE_GOBJ_AnimateOff(self->xC);
        self->xC = 0;
    }
    cMap_ClearCallouts(self);
    cInterfaceModel_Activate(*self->x8, 0, 0);
    cam = g_Hud;
    SetA_26D720(cam, D_004FF030, D_004FF038);
    SetB_26D720(cam, D_004FF040, D_004FF048, D_004FF050);
    cam->x604 = 0;
    cInfoBar_ClearPriorityMessages(cam->x100, 2, 1);
    if (D_004FF060) {
        void* a = Gui_Canvas();
        GuiWidget_SendMessage(a, Gui_Canvas(), 0x11, 9, 0);
        D_004FF060 = 0;
    }
}
static inline void merge_flush_func_0026D720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026D720 */
