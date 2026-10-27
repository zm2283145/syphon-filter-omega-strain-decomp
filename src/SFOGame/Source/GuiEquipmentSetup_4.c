/*
 * SFOGame/Source/GuiEquipmentSetup: 4 files, 002A1D20-002A2EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A1D20 */
#pragma push /* merge_units */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

#pragma cplusplus on
struct Ev_002A1D20 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Ui_002A1D20 { char pad[0x20]; void* f20; };
struct S_002A1D20 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16();
    virtual void* Next(void* cur, int dir);
    char pad4[0xD8]; float fDC;
};
extern "C" {
extern void* D_004FFC04;
Ui_002A1D20* Gui_Canvas(void);
void GuiWidget_SendMessage(void* a, void* b, int c, int d, int e);
void GuiCanvas_SetFocus(void* ui, void* w);
char* nGlobalization_GetString_charP(char* key);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, S_002A1D20* d, int e);
}
static inline unsigned char Down_002A1D20(Ev_002A1D20* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_002A1D20(Ev_002A1D20* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_002A1D20(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_002A1D20(Ev_002A1D20* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_002A1D20(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int GuiEquipmentSetup_onInput(S_002A1D20* self, Ev_002A1D20* ev)
{
    if (Press_002A1D20(ev, 0x1000))
        return 1;
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x4000 && ev->f6 == 0;
        if (b)
            return 1;
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x8000 && ev->f6 == 0;
        if (b) {
            void* cur = Gui_Canvas()->f20;
            GuiWidget_SendMessage(cur, Gui_Canvas(), 0x10, 0, 0);
            {
                Ui_002A1D20* a = Gui_Canvas();
                Ui_002A1D20* u = Gui_Canvas();
                GuiCanvas_SetFocus(u, self->Next(a->f20, 1));
            }
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x2000 && ev->f6 == 0;
        if (b) {
            void* cur = Gui_Canvas()->f20;
            GuiWidget_SendMessage(cur, Gui_Canvas(), 0x10, 0, 0);
            {
                Ui_002A1D20* a = Gui_Canvas();
                Ui_002A1D20* u = Gui_Canvas();
                GuiCanvas_SetFocus(u, self->Next(a->f20, 1));
            }
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x10 && ev->f6 == 0;
        if (b) {
            char* a = nGlobalization_GetString_charP("QuitTitle");
            char* c = nGlobalization_GetString_charP("QuitMessage");
            if (a && c)
                cGameFrontEnd_PushMessageBox(D_004FFC04, 5, a, c, self, 0);
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 2;
        if (b) {
            bool s = ev->type == 1 && ev->f2 == 0 && ev->f6 == 0;
            self->fDC += s ? -1.0f : 1.0f;
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 1;
        if (b) {
            bool s = ev->type == 1 && ev->f2 == 0 && ev->f6 == 0;
            self->fDC += s ? 1.0f : -1.0f;
            return 1;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A1D20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A1D20 */

/* merge_units: begin func_002A2170 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_002A2170 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char name[4];
};
struct St_002A2170 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26();
    virtual void SetState(int s); virtual unsigned char GetState();
};
struct Net_002A2170 { char pad[0x30]; St_002A2170* p30; };
struct G_002A2170 { char pad[0x26A0]; unsigned char b26A0; };
struct S_002A2170 { char pad0[0xC0]; int fC0; char padC4[0x14]; unsigned char bD8; };
extern "C" {
extern char D_004AB0B0[];
extern char D_004A9870[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern Net_002A2170* g_LocalPlayer;
extern unsigned char g_LoadoutPending;
extern char D_0055A300[];
extern unsigned char D_005723F8;
extern unsigned char D_00572400;
extern char g_Game[];
void func_002A3A10(S_002A2170* self);
char* std_basic_string_char_char_traits_char_c_str(void* s);
void cJoystick_Poll(void* p);
void cDME_SendPlayGame(void);
#if 0 /* merge_units */
void* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((void *)Gui_Canvas()) /* merge_units */


void GuiCanvas_Transition(void* ui, S_002A2170* self, void* pg);
G_002A2170* cDME_GetLobby(void);
void GuiTextWidget_SetText(void* w, char* s, int a);
void* Gui_Manager(void);
void* GuiManager_OpenGui(void* a, char* b, char* c);
void cGameSystem_Restart(void* a, int b);
int GuiWidget_onMessage(S_002A2170* self, W_002A2170* w, int msg, int sub, char* text);
}
extern "C" int GuiEquipmentSetup_onMessage(S_002A2170* self, W_002A2170* w, int msg, int sub, char* text)
{
    unsigned short m;
    func_002A3A10(self);
    m = msg;
    if (m == 2) {
        char* n = std_basic_string_char_char_traits_char_c_str(w->name);
        if (!strcmp(n, D_004AB0B0)) {
            if (g_IsMultiplayer) {
                int ok;
                w = (w && w->IsA(D_004A9870)) ? w : 0;
                if (g_IsMultiplayer)
                    ok = D_005721C0;
                else
                    ok = 1;
                if (ok) {
                    if (g_LocalPlayer->p30->GetState() == 3) {
                        if (self->fC0 == 2) {
                            g_LoadoutPending = 0;
                            cJoystick_Poll(D_0055A300);
                            cDME_SendPlayGame();
                            GuiCanvas_Transition(Gui_Canvas(), self, 0);
                            g_LocalPlayer->p30->SetState(4);
                        }
                    } else if (self->fC0 > 0) {
                        g_LocalPlayer->p30->SetState(3);
                        D_005723F8 = 1;
                        if (!self->bD8) {
                            G_002A2170* g;
                            self->bD8 = 1;
                            g = cDME_GetLobby();
                            if (g)
                                g->b26A0 = 1;
                        }
                    }
                } else if (D_00572400) {
                    g_LoadoutPending = 0;
                    cJoystick_Poll(D_0055A300);
                    GuiCanvas_Transition(Gui_Canvas(), self, 0);
                    g_LocalPlayer->p30->SetState(4);
                } else if (g_LocalPlayer->p30->GetState() == 1) {
                    char* t;
                    g_LocalPlayer->p30->SetState(2);
                    t = nGlobalization_GetString_charP("EQS_WAITING");
                    if (t)
                        GuiTextWidget_SetText(w, t, 0);
                } else {
                    char* t;
                    g_LocalPlayer->p30->SetState(1);
                    t = nGlobalization_GetString_charP("EQS_EQUIP");
                    if (t)
                        GuiTextWidget_SetText(w, t, 0);
                }
            } else {
                g_LoadoutPending = 0;
                cJoystick_Poll(D_0055A300);
                GuiCanvas_Transition(Gui_Canvas(), self, 0);
            }
            return 1;
        }
        if (!strcmp(n, "equipbutton")) {
            void* pg = GuiManager_OpenGui(Gui_Manager(), "GuiEquipmentModify", "eqmodify");
            g_LocalPlayer->p30->SetState(1);
            GuiCanvas_Transition(Gui_Canvas(), self, pg);
            return 1;
        }
    }
    if (m == 0x1A && !sub) {
        GuiCanvas_Transition(Gui_Canvas(), self, 0);
        cGameSystem_Restart(g_Game, 3);
        return 1;
    }
    return GuiWidget_onMessage(self, w, msg, sub, text);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A2170(void) {}
#undef Gui_Canvas /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A2170 */

/* merge_units: begin func_002A2590 */
#pragma push /* merge_units */
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
    char pad0[0x48];
    Mdl* m[4];
    Obj* obj;
    char pad5C[0x60 - 0x5C];
    float rx, ry, rz;
    char pad6C[0x70 - 0x6C];
    float f70, f74, f78;
    char pad7C[0x80 - 0x7C];
    V pos[4];
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
#if 0 /* merge_units */
Scr* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Scr *)Gui_Canvas()) /* merge_units */

void cMan_ManNextFrame(void* p, float t);
void cMotionManager_NextFrame(float t);
void GuiEquipmentSetup_ManRender(Self* self);
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


extern "C" void GuiEquipmentSetup_ManRender(Self* self0)
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
        if (self->m[i]) {
            char key[4];
            bool done = false;
            unsigned int k;
            for (k = 0; k < 4u; k++) {
                char c;
                if (!D_004AB158[k]) done = true;
                if (done) c = 0; else c = D_004AB158[k];
                key[k] = c;
            }
            Root2* rr = &self->m[i]->r2EC0; r = RootCollection_FindByKey(rr->coll, key);
            SetPl(r, Place(mm));
            r->x160 = 0;
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
        cMotionManager_NextFrame(t);
        if (last != -1) {
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
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_002A2590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A2590 */

/* merge_units: begin func_002A2EC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiEquipmentSetup_types.h"

extern char g_LightMgr[];
extern int cLightMan_BuildVisibleLightSubset(void* p);
extern int GuiWidget_onRender(GuiEquipmentSetup* self);

int GuiEquipmentSetup_onRender(GuiEquipmentSetup* self) {
    cLightMan_BuildVisibleLightSubset(g_LightMgr);
    return GuiWidget_onRender(self);
}
static inline void merge_flush_func_002A2EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A2EC0 */
