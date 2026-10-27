/*
 * SFOGame/Source/GuiScoresEquip: 7 files, 0035AEC0-0035BFB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0035AEC0 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
class W_35AEC0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad[0x10]; unsigned short a14;
};
struct S_35AEC0 { char pad[0x224]; int a224; float a228; };
struct Ev_35AEC0 { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
struct G_35AEC0 { char pad[0x6A8]; unsigned char b6A8; };
extern "C" {
extern char D_004BB4D8[];
extern char D_004BB530[];
extern char D_004A9870[];
extern G_35AEC0* g_Hud;
W_35AEC0* GuiWidget_FindChild_charP(void* self, char* name);
char* nGlobalization_GetString_charP(char* key);
void GuiTextWidget_SetText(W_35AEC0* w, char* text, int flags);
void GuiStartMenu_ReturnToMenu(S_35AEC0* o);
void GuiStartMenu_PopStartMenu(S_35AEC0* o);
int GuiScoresEquip_onInput(S_35AEC0* o, Ev_35AEC0* ev);
}
static inline W_35AEC0* cast_35AEC0(W_35AEC0* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
static inline unsigned char Down_35AEC0(Ev_35AEC0* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_35AEC0(Ev_35AEC0* e, int b) { unsigned char r = 0; if (Down_35AEC0(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_35AEC0(Ev_35AEC0* e, int b) { unsigned char r = 0; if (Btn_35AEC0(e, b) && e->b6 == 0) r = 1; return r; }

static inline bool Down2_35AEC0(Ev_35AEC0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_35AEC0(Ev_35AEC0* e, int b) { return Down2_35AEC0(e) && e->btn == b; }
static inline bool Plain2_35AEC0(Ev_35AEC0* e, int b) { return Btn2_35AEC0(e, b) && e->b6 == 0; }
static inline bool NoMod2_35AEC0(Ev_35AEC0* e) { return Down2_35AEC0(e) && e->b6 == 0; }
int GuiScoresEquip_onInput(S_35AEC0* o, Ev_35AEC0* ev)
{
    if (Plain_35AEC0(ev, 0x10)) {
        W_35AEC0* a;
        W_35AEC0* b;
        W_35AEC0* c;
        if (o->a224 == 0) {
            GuiStartMenu_ReturnToMenu(o);
            return 1;
        }
        o->a224 = 0;
        a = GuiWidget_FindChild_charP(o, D_004BB4D8);
        b = GuiWidget_FindChild_charP(o, "equipment_grp");
        if (a) a->a14 |= 2;
        if (b) b->a14 &= ~2;
        c = cast_35AEC0(GuiWidget_FindChild_charP(o, "button_equip_score"));
        if (c) {
            char* t = nGlobalization_GetString_charP("ScoresEquipScr0");
            GuiTextWidget_SetText(c, t ? t : D_004BB530, 0);
        }
        return 1;
    }
    if (Plain2_35AEC0(ev, 0x800) && g_Hud->b6A8) {
        GuiStartMenu_PopStartMenu(o);
        return 1;
    }
    if (Btn2_35AEC0(ev, 2)) {
        o->a228 += NoMod2_35AEC0(ev) ? -1.0f : 1.0f;
        return 1;
    }
    if (Btn2_35AEC0(ev, 1)) {
        o->a228 += NoMod2_35AEC0(ev) ? 1.0f : -1.0f;
        return 1;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035AEC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035AEC0 */

/* merge_units: begin func_0035B210 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_0035B210 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
struct B_0035B210 { char pad0[0x14]; unsigned short flags; };
struct S_0035B210 { char pad0[0x224]; int f224; };
extern "C" {
extern char D_004BB4E8[];
extern char D_004BB500[];
extern char D_004BB520[];
extern char D_004BB540[];
#if 0 /* merge_units */
void* GuiWidget_FindChild_charP(void* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((void *)GuiWidget_FindChild_charP((a0), (a1))) /* merge_units */


#if 0 /* merge_units */
void GuiTextWidget_SetText(W_0035B210* w, char* s, int a);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((W_35AEC0 *)(a0), (a1), (a2))) /* merge_units */


