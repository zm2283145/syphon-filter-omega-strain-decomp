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
extern void String_CtorCStr_13B480(Str_43C890* s, char* c);
extern void func_0013D680(Str_43C890* d, Str_43C890* s);
extern void String_Dtor(Str_43C890* s, int f);
extern void func_001BFF20(It_43C890* out, Str_43C890* s);
extern void func_001BFEE0(It_43C890* out, Str_43C890* s);
extern int func_001BFE90(It_43C890* a, It_43C890* b);
extern char* func_001BFED0(It_43C890* a);
extern void func_001BFEB0(It_43C890* a);
extern void Tex_Release(int a, int b, int c);
extern int GuiBitmapWidget_Load(O_43C890* o);
extern int D_00539248;
extern char D_004C0018[];

int GuiBitmapWidget_SetImage(O_43C890* o, char* name, int arg)
{
    Str_43C890 t2;
    Str_43C890 t;
    if (o->h48 != -1) {
        Tex_Release(D_00539248, o->h48, 0);
        o->h48 = -1;
    }
    o->f4C = 0;
    {
        String_CtorCStr_13B480(&t, D_004C0018);
        func_0013D680(&o->name, &t);
        String_Dtor(&t, 0);
    }
    if (name == 0 || *name == 0) return 1;
    o->f4C = arg;
    {
        It_43C890 it;
        It_43C890 end;
        String_CtorCStr_13B480(&t2, name);
        func_0013D680(&o->name, &t2);
        String_Dtor(&t2, 0);
        func_001BFF20(&it, &o->name);
        func_001BFEE0(&end, &o->name);
        while (func_001BFE90(&it, &end)) {
            if (*func_001BFED0(&it) >= 'a' && *func_001BFED0(&it) <= 'z') *func_001BFED0(&it) -= 0x20;
            func_001BFEB0(&it);
        }
    }
    if (o->flags & 8) return GuiBitmapWidget_Load(o);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043C890 */

/* merge_units: begin func_0043CA20 */
#pragma push /* merge_units */
typedef struct { int words[3]; } String;
typedef struct { char pad[0x48]; int handle; int unk4C; String name; } Obj;
#if 0 /* merge_units */
extern void* D_00539248;
#endif /* merge_units */
#define D_00539248 (*(void **)&D_00539248) /* merge_units */

extern void GuiWidget_Deinit(Obj* self);
#if 0 /* merge_units */
extern void Tex_Release(void* mgr, int handle, int a2);
#endif /* merge_units */
#define Tex_Release(a0, a1, a2) (Tex_Release((int)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void String_CtorCStr_13B480(String* s, const char* text);
#endif /* merge_units */
#define String_CtorCStr_13B480(a0, a1) (String_CtorCStr_13B480((Str_43C890 *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_0013D680(String* dst, String* src);
#endif /* merge_units */
#define func_0013D680(a0, a1) (func_0013D680((Str_43C890 *)(a0), (Str_43C890 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_Dtor(String* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_43C890 *)(a0), (a1))) /* merge_units */


/* Resets: base reset, releases the handle, clears fields and the name. */
void GuiBitmapWidget_Deinit(Obj* self)
{
    String tmp;
    GuiWidget_Deinit(self);
    if (self->handle != -1) {
        Tex_Release(D_00539248, self->handle, 0);
        self->handle = -1;
    }
    self->unk4C = 0;
    String_CtorCStr_13B480(&tmp, D_004C0018);
    func_0013D680(&self->name, &tmp);
    String_Dtor(&tmp, 0);
}
#undef D_00539248 /* merge_units */
#undef Tex_Release /* merge_units */
#undef String_CtorCStr_13B480 /* merge_units */
#undef func_0013D680 /* merge_units */
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043CA20 */
