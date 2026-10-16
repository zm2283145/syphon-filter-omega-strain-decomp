/*
 * main/mem: 4 files, 00356590-003566D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00356590 */
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
void* func_00356590(SsoString* str, const char* first, const char* last)
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
/* merge_units: end func_00356590 */

/* merge_units: begin func_003565E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_003565E0(char* self) {
    *(int*)(self + 4) = 0;
}

void func_003565F0(char* self) {
    *(int*)(self + 4) = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003565E0 */

/* merge_units: begin func_00356600 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* Factory: allocate a 0x250-byte personnel screen and construct it inline (two strings, one payload). */
extern "C" {
extern char D_004DF020[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiPersonnelScreen_ctor(void* self);
void func_00298690(void* str);
void func_00356730(void* payload);
}
struct O356600 { void* vtable; char pad4[0x68]; char s6C[0xC]; char s78[0xC]; char pad84[0x2C]; char pB0[0x1A0]; };
extern "C" O356600* func_00356600(void)
{
    O356600* p;
    {
        AllocGuard guard;
        p = (O356600*)Mem_Alloc(0, 0x250, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiPersonnelScreen_ctor(p);
        p->vtable = D_004DF020;
        func_00298690(p->s6C);
        func_00298690(p->s78);
        func_00356730(p->pB0);
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_00356600 */

/* merge_units: begin func_003566D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_003566D0, D_004DF0B0, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_003566D0 */
