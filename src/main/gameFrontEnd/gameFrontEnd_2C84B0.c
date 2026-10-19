/*
 * main/gameFrontEnd: range (2 files, 002C84B0-002C8840)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002C84B0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
typedef struct { char p0[0x2409]; unsigned char busy; } O2C84B0;
extern volatile int g_TimerAccum;
extern long g_TickCounter64;
extern int g_ProfileLockDepth;
extern int D_0048C348;
extern unsigned char g_GuiSoundGate;
extern unsigned char D_0051EE90;
extern unsigned char D_00572528;
extern unsigned char D_005723C8;
extern void SleepThread(void);
extern void func_0010D0D0(int);
extern void SuspendThread(int);
extern void App_CardWaitPoll(int, int);
extern O2C84B0* DME_GetLobby(void);
extern void SFOLobby_Update(O2C84B0* o);
}
#pragma define_section REENT_DTOR ".dtors_drop" far_absolute RX
struct Reent_84B0 { Reent_84B0(unsigned char b) { if (!b) D_005723C8 = 1; } __declspec(weak) __declspec(REENT_DTOR) ~Reent_84B0() { D_005723C8 = 0; } };

static inline int DivTime(void)
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
    #pragma opt_rotateloops off
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

static inline void SpSave(void* dst)
{
    int n = 0x400;
    void* s = (void*)0x70000000;
    void* d = dst;
    asm {
        .set noreorder
    loop:
        lq $a0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $a0, -0x10(d)
        .set reorder
    }
}

static inline void SpLoad(void* src)
{
    int n = 0x400;
    void* s = src;
    void* d = (void*)0x70000000;
    asm {
        .set noreorder
    loop:
        lq $a0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $a0, -0x10(d)
        .set reorder
    }
}

#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_rotateloops off
extern "C" void FrontEnd_SplashThreadMain(int arg)
{
    char buf[0x4000];
    int last;
    void (*fp)(int, int);
    if (arg) {
        last = 0;
        for (;;) {
            g_TickCounter64 += (int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f);
            *(volatile int*)0x10000800 = 0;
            *(volatile int*)0x10000810 = 0x82;
            g_TimerAccum = 0;
            if (DivTime() - last >= 10 && !g_ProfileLockDepth) {
                func_0010D0D0(D_0048C348);
                SpSave(buf);
                fp = App_CardWaitPoll;
                D_0051EE90 = g_GuiSoundGate = 1;
                fp(0, 0x3039);
                unsigned char b;
                if (!D_00572528 && !(b = D_005723C8)) {
                    O2C84B0* o;
                    { Reent_84B0 r(b); }
                    o = DME_GetLobby();
                    if (o) {
                        if (!o->busy) {
                            o->busy = 1;
                            SFOLobby_Update(o);
                            o->busy = 0;
                        } else {
                            SFOLobby_Update(o);
                        }
                    }
                }
                g_GuiSoundGate = 0;
                D_0051EE90 = 0;
                SpLoad(buf);
                SuspendThread(D_0048C348);
                last = DivTime();
            }
            SleepThread();
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C84B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C84B0 */

/* merge_units: begin func_002C8840 */
#pragma push /* merge_units */
/* func_002C8840: full-screen textured quad (3 passes). Same tricks as 0025EC20: struct global for D_00539210..D8, GCC-style __asm__ volatile quad copy / identity matrix, umax/vmax defaults assigned after the texture-size reads. */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma opt_rebuildconditionals off

typedef struct V4_002C8840 { float x, y, z, w; } V4_002C8840;
typedef struct Mtx_002C8840 { __int128 q[4]; } Mtx_002C8840;
typedef struct Ent_002C8840 {
    char pad[0x28];
    V4_002C8840* pos;
    V4_002C8840* c2C;
    V4_002C8840* c30;
    V4_002C8840* c34;
} Ent_002C8840;
typedef struct Slot_002C8840 {
    char pad[0x1F0];
    float r[4];
    char pad200[0x2E0 - 0x200];
    int f2E0;
    int pad2E4;
    float f2E8;
    char pad2EC[0x2F4 - 0x2EC];
    char f2F4;
    char f2F5;
    char f2F6;
} Slot_002C8840;
typedef struct Rs_002C8840 {
    char pad[0xA80];
    Mtx_002C8840 mtx[1];
    char padAC0[0xFB0 - 0xAC0];
    Ent_002C8840 ents[1];
} Rs_002C8840;
typedef struct Tex_002C8840 { int pad[1]; unsigned short w, h; } Tex_002C8840;
typedef struct Obj_002C8840 { char pad[0x44]; Tex_002C8840* tex; } Obj_002C8840;
typedef struct Mgr_002C8840 { int pad[2]; Obj_002C8840** objs; } Mgr_002C8840;
typedef struct Str_002C8840 { char buf[0xA0]; } Str_002C8840;

