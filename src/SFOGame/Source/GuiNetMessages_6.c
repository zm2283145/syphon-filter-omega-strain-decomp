/*
 * SFOGame/Source/GuiNetMessages: 4 files, 00347820-00347B40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00347820 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct Obj47820 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(const char* type); /* +0x58 */
};
struct List47820 { char pad[0x60]; int f60; char pad64[0x18]; Obj47820* f7C; };

struct V47820 { float x, y, z, w; } __attribute__((aligned(16)));
struct Sp47820 { char pad[0x10]; V47820 c0; V47820 c1; };
static inline void SetA47820(Sp47820* p, V47820 a) { p->c0 = a; }
static inline void SetB47820(Sp47820* p, V47820 b) { p->c1 = b; }
typedef struct Screen47820 {
    char pad[0x88];
    Obj47820* f88;
    Obj47820* f8C;
    Obj47820* f90;
    Obj47820* f94;
    char pad98[8];
    Obj47820* fA0;
    Obj47820* fA4;
} Screen47820;

extern "C" {
extern char D_004BA2A0[];
static void * const dat_00492B60[2] = { (void*)D_004BA2A0, (void*)0x0 };
extern char D_004BA2B0[];
static void * const dat_00492B68[2] = { (void*)D_004BA2B0, (void*)0x0 };
extern char D_004BA2B8[];
static void * const dat_00492B70[2] = { (void*)D_004BA2B8, (void*)0x0 };
extern char D_004BA2C0[];
static void * const dat_00492B78[2] = { (void*)D_004BA2C0, (void*)0x0 };
extern char D_004BA2C8[];
static void * const dat_00492B80[2] = { (void*)D_004BA2C8, (void*)0x0 };
extern char D_004BA540[];
extern char D_004A9870[];
extern char D_004A7520[];
extern char D_004BA3B0[];
extern V47820 D_00587B50;
extern V47820 D_00587B60;
extern const char* D_00492B98;
void GuiLobbyScreen_onAdd(Screen47820* self);
Obj47820* GuiWidget_FindChild_charP(Screen47820* self, const char* name);
int Gui_Manager(void);
Sp47820* GuiManager_GetFont(int mgr, char* name);
}

static inline Obj47820* As47820(Obj47820* obj, const char* type)
{
    return (obj && obj->IsA(type)) ? obj : 0;
}

/* Screen init: base init, child widget lookups, then sets the two colours of a named sprite. */
extern "C" void GuiNetMessages_Init(Screen47820* self)
{
    Sp47820* sp;
    GuiLobbyScreen_onAdd(self);
    self->f88 = As47820(GuiWidget_FindChild_charP(self, *(const char**)dat_00492B60), D_004BA540);
    self->f8C = As47820(GuiWidget_FindChild_charP(self, *(const char**)dat_00492B68), D_004A9870);
    self->f90 = As47820(GuiWidget_FindChild_charP(self, *(const char**)dat_00492B70), D_004A9870);
    self->f94 = As47820(GuiWidget_FindChild_charP(self, *(const char**)dat_00492B78), D_004A9870);
    self->fA0 = As47820(GuiWidget_FindChild_charP(self, *(const char**)dat_00492B80), D_004A7520);
    self->fA4 = GuiWidget_FindChild_charP(self, D_00492B98);
    sp = GuiManager_GetFont(Gui_Manager(), D_004BA3B0);
    if (sp) { SetA47820(sp, D_00587B50); SetB47820(sp, D_00587B60); }
}
static inline void merge_flush_func_00347820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00347820 */

/* merge_units: begin func_00347A40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiNetMessages.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiNetMessages_types.h"

extern char D_004DEB10[];   /* GuiNetMessages vtable */
extern void* GuiLobbyScreen_ctor(void* self);

/* Constructor. */
GuiNetMessages* GuiNetMessages_ctor(GuiNetMessages* self) {
    GuiLobbyScreen_ctor(self);
    self->vtable = D_004DEB10;
    self->unk84 = 9;
    self->unk88 = 0;
    self->unk9C = -1;
    return self;
}
static inline void merge_flush_func_00347A40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00347A40 */

