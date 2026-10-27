/*
 * SFOGame/Source/GuiSlideShow: 6 files, 00327D90-003282A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00327D90 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char p0[0x10]; int n; char p14[0xC]; } E327D90;
typedef struct { char p0[0x14]; unsigned short flags; } W327D90;
typedef struct {
    char p0[0x4C]; int count; E327D90* data; char p54[0x10]; W327D90* w64;
    char p68[0xD4 - 0x68]; unsigned char active;
} S327D90;
extern void* D_004FFC04;
extern char* D_00491560;
extern char* D_00491568;
extern void GuiWidget_onWake(S327D90* self);
extern void cMemMan_ReleaseBin(int a0);
extern void cMemMan_Init_int_uint_uint(int a0, int a1, int a2);
extern void cGameFrontEnd_PlayMusic(void* a0, int a1);
extern void GuiSlideShow_UpdateCurrentSlide(S327D90* self);
extern W327D90* GuiWidget_FindChild_charP(S327D90* self, char* name);
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
/* Total number of sub-items over all entries (inlined GuiSlideShow_GetNumSlides; the
   data pointer is loaded once after the guard). */
static inline int Count327D90(S327D90* l)
{
    int total = 0;
    int i;
    int j;
    E327D90* d;
    int n;
    i = 0;
    if (0 < *(volatile int*)&l->count) {
        d = l->data;
        do {
            n = d[i].n;
            for (j = 0; j < n; j++) total++;
            i++;
        } while (i < *(volatile int*)&l->count);
    }
    return total;
}
void GuiSlideShow_onWake(S327D90* self)
{
    int n;
    W327D90* w;
    GuiWidget_onWake(self);
    cMemMan_ReleaseBin(1);
    cMemMan_Init_int_uint_uint(1, 0x100000, 0x800);
    cGameFrontEnd_PlayMusic(D_004FFC04, 2);
    self->active = 0;
    GuiSlideShow_UpdateCurrentSlide(self);
    n = Count327D90(self);
    w = self->w64;
    if (w) {
        if (n > 1) w->flags |= 2;
        else w->flags &= ~2;
    }
    w = GuiWidget_FindChild_charP(self, D_00491560);
    if (w) {
        if (n > 1) w->flags |= 2;
        else w->flags &= ~2;
    }
    w = GuiWidget_FindChild_charP(self, D_00491568);
    if (w) {
        if (n > 1) w->flags |= 2;
        else w->flags &= ~2;
    }
}
static inline void merge_flush_func_00327D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327D90 */

/* merge_units: begin func_00327F20 */
#pragma push /* merge_units */
typedef struct { char p0[0x10]; int n; char p14[0xC]; } E327F20;
typedef struct { char p0[0x4C]; int count; E327F20* data; } L327F20;
#pragma opt_strength_reduction off
/* Total number of sub-items over all entries. */
int GuiSlideShow_GetNumSlides(L327F20* l)
{
    int total = 0; int i;
    for (i = 0; i < *(volatile int*)&l->count; i++) {
        int j; int n = l->data[i].n;
        for (j = 0; j < n; j++) total++;
    }
    return total;
}
static inline void merge_flush_func_00327F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327F20 */

/* merge_units: begin func_00327FD0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W327FD0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* type);
};
struct F327FD0 { char p0[0x14]; unsigned short flags; };
struct S327FD0 { char p0[0x5C]; W327FD0* w5C; W327FD0* w60; W327FD0* w64; W327FD0* w68; };
extern "C" {
extern char* D_00491548;
extern char* D_00491540;
extern char* D_00491550;
extern char* D_00491558;
extern char D_004B88F0[];
extern char D_004A7520[];
void GuiWidget_onAdd(S327FD0* self);
#if 0 /* merge_units */
W327FD0* GuiWidget_FindChild_charP(S327FD0* a, char* b);
#endif /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((W327FD0 *)GuiWidget_FindChild_charP((S327D90 *)(a0), (a1))) /* merge_units */


void GuiTextWidget_SetDisableWrap(W327FD0* w, int a);
}
extern "C" void GuiSlideShow_onAdd(S327FD0* self)
{
    W327FD0* p;
    GuiWidget_onAdd(self);
    p = GuiWidget_FindChild_charP(self, D_00491548);
    self->w5C = (p && p->IsA(D_004B88F0)) ? p : 0;
    if (self->w5C)
        ((F327FD0*)self->w5C)->flags &= ~2;
    p = GuiWidget_FindChild_charP(self, D_00491540);
    self->w60 = (p && p->IsA(D_004A7520)) ? p : 0;
    if (self->w60)
        GuiTextWidget_SetDisableWrap(self->w60, 1);
    p = GuiWidget_FindChild_charP(self, D_00491550);
    self->w64 = (p && p->IsA(D_004A7520)) ? p : 0;
    p = GuiWidget_FindChild_charP(self, D_00491558);
    self->w68 = (p && p->IsA(D_004A7520)) ? p : 0;
}
#undef GuiWidget_FindChild_charP /* merge_units */
static inline void merge_flush_func_00327FD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327FD0 */

