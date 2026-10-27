/*
 * Libs/SFOLib/Source/guiTextEditWidget: 6 files, 0041A0D0-0041A180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041A0D0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiTextEditWidget". */
int GuiTextEditWidget_IsClass(void* self, const char* name)
{
    return strcmp("GuiTextEditWidget", name) == 0;
}
static inline void merge_flush_func_0041A0D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041A0D0 */

/* merge_units: begin func_0041A100 */
#pragma push /* merge_units */
typedef struct { unsigned char lng : 1; unsigned char len : 7; } SS41A100;
typedef struct { union { SS41A100 s; unsigned int w; } h; unsigned int size; } Str41A100;
typedef struct { char p[0x48]; Str41A100 text; char p50[0x3C]; int cursor; } W41A100;
static inline unsigned int Size41A100(Str41A100* s) { return (s->h.w & 1) ? s->size : (unsigned char)s->h.s.len; }
int GuiTextEditWidget_SetCursorPos(W41A100* w, int pos)
{
    int len = Size41A100(&w->text);
    if (pos == -1) pos = len;
    if (len < pos) { w->cursor = len; return 0; }
    if (pos < 0) { w->cursor = 0; return 0; }
    w->cursor = pos;
    return 1;
}
static inline void merge_flush_func_0041A100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041A100 */

/* merge_units: begin func_0041A180 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

struct Alloc_41A180 { char unused; };
union Str_41A180 {
    struct { int w0; int len; char* data; } l;
    struct { unsigned char f : 1; unsigned char n : 7; } s;
    bool IsShort() const { return !(l.w0 & 1); }
    int Size() const { return IsShort() ? (unsigned char)s.n : l.len; }
};
struct O_41A180 {
    VPAD16(p) VPAD4(q) VPAD1(r)
    virtual void Changed();
    char pad[0x44];
    Str_41A180 str;
    char pad54[0x38];
    int cursor;
};
#if 0 /* merge_units */
extern "C" void GuiTextEditWidget_SetCursorPos(O_41A180* o, int c);
#endif /* merge_units */
#define GuiTextEditWidget_SetCursorPos(a0, a1) ((void)GuiTextEditWidget_SetCursorPos((W41A100 *)(a0), (a1))) /* merge_units */

extern "C" void std_basic_string_char_char_traits_char_do_replace(Str_41A180* s, int pos, int count, const char* first, const char* last, Alloc_41A180 a);

extern "C" int GuiTextEditWidget_RemoveCharAtCursor(O_41A180* o, int fwd)
{
    GuiTextEditWidget_SetCursorPos(o, o->cursor);
    if (o->str.Size() == 0) return 0;
    if (fwd) {
        if (o->cursor == o->str.Size()) return 0;
        Alloc_41A180 a;
        std_basic_string_char_char_traits_char_do_replace(&o->str, o->cursor, 1, 0, 0, a);
    } else {
        if (o->cursor == 0) return 0;
        Alloc_41A180 a;
        std_basic_string_char_char_traits_char_do_replace(&o->str, o->cursor - 1, 1, 0, 0, a);
        o->cursor--;
    }
    o->Changed();
    return 1;
}
#undef GuiTextEditWidget_SetCursorPos /* merge_units */
static inline void merge_flush_func_0041A180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041A180 */

/* merge_units: begin func_0041A2C0 */
#pragma push /* merge_units */
#pragma cplusplus on

union Str_41A2C0 {
    struct { int w0; int len; char* data; } l;
    struct { unsigned char f : 1; unsigned char n : 7; } s;
    int Size() const { return (l.w0 & 1) ? l.len : (unsigned char)s.n; }
};
struct O_41A2C0 {
    VPAD16(p) VPAD4(q) VPAD1(r)
    virtual void Changed();
    char pad[0x44];
    Str_41A2C0 str;
    char pad54[0x30];
    int maxLen;
    char pad88[4];
    int cursor;
};
extern "C" {
void std_basic_string_char_char_traits_char_ctor_charP(Str_41A2C0* s, char* c);
void String_Dtor(Str_41A2C0* s, int f);
void cString_Substr(Str_41A2C0* out, Str_41A2C0* s, int a, int b);
void opAdd_cStringR_cStringR(Str_41A2C0* out, Str_41A2C0* a, Str_41A2C0* b);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str_41A2C0* d, Str_41A2C0* s);
#if 0 /* merge_units */
void GuiTextEditWidget_SetCursorPos(O_41A2C0* o, int c);
#endif /* merge_units */
#define GuiTextEditWidget_SetCursorPos(a0, a1) ((void)GuiTextEditWidget_SetCursorPos((W41A100 *)(a0), (a1))) /* merge_units */


}

