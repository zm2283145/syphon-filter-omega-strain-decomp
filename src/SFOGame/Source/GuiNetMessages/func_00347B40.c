/* GuiNetMessageArray::onRowRender (GuiNetMessages.cc). cMatrix/cVector operator= are quad-copy asm (proto __as__7cMatrix / __as__7cVector use u_long128 regs). */
#pragma cplusplus on
#include "types.h"

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



