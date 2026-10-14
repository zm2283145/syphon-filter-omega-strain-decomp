/*
 * main/guiWidget: 2 files, 00420A40-00420A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00420A40 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char tag; } Alloc;
typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; } SsoString;

extern void String_Replace(SsoString* self, int pos, int n, const char* first, const char* last, Alloc alloc);

/* Assigns [first, last) to the string by replacing its whole contents. */
void func_00420A40(SsoString* self, const char* first, const char* last)
{
    Alloc alloc;
    String_Replace(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, first, last, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_00420A40 */

/* merge_units: begin func_00420A90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004BF478[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(func_00420A90, 0x48, D_004BF478, GuiWidget_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_00420A90 */
