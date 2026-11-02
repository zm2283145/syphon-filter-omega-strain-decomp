/*
 * Libs/SFOLib/Source/guiBitmapWidget: 9 files, 0043C810-0043CAA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GenInfoObject_43C810 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int std_basic_string_char_char_traits_char_ctor_charP(char *, char *);                 
int String_Dtor(char *, int);                            
int std_basic_string_char_char_traits_char_assign_basicstringR(char * , char *);                       
int cTexMan_RemoveTexture(int, int, int);                       
const unsigned int D_004C0018[2] = { 0x0, 0x0 };
extern int g_TextureMgr;

#pragma push
#pragma opt_common_subs off
void GuiBitmapWidget_ClearBitmap(char * arg0) {
    struct { int f20[4]; } sl;
    int temp_a1;

    temp_a1 = F_(arg0, 0x48, int);
    if (temp_a1 != -1) {
        cTexMan_RemoveTexture(g_TextureMgr, temp_a1, 0);
        F_(arg0, 0x48, int) = -1;
    }
    F_(arg0, 0x4C, int) = 0;
    std_basic_string_char_char_traits_char_ctor_charP(sl.f20, &(*(char*)D_004C0018));
    std_basic_string_char_char_traits_char_assign_basicstringR(arg0 + 0x50, sl.f20);
    String_Dtor(sl.f20, 0);
}
#pragma pop
static inline void merge_flush_GenInfoObject_43C810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GenInfoObject_43C810 */

/* merge_units: begin func_0043C890 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } Str_43C890;
typedef struct { char* p; } It_43C890;
typedef struct { char pad[0x14]; unsigned short flags; char pad16[0x32]; int h48; int f4C; Str_43C890 name; } O_43C890;
#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_43C890* s, char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) ((void)std_basic_string_char_char_traits_char_ctor_charP((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_assign_basicstringR(Str_43C890* d, Str_43C890* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_assign_basicstringR(a0, a1) ((void)std_basic_string_char_char_traits_char_assign_basicstringR((char *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_Dtor(Str_43C890* s, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) ((void)String_Dtor((char *)(a0), (a1))) /* merge_units */

extern void std_basic_string_char_char_traits_char_begin(It_43C890* out, Str_43C890* s);
extern void std_basic_string_char_char_traits_char_end(It_43C890* out, Str_43C890* s);
extern int std_opNe_wrapiteratorR_wrapiteratorR(It_43C890* a, It_43C890* b);
extern char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_43C890* a);
extern void std_wrap_iterator_basic_string_char_charPtr_opInc(It_43C890* a);
#if 0 /* merge_units */
extern void cTexMan_RemoveTexture(int a, int b, int c);
#endif /* merge_units */
#define cTexMan_RemoveTexture(a0, a1, a2) ((void)cTexMan_RemoveTexture((a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int GuiBitmapWidget_LoadBitmap(O_43C890* o);
#endif /* merge_units */
int GuiBitmapWidget_LoadBitmap(void*); /* merge_units */
#define GuiBitmapWidget_LoadBitmap(a0) (GuiBitmapWidget_LoadBitmap((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern char D_004C0018[];
#endif /* merge_units */
#define D_004C0018 ((char*)&D_004C0018) /* merge_units */


int GuiBitmapWidget_SetBitmap(O_43C890* o, char* name, int arg)
{
    Str_43C890 t2;
    Str_43C890 t;
    if (o->h48 != -1) {
        cTexMan_RemoveTexture(g_TextureMgr, o->h48, 0);
        o->h48 = -1;
    }
    o->f4C = 0;
    {
        std_basic_string_char_char_traits_char_ctor_charP(&t, D_004C0018);
        std_basic_string_char_char_traits_char_assign_basicstringR(&o->name, &t);
        String_Dtor(&t, 0);
    }
    if (name == 0 || *name == 0) return 1;
    o->f4C = arg;
    {
        It_43C890 it;
        It_43C890 end;
        std_basic_string_char_char_traits_char_ctor_charP(&t2, name);
        std_basic_string_char_char_traits_char_assign_basicstringR(&o->name, &t2);
        String_Dtor(&t2, 0);
        std_basic_string_char_char_traits_char_begin(&it, &o->name);
        std_basic_string_char_char_traits_char_end(&end, &o->name);
        while (std_opNe_wrapiteratorR_wrapiteratorR(&it, &end)) {
            if (*std_wrap_iterator_basic_string_char_charPtr_opMul(&it) >= 'a' && *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) <= 'z') *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) -= 0x20;
            std_wrap_iterator_basic_string_char_charPtr_opInc(&it);
        }
    }
    if (o->flags & 8) return GuiBitmapWidget_LoadBitmap(o);
    return 1;
}
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_assign_basicstringR /* merge_units */
#undef String_Dtor /* merge_units */
#undef cTexMan_RemoveTexture /* merge_units */
#undef GuiBitmapWidget_LoadBitmap /* merge_units */
#undef D_004C0018 /* merge_units */
static inline void merge_flush_func_0043C890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043C890 */

/* merge_units: begin func_0043CA20 */
#pragma push /* merge_units */
typedef struct { int words[3]; } String;
typedef struct { char pad[0x48]; int handle; int unk4C; String name; } Obj;
#if 0 /* merge_units */
extern void* g_TextureMgr;
#endif /* merge_units */
#define g_TextureMgr (*(void **)&g_TextureMgr) /* merge_units */


