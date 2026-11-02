/*
 * SFOGame/Source/GuiPersonnelMenu: 6 files, 00356590-00356730
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
extern void* std_basic_string_char_char_traits_char_do_replace(SsoString* str, int pos, int count, const char* first, const char* last, Allocator alloc);

/* Assigns the range [first, last) to the string (replaces the whole contents). */
void* func_00356590(SsoString* str, const char* first, const char* last)
{
    Allocator alloc;
    int len;
    if (!(str->h.flags & 1))
        len = (unsigned char)str->h.s.shortLen;
    else
        len = str->longLen;
    return std_basic_string_char_char_traits_char_do_replace(str, 0, len, first, last, alloc);
}
static inline void merge_flush_func_00356590(void) {} /* merge_units */
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
static inline void merge_flush_func_003565E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003565E0 */

/* merge_units: begin func_00356600 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* Factory: allocate a 0x250-byte personnel screen and construct it inline (two strings, one payload). */
extern "C" {
extern char D_004DF020[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiPersonnelScreen_ctor(void* self);
void cString_ctor_void(void* str);
#if 0 /* merge_units */
void cSndFx_ctor_void(void* payload);
#endif /* merge_units */
struct P356730; /* merge_units */
P356730* cSndFx_ctor_void(P356730* p); /* merge_units */
#define cSndFx_ctor_void(a0) ((void)cSndFx_ctor_void((P356730 *)(a0))) /* merge_units */

}
struct O356600 { void* vtable; char pad4[0x68]; char s6C[0xC]; char s78[0xC]; char pad84[0x2C]; char pB0[0x1A0]; };
extern "C" O356600* ConcreteWidgetClassRep_GuiPersonnelMenu_Create(void)
{
    O356600* p;
    {
        AllocGuard guard;
        p = (O356600*)cMemMan_Allocate(0, 0x250, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiPersonnelScreen_ctor(p);
        p->vtable = D_004DF020;
        cString_ctor_void(p->s6C);
        cString_ctor_void(p->s78);
        cSndFx_ctor_void(p->pB0);
    }
    return p;
}
#undef cSndFx_ctor_void /* merge_units */
static inline void merge_flush_func_00356600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00356600 */

/* merge_units: begin func_003566D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiPersonnelScreen_dtor_3566D0, D_004DF0B0, GuiWidget_dtor)
static inline void merge_flush_func_003566D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003566D0 */

/* merge_units: begin func_00356730 */
#pragma push /* merge_units */
#pragma cplusplus on
struct H356730 { int v; };
struct P356730 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H356730 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
extern "C" void cFileMan_ctor_void(void* m);
/* constructor: reset two members, ids, mask, handle (copied through a stack temp) */
#pragma push
#pragma opt_propagation off
extern "C" P356730* cSndFx_ctor_void(P356730* p)
{
    *(int*)((char*)p + 0x24) = -2;
    *(int*)((char*)p + 0x20) = 0;
    cFileMan_ctor_void(p->memberA);
    cFileMan_ctor_void(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H356730 h; H356730* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    return p;
}
#pragma pop
static inline void merge_flush_func_00356730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00356730 */

/* merge_units: begin func_003567B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiPersonnelScreen_dtor_3567B0, D_004DF0B0, GuiWidget_dtor)
static inline void merge_flush_func_003567B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003567B0 */
