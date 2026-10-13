#pragma opt_rebuildconditionals off
#pragma cplusplus on

#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& s) { __int128* pd = (__int128*)this; const __int128* ps = (const __int128*)&s; *pd = *ps; }
    V4& operator=(const V4& s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&s) : "memory"); void* xx = this; /* dead on purpose: retail keeps this addiu */ return *this; }
} __attribute__((aligned(16)));
typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Slot { V4 color; char pad10[0x105 - 0x10]; char b105; char b106; char pad107[0x110 - 0x107]; } Slot;
typedef struct Ent { char pad[0x28]; char* pos; char* c2C; char* c30; char* c34; } Ent;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
typedef struct Scr { char pad[0x20]; void* top; } Scr;
typedef struct Self { char pad[0x54]; int f54; char pad58[0x78 - 0x58]; int f78; char pad7C[0x88 - 0x7C]; unsigned char f88; char pad89[3]; int f8C; } Self;

extern "C" {
extern char D_005381F0[];
extern long long D_005381F8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern float D_00539170[4];
extern int D_00539210;
extern int D_00539224;
extern int D_00539228;
extern int D_00539238;
extern int D_0053923C;
extern int D_005392D0;
void func_0025CD10(char* r);
void func_0025CA40(char* r);
void Vec4_Copy(void* d, V4* s);
int* func_0025C9D0(void* out, V4* in);
void func_003701B0(char* r);
void func_0041C150(Self* self);
Scr* Gui_GetScreenStack(void);
int func_003CF3A0(int a, float* x, float* y, int d);
int func_0036A2F0(int a);
extern V4 D_005720E0;
}

#define SlotAt(i) ((Slot*)(D_005381F0 + 0x1F0 + (i) * 0x110))
#define EntAt(i) ((Ent*)(D_005381F0 + 0xFB0 + (i) * 0x38))
static inline Mtx* MtxAt(int i) { return &((Render*)D_005381F0)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

static inline V4 Pt(float x, float y) { return V4(x, y, 1.0f, 0.0f); }

static inline void Vertex(V4* p, V4* c) {
    Ent* e;
    func_0025CA40(D_005381F0);
    e = EntAt(D_00539210);
    Vec4_Copy(e->pos + (D_00539224 - 1) * 16, p);
    func_0025C9D0(e->c30 + (D_00539224 - 1) * 16, c);
    D_005381F8 = 0x200000000LL;
}

extern "C" void func_0041A450(Self* self)
{
    func_0041C150(self);
    if (self->f78 == 0) return;
    if (self->f88 == 0 && Gui_GetScreenStack()->top != self) return;
    float x = 0;
    float y = 0;
    if (!func_003CF3A0(self->f78, &x, &y, self->f8C)) return;
    float h = func_0036A2F0(self->f54);
    int save = D_005392D0;
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_005392D0 = 0;
    V4 p[4];
    {
        int i;
        Slot* s;
        float* v;
        v = D_00539170;
        i = D_00538C60;
        D_00538C68 = 1;
        s = SlotAt(i);
        s->color.x = v[0];
        s->color.y = v[1];
        s->color.z = v[2];
        s->color.w = v[3];
        s->b105 = 1;
        s->b106 = 1;
    }
    {
        p[0] = Pt(x, y);
        p[1] = Pt(x, y - h);
        { unsigned char t; if (D_005392D0 & 1) t = 3; else t = 2; D_00539238 = t; }
        { int m; if (D_005392D0 & 1) m = 0x41; else m = 0x62; D_0053923C = m; }
        D_00539228 = 0;
        {
            int m = D_0053923C;
            Ent* e;
            D_0053923C = m & ~1;
            e = EntAt(D_00539210);
            e->pos += D_00539224 * 16;
            e->c2C += D_00539224 * 16;
            e->c30 += D_00539224 * 16;
            e->c34 += D_00539224 * 16;
            func_0025CD10(D_005381F0);
            D_00539224 = 0;
        }
        Vertex(&p[0], &D_005720E0);
        Vertex(&p[1], &D_005720E0);
        func_003701B0(D_005381F0);
    }
    D_005392D0 = save;
    D_00538C68 = 1;
    D_00538C64--;
}