/* merge_units: begin func_00347A90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct C347A90 { int pad0; int a4; };
class S347A90 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void f5C(int, int);
    char pad[0x48]; unsigned int a4C; int pad50; int a54; char pad2[0x4C]; C347A90* aA4;
};
extern "C" {
extern void GuiArrayWidget_GetSelected(S347A90*, int*, unsigned int*);
extern void GuiArrayWidget_SetSelected(S347A90*, int, unsigned int);
void GuiNetMessageArray_UpdateSize(S347A90* o);
}
void GuiNetMessageArray_UpdateSize(S347A90* o)
{
    int a;
    unsigned int b;
    if (o->aA4) o->f5C(4, o->aA4->a4);
    GuiArrayWidget_GetSelected(o, &a, &b);
    if (b >= o->a4C && o->a4C != 0) b = o->a4C - 1;
    else if (b >= o->a4C) b = 0;
    o->a54 = 100000;
    GuiArrayWidget_SetSelected(o, a, b);
}
static inline void merge_flush_func_00347A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00347A90 */

/* merge_units: begin func_00347B40 */
#pragma push /* merge_units */
/* GuiNetMessageArray::onRowRender (GuiNetMessages.cc). cMatrix/cVector operator= are quad-copy asm (proto __as__7cMatrix / __as__7cVector use u_long128 regs). */
#pragma cplusplus on

typedef struct V4_00347B40 { float x, y, z, w; } V4_00347B40;
typedef struct Mtx_00347B40 { __int128 q[4]; } Mtx_00347B40;
typedef struct Ent_00347B40 {
    char pad[0x28];
    V4_00347B40* pos;
    V4_00347B40* c2C;
    V4_00347B40* c30;
    V4_00347B40* c34;
} Ent_00347B40;
typedef struct Slot_00347B40 {
    float r[4];
    char pad10[0x105 - 0x10];
    char b105;
    char b106;
} Slot_00347B40;
typedef struct Rs_00347B40 {
    char pad[0xA80];
    Mtx_00347B40 mtx[1];
    char padAC0[0xFB0 - 0xAC0];
    Ent_00347B40 ents[1];
} Rs_00347B40;
typedef struct Self_00347B40 { char pad[0x4C]; unsigned int count; char pad50[4]; unsigned int sel; } Self_00347B40;

union Q_00347B40 {
    V4_00347B40 v;
    __int128 q;
};

extern "C" {
typedef struct G_00347B40 {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_00347B40;
extern G_00347B40 D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_00347B40 D_00539170;
extern V4_00347B40 D_00587C30;
void GuiArrayWidget_onRowRender(Self_00347B40*, unsigned int, const V4_00347B40&);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
V4_00347B40& cVector_opAssign(V4_00347B40* d, const V4_00347B40& s);
V4_00347B40& tIRGBA_opAssign_tRGBAR(V4_00347B40* d, const V4_00347B40& s);
void XLib_DrawStrip(void* s);
void XLib_DrawLines(void* s);
}
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_DrawMode (D_00539210.fD0)

#define RS_00347B40 ((Rs_00347B40*)g_Video)
#define SLOT_00347B40(i) ((Slot_00347B40*)(g_Video + 0x1F0 + (i) * 0x110))

static inline void UM_00347B40(void* m) { __asm__ volatile("sqc2 vf0, 0x30(%0); qmfc2.ni v0, vf0; pcpyud v0, v0, zero; sq v0, 0x10(%0); pexcw v0, v0; sq v0, 0x20(%0); pcpyud v0, v0, zero; sq v0, 0(%0)" : : "r"(m) : "v0", "memory"); }
static inline void QR_00347B40(void* dd, void* ss) { __int128 reg0, reg1; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(reg0), "=&r"(reg1) : "r"(ss), "r"(dd) : "memory"); }

