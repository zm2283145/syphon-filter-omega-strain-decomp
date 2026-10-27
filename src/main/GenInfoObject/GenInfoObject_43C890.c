/*
 * main/GenInfoObject: 2 files, 0043C890-0043CA20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043C890 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_43C890;
typedef struct { char* p; } It_43C890;
typedef struct { char pad[0x14]; unsigned short flags; char pad16[0x32]; int h48; int f4C; Str_43C890 name; } O_43C890;
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_43C890* s, char* c);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(Str_43C890* d, Str_43C890* s);
extern void String_Dtor(Str_43C890* s, int f);
extern void std_basic_string_char_char_traits_char_begin(It_43C890* out, Str_43C890* s);
extern void std_basic_string_char_char_traits_char_end(It_43C890* out, Str_43C890* s);
extern int std_opNe_wrapiteratorR_wrapiteratorR(It_43C890* a, It_43C890* b);
extern char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_43C890* a);
extern void std_wrap_iterator_basic_string_char_charPtr_opInc(It_43C890* a);
extern void cTexMan_RemoveTexture(int a, int b, int c);
extern int GuiBitmapWidget_LoadBitmap(O_43C890* o);
extern int g_TextureMgr;
extern char D_004C0018[];

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
#define cTexMan_RemoveTexture(a0, a1, a2) (cTexMan_RemoveTexture((int)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((Str_43C890 *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String* dst, String* src);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_assign_basicstringR(a0, a1) (std_basic_string_char_char_traits_char_assign_basicstringR((Str_43C890 *)(a0), (Str_43C890 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_Dtor(String* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_43C890 *)(a0), (a1))) /* merge_units */


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
#pragma pop /* merge_units */
/* merge_units: end func_0043CA20 */