/* merge_units: begin func_00328140 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } Str_328140;
typedef struct { Str_328140 name; int val; Str_328140 desc; unsigned char flag; char pad[0x2C - 0x1D]; } E_328140;
typedef struct { char p0[0xC]; char list[4]; int count; E_328140* data; char p18[8]; } G_328140;
typedef struct {
    char pad[0x4C];
    int count;
    G_328140* data;
} O_328140;
extern char D_004B8790[];
void cString_ctor_void(void* s);
void std_basic_string_char_char_traits_char_ctor_charP(Str_328140* s, char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str_328140* d, Str_328140* s);
void String_Dtor(void* s, int f);
void std_vector_imp_Slide_insert(void* v, E_328140* pos, int n, E_328140* e);

static inline void CtorE_328140(E_328140* e)
{
    cString_ctor_void(&e->name);
    cString_ctor_void(&e->desc);
}
static inline void DtorS_328140(Str_328140* s)
{
    if (s) String_Dtor(s, 0);
}
static inline G_328140* At_328140(O_328140* self, int i)
{
    if (i < 0 || self->count <= i) return 0;
    return &self->data[i];
}

int GuiSlideShow_AddSlide(O_328140* o, int idx, char* name, int val, char* desc)
{
    G_328140* g = At_328140(o, idx);
    if (g == 0) return -1;
    {
        E_328140 e;
        Str_328140 ta;
        Str_328140 tb;
        int r;
        CtorE_328140(&e);
        std_basic_string_char_char_traits_char_ctor_charP(&ta, name);
        std_basic_string_char_char_traits_char_assign_basicstringR(&e.name, &ta);
        String_Dtor(&ta, 0);
        e.val = val;
        { Str_328140* p = &tb; std_basic_string_char_char_traits_char_ctor_charP(p, desc ? desc : D_004B8790); }
        std_basic_string_char_char_traits_char_assign_basicstringR(&e.desc, &tb);
        String_Dtor(&tb, 0);
        e.flag = 0;
        std_vector_imp_Slide_insert(g->list, g->data + g->count, 1, &e);
        r = g->count - 1;
        DtorS_328140(&e.desc);
        String_Dtor(&e, 0);
        return r;
    }
}
static inline void merge_flush_func_00328140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00328140 */

/* merge_units: begin func_003282A0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void*);
#if 0 /* merge_units */
extern "C" void String_Dtor(void*, short);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((a0), (int)(a1))) /* merge_units */

extern "C" void* GuiSlideShow_Slide_dtor(void* self, short del)
{
    if (self) {
        char* m = (char*)self + 0x10;
        if (m) String_Dtor(m, 0);
        if (self) String_Dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_003282A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003282A0 */

/* merge_units: begin func_00328310 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } Str_328310;
typedef struct { int a, b, c, d; } Sub_328310;
typedef struct { Str_328310 name; Sub_328310 sub; int x; } E_328310;
typedef struct {
    char pad[0x48];
    char v48[4];
    int n4C;
    E_328310* v50;
} O_328310;
void cArray_Slide_ctor(void* s);
#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_ctor_charP(Str_328310* s, char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((Str_328140 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_assign_basicstringR(Str_328310* d, Str_328310* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_assign_basicstringR(a0, a1) (std_basic_string_char_char_traits_char_assign_basicstringR((Str_328140 *)(a0), (Str_328140 *)(a1))) /* merge_units */


void std_vector_imp_Section_insert(void* v, E_328310* pos, int n, E_328310* e);
void std_vector_deleter_Slide_dtor(void* s, int f);

int GuiSlideShow_AddSection(O_328310* o, char* s)
{
    E_328310 e;
    Str_328310 t;
    int r;
    Sub_328310* m;
    cString_ctor_void(&e);
    m = &e.sub;
    cArray_Slide_ctor(m);
    { Str_328310* p = &t; std_basic_string_char_char_traits_char_ctor_charP(p, s ? s : D_004B8790); }
    std_basic_string_char_char_traits_char_assign_basicstringR(&e.name, &t);
    String_Dtor(&t, 0);
    e.x = 0;
    std_vector_imp_Section_insert(o->v48, o->v50 + o->n4C, 1, &e);
    r = o->n4C - 1;
    if (m) {
        if (m) {
            if (m) std_vector_deleter_Slide_dtor(m, 0);
        }
    }
    String_Dtor(&e, 0);
    return r;
}
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_assign_basicstringR /* merge_units */
static inline void merge_flush_func_00328310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00328310 */