struct V4c_00347B40 {
    union { float f[4]; __int128 q; } u;
    V4c_00347B40() {}
    V4c_00347B40(float a, float b, float c, float d) { u.f[0] = a; u.f[1] = b; u.f[2] = c; u.f[3] = d; }
    V4c_00347B40& operator=(const V4c_00347B40& s) { V4c_00347B40* d = this; const V4c_00347B40* p = &s; __int128 reg; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(reg) : "r"(p), "r"(d) : "memory"); return *this; }
};
static inline void Emit_00347B40(V4c_00347B40* pos, V4_00347B40* col)
{
    Ent_00347B40* e;
    XLib_NextBatchVert(g_Video);
    e = &RS_00347B40->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], *(V4_00347B40*)pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], *col);
    D_005381F8 = 2LL << 32;
}
static inline unsigned char Prim_00347B40(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode_00347B40(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }
static inline void Begin_00347B40(void)
{
    Ent_00347B40* e;
    D_00539238 = Prim_00347B40();
    D_0053923C = Mode_00347B40();
    D_00539228 = 0;
    D_0053923C &= ~1;
    e = &RS_00347B40->ents[D_00539210.f10];
    e->pos += D_00539224;
    e->c2C += D_00539224;
    e->c30 += D_00539224;
    e->c34 += D_00539224;
    XLib_NewStrip(g_Video);
    D_00539224 = 0;
}

static inline void SetVp_00347B40(V4_00347B40* v)
{
    Slot_00347B40* s = SLOT_00347B40(D_00538C60);
    s->r[0] = v->x;
    s->r[1] = v->y;
    s->r[2] = v->z;
    s->r[3] = v->w;
    s->b105 = 1;
    s->b106 = 1;
}

extern "C" void GuiNetMessageArray_onRowRender(Self_00347B40* self, unsigned int idx, V4_00347B40* rect)
{
    V4_00347B40* col;
    int saved;
    unsigned char strip;
    int vp;
    V4_00347B40 r;
    V4c_00347B40 p[4];
    GuiArrayWidget_onRowRender(self, idx, *rect);
    if (idx != self->sel || idx >= self->count) return;
    saved = g_DrawMode;
    strip = 1;
    col = &D_00587C30;
    QR_00347B40(&RS_00347B40->mtx[D_00538C64 + 1], &RS_00347B40->mtx[D_00538C64]);
    D_00538C64++;
    UM_00347B40(&RS_00347B40->mtx[D_00538C64]);
    D_00538C68 = 1;
    g_DrawMode = 0;
    vp = (int)&D_00539170;
    SetVp_00347B40((V4_00347B40*)vp);
    r = *rect;
    r.x += 1.0f;
    r.y -= 1.0f;
    r.z -= 2.0f;
    r.w -= 2.0f;
    p[0] = V4c_00347B40(r.x, r.y, 1.0f, 0.0f);
    p[1] = V4c_00347B40(r.x + r.z, r.y, 1.0f, 0.0f);
    p[2] = V4c_00347B40(r.x, r.y - r.w, 1.0f, 0.0f);
    p[3] = V4c_00347B40(r.x + r.z, r.y - r.w, 1.0f, 0.0f);
    if (strip) {
        Begin_00347B40();
        Emit_00347B40(&p[0], col);
        Emit_00347B40(&p[1], col);
        Emit_00347B40(&p[2], col);
        Emit_00347B40(&p[3], col);
        XLib_DrawStrip(g_Video);
    } else {
        Begin_00347B40();
        Emit_00347B40(&p[0], col);
        Emit_00347B40(&p[2], col);
        Emit_00347B40(&p[3], col);
        Emit_00347B40(&p[1], col);
        Emit_00347B40(&p[0], col);
        XLib_DrawLines(g_Video);
    }
    g_DrawMode = saved;
    D_00538C64--;
    D_00538C68 = 1;
}
static inline void merge_flush_func_00347B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00347B40 */
