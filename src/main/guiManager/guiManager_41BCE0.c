/*
 * main/guiManager: 2 files, 0041BCE0-0041BD30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041BCE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc0041BCE0; /* empty allocator object passed by value */
typedef struct { unsigned long long isLong : 1; unsigned long long size : 7; } Short0041BCE0;
typedef union { unsigned int flags; Short0041BCE0 s; struct { int f0; int length; char* data; } l; } Str0041BCE0;
extern void String_Replace(Str0041BCE0* str, int pos, int count, int a, int b, Alloc0041BCE0 alloc);
/* Forward (0, size) of the string to String_Replace. */
void func_0041BCE0(Str0041BCE0* s, int a, int b)
{
    Alloc0041BCE0 alloc;
    int len;
    if (s->flags & 1) {
        len = s->l.length;
    } else {
        len = (unsigned char)s->s.size;
    }
    String_Replace(s, 0, len, a, b, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_0041BCE0 */

/* merge_units: begin func_0041BD30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004E0A40[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_0041C7D0(void* self);

}
struct G0041BD30 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
#define GH(off) (*(unsigned short*)((char*)p + (off)))
extern "C" G0041BD30* func_0041BD30(void)
{
    G0041BD30* p;
    {
        AllocGuard guard;
        p = (G0041BD30*)Mem_Alloc(0, 0x90, "guiWidget.hh", 0x2A);
    }
    if (p) {
        func_0041C7D0(p);
        p->vtable = D_004E0A40; GH(0x14) |= 0x80; GB(0x80) = 0; GW(0x84) = 0x64; GW(0x8C) = 0; GB(0x88) = 0;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041BD30 */
