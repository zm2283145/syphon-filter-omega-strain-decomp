/*
 * main/guiTextWidget: range (8 files, 0041C070-0041C560)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "guiTextWidget_types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_0041C070 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C0041C070 { float r, g, b, a; };
struct Q0041C070 { __int128 q; };
struct W0041C070 { char p[0x60]; C0041C070 c; char p70[8]; void* h; };
extern "C" void func_003D0810(void* h, C0041C070* c);
static inline void Set0041C070(C0041C070* d, const C0041C070& s) { d->r = s.r; d->g = s.g; d->b = s.b; d->a = s.a; }
extern "C" void func_0041C070(W0041C070* w, Q0041C070* in)
{
    Q0041C070 t = *in;
    Set0041C070(&w->c, *(C0041C070*)&t);
    if (w->h) func_003D0810(w->h, &w->c);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C070 */

/* merge_units: begin func_0041C0D0 */
#pragma push /* merge_units */
/* Copy the state byte to the optional child widget. */
void func_0041C0D0(GuiTextStateOwnerD0* self, unsigned char state)
{
    self->state = state;
    if (self->child)
        self->child->state = state;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C0D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C0D0 */

/* merge_units: begin func_0041C0F0 */
#pragma push /* merge_units */
/* Copy the state byte to the optional child widget. */
void func_0041C0F0(GuiTextStateOwnerF0* self, unsigned char state)
{
    self->state = state;
    if (self->child)
        self->child->state = state;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C0F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C0F0 */

/* merge_units: begin func_0041C110 */
#pragma push /* merge_units */
typedef struct { char pad[0x11]; unsigned char b11; unsigned char b12; } PC110;
typedef struct { char pad[0x74]; unsigned char mode; char pad2[3]; PC110* p; } TC110;
void func_0041C110(TC110* t, unsigned char mode) {
    t->mode = mode;
    if (t->p) {
        t->p->b12 = t->mode == 0;
        t->p->b11 = t->mode == 2;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C110 */

/* merge_units: begin func_0041C150 */
#pragma push /* merge_units */
#pragma opt_rebuildconditionals off
#pragma cplusplus on

typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
typedef struct Child { int x, y, w, h; } Child;
typedef struct Self {
    char pad0[0x14];
    unsigned short flags;
    char pad16[0x34 - 0x16];
    float x, y, w, h;
    char pad44[0x60 - 0x44];
    float color[4];
    char pad70[0x78 - 0x70];
    Child* child;
} Self;

extern "C" {
extern char D_005381F0[];
extern int D_00538C64;
extern char D_00538C68;
void func_0041E470(Self* self);
#if 0 /* merge_units */
void func_003D0810(Child* c, float* color);
#endif /* merge_units */
#define func_003D0810(a0, a1) (func_003D0810((void *)(a0), (C0041C070 *)(a1))) /* merge_units */

void func_003CFAB0(Child* c);
}

static inline void SetPos(Child* c, int x, int y) { c->x = x; c->y = y; }
static inline void SetSize(Child* c, int w, int h) { c->w = w; c->h = h; }
static inline Mtx* MtxAt(int i) { return &((Render*)D_005381F0)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

extern "C" void func_0041C150(Self* self)
{
    float c[4];
    Mtx saved;
    func_0041E470(self);
    if (self->child == 0) return;
    c[0] = self->color[0];
    c[1] = self->color[1];
    c[2] = self->color[2];
    c[3] = self->color[3];
    if (!(self->flags & 4)) {
        c[0] *= 0.5f;
        c[1] *= 0.5f;
        c[2] *= 0.5f;
    }
    func_003D0810(self->child, c);
    { Mtx* s = MtxAt(D_00538C64); Mtx* d = &saved; GQR(d, s); }
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    SetPos(self->child, (int)self->x, (int)self->y);
    SetSize(self->child, (int)self->w, (int)self->h);
    func_003CFAB0(self->child);
    GQR(MtxAt(D_00538C64), &saved);
    D_00538C68 = 1;
}
#undef func_003D0810 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C150 */

/* merge_units: begin func_0041C310 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Release the owned record at +0xDC (string member at +0x14) under the allocator guard, reset +0x10. */
extern "C" {
void* String_Dtor(void* self, short flags);
void func_0041EBF0(void* self);
}
struct O34DB10 { char pad[0x10]; int a10; char pad14[0x64]; char* aDC; };
extern "C" void func_0041C310(O34DB10* o)
{
    char* p;
    func_0041EBF0(o);
    p = o->aDC;
    if (p) {
        {
            AllocGuard guard;
            if (p) {
                char* s = p + 0x14;
                if (s)
                    String_Dtor(s, 0);
            }
            Mem_Free(0, p, "guiTextWidget.cc", 0x56);
        }
        o->aDC = 0;
    }

}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C310 */

/* merge_units: begin func_0041C3E0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct GuiTextChild {
    char pad00[0x10];
    char value;           /* 0x10 */
    unsigned char right;  /* 0x11 */
    unsigned char left;   /* 0x12 */
    char pad13[0x45];
    unsigned char s58;    /* 0x58 */
    char pad59[2];
    unsigned char s5B;    /* 0x5B */
};

struct GuiText {
    char pad00[0x34];
    float x;              /* 0x34 */
    float y;              /* 0x38 */
    float w;              /* 0x3C */
    float h;              /* 0x40 */
    char pad44[4];
    char text[0xC];       /* 0x48 */
    int resource;         /* 0x54 */
    char pad58[8];
    float color[4];       /* 0x60 */
    int value;            /* 0x70 */
    unsigned char align;  /* 0x74 */
    unsigned char s75;    /* 0x75 */
    unsigned char s76;    /* 0x76 */
    char pad77;
    GuiTextChild* child;  /* 0x78 */
};

extern "C" {
extern char D_004BF2D0[];
void func_0041EFA0(GuiText* self);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
GuiTextChild* func_003D0940(void* p, int x, int y, int w, int h, int resource, float* color);
char* String_CStr(void* s);
void func_003D08B0(GuiTextChild* child, char* text);
}

static inline void* Alloc_C3E0(unsigned int size)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BF2D0, 0x45);
}

static inline void Set75(GuiText* self, unsigned char v)
{
    self->s75 = v;
    if (self->child)
        self->child->s58 = v;
}

static inline void Set76(GuiText* self, unsigned char v)
{
    self->s76 = v;
    if (self->child)
        self->child->s5B = v;
}

extern "C" void func_0041C3E0(GuiText* self)
{
    func_0041EFA0(self);
    if (!self->child) {
        void* p = Alloc_C3E0(0x60);
        if (p)
            p = func_003D0940(p, (int)self->x, (int)self->y, (int)self->w, (int)self->h, self->resource, self->color);
        self->child = (GuiTextChild*)p;
    }
    if (self->child) {
        self->child->left = self->align == 0;
        self->child->right = self->align == 2;
    }
    Set75(self, self->s75);
    Set76(self, self->s76);
    func_003D08B0(self->child, String_CStr(self->text));
    self->child->value = self->value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C3E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C3E0 */

/* merge_units: begin func_0041C560 */
#pragma push /* merge_units */
extern int func_0041F210(GuiWidgetStreamRecord* self, char** cursor);
extern void func_0041BEB0(GuiTextStreamRecord* self, const char* text, int localized);
extern void* Gui_GetScreenList(void);
extern int func_00418420(void* manager, const char* name);

static inline const char* read_string(char** cursor)
{
    const char* start = *cursor;
    while (*(*cursor)++)
        ;
    return start;
}

/* Load two strings, align the stream, and read the text widget's numeric fields. */
int func_0041C560(GuiTextStreamRecord* self, char** cursor)
{
    const char* resource;
    if (!func_0041F210(&self->base, cursor))
        return 0;
    func_0041BEB0(self, read_string(cursor), 1);
    resource = read_string(cursor);
    self->resource = func_00418420(Gui_GetScreenList(), resource);
    *cursor = (char*)(((unsigned int)*cursor + 3) & ~3u);
    self->first = *(float*)*cursor;
    *cursor += 4;
    self->second = *(float*)*cursor;
    *cursor += 4;
    self->third = *(float*)*cursor;
    *cursor += 4;
    self->scale = 1.0f;
    self->value = *(int*)*cursor;
    *cursor += 4;
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C560(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C560 */