int GuiWidget_onMessage(void* self, int a, unsigned short b);
}
static inline W_0035B210* FindAs_0035B210(void* self, char* name, char* type)
{
    W_0035B210* w = (W_0035B210*)GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" int GuiScoresEquip_onMessage(S_0035B210* self, int a, unsigned short b)
{
    if (b == 2) {
        int on = self->f224 == 0;
        B_0035B210* b1;
        B_0035B210* b2;
        W_0035B210* w;
        self->f224 = on;
        b1 = (B_0035B210*)GuiWidget_FindChild_charP(self, D_004BB4D8);
        b2 = (B_0035B210*)GuiWidget_FindChild_charP(self, D_004BB4E8);
        if (b1) {
            if (!on)
                b1->flags |= 2;
            else
                b1->flags &= ~2;
        }
        if (b2) {
            if (on)
                b2->flags |= 2;
            else
                b2->flags &= ~2;
        }
        w = FindAs_0035B210(self, D_004BB500, D_004A9870);
        if (w) {
            char* t = nGlobalization_GetString_charP(on == 0 ? D_004BB520 : D_004BB540);
            GuiTextWidget_SetText(w, t ? t : D_004BB530, 0);
        }
        return 1;
    }
    return GuiWidget_onMessage(self, a, b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035B210(void) {}
#undef GuiWidget_FindChild_charP /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0035B210 */

/* merge_units: begin func_0035B390 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

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
struct VB : V { VB(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; } };
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
    char pad0[0x1A4];
    Mdl* m[4];
    Obj* obj;
    char pad1B8[0x1C0 - 0x1B8];
    float rx, ry, rz;
    char pad1CC[0x1D0 - 0x1CC];
    float f70, f74, f78;
    char pad1DC[0x1E0 - 0x1DC];
    V pos[4];
    char pad220[0x22C - 0x220];
    unsigned char b22C;
};
struct Fog { char pad[0x150]; float fogNear, fogFar, zNear, zFar; int ci[4]; float cf[4]; };

extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int g_DrawMode;
extern long long D_005392D8;
extern long long D_004BC1B0;
extern float D_00539170[4];
extern char D_004AB158[];
void XLib_ClearZBuffer(char* p);
void XLib_Restore(char* p);
float COS(float);
float SIN(float);
#if 0 /* merge_units */
void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
#endif /* merge_units */
#define cMatrix_Set_ColumnMajorForm(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) ((void)cMatrix_Set_ColumnMajorForm((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7), (a8), (a9))) /* merge_units */

#if 0 /* merge_units */
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
#endif /* merge_units */
#define cMatrix_ctor_cMatrixR(a0, a1) ((M *)cMatrix_ctor_cMatrixR((a0), (a1))) /* merge_units */

M* cMatrix_InvertRotTrans(M* m);
void cMatrix_ctor_void(TM* m);
void cMatrix_SetWithAxisAngle(TM* m, float x, float y, float z, float a);
void cMatrix_Rotate(M* a, TM* b);
Root* RootCollection_FindByKey(void* c, char* key);
void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(Root* r, Place* p);
Scr* Gui_Canvas(void);
void cMan_ManNextFrame(void* p, float t);
void cMotionManager_NextFrame(float t);
void GuiScoresEquip_ManRender(Self* self);
extern char D_004BB550[];
extern char g_GameState;
extern unsigned char g_IsMultiplayer;
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


extern "C" void GuiScoresEquip_ManRender(Self* self0)
{
    V e;
    M view;
    M r2;
    V p;
    M cm;
    int i;
    Root* r;
    int last;
    int j;
    Self* self = self0;
    int saved;
    XLib_ClearZBuffer(g_Video);
    saved = g_DrawMode;
    e.x = 0.0f; e.y = 5.0f; e.z = 1.5f; e.w = 1.0f;
    *STK(D_00538C64 + 1) = *STK(D_00538C64);
    g_DrawMode = 0x15;
    D_00538C64++;
    D_005392D8 = D_004BC1B0;
    {
        float ka; ka = 0.5235988f; Cam* c = &SLOT(D_00538C60)->cam; c->fov = ka; c->f2E4 = 1.0000001f; c->f2EC = 40.0f;
        c->b2F6 = 1;
        c->b2F4 = 0;
    }
    { float ey = self->f74; float ex = self->f70; float ez = self->f78; r2 = Euler(ey, ex, ez); }
    p = V(e.x, -e.y, e.z, 1.0f);
    Apply33(&p, &p, &r2);
    cm.m[0][0] = r2.m[0][0]; cm.m[0][1] = r2.m[0][1]; cm.m[0][2] = r2.m[0][2];
    cm.m[1][0] = r2.m[1][0]; cm.m[1][1] = r2.m[1][1]; cm.m[1][2] = r2.m[1][2];
    cm.m[2][0] = r2.m[2][0]; cm.m[2][1] = r2.m[2][1]; cm.m[2][2] = r2.m[2][2];
    cm.m[0][3] = r2.m[0][3]; cm.m[1][3] = r2.m[1][3]; cm.m[2][3] = r2.m[2][3];
    cm.r(3) = p;
    view = Inverse(cm);
    *STK(D_00538C64) = view;
    D_00538C68 = 1;
    self->obj->xf->SetPos(&cm.r(3));
    for (i = 3; i >= 0; i--) {
        M mm;
        V pp(self->pos[i]);
        UnitM(&mm);
        Rot(&mm, VA(1.0f, 0.0f, 0.0f, 0.0f), self->rx);
        Rot(&mm, V(0.0f, 1.0f, 0.0f, 0.0f), self->ry);
        Rot(&mm, V(0.0f, 0.0f, 1.0f, 0.0f), self->rz);
        mm.r(3) = pp;
        Mul33(&mm, &cm, &mm);
        if ((unsigned char)g_GameState == 2) {
            if (self->m[i]) {
                char key[4];
                bool done = false;
                unsigned int k;
                for (k = 0; k < 4u; k++) {
                    char c;
                    if (!D_004BB530[k]) done = true;
                    if (done) c = 0; else c = D_004BB530[k];
                    key[k] = c;
                }
                Root2* rr = &self->m[i]->r2EC0; r = RootCollection_FindByKey(rr->coll, key);
                SetPl(r, Place(mm));
                r->x160 = 0;
            }
        } else {
            if (self->m[i]) {
                char key[4];
                bool done = false;
                unsigned int k;
                for (k = 0; k < 4u; k++) {
                    char c;
                    if (!D_004BB550[k]) done = true;
                    if (done) c = 0; else c = D_004BB550[k];
                    key[k] = c;
                }
                Root2* rr = &self->m[i]->r2EC0; r = RootCollection_FindByKey(rr->coll, key);
                SetPl(r, Place(mm));
                r->x160 = 0;
            }
        }
    }
    {
        float t = Gui_Canvas()->t;
        last = -1;
        for (j = 0; j < 4; j++) {
            if (self->m[j]) {
                self->m[j]->Tick(t);
                cMan_ManNextFrame((char*)self->m[j] + 0x60, t);
                last = j;
            }
        }
        if (last != -1) {
            bool ph = !g_IsMultiplayer || self->b22C;
            self->b22C = 0;
            if (ph) cMotionManager_NextFrame(t);
            for (j = 0; j < 4; j++) {
                if (self->m[j]) {
                    { Mdl* m = self->m[j]; m->x38 = 2.0f; }
                    self->m[j]->Draw();
                }
            }
        }
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
#undef cMatrix_Set_ColumnMajorForm /* merge_units */
#undef cMatrix_ctor_cMatrixR /* merge_units */
static inline void merge_flush_func_0035B390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0035B390 */

/* merge_units: begin func_0035BF70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiScoresEquip.cc. Functions are named by address
 * until real names are known.
 */


extern char g_LightMgr[];
extern int cLightMan_BuildVisibleLightSubset(void* p);
extern int GuiWidget_onRender(void* self);

int GuiScoresEquip_onRender(void* self) {
    cLightMan_BuildVisibleLightSubset(g_LightMgr);
    return GuiWidget_onRender(self);
}
static inline void merge_flush_func_0035BF70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0035BF70 */

/* merge_units: begin func_0035BFB0 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
int strlen(const char *);

#pragma cplusplus on
struct W_35BFB0 { char pad0[0x14]; unsigned short flags; };
struct Ctl_35BFB0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsActive();
};
struct Player_35BFB0 {
    char pad0[0xC];
    unsigned int fC;
    char pad10[0x14 - 0x10];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Ctl_35BFB0* f58;
    char pad5C[4];
    char m60[4];
};
struct Item_35BFB0 { char pad0[0x40A]; short id; };
struct WDef_35BFB0 { char pad0[0x30]; unsigned char slot; char pad31[0x80 - 0x31]; char name[1]; };
struct Inv_35BFB0 { char pad0[0x2410]; Item_35BFB0* arr[13]; void Set(int i, Item_35BFB0* it) { arr[i] = it; } Item_35BFB0*& Slot(int i) { return arr[i]; } Item_35BFB0** PSlot(int i) { return &arr[i]; } };
struct Skel_35BFB0 {
    char pad0[0x60];
    Inv_35BFB0 inv;
    char pad24A4[0x2C3A - 0x24A4];
    signed char b2C3A;
    char pad2C3B[0x2C71 - 0x2C3B];
    unsigned char b2C71;
};
struct Agent_35BFB0 { char pad0[0xB70]; unsigned char bB70; };
struct Screen_35BFB0 {
    char pad0[0x48];
    W_35BFB0* f48[4];
    int f58;
    int f5C;
    unsigned char b60;
    W_35BFB0* rows[4][20];
    Skel_35BFB0* skel[4];
    float f1B4[5];
    float f1C8;
    char pad1CC[0x220 - 0x1CC];
    unsigned char f220[4];
    char pad224[0x228 - 0x224];
    float f228;
    char pad22C[0x230 - 0x22C];
    W_35BFB0* f230[4][2];
};
struct Top_35BFB0 { char pad0[8]; void* f8; };
struct Stack_35BFB0 { char pad0[0x2C]; Top_35BFB0* f2C; };
extern "C" {
extern char D_004BB558[];
extern char D_004BB568[];
extern char D_004BB578[];
extern char D_004BB580[];
extern char D_004BB588[];
extern void* g_WeaponDatabase;
extern char D_00533790[];
#if 0 /* merge_units */
Stack_35BFB0* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Stack_35BFB0 *)Gui_Canvas()) /* merge_units */

Player_35BFB0* cNetObj_GetPlayer(int i);
void cSKM_GOBJ_CloneMan(Skel_35BFB0* s, void* p);
WDef_35BFB0* cWeaponDB_GetEntry(void* table, int id);
int cAgentData_GetStat(Agent_35BFB0* a, int stat);
char Libc_Toupper(char c);
Agent_35BFB0* cHuman_GetAgentData(Player_35BFB0* p, unsigned char* flag);
char* cAgentData_GetUserName(Agent_35BFB0* a);
#if 0 /* merge_units */
void GuiTextWidget_SetText(W_35BFB0* w, char* text, int flags);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((W_35AEC0 *)(a0), (a1), (a2))) /* merge_units */

void GuiWidget_SendMessage(Screen_35BFB0* s, W_35BFB0* w, int a, int b, int c);
void GuiWidget_onAdvanceTime(Screen_35BFB0* s, float dt);
float cDME_GetConnectionStatus(int i);
}

static inline int Slot_35BFB0(Player_35BFB0* p) { return ((p->fC & 0x7F000000) >> 24) - 1; }

static inline void SetLoc_35BFB0(W_35BFB0* w, char* key)
{
    char* t = nGlobalization_GetString_charP(key);
    if (t)
        GuiTextWidget_SetText(w, t, 0);
    else
        GuiTextWidget_SetText(w, key, 0);
}

static inline void ShowItem_35BFB0(W_35BFB0* w, Item_35BFB0* it)
{
    if (it) {
        WDef_35BFB0* d = cWeaponDB_GetEntry(g_WeaponDatabase, it->id);
        SetLoc_35BFB0(w, d->name);
    } else {
        GuiTextWidget_SetText(w, D_004BB530, 0);
    }
}

#define SHOW_ITEM(W, IT) \
    if (IT) { \
        WDef_35BFB0* d = cWeaponDB_GetEntry(g_WeaponDatabase, (IT)->id); \
        char* t = nGlobalization_GetString_charP(d->name); \
        if (t) \
            GuiTextWidget_SetText(W, t, 0); \
        else \
            GuiTextWidget_SetText(W, d->name, 0); \
    } else { \
        GuiTextWidget_SetText(W, D_004BB530, 0); \
    }

static const float kPi_35BFB0 = 3.1415927f;
extern "C" void GuiScoresEquip_onAdvanceTime(Screen_35BFB0* s, float dt)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (s->rows[i][0]) {
            GuiTextWidget_SetText(s->rows[i][0], D_004BB530, 0);
            GuiTextWidget_SetText(s->rows[i][1], D_004BB530, 0);
            GuiTextWidget_SetText(s->rows[i][13], D_004BB530, 0);
            GuiTextWidget_SetText(s->rows[i][14], D_004BB530, 0);
        }
    }
    {
    int n;
    for (n = 0; n < 4; n++) {
        Player_35BFB0* p = cNetObj_GetPlayer(n);
        if (p) {
            int slot = Slot_35BFB0(p);
            Agent_35BFB0* a;
            if (slot < 0) slot = 0;
            cSKM_GOBJ_CloneMan(s->skel[slot], p->m60);
            s->skel[slot]->b2C71 = 1;
            if (!s->f220[slot]) s->f220[slot] = 1;
            a = cHuman_GetAgentData(p, &s->f220[slot]);
            if (a->bB70) {
                char buf[0x10];
                char key[0x20];
                unsigned int k;
                int d;
                GuiTextWidget_SetText(s->rows[slot][0], cAgentData_GetUserName(a), 0);
                GuiTextWidget_SetText(s->rows[slot][13], cAgentData_GetUserName(a), 0);
                sprintf(key, D_004BB558, slot);
                sprintf(D_00533790, D_004BB568, 0x11, nGlobalization_GetString_charP(key), 0x10);
                for (k = 0; k < strlen(D_00533790); k++)
                    D_00533790[k] = Libc_Toupper(D_00533790[k]);
                GuiTextWidget_SetText(s->rows[slot][1], D_00533790, 0);
                GuiTextWidget_SetText(s->rows[slot][14], D_00533790, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x1B));
                GuiTextWidget_SetText(s->rows[slot][2], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x1C));
                GuiTextWidget_SetText(s->rows[slot][3], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x14));
                GuiTextWidget_SetText(s->rows[slot][4], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x13));
                GuiTextWidget_SetText(s->rows[slot][5], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x16));
                GuiTextWidget_SetText(s->rows[slot][6], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x12));
                GuiTextWidget_SetText(s->rows[slot][7], buf, 0);
                d = cAgentData_GetStat(a, 0x1B);
                if (d == 0) d = 1;
                sprintf(buf, D_004BB580, cAgentData_GetStat(a, 0x1C) * 100 / d);
                GuiTextWidget_SetText(s->rows[slot][9], buf, 0);
                d = cAgentData_GetStat(a, 0x1D);
                if (d == 0) d = 1;
                sprintf(buf, D_004BB580, cAgentData_GetStat(a, 0x1E) * 100 / d);
                GuiTextWidget_SetText(s->rows[slot][8], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x18));
                GuiTextWidget_SetText(s->rows[slot][10], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x19));
                GuiTextWidget_SetText(s->rows[slot][11], buf, 0);
                sprintf(buf, D_004BB578, cAgentData_GetStat(a, 0x1A));
                GuiTextWidget_SetText(s->rows[slot][12], buf, 0);
            } else {
                int j;
                GuiTextWidget_SetText(s->rows[slot][0], D_004BB530, 0);
                for (j = 2; j < 13; j++) GuiTextWidget_SetText(s->rows[slot][j], D_004BB588, 0);
                for (j = 15; j < 20; j++) GuiTextWidget_SetText(s->rows[slot][j], D_004BB530, 0);
            }
            if (s->skel[slot]->inv.arr[0]) {
                WDef_35BFB0* d = cWeaponDB_GetEntry(g_WeaponDatabase, s->skel[slot]->inv.arr[0]->id);
                s->skel[slot]->inv.Slot(d->slot) = s->skel[slot]->inv.Slot(0);
            }
            SHOW_ITEM(s->rows[slot][15], s->skel[slot]->inv.arr[3])
            SHOW_ITEM(s->rows[slot][16], s->skel[slot]->inv.arr[2])
            SHOW_ITEM(s->rows[slot][17], s->skel[slot]->inv.arr[5])
            SHOW_ITEM(s->rows[slot][18], s->skel[slot]->inv.arr[8])
            SHOW_ITEM(s->rows[slot][19], s->skel[slot]->inv.arr[9])
            if (s->skel[slot]->inv.arr[0]) {
                WDef_35BFB0* d = cWeaponDB_GetEntry(g_WeaponDatabase, s->skel[slot]->inv.arr[0]->id);
                s->skel[slot]->inv.Slot(d->slot) = 0;
            }
        } else {
            s->skel[n]->b2C3A = -1;
            if (s->rows[n][0]) {
                GuiTextWidget_SetText(s->rows[n][0], D_004BB530, 0);
                for (i = 2; i < 13; i++) GuiTextWidget_SetText(s->rows[n][i], D_004BB588, 0);
                for (i = 15; i < 20; i++) GuiTextWidget_SetText(s->rows[n][i], D_004BB530, 0);
            }
        }
        if (s->f230[n][0]) {
            if (p) s->f230[n][0]->flags |= 2;
            else s->f230[n][0]->flags &= ~2;
        }
        if (s->f230[n][1]) {
            if (p) s->f230[n][1]->flags |= 2;
            else s->f230[n][1]->flags &= ~2;
        }
    }
    }
    if (s->b60) {
        int m;
        for (m = 0; m < 4; m++) {
            if (s->f48[m]) {
                Player_35BFB0* p = cNetObj_GetPlayer(m);
                if (p) {
                    if (p->b14) {
                        s->f48[m]->flags &= ~2;
                    } else {
                        int idx;
                        s->f48[m]->flags |= 2;
                        if (g_IsMultiplayer) {
                            bool ok = false;
                            if (p->f58 && p->f58->IsActive()) ok = true;
                            if (ok) idx = Slot_35BFB0(p);
                            else idx = -1;
                        } else {
                            idx = 0;
                        }
                        GuiWidget_SendMessage(s, s->f48[m], 0xB, s->f58 + (int)((float)(s->f5C - s->f58) * (1.0f - cDME_GetConnectionStatus(idx))), 0);
                    }
                } else {
                    s->f48[m]->flags &= ~2;
                }
            }
        }
    }
    if (Gui_Canvas()->f2C->f8 != s) {
        s->f228 = 0.0f;
    } else {
        float k = kPi_35BFB0 * (dt / 30.0f); s->f1C8 += k * s->f228;
        if (s->f1C8 > 3.1415927f)
            s->f1C8 -= 6.2831855f;
        else if (s->f1C8 < -3.1415927f)
            s->f1C8 += 6.2831855f;
    }
    GuiWidget_onAdvanceTime(s, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035BFB0(void) {}
#undef Gui_Canvas /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0035BFB0 */

/* merge_units: begin func_0035CB30 */
#pragma push /* merge_units */
extern char* nGlobalization_GetString_charP(char* key);
#if 0 /* merge_units */
extern char Libc_Toupper(int c);
#endif /* merge_units */
#define Libc_Toupper(a0) (Libc_Toupper((char)(a0))) /* merge_units */


char* GetCodename(int n)
{
    char buf[32];
    unsigned int i;
    sprintf(buf, D_004BB558, n);
    sprintf(D_00533790, D_004BB568, 0x11, nGlobalization_GetString_charP(buf), 0x10);
    for (i = 0; i < strlen(D_00533790); i++) D_00533790[i] = Libc_Toupper(D_00533790[i]);
    return D_00533790;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035CB30(void) {}
#undef Libc_Toupper /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0035CB30 */

/* merge_units: begin func_0035CBF0 */
#pragma push /* merge_units */
#pragma cplusplus on
class W35CBF0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad[0x10]; unsigned short a14;
};
struct S35CBF0 { char pad[0x224]; int a224; char pad228[4]; unsigned char a22C; };
extern "C" {
void GuiWidget_onWake(S35CBF0* o);
#if 0 /* merge_units */
W35CBF0* GuiWidget_FindChild_charP(void* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((W35CBF0 *)GuiWidget_FindChild_charP((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void GuiTextWidget_SetText(W35CBF0* w, char* text, int flags);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((W_35AEC0 *)(a0), (a1), (a2))) /* merge_units */


void GuiScoresEquip_onWake(S35CBF0* o);
}
static inline W35CBF0* cast35CBF0(W35CBF0* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
void GuiScoresEquip_onWake(S35CBF0* o)
{
    W35CBF0* a;
    W35CBF0* b;
    W35CBF0* c;
    GuiWidget_onWake(o);
    o->a224 = 0;
    a = GuiWidget_FindChild_charP(o, D_004BB4D8);
    b = GuiWidget_FindChild_charP(o, D_004BB4E8);
    if (a) a->a14 |= 2;
    if (b) b->a14 &= ~2;
    c = cast35CBF0(GuiWidget_FindChild_charP(o, D_004BB500));
    if (c) {
        char* t = nGlobalization_GetString_charP(D_004BB520);
        GuiTextWidget_SetText(c, t ? t : D_004BB530, 0);
    }
    o->a22C = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035CBF0(void) {}
#undef GuiWidget_FindChild_charP /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0035CBF0 */
