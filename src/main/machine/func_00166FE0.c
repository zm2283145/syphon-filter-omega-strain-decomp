/* func_00166FE0 (machine): loading-screen progress tick (sibling of GameFlow_EnterMpLobby). The quad copy and
   identity-matrix store are GCC-style __asm__ volatile: MW does no CSE across them, so the base address
   and constant are rematerialised as in retail. */
#pragma opt_rotateloops off
#pragma cplusplus on
#include "types.h"

typedef struct V4_00166FE0 { float x, y, z, w; } V4_00166FE0;
typedef struct Mtx_00166FE0 { __int128 q[4]; } Mtx_00166FE0;
typedef struct Slot_00166FE0 {
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
} Slot_00166FE0;
typedef struct Rs_00166FE0 {
    char pad[0xA80];
    Mtx_00166FE0 mtx[1];
} Rs_00166FE0;
typedef struct Screen_00166FE0 {
    char pad[0x27C];
    void* anim;
    void* font;
} Screen_00166FE0;

extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_00166FE0 D_00539170;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern int g_TimerAccum;
extern unsigned long long g_TickCounter64;
extern unsigned long long D_004EE4B8;
extern signed char D_004EE4C0;
extern char D_0049C3E8[];
extern char D_0049C3F0[];
extern char D_0049C400[];
extern float g_TextColourBlock;
extern float D_0055A284;
extern float D_0055A288;
extern float D_0055A28C;
int sprintf(char* d, const char* f, ...);
void Video_BeginFrame(void* p);
float SoftFloat_U64ToFloat(unsigned long long t);
void func_0027A830(void* o, float dt);
void func_0027A7F0(void* o);
void func_0036A300(void* font, char* s, V4_00166FE0* col, int x, int y, float scale);
int TextManager_Get(void);
void TextManager_DrawImmediate(int a);
}

#define RS_00166FE0 ((Rs_00166FE0*)g_Video)
#define SLOT_00166FE0(i) ((Slot_00166FE0*)(g_Video + (i) * 0x110))

static inline void UM_00166FE0(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void QR_00166FE0(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

static inline unsigned long long Now_00166FE0(void)
{
    return g_TickCounter64 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f);
}

struct V4c_00166FE0 {
    float x, y, z, w;
    V4c_00166FE0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

static inline void SetCol_00166FE0(const V4c_00166FE0& c)
{
    g_TextColourBlock = c.x;
    D_0055A284 = c.y;
    D_0055A288 = c.z;
    D_0055A28C = c.w;
}

extern "C" void func_00166FE0(Screen_00166FE0* self, int first, int last)
{
    int n;
    if (self->anim == 0) return;
    if (!D_004EE4C0) {
        D_004EE4B8 = Now_00166FE0();
        D_004EE4C0 = 1;
    }
    {
        int vpi = (int)&D_00539170;
        Slot_00166FE0* s = SLOT_00166FE0(D_00538C60);
        V4_00166FE0* vp = (V4_00166FE0*)vpi;
        s->r[0] = vp->x;
        s->r[1] = vp->y;
        s->r[2] = vp->z;
        s->r[3] = vp->w;
        s->f2F5 = 1;
        s->f2F6 = 1;
    }
    {
        Slot_00166FE0* s = SLOT_00166FE0(D_00538C60);
        s->f2E0 = 0;
        *(int*)&s->f2E8 = 0x3F800000;
        s->f2F6 = 1;
        s->f2F4 = 1;
    }
    QR_00166FE0(&RS_00166FE0->mtx[D_00538C64 + 1], &RS_00166FE0->mtx[D_00538C64]);
    D_00538C64++;
    UM_00166FE0(&RS_00166FE0->mtx[D_00538C64]);
    D_00538C68 = 1;
    D_005392D8 = D_004BC1B0;
    Video_BeginFrame(g_Video);
    {
        V4c_00166FE0 c(1.0f, 1.0f, 0.0f, 1.0f);
        SetCol_00166FE0(c);
    }
    {
        unsigned long long now = Now_00166FE0();
        func_0027A830(self->anim, SoftFloat_U64ToFloat(now - D_004EE4B8) / 100000.0f);
        D_004EE4B8 = now;
    }
    func_0027A7F0(self->anim);
    D_005392D8 = D_004BC1B0;
    n = last - first - 1;
    if (n != 0) {
        float t = SoftFloat_U64ToFloat((int)Now_00166FE0() % 100000) / 100000.0f;
        V4c_00166FE0 c(1.0f, 1.0f, 1.0f, 1.0f);
        V4_00166FE0 col;
        char buf[0x80];
        col.x = c.x; col.y = c.y; col.z = c.z; col.w = c.w;
        col.w = (t > 0.5f) ? 2.0f * (1.0f - t) : 2.0f * t;
        sprintf(buf, D_0049C400, n, n > 1 ? D_0049C3E8 : D_0049C3F0);
        func_0036A300(self->font, buf, &col, -220, -156, 0.001f);
    }
    TextManager_DrawImmediate(TextManager_Get());
    D_00538C68 = 1;
    D_00538C64--;
    {
        Slot_00166FE0* s = SLOT_00166FE0(D_00538C60);
        s->f2F6 = 1;
        s->f2F4 = 0;
    }
}
