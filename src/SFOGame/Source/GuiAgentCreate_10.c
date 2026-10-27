/*
 * SFOGame/Source/GuiAgentCreate: 6 files, 0028D530-0028E600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028D530 */
#pragma push /* merge_units */
#include "types.h"
#include "vec4_with_comp.h"

#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
VEC4_WITH_COMP_FUNC(cBone_SetScaleY, 0x120, y)
#pragma pop
static inline void merge_flush_func_0028D530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028D530 */

/* merge_units: begin func_0028D580 */
#pragma push /* merge_units */
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
VEC4_WITH_COMP_FUNC(cBone_SetScaleX, 0x110, x)
#pragma pop
static inline void merge_flush_func_0028D580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028D580 */

/* merge_units: begin func_0028D5D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentCreate.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiAgentCreate_types.h"

AgentCreateEntry* func_0028D5D0(AgentCreateEntryVec* v, int i) {
    return v->data + i;
}

Rec12* cArray_cBoneScale_opIndex(Rec12Vec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_0028D5D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028D5D0 */

/* merge_units: begin func_0028D610 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } W_28D610;
typedef struct { __int128 a; __int128 b; } Ent_28D610;
typedef struct { char pad[0xE0]; Ent_28D610 e[1]; } Tbl_28D610;
typedef struct { unsigned char mode; signed char slot; short pos; } Tab_28D610;
typedef struct {
    char pad0[0x58]; W_28D610* w58; W_28D610* w5C; char pad60[0x10]; Tbl_28D610* items; char pad74[0x4C];
    int dirty; int count; int pos; char padCC[0xC]; int row; char padDC[4]; int vE0; int vE4; char padE8[5];
    signed char slot; unsigned char mode; signed char cur; signed char prev;
} S_28D610;

extern char D_0048B560[11][20];
extern Tab_28D610 D_0048B500[][11];
extern unsigned char D_0048B501[][44];
extern char g_AgentPartCache[];
extern char D_004A9A30[];
extern char D_004A9A38[];
extern char D_004A9A40[];
extern int strcmp(const char* a, const char* b);
extern int sprintf(char* buf, const char* fmt, ...);
extern int FindPartNumber__7MonsterF1(void* db, __int128 key);
extern int FindTextureNumber__7MonsterF1(void* db, __int128 key);
extern void GuiAgentCreate_CountSelections(S_28D610* o);
extern void GuiTextWidget_SetText(W_28D610* w, char* text, int flags);
extern void GuiWidget_SendMessage(S_28D610* o, W_28D610* w, int kind, int v, int f);

static inline void Slider_28D610(S_28D610* o, W_28D610* w, int kind, int v, int f)
{
    if (w) GuiWidget_SendMessage(o, w, kind, v, f);
}

void GuiAgentCreate_UserInterfaceNextButton(S_28D610* o, char* name)
{
    char buf[0x10];
    int i;
    for (i = 0; i < 11; i++) {
        if (!strcmp(D_0048B560[i], name)) break;
    }
    if (i != o->cur) {
        o->prev = o->cur;
        o->cur = i;
        o->dirty = 1;
        if (i < 11) {
            o->slot = D_0048B501[o->row][o->cur * 4];
            o->mode = D_0048B500[o->row][o->cur].mode;
            o->vE0 = FindPartNumber__7MonsterF1(g_AgentPartCache, o->items->e[o->slot].a);
            o->vE4 = FindTextureNumber__7MonsterF1(g_AgentPartCache, o->items->e[o->slot].b);
            GuiAgentCreate_CountSelections(o);
            if (o->w58) o->w58->flags |= 2;
            Slider_28D610(o, o->w58, 10, (int)((100.0f / (float)(o->count - 1)) * (float)o->pos), 0);
            if (o->w5C) {
                if (o->count) {
                    sprintf(buf, D_004A9A30, o->pos + 1, o->count);
                    GuiTextWidget_SetText(o->w5C, buf, 0);
                } else {
                    GuiTextWidget_SetText(o->w5C, D_004A9A38, 0);
                }
            }
        } else {
            o->count = 0;
            o->pos = 0;
            if (o->w58) o->w58->flags &= ~2;
            if (o->w5C) GuiTextWidget_SetText(o->w5C, D_004A9A40, 0);
        }
    }
}
static inline void merge_flush_func_0028D610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028D610 */

/* merge_units: begin func_0028D870 */
#pragma push /* merge_units */
/* GuiAgentCreate_ManRender: agent-create preview draw (camera, four placed figure models, tick/render); sibling of GuiAgentModify_ManRender. */
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
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
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
    char pad0[0x60];
    Mdl* m[4];              /* 0x60 */
    Mdl* mdl;               /* 0x70 */
    Obj* obj;               /* 0x74 */
    char pad78[0x94 - 0x78];
    float fov;
    float ex, ey, ez;
    float rx, ry, rz;
    float f70, f74, f78;
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
void GuiAgentCreate_ManRender(Self* self); void GuiAgentCreate_BlendMenOnOff(Self* self);
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


static inline void PlaceModel(Self* self, int idx, M& mm)
{
    char key[4];
    bool done = false;
    unsigned int k;
    for (k = 0; k < 4u; k++) {
        char c;
        if (!D_004A9A40[k]) done = true;
        if (done) c = 0; else c = D_004A9A40[k];
        key[k] = c;
    }
    Root2* rr = &self->m[idx]->r2EC0; Root* r = RootCollection_FindByKey(rr->coll, key);
    SetPl(r, Place(mm));
    r->x160 = 0;
}

extern "C" void GuiAgentCreate_ManRender(Self* self)
{
    V e(0.0f, 5.0f, 1.5f, 1.0f);
    M view;
    M r2;
    V p;
    M cm;
    int saved;
    int i;
    XLib_ClearZBuffer(g_Video);
    GuiAgentCreate_BlendMenOnOff(self);
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
    { float ey = self->f74; float ex = self->f70; float ez = self->f78; r2 = Euler(ey, ex, ez); }
    p = V(self->ex, -self->ey, self->ez, 1.0f);
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
        V pp(0.0f, 0.0f, -3.0f, 1.0f);
        UnitM(&mm);
        Rot(&mm, VA(1.0f, 0.0f, 0.0f, 0.0f), self->rx);
        Rot(&mm, V(0.0f, 1.0f, 0.0f, 0.0f), self->ry);
        Rot(&mm, V(0.0f, 0.0f, 1.0f, 0.0f), self->rz);
        mm.r(3) = pp;
        Mul33(&mm, &cm, &mm);
        if (i == 0) {
            PlaceModel(self, 0, mm);
            PlaceModel(self, 1, mm);
        } else {
            PlaceModel(self, i + 1, mm);
        }
    }
    {
        float t = Gui_Canvas()->t;
        int j;
        for (j = 0; j < 4; j++) {
            self->m[j]->Tick(t);
            cMan_ManNextFrame((char*)self->m[j] + 0x60, t);
        }
        cMotionManager_NextFrame(t);
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
static inline void merge_flush_func_0028D870(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028D870 */

/* merge_units: begin func_0028E600 */
#pragma push /* merge_units */
extern char g_LightMgr[];
extern int cLightMan_BuildVisibleLightSubset(void* p);
extern int GuiWidget_onRender(void* self);

int GuiAgentCreate_onRender(void* self) {
    cLightMan_BuildVisibleLightSubset(g_LightMgr);
    return GuiWidget_onRender(self);
}
static inline void merge_flush_func_0028E600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028E600 */
