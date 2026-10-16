/*
 * main/guiTextListWidget: 4 files, 00423250-004233D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00423250 */
#pragma push /* merge_units */
#include "types.h"

/* Short-string-optimized string: bit 0 of the first byte marks heap storage. */
typedef struct SsoString {
    union {
        struct { unsigned char isLong : 1; unsigned char shortLen : 7; } s;
        int flags;
    } h;
    int longLen;
    char* longData;
} SsoString;

typedef struct { char unused; } Allocator; /* empty allocator object passed by value */

/* Replaces count characters at pos with the range [first, last). */
extern void* String_Replace(SsoString* str, int pos, int count, const char* first, const char* last, Allocator alloc);

/* Assigns the range [first, last) to the string (replaces the whole contents). */
void* func_00423250(SsoString* str, const char* first, const char* last)
{
    Allocator alloc;
    int len;
    if (!(str->h.flags & 1))
        len = (unsigned char)str->h.s.shortLen;
    else
        len = str->longLen;
    return String_Replace(str, 0, len, first, last, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_00423250 */

/* merge_units: begin func_004232A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004BF5F8[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(func_004232A0, 0x100, D_004BF5F8, GuiTextListWidget_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_004232A0 */

/* merge_units: begin func_00423350 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_member_base_dtor.h"

/* Derived destructor: member, then base, optionally delete. */
DEFINE_VTABLE_MEMBER_BASE_DTOR(func_00423350, D_004E0D20, 0x60, func_0013A040, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_00423350 */

/* merge_units: begin func_004233D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_004233D0)
#pragma pop /* merge_units */
/* merge_units: end func_004233D0 */