extern "C" {
typedef struct G_002C8840 {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_002C8840;
extern G_002C8840 D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_002C8840 D_00539170;
extern long long D_004BC1B0;
void Renderer_BindTexture(void* m, int idx);
void func_0025CD10(void* s);
void func_0025CA40(void* s);
void Vec4_Copy(V4_002C8840* d, V4_002C8840* s);
void GuiBatch_AddVertexColor(V4_002C8840* d, V4_002C8840* s);
float GuiBatch_AddVertexUV(void);
V4_002C8840* Vec4_Set(V4_002C8840* o, float x, float y, float z, float w);
void Renderer_FlushPrimitives(void* s);
void Video_BeginFrame(void* s);
void func_0036E4B0(void* s, char* name, int a, int b);
void FileMan_Release(void* s, int a);
int TexMan_FindOrLoad(void* m, void* s);
void Tex_Release(void* m, int idx, int a, int b);
}
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)

#define RS_002C8840 ((Rs_002C8840*)g_Video)
#define SLOT_002C8840(i) ((Slot_002C8840*)(g_Video + (i) * 0x110))

static inline void UM_002C8840(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void QR_002C8840(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

struct V4c_002C8840 {
    float x, y, z, w;
    V4c_002C8840(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
static inline void Emit_002C8840(const V4c_002C8840& pos, const V4c_002C8840& col, const V4c_002C8840& uv)
{
    V4_002C8840 tmp;
    Ent_002C8840* e;
    float u;
    func_0025CA40(g_Video);
    e = &RS_002C8840->ents[D_00539210.f10];
    Vec4_Copy(&e->pos[D_00539224 - 1], (V4_002C8840*)&pos);
    GuiBatch_AddVertexColor(&e->c30[D_00539224 - 1], (V4_002C8840*)&col);
    u = uv.x + GuiBatch_AddVertexUV();
    Vec4_Copy(&e->c34[D_00539224 - 1], Vec4_Set(&tmp, u, uv.y + GuiBatch_AddVertexUV(), uv.z, uv.w));
    D_005381F8 = 6LL << 32;
}
static inline unsigned char Prim_002C8840(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode_002C8840(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }


extern "C" void func_002C8840(char* name)
{
    Str_002C8840 str;
    int idx;
    int saved;
    int i;
    float hw, hh, umax, vmax;
    Ent_002C8840* e;
    int vp;
    if (name == 0 || *name == 0) return;
    func_0036E4B0(&str, name, 0, 0);
    idx = TexMan_FindOrLoad(g_TextureMgr, &str);
    if (idx == -1) {
        FileMan_Release(&str, -1);
        return;
    }
    saved = g_DrawMode;
    QR_002C8840(&RS_002C8840->mtx[D_00538C64 + 1], &RS_002C8840->mtx[D_00538C64]);
    D_00538C64++;
    UM_002C8840(&RS_002C8840->mtx[D_00538C64]);
    D_00538C68 = 1;
    g_DrawMode = 1;
    Renderer_BindTexture(g_TextureMgr, idx);
    vp = (int)&D_00539170;
    {
        Slot_002C8840* s = SLOT_002C8840(D_00538C60);
        s->f2E0 = 0;
        s->f2E8 = 1000.0f;
        s->f2F6 = 1;
        s->f2F4 = 1;
        s->r[0] = ((V4_002C8840*)vp)->x;
        s->r[1] = ((V4_002C8840*)vp)->y;
        s->r[2] = ((V4_002C8840*)vp)->z;
        s->r[3] = ((V4_002C8840*)vp)->w;
        s->f2F5 = 1;
        s->f2F6 = 1;
    }
    hw = 0.5f * ((V4_002C8840*)vp)->z;
    hh = 0.5f * ((V4_002C8840*)vp)->w;
    {
        Tex_002C8840* t = ((Mgr_002C8840*)g_TextureMgr)->objs[idx]->tex;
        float w = (int)t->w;
        float h = (int)t->h;
        umax = 1.0f;
        vmax = 1.0f;
        if (w == 1024.0f && h == 512.0f) {
            umax = 0.625f;
            vmax = 0.9375f;
        }
    }
    for (i = 0; i < 3; i++) {
        D_00539238 = Prim_002C8840();
        D_0053923C = Mode_002C8840();
        D_00539228 = 0;
        D_0053923C &= ~1;
        e = &RS_002C8840->ents[D_00539210.f10];
        e->pos += D_00539224;
        e->c2C += D_00539224;
        e->c30 += D_00539224;
        e->c34 += D_00539224;
        func_0025CD10(g_Video);
        D_00539224 = 0;
        Emit_002C8840(V4c_002C8840(-hw, hh, 0.5f, 1.0f), V4c_002C8840(1.0f, 1.0f, 1.0f, 1.0f), V4c_002C8840(0.0f, 0.0f, 1.0f, 0.0f));
        Emit_002C8840(V4c_002C8840(hw, -hh, 0.5f, 1.0f), V4c_002C8840(1.0f, 1.0f, 1.0f, 1.0f), V4c_002C8840(umax, vmax, 1.0f, 0.0f));
        Renderer_FlushPrimitives(g_Video);
        Video_BeginFrame(g_Video);
    }
    D_00538C64--;
    D_00538C68 = 1;
    {
        Slot_002C8840* s = SLOT_002C8840(D_00538C60);
        s->f2F6 = 1;
        s->f2F4 = 0;
    }
    g_DrawMode = saved;
    Tex_Release(g_TextureMgr, idx, 0, 1);
    FileMan_Release(&str, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C8840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C8840 */
