/*
 * SFOGame/Source/GuiAgentInfo: 6 files, 00361AA0-00362850
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00361AA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct W_361AA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x5C - 0x16];
    int f5C;
};
typedef struct {
    char pad[0x100]; W_361AA0* f100; W_361AA0* f104; W_361AA0* f108; W_361AA0* f10C; W_361AA0* f110;
    W_361AA0* f114; W_361AA0* f118; W_361AA0* f11C; W_361AA0* f120;
} O_361AA0;
extern "C" {
extern char D_004BB978[]; extern char D_004BB988[]; extern char D_004BB998[]; extern char D_004BB9A8[];
extern char D_004BB9B8[]; extern char D_004BB9C8[];extern char D_004A7520[]; extern char D_004ABAB0[]; extern char D_004A9870[]; extern char D_004B88F0[]; extern char D_004BBBB0[];
extern void* D_004FFC04;
void GuiLobbyScreen_onAdd(O_361AA0* o);
W_361AA0* GuiWidget_FindChild_charP(void* o, char* name);
void func_0041C0D0(W_361AA0* w, int v);
void GuiArrayWidget_SetRowHeight(W_361AA0* w, int v);
void FrontEnd_GetCharacterData(void* p);
void GuiAgentInfo_onAdd(O_361AA0* o);
}
static inline W_361AA0* Cast_361AA0(W_361AA0* w, void* t) { return w && w->IsA(t) ? w : 0; }

void GuiAgentInfo_onAdd(O_361AA0* o)
{
    GuiLobbyScreen_onAdd(o);
    o->f100 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB978), D_004A7520);
    o->f104 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB988), D_004A7520);
    o->f108 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB998), D_004A7520);
    if (o->f108) func_0041C0D0(o->f108, 1);
    o->f10C = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB9A8), D_004ABAB0);
    o->f110 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB9B8), D_004ABAB0);
    o->f114 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB9C8), D_004A9870);
    o->f118 = Cast_361AA0(GuiWidget_FindChild_charP(o, "02"), D_004A9870);
    o->f11C = Cast_361AA0(GuiWidget_FindChild_charP(o, "thumbnail"), D_004B88F0);
    o->f120 = Cast_361AA0(GuiWidget_FindChild_charP(o, "playercharacter"), D_004BBBB0);
    o->f10C->flags &= ~0x80;
    o->f110->flags &= ~0x80;
    GuiArrayWidget_SetRowHeight(o->f110, o->f110->f5C - 2);
    GuiArrayWidget_SetRowHeight(o->f10C, o->f10C->f5C - 4);
    FrontEnd_GetCharacterData(D_004FFC04);
}
static inline void merge_flush_func_00361AA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00361AA0 */

/* merge_units: begin func_00361D90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo constructor (vtable GuiAgentInfo_vtable); derives from the screen base
 * built by GuiLobbyScreen_ctor (GuiLobbyScreen.cc range).
 */

#include "loose03_types.h"

extern char GuiAgentInfo_vtable[];       /* GuiAgentInfo vtable */
extern int cString_ctor_void(void*);
extern int GuiLobbyScreen_ctor(GuiAgentInfo*);

/* GuiAgentInfo constructor. */
GuiAgentInfo* GuiAgentInfo_ctor(GuiAgentInfo* self) {
    GuiAgentInfoMember88* member;

    GuiLobbyScreen_ctor(self);
    member = &self->unk88;
    self->base.vtable = GuiAgentInfo_vtable;
    cString_ctor_void(member->unk30);
    cString_ctor_void(member->unk3C);
    self->base.screenId = 8;
    self->unkFC = 0;
    return self;
}
static inline void merge_flush_func_00361D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00361D90 */

