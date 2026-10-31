/* GuiMissionList::onRowRender (GuiMissionList.cc). cMatrix/cVector operator= are quad-copy asm (proto __as__7cMatrix / __as__7cVector use u_long128 regs). */
#pragma cplusplus on
#include "types.h"

typedef struct V4_002AB2A0 { float x, y, z, w; } V4_002AB2A0;
typedef struct Mtx_002AB2A0 { __int128 q[4]; } Mtx_002AB2A0;
typedef struct Ent_002AB2A0 {
    char pad[0x28];
    V4_002AB2A0* pos;
    V4_002AB2A0* c2C;
    V4_002AB2A0* c30;
    V4_002AB2A0* c34;
} Ent_002AB2A0;
typedef struct Slot_002AB2A0 {
    float r[4];
    char pad10[0x105 - 0x10];
    char b105;
    char b106;
} Slot_002AB2A0;
typedef struct Rs_002AB2A0 {
    char pad[0xA80];
    Mtx_002AB2A0 mtx[1];
    char padAC0[0xFB0 - 0xAC0];
    Ent_002AB2A0 ents[1];
} Rs_002AB2A0;
typedef struct Self_002AB2A0 { char pad[0x4C]; unsigned int count; char pad50[4]; unsigned int sel; } Self_002AB2A0;

union Q_002AB2A0 {
    V4_002AB2A0 v;
    __int128 q;
};

extern "C" {
typedef struct G_002AB2A0 {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_002AB2A0;
extern G_002AB2A0 D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_002AB2A0 D_00539170;
extern V4_002AB2A0 D_00587C60;
typedef struct Canvas_002AB2A0 { char pad[0x20]; void* top; } Canvas_002AB2A0;
Canvas_002AB2A0* Gui_Canvas(void);
void GuiArrayWidget_onRowRender(Self_002AB2A0*, unsigned int, const V4_002AB2A0&);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
V4_002AB2A0& cVector_opAssign(V4_002AB2A0* d, const V4_002AB2A0& s);
V4_002AB2A0& tIRGBA_opAssign_tRGBAR(V4_002AB2A0* d, const V4_002AB2A0& s);
void XLib_DrawStrip(void* s);
void XLib_DrawLines(void* s);
}
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_DrawMode (D_00539210.fD0)

#define RS_002AB2A0 ((Rs_002AB2A0*)g_Video)
#define SLOT_002AB2A0(i) ((Slot_002AB2A0*)(g_Video + 0x1F0 + (i) * 0x110))

static inline void UM_002AB2A0(void* m) { __asm__ volatile("sqc2 vf0, 0x30(%0); qmfc2.ni v0, vf0; pcpyud v0, v0, zero; sq v0, 0x10(%0); pexcw v0, v0; sq v0, 0x20(%0); pcpyud v0, v0, zero; sq v0, 0(%0)" : : "r"(m) : "v0", "memory"); }
static inline void QR_002AB2A0(void* dd, void* ss) { __int128 reg0, reg1; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(reg0), "=&r"(reg1) : "r"(ss), "r"(dd) : "memory"); }

struct V4c_002AB2A0 {
    union { float f[4]; __int128 q; } u;
    V4c_002AB2A0() {}
    V4c_002AB2A0(float a, float b, float c, float d) { u.f[0] = a; u.f[1] = b; u.f[2] = c; u.f[3] = d; }
    V4c_002AB2A0& operator=(const V4c_002AB2A0& s) { V4c_002AB2A0* d = this; const V4c_002AB2A0* p = &s; __int128 reg; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(reg) : "r"(p), "r"(d) : "memory"); return *this; }
};
static inline void Emit_002AB2A0(V4c_002AB2A0* pos, V4_002AB2A0* col)
{
    Ent_002AB2A0* e;
    XLib_NextBatchVert(g_Video);
    e = &RS_002AB2A0->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], *(V4_002AB2A0*)pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], *col);
    D_005381F8 = 2LL << 32;
}
static inline unsigned char Prim_002AB2A0(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode_002AB2A0(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }
static inline void Begin_002AB2A0(void)
{
    Ent_002AB2A0* e;
    D_00539238 = Prim_002AB2A0();
    D_0053923C = Mode_002AB2A0();
    D_00539228 = 0;
    D_0053923C &= ~1;
    e = &RS_002AB2A0->ents[D_00539210.f10];
    e->pos += D_00539224;
    e->c2C += D_00539224;
    e->c30 += D_00539224;
    e->c34 += D_00539224;
    XLib_NewStrip(g_Video);
    D_00539224 = 0;
}

static inline void SetVp_002AB2A0(V4_002AB2A0* v)
{
    Slot_002AB2A0* s = SLOT_002AB2A0(D_00538C60);
    s->r[0] = v->x;
    s->r[1] = v->y;
    s->r[2] = v->z;
    s->r[3] = v->w;
    s->b105 = 1;
    s->b106 = 1;
}

extern "C" void GuiMissionList_onRowRender(Self_002AB2A0* self, unsigned int idx, V4_002AB2A0* rect)
{
    V4_002AB2A0* col;
    int saved;
    unsigned char strip;
    int vp;
    V4_002AB2A0 r;
    V4c_002AB2A0 p[4];
    GuiArrayWidget_onRowRender(self, idx, *rect);
    if (Gui_Canvas()->top != self) return;
    if (idx != self->sel) return;
    saved = g_DrawMode;
    strip = 1;
    col = &D_00587C60;
    QR_002AB2A0(&RS_002AB2A0->mtx[D_00538C64 + 1], &RS_002AB2A0->mtx[D_00538C64]);
    D_00538C64++;
    UM_002AB2A0(&RS_002AB2A0->mtx[D_00538C64]);
    D_00538C68 = 1;
    g_DrawMode = 0;
    vp = (int)&D_00539170;
    SetVp_002AB2A0((V4_002AB2A0*)vp);
    r = *rect;
    r.x += 1.0f;
    r.y -= 1.0f;
    r.z -= 2.0f;
    r.w -= 2.0f;
    p[0] = V4c_002AB2A0(r.x, r.y, 1.0f, 0.0f);
    p[1] = V4c_002AB2A0(r.x + r.z, r.y, 1.0f, 0.0f);
    p[2] = V4c_002AB2A0(r.x, r.y - r.w, 1.0f, 0.0f);
    p[3] = V4c_002AB2A0(r.x + r.z, r.y - r.w, 1.0f, 0.0f);
    if (strip) {
        Begin_002AB2A0();
        Emit_002AB2A0(&p[0], col);
        Emit_002AB2A0(&p[1], col);
        Emit_002AB2A0(&p[2], col);
        Emit_002AB2A0(&p[3], col);
        XLib_DrawStrip(g_Video);
    } else {
        Begin_002AB2A0();
        Emit_002AB2A0(&p[0], col);
        Emit_002AB2A0(&p[2], col);
        Emit_002AB2A0(&p[3], col);
        Emit_002AB2A0(&p[1], col);
        Emit_002AB2A0(&p[0], col);
        XLib_DrawLines(g_Video);
    }
    g_DrawMode = saved;
    D_00538C64--;
    D_00538C68 = 1;
}



