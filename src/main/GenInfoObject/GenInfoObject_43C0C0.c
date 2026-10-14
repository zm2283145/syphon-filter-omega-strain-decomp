/*
 * main/GenInfoObject: 6 files, 0043C0C0-0043C730
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043C0C0 */
#pragma push /* merge_units */
#include "types.h"
extern int strcmp(void* p);
/* Returns whether the test on the global object fails. */
int func_0043C0C0(void) { return strcmp("GuiBitmapWidget") == 0; }
#pragma pop /* merge_units */
/* merge_units: end func_0043C0C0 */

/* merge_units: begin func_0043C0F0 */
#pragma push /* merge_units */
#pragma opt_rebuildconditionals off
#pragma cplusplus on

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& s) { __int128* pd = (__int128*)this; const __int128* ps = (const __int128*)&s; *pd = *ps; }
    V4& operator=(const V4& s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&s) : "memory"); void* xx = this; return *this; }
} __attribute__((aligned(16)));
struct V4c {
    float x, y, z, w;
    V4c(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Slot { float color[4]; char pad10[0x105 - 0x10]; char b105; char b106; char pad107[0x110 - 0x107]; } Slot;
typedef struct Ent { char pad[0x28]; char* pos; char* c2C; char* c30; char* c34; } Ent;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
struct TexInfo { int pad0; unsigned short w; unsigned short h; };
struct Tex { char pad[0x44]; TexInfo* info; };
struct TexMan { char pad[8]; Tex** texs; };
struct Self {
    char pad0[0x34];
    float x, y, w, h;
    char pad44[4];
    int tex;
    char pad4C[0x60 - 0x4C];
    V4 color;
    float z;
};

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
extern TexMan* D_00539248;
extern int D_005392D0;
void func_0041E470(Self* self);
void func_003820E0(TexMan* m, int idx);
void func_0025CD10(char* r);
void func_0025CA40(char* r);
void Vec4_Copy(void* d, const void* s);
void func_0025C9D0(void* out, const void* in);
float func_0025F220(void);
V4* func_00132000(V4* o, float x, float y, float z, float w);
void func_00370550(char* r);
}

#define SlotAt(i) ((Slot*)(D_005381F0 + 0x1F0 + (i) * 0x110))
#define EntAt(i) ((Ent*)(D_005381F0 + 0xFB0 + (i) * 0x38))
static inline Mtx* MtxAt(int i) { return &((Render*)D_005381F0)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

static inline Tex* TexQ(TexMan* m, int i) { return m->texs[i]; }

static inline void Emit(const V4& pos, const V4& col, const V4c& uv)
{
    V4 tmp;
    Ent* e;
    float u;
    func_0025CA40(D_005381F0);
    e = EntAt(D_00539210);
    Vec4_Copy(e->pos + (D_00539224 - 1) * 16, &pos);
    func_0025C9D0(e->c30 + (D_00539224 - 1) * 16, &col);
    u = uv.x + func_0025F220();
    Vec4_Copy(e->c34 + (D_00539224 - 1) * 16, func_00132000(&tmp, u, uv.y + func_0025F220(), uv.z, uv.w));
    D_005381F8 = 6LL << 32;
}

extern "C" void func_0043C0F0(Self* self)
{
    func_0041E470(self);
    if (self->tex == -1) return;
    int save = D_005392D0;
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    D_005392D0 = 5;
    func_003820E0(D_00539248, self->tex);
    {
        Slot* s = SlotAt(D_00538C60);
        float* v = D_00539170;
        s->color[0] = v[0];
        s->color[1] = v[1];
        s->color[2] = v[2];
        s->color[3] = v[3];
        s->b105 = 1;
        s->b106 = 1;
    }
    V4 p1;
    V4 p0;
    p0 = V4(self->x, self->y, self->z, 0.0f);
    p1 = V4(self->x + self->w, self->y - self->h, self->z, 0.0f);
    float us = 1.0f;
    float vs = 1.0f;
    float tw = (int)TexQ(D_00539248, self->tex)->info->w;
    float th = (int)TexQ(D_00539248, self->tex)->info->h;
    if (tw == 1024.0f && th == 512.0f) {
        us = 0.625f;
        vs = 0.9375f;
    }
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
    Emit(p0, self->color, V4c(0.0f, 0.0f, 1.0f, 0.0f));
    Emit(p1, self->color, V4c(us, vs, 1.0f, 0.0f));
    func_00370550(D_005381F0);
    D_005392D0 = save;
    D_00538C68 = 1;
    D_00538C64--;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043C0F0 */

/* merge_units: begin func_0043C6A0 */
#pragma push /* merge_units */
/* Returns 2048.0f. */
float func_0043C6A0(void)
{
    return 2048.0f;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043C6A0 */

/* merge_units: begin func_0043C6B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GenInfoObject.cc (ends 0x0043BA00),
 * before guiMLTextWidget.cc (starts 0x0043DB80).
 */


Quad* func_0043C6B0(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043C6B0 */

/* merge_units: begin func_0043C6E0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_003813A0(int, int, int);                       
#if 0 /* merge_units */
extern int D_00539248;
#endif /* merge_units */
#define D_00539248 (*(int*)&D_00539248) /* merge_units */


#pragma opt_common_subs off
void func_0043C6E0(int arg0) {
    int temp_a1;

    temp_a1 = F_(arg0, 0x48, int);
    if (temp_a1 != -1) {
        func_003813A0(D_00539248, temp_a1, 0);
        F_(arg0, 0x48, int) = -1;
    }
}
#undef D_00539248 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043C6E0 */

/* merge_units: begin func_0043C730 */
#pragma push /* merge_units */
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Hog_Register();                   
int String_CStr();                          
int func_002071F0();                             
int func_0036E220();                            
int func_0036E4B0();                    
int func_0036E5D0();                               
int func_00380A40();                        
#if 0 /* merge_units */
extern int D_00539248;
#endif /* merge_units */
#define D_00539248 (*(int*)&D_00539248) /* merge_units */


#pragma push
#pragma opt_common_subs off
int func_0043C730(char * arg0) {
    struct { int f20[40]; int fC0[40]; } sl;

    if (func_002071F0(arg0 + 0x50) == 0) {
        return 0;
    }
    if (F_(arg0, 0x4C, int) != 0) {
        func_0036E5D0(sl.fC0);
        Hog_Register(sl.fC0, String_CStr(arg0 + 0x50), F_(arg0, 0x4C, int), 0);
        F_(arg0, 0x48, int) = func_00380A40(D_00539248, sl.fC0);
        func_0036E220(sl.fC0, -1);
    } else {
        func_0036E4B0(sl.f20, String_CStr(arg0 + 0x50), 0, 0);
        F_(arg0, 0x48, int) = func_00380A40(D_00539248, sl.f20);
        func_0036E220(sl.f20, -1);
    }
    return ~F_(arg0, 0x48, int) != 0;
}
#pragma pop
#undef D_00539248 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043C730 */