extern "C" int GuiTextEditWidget_InsertAtCursor(O_41A2C0* o, char* text)
{
    Str_41A2C0 s;
    Str_41A2C0 left;
    Str_41A2C0 right;
    std_basic_string_char_char_traits_char_ctor_charP(&s, text);
    if (o->maxLen > 0 && s.Size() + o->str.Size() >= o->maxLen) {
        String_Dtor(&s, 0);
        return 0;
    }
    cString_Substr(&left, &o->str, 0, o->cursor);
    cString_Substr(&right, &o->str, o->cursor, -1);
    {
        Str_41A2C0 t1;
        Str_41A2C0 t2;
        opAdd_cStringR_cStringR(&t1, &left, &s);
        opAdd_cStringR_cStringR(&t2, &t1, &right);
        std_basic_string_char_char_traits_char_assign_basicstringR(&o->str, &t2);
        String_Dtor(&t2, 0);
        String_Dtor(&t1, 0);
    }
    GuiTextEditWidget_SetCursorPos(o, o->cursor + s.Size());
    o->Changed();
    String_Dtor(&right, 0);
    String_Dtor(&left, 0);
    String_Dtor(&s, 0);
    return 1;
}
#undef GuiTextEditWidget_SetCursorPos /* merge_units */
static inline void merge_flush_func_0041A2C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041A2C0 */

/* merge_units: begin func_0041A450 */
#pragma push /* merge_units */
#pragma opt_rebuildconditionals off
#pragma cplusplus on

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
extern char g_Video[];
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
extern int g_DrawMode;
void XLib_NewStrip(char* r);
void XLib_NextBatchVert(char* r);
void cVector_opAssign(void* d, V4* s);
int* tIRGBA_opAssign_tRGBAR(void* out, V4* in);
void XLib_DrawLines(char* r);
void GuiTextWidget_onRender(Self* self);
Scr* Gui_Canvas(void);
int cTextArea_Render(int a, float* x, float* y, int d);
int cFont_GetCharH(int a);
extern V4 D_005720E0;
}

#define SlotAt(i) ((Slot*)(g_Video + 0x1F0 + (i) * 0x110))
#define EntAt(i) ((Ent*)(g_Video + 0xFB0 + (i) * 0x38))
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

static inline V4 Pt(float x, float y) { return V4(x, y, 1.0f, 0.0f); }

static inline void Vertex(V4* p, V4* c) {
    Ent* e;
    XLib_NextBatchVert(g_Video);
    e = EntAt(D_00539210);
    cVector_opAssign(e->pos + (D_00539224 - 1) * 16, p);
    tIRGBA_opAssign_tRGBAR(e->c30 + (D_00539224 - 1) * 16, c);
    D_005381F8 = 0x200000000LL;
}

extern "C" void GuiTextEditWidget_onRender(Self* self)
{
    GuiTextWidget_onRender(self);
    if (self->f78 == 0) return;
    if (self->f88 == 0 && Gui_Canvas()->top != self) return;
    float x = 0;
    float y = 0;
    if (!cTextArea_Render(self->f78, &x, &y, self->f8C)) return;
    float h = cFont_GetCharH(self->f54);
    int save = g_DrawMode;
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    g_DrawMode = 0;
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
        { unsigned char t; if (g_DrawMode & 1) t = 3; else t = 2; D_00539238 = t; }
        { int m; if (g_DrawMode & 1) m = 0x41; else m = 0x62; D_0053923C = m; }
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
            XLib_NewStrip(g_Video);
            D_00539224 = 0;
        }
        Vertex(&p[0], &D_005720E0);
        Vertex(&p[1], &D_005720E0);
        XLib_DrawLines(g_Video);
    }
    g_DrawMode = save;
    D_00538C68 = 1;
    D_00538C64--;
}
static inline void merge_flush_func_0041A450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041A450 */

/* merge_units: begin func_0041A8C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Quad* func_0041A8C0(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}
static inline void merge_flush_func_0041A8C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041A8C0 */