/* merge_units: begin func_00361DF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: string members at +0x3C and +0x30. */
extern "C" {
void operator_delete(void* allocation);
void* String_Dtor(void* self, short deleteFlag);
}
extern "C" void* GuiAgentInfo_AgentInfo_dtor(void* self, short deleteFlag)
{
    if (self) {
        char* a = (char*)self + 0x3C;
        if (a)
            String_Dtor(a, 0);
        char* b = (char*)self + 0x30;
        if (b)
            String_Dtor(b, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00361DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00361DF0 */

/* merge_units: begin func_00361E70 */
#pragma push /* merge_units */
/* GuiAgentDisplay_onRender: figure-preview draw callback (GuiWidget_onRender, camera fov from self, model placement, appearance refresh); sibling of GuiAgentModify_ManRender. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"

struct M;
extern "C" void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
extern "C" M* cMatrix_ctor_cMatrixR(M* d, const M* s);
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M* p) { cMatrix_ctor_cMatrixR(this, p); void* xx = this; }
    M(float a, float b, float c, float d, float e, float f, float g, float h, float i) { cMatrix_Set_ColumnMajorForm(this, a, b, c, d, e, f, g, h, i); }
    V& r(int i) { return *(V*)m[i]; }
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& operator=(const M& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct TM { M m; };
struct VA : V { VA(float ax, float ay, float az, float aw) { void* xx = this; x = ax; y = ay; z = az; w = aw; } };
struct Place { V q; V p; Place(M& m); };

struct Cam {
    float col[4]; char pad10[0xF0 - 0x10];
    float f2E0, f2E4, f2E8, f2EC, fov;
    unsigned char b2F4, b2F5, b2F6;
};
struct Slot { char pad[0x1F0]; Cam cam; };

class Xf {
public:
    VPAD2(a) virtual void v2(); virtual void SetPos(V* p);
};
struct Obj { char pad[0x50]; Xf* xf; };
struct Coll { char pad[1]; };
struct Root { char pad[0x160]; int x160; };
struct Root2 { char pad[0xB0]; char coll[4]; };
class Mdl {
public:
    VPAD16(a) virtual void Tick(float t); VPAD2(b) virtual void v19(); virtual void Draw();
    char pad4[0x34]; float x38; char pad3c[0x2EC0-0x3C]; Root2 r2EC0;
};
struct Scr { char pad[0x64]; float t; };

struct Self {
    char pad0[0x48];
    Mdl* mdl;
    char pad4C[0x64 - 0x4C];
    float fov;
    float ex, ey, ez;
    float rx, ry, rz;
    float f70, f74, f78;
    char pad8C[0x90 - 0x8C];
    Obj* obj;
};

extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int g_DrawMode;
extern long long D_005392D8;
extern long long D_004BC1B0;
extern float D_00539170[4];
extern char D_004BB868[];
void XLib_ClearZBuffer(char* p);
void XLib_Restore(char* p);
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_InvertRotTrans(M* m);
void cMatrix_ctor_void(TM* m);
void cMatrix_SetWithAxisAngle(TM* m, float x, float y, float z, float a);
void cMatrix_Rotate(M* a, TM* b);
Root* RootCollection_FindByKey(void* c, char* key);
void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(Root* r, Place* p);
Scr* Gui_Canvas(void);
void cMan_ManNextFrame(void* p, float t);
void cMotionManager_NextFrame(float t);
void GuiWidget_onRender(Self* self); unsigned char SKL_FindRace(void* a); int SKL_FindSex(void* a); void GuiAgentDisplay_onRender(Self* self);
}

#define SLOT(i) ((Slot*)(g_Video + (i) * 0x110))
#define STK(i) ((M*)(g_Video + 0xA80 + (i) * 0x40))

static inline void UnitM(M* m) { M* p = m; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void Apply33(V* out, const V* v, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(out), "r"(m), "r"(v) : "memory"); }
static inline void Mul33(M* out, const M* a, const M* b) { __asm__ volatile("lqc2 vf4, 0x0(%2); lqc2 vf5, 0x10(%2); lqc2 vf6, 0x20(%2); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; vmulax.xyz ACC, vf4, vf9x; vmadday.xyz ACC, vf5, vf9y; vmaddz.xyz vf9, vf6, vf9z; vmulax.xyz ACC, vf4, vf10x; vmadday.xyz ACC, vf5, vf10y; vmaddz.xyz vf10, vf6, vf10z; vmulax.xyz ACC, vf4, vf11x; vmadday.xyz ACC, vf5, vf11y; vmaddz.xyz vf11, vf6, vf11z; sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0); sqc2 vf11, 0x30(%0)" : : "r"(out), "r"(b), "r"(a) : "memory"); }

static inline void MtxToQuat(void* m, void* out) {
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(out)
        .set reorder
    }
}

static inline M Euler(float ey, float ex, float ez)
{
    float cy = COS(ey);
    float sy = SIN(ey);
    float cx = COS(ex);
    float sx = SIN(ex);
    float cz = COS(ez);
    float sz = SIN(ez);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    float a1 = czcy - szsy * sx;
    float a2 = -sz * cx;
    float a3 = czsy + szcy * sx;
    float a4 = szcy + czsy * sx;
    float a5 = cz * cx;
    float a6 = szsy - czcy * sx;
    float a7 = -cx * sy;
    float a8 = sx;
    float a9 = cx * cy;
    return M(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

static inline M Inverse(const M& m) { M t; return M(cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&t, &m))); }

static inline void Rot2(M* m, const V& ax, float a)
{
    TM t;
    cMatrix_ctor_void(&t);
    cMatrix_SetWithAxisAngle(&t, ax.x, ax.y, ax.z, a);
    cMatrix_Rotate(m, &t);
}

inline Place::Place(M& m) { MtxToQuat(&m, &q); p = m.r(3); }
static inline void Rot(M* m, const V& ax, float a) { Rot2(m, ax, a); }
static inline void SetPl(Root* r, const Place& pl) { cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(r, (Place*)&pl); }


extern "C" void GuiAgentDisplay_onRender(Self* self)
{
    int saved;
    GuiWidget_onRender(self);
    XLib_ClearZBuffer(g_Video);
    saved = g_DrawMode;
    *STK(D_00538C64 + 1) = *STK(D_00538C64);
    g_DrawMode = 0x15;
    D_00538C64++;
    D_005392D8 = D_004BC1B0;
    {
        Cam* c = &SLOT(D_00538C60)->cam;
        c->fov = self->fov;
        c->f2E4 = 2.0f;
        c->f2EC = 15000.0f;
        c->b2F6 = 1;
        c->b2F4 = 0;
    }
    float ey = self->f74; float ex = self->f70; float ez = self->f78; M r2 = Euler(ey, ex, ez);
    V p(self->ex, -self->ey, self->ez, 1.0f);
    Apply33(&p, &p, &r2);
    M cm;
    cm.m[0][0] = r2.m[0][0]; cm.m[0][1] = r2.m[0][1]; cm.m[0][2] = r2.m[0][2];
    cm.m[1][0] = r2.m[1][0]; cm.m[1][1] = r2.m[1][1]; cm.m[1][2] = r2.m[1][2];
    cm.m[2][0] = r2.m[2][0]; cm.m[2][1] = r2.m[2][1]; cm.m[2][2] = r2.m[2][2];
    cm.m[0][3] = r2.m[0][3]; cm.m[1][3] = r2.m[1][3]; cm.m[2][3] = r2.m[2][3];
    cm.r(3) = p;
    M view = Inverse(cm);
    *STK(D_00538C64) = view;
    D_00538C68 = 1;
    self->obj->xf->SetPos(&cm.r(3));
    M mm;
    V pp(0.0f, 0.0f, -3.0f, 1.0f);
    UnitM(&mm);
    Rot(&mm, VA(1.0f, 0.0f, 0.0f, 0.0f), self->rx);
    Rot(&mm, V(0.0f, 1.0f, 0.0f, 0.0f), self->ry);
    Rot(&mm, V(0.0f, 0.0f, 1.0f, 0.0f), self->rz);
    mm.r(3) = pp;
    Mul33(&mm, &cm, &mm);
    {
        char key[4];
        bool done = false;
        unsigned int k;
        for (k = 0; k < 4u; k++) {
            char c;
            if (!D_004BB868[k]) done = true;
            if (done) c = 0; else c = D_004BB868[k];
            key[k] = c;
        }
        Root2* rr = &self->mdl->r2EC0; Root* r = RootCollection_FindByKey(rr->coll, key);
        SetPl(r, Place(mm));
        r->x160 = 0;
    }    {
        float t = Gui_Canvas()->t;
        self->mdl->Tick(t);
        cMan_ManNextFrame((char*)self->mdl + 0x60, t);
        cMotionManager_NextFrame(t);
        { char* a = (char*)self->mdl + 0x60; a[0x2C0D] = SKL_FindRace(a + 0x40); }
        { char* a = (char*)self->mdl + 0x60; SKL_FindSex(a + 0x40); }
        { Mdl* m = self->mdl; m->x38 = 2.0f; }
        self->mdl->Draw();
    }
    XLib_Restore(g_Video);
    {
        Slot* s = SLOT(D_00538C60);
        s->cam.f2E0 = 0;
        s->cam.f2E8 = 1000.0f;
        s->cam.b2F6 = 1;
        s->cam.b2F4 = 1;
        {
            float* v = D_00539170;
            s->cam.col[0] = v[0];
            s->cam.col[1] = v[1];
            s->cam.col[2] = v[2];
            s->cam.col[3] = v[3];
        }
        s->cam.b2F5 = 1;
        s->cam.b2F6 = 1;
    }
    D_00538C68 = 1;
    g_DrawMode = saved;
    D_00538C64--;
}
static inline void merge_flush_func_00361E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00361E70 */

/* merge_units: begin func_003626B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } Plc;
typedef struct { int w[1]; } It;
static inline void QRot(V4* v, V4* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3(V4* s, V4* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct Nd { char pad[0x50]; Plc p; char pad70[0x30]; unsigned char bA0; char padA1[0xF]; int bB0; };
extern "C" {
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(Nd* n);
Plc* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
void cQuatVec_opAssign(Plc* d, Plc* s);
void cQuatVec_InvertAssumingUnitQuat(Plc* p);
void cQuaternion_ctor_void(V4* q);
void cQuaternion_VU0Multiply(V4* a, V4* b, V4* c);
void cQuaternion_ctor_cQuaternionR(V4* d, V4* s);
int cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(Nd* n);
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(Nd* n);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(It* out, void* vec);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(It* out, void* vec);
bool cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(It* a, It* b);
Nd** cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(It* it);
void cSkaAnimAnchor_TreeNode_TellNeedToUpdate(Nd* n);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(It* it);
}
static inline void Cp(Plc* d, Plc* s) { QC(&d->rot, &s->rot); QC(&d->pos, &s->pos); }
extern "C" void Root_SetWorldPlacement_3626B0(Nd* self, Plc* src)
{
    { Plc* d = &self->p; QC(&d->rot, &src->rot); QC(&d->pos, &src->pos); }
    if (self->bB0) {
        Plc inv;
        V4 r;
        V4 m;
        Plc* p;
        Plc* ip;
        cQuatVec_opAssign(&inv, cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self)));
        cQuatVec_InvertAssumingUnitQuat(&inv);
        ip = &inv;
        p = &self->p;
        cQuaternion_ctor_void(&m);
        cQuaternion_VU0Multiply(&m, &ip->rot, &p->rot);
        cQuaternion_ctor_cQuaternionR(&r, &m);
        { void* xx = &r; /* dead on purpose: retail keeps this addiu */ }
        QC(&p->rot, &r);
        V4* v = &p->pos;
        QRot(v, &ip->rot);
        VAdd3(&ip->pos, &p->pos);
    }
    self->bA0 = 1;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(self)) {
        It it, end;
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(&it, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self));
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(&end, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self));
        for (; cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(&it, &end); cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(&it))
            cSkaAnimAnchor_TreeNode_TellNeedToUpdate(*cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(&it));
    }
}
static inline void merge_flush_func_003626B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003626B0 */

/* merge_units: begin func_00362850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


int func_00362850(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_00362870(Iter* it) {
    it->p++;
    return it;
}
static inline void merge_flush_func_00362850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00362850 */
