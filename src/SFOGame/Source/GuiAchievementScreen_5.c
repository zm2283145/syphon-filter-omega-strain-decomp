/*
 * main/GuiAchievementScreen: 5 files, 00354440-003546B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00354440 */
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
extern void* std_basic_string_char_char_traits_char_do_replace(SsoString* str, int pos, int count, const char* first, const char* last, Allocator alloc);

/* Assigns the range [first, last) to the string (replaces the whole contents). */
void* func_00354440(SsoString* str, const char* first, const char* last)
{
    Allocator alloc;
    int len;
    if (!(str->h.flags & 1))
        len = (unsigned char)str->h.s.shortLen;
    else
        len = str->longLen;
    return std_basic_string_char_char_traits_char_do_replace(str, 0, len, first, last, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_00354440 */

/* merge_units: begin func_00354490 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* Factory: allocate a 0x8C-byte personnel screen and construct it inline (member at +0x6C, string at +0x80). */
extern "C" {
extern char D_004DEF90[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiPersonnelScreen_ctor(void* self);
void cArray_tAchievementInfo_ctor(void* m);
void cString_ctor_void(void* str);
}
struct O354490 { void* vtable; char pad4[0x68]; char m6C[0x14]; char s80[0xC]; };
extern "C" O354490* ConcreteWidgetClassRep_GuiAchievementScreen_Create(void)
{
    O354490* p;
    {
        AllocGuard guard;
        p = (O354490*)cMemMan_Allocate(0, 0x8C, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiPersonnelScreen_ctor(p);
        p->vtable = D_004DEF90;
        cArray_tAchievementInfo_ctor(p->m6C);
        cString_ctor_void(p->s80);
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_00354490 */

/* merge_units: begin func_00354560 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

DEFINE_BASE_DTOR_CHAIN(func_00354560, func_00296FC0)
#pragma pop /* merge_units */
/* merge_units: end func_00354560 */

/* merge_units: begin func_003545C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "owned_buffer8_dtor.h"

/* Deleting destructor of a vector of trivially destructible elements (two inlined null tests). */
extern "C" char D_004AA5B8[];
extern "C" OwnedBuffer8* func_003545C0(OwnedBuffer8* self, short deleteFlag)
{
    if (self) {
        if (self) {
            self->last = 0;
            void* p = self->buffer;
            if (p) {
                if (p) {
                    AllocGuard guard;
                    cMemMan_Deallocate(0, p, D_004AA5B8, 0x64);
                }
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003545C0 */

/* merge_units: begin func_003546B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiPersonnelScreen_dtor_3546B0, D_004DF0B0, GuiWidget_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003546B0 */