extern void GuiWidget_onRemove(Obj* self);
#if 0 /* merge_units */
extern void cTexMan_RemoveTexture(void* mgr, int handle, int a2);
#endif /* merge_units */
#define cTexMan_RemoveTexture(a0, a1, a2) ((void)cTexMan_RemoveTexture((int)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) ((void)std_basic_string_char_char_traits_char_ctor_charP((char *)(a0), (char *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String* dst, String* src);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_assign_basicstringR(a0, a1) ((void)std_basic_string_char_char_traits_char_assign_basicstringR((char *)(a0), (char *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void String_Dtor(String* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) ((void)String_Dtor((char *)(a0), (a1))) /* merge_units */



/* Resets: base reset, releases the handle, clears fields and the name. */
void GuiBitmapWidget_onRemove(Obj* self)
{
    String tmp;
    GuiWidget_onRemove(self);
    if (self->handle != -1) {
        cTexMan_RemoveTexture(g_TextureMgr, self->handle, 0);
        self->handle = -1;
    }
    self->unk4C = 0;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp, D_004C0018);
    std_basic_string_char_char_traits_char_assign_basicstringR(&self->name, &tmp);
    String_Dtor(&tmp, 0);
}
#undef g_TextureMgr /* merge_units */
#undef cTexMan_RemoveTexture /* merge_units */
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_assign_basicstringR /* merge_units */
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_0043CA20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043CA20 */

/* merge_units: begin func_0043CAA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between GenInfoObject.cc and guiMLTextWidget.cc; gui widget code.
 */

#include "loose05_types.h"

extern char D_004E0FC0[]; /* vtable */
#if 0 /* merge_units */
extern int cTexMan_RemoveTexture(int registry, int handle, int arg);
#endif /* merge_units */
#define cTexMan_RemoveTexture(a0, a1, a2) (cTexMan_RemoveTexture((a0), (a1), (a2))) /* merge_units */

extern int GuiWidget_onSleep(void* self);
extern int GuiWidget_onWake(void* self);
extern void GuiWidget_ctor(void* self);
#if 0 /* merge_units */
extern int GuiBitmapWidget_LoadBitmap(GuiWidget43CB20* self);
#endif /* merge_units */
#define GuiBitmapWidget_LoadBitmap(a0) (GuiBitmapWidget_LoadBitmap((void *)(a0))) /* merge_units */


/* Shutdown: base shutdown, then releases the held registry handle. */
void GuiBitmapWidget_onSleep(GuiWidget43CB20* self) {
    GuiWidget_onSleep(self);
    if (self->handle != -1) {
        cTexMan_RemoveTexture(g_TextureMgr, self->handle, 0);
        self->handle = -1;
    }
}

int GuiBitmapWidget_onWake(GuiWidget43CB20* self) {
    GuiWidget_onWake(self);
    return GuiBitmapWidget_LoadBitmap(self);
}

/* Constructor: no handle, white color. */
GuiWidget43CB20* GuiBitmapWidget_ctor(GuiWidget43CB20* self) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004E0FC0;
    self->unk50 = 0;
    self->unk54 = 0;
    self->unk58 = 0;
    self->handle = -1;
    self->unk4C = 0;
    self->color[0] = 1.0f;
    self->color[1] = 1.0f;
    self->color[2] = 1.0f;
    self->color[3] = 1.0f;
    self->unk70 = 1.0f;
    return self;
}
#undef cTexMan_RemoveTexture /* merge_units */
#undef GuiBitmapWidget_LoadBitmap /* merge_units */
static inline void merge_flush_func_0043CAA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043CAA0 */

/* merge_units: begin func_0043CB90 */
#pragma push /* merge_units */
typedef struct { char unused; } Alloc0043CB90; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } Str0043CB90;
extern int strlen(const char* s);
extern void std_basic_string_char_char_traits_char_reserve(Str0043CB90* str, int n);
extern void std_basic_string_char_char_traits_char_do_replace(Str0043CB90* str, int pos, int count, const char* first, const char* last, Alloc0043CB90 alloc);
/* Construct a string from a C string. */
Str0043CB90* String_CtorCStr_43CB90(Str0043CB90* str, const char* s)
{
    Alloc0043CB90 alloc;
    int n;
    str->w0 = 0;
    str->w4 = 0;
    str->w8 = 0;
    n = strlen(s);
    std_basic_string_char_char_traits_char_reserve(str, n);
    std_basic_string_char_char_traits_char_do_replace(str, 0, 0, s, s + n, alloc);
    return str;
}
static inline void merge_flush_func_0043CB90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043CB90 */

/* merge_units: begin func_0043CC10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004C0020[] = "basic_string: out_of_range"; char D_004C0040[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_0043CC10, D_004C0020, D_004C0040, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_004976A8, D_004976B0, Libc_Memmove, std_basic_string_char_char_traits_char_assign_charP_charP_intP)
static inline void merge_flush_func_0043CC10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043CC10 */

/* merge_units: begin func_0043D100 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_0043D100)
static inline void merge_flush_func_0043D100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043D100 */

/* merge_units: begin func_0043D190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004C0060[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(String_Reserve_43D190, D_004C0060, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
static inline void merge_flush_func_0043D190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043D190 */

/* merge_units: begin func_0043D4D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_43D4D0)
static inline void merge_flush_func_0043D4D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043D4D0 */
