/*
 * main/GuiGameOptions: 3 files, 002994B0-00299520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002994B0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char tag; } Alloc;
typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; } SsoString;

extern void String_Replace(SsoString* self, int pos, int n, const char* first, const char* last, Alloc alloc);

/* Assigns [first, last) to the string by replacing its whole contents. */
void String_AssignRange(SsoString* self, const char* first, const char* last)
{
    Alloc alloc;
    String_Replace(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, first, last, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_002994B0 */

/* merge_units: begin func_00299500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Vector clear (count = 0). */
void func_00299500(PtrVec* v) {
    v->count = 0;
}

/* Vector clear (count = 0). */
void func_00299510(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00299500 */

/* merge_units: begin func_00299520 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004AA5A8[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(GuiCommandCenter_Create, 0x328, D_004AA5A8, GuiCommandCenter_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_00299520 */
