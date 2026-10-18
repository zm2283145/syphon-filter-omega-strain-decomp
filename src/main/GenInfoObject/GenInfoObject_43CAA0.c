/*
 * main/GenInfoObject: 6 files, 0043CAA0-0043D4D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043CAA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between GenInfoObject.cc and guiMLTextWidget.cc; gui widget code.
 */

#include "loose05_types.h"

extern char D_004E0FC0[]; /* vtable */
extern int D_00539248;    /* resource registry */
extern int Tex_Release(int registry, int handle, int arg);
extern int GuiWidget_BaseSleep(void* self);
extern int GuiWidget_BaseWake(void* self);
extern void GuiWidget_ctor(void* self);
extern int GuiBitmapWidget_Load(GuiWidget43CB20* self);

/* Shutdown: base shutdown, then releases the held registry handle. */
void GuiBitmapWidget_Sleep(GuiWidget43CB20* self) {
    GuiWidget_BaseSleep(self);
    if (self->handle != -1) {
        Tex_Release(D_00539248, self->handle, 0);
        self->handle = -1;
    }
}

int GuiBitmapWidget_Wake(GuiWidget43CB20* self) {
    GuiWidget_BaseWake(self);
    return GuiBitmapWidget_Load(self);
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
#pragma pop /* merge_units */
/* merge_units: end func_0043CAA0 */

/* merge_units: begin func_0043CB90 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc0043CB90; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } Str0043CB90;
extern int strlen(const char* s);
extern void String_Reserve(Str0043CB90* str, int n);
extern void String_Replace(Str0043CB90* str, int pos, int count, const char* first, const char* last, Alloc0043CB90 alloc);
/* Construct a string from a C string. */
Str0043CB90* func_0043CB90(Str0043CB90* str, const char* s)
{
    Alloc0043CB90 alloc;
    int n;
    str->w0 = 0;
    str->w4 = 0;
    str->w8 = 0;
    n = strlen(s);
    String_Reserve(str, n);
    String_Replace(str, 0, 0, s, s + n, alloc);
    return str;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043CB90 */

/* merge_units: begin func_0043CC10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004C0020[] = "basic_string: out_of_range"; char D_004C0040[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_0043CC10, D_004C0020, D_004C0040, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_004976A8, D_004976B0, func_00125FE8, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_0043CC10 */

/* merge_units: begin func_0043D100 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_0043D100)
#pragma pop /* merge_units */
/* merge_units: end func_0043D100 */

/* merge_units: begin func_0043D190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004C0060[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(func_0043D190, D_004C0060, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0043D190 */

/* merge_units: begin func_0043D4D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_0043D4D0)
#pragma pop /* merge_units */
/* merge_units: end func_0043D4D0 */
