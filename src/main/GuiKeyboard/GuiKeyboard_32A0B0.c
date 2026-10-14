/*
 * main/GuiKeyboard: 4 files, 0032A0B0-0032A280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032A0B0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc0032A0B0; /* empty allocator object passed by value */
typedef struct { char data[44]; } Elem0032A0B0;
typedef struct { int unk0; int count; Elem0032A0B0* items; } Src0032A0B0;
typedef struct { int begin; int end; int cap; } Vec0032A0B0;
extern void func_0032A5A0(Vec0032A0B0* v, Elem0032A0B0* first, Elem0032A0B0* last, Alloc0032A0B0 alloc);
/* Construct an empty vector and fill it from src's items. */
Vec0032A0B0* func_0032A0B0(Vec0032A0B0* v, Src0032A0B0* src)
{
    Alloc0032A0B0 alloc;
    v->begin = 0;
    v->end = 0;
    v->cap = 0;
    func_0032A5A0(v, src->items, src->items + src->count, alloc);
    return v;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032A0B0 */

/* merge_units: begin func_0032A110 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "release_buffer_call_dtor.h"

extern "C" { char D_004B88A0[] = "allocator.hh"; }
DEFINE_RELEASE_BUFFER_CALL_DTOR(func_0032A110, func_0032AB90,func_0032A190,D_004B88A0)
#pragma pop /* merge_units */
/* merge_units: end func_0032A110 */

/* merge_units: begin func_0032A190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element (member at +0x4C, then base), then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_0034F7A0(void* self, short flags);
void* func_00138350(void* self, short flags);
void func_0032A190(void* allocation, int pool, int destroy, char* file, int line);
}
void func_0032A190(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation) {
            func_00138350((char*)allocation + 0x10, -1);
            func_00138350(allocation, -1);
        }
    }
    Mem_Free(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032A190 */

/* merge_units: begin func_0032A280 */
#pragma push /* merge_units */
typedef struct { char d[0x20]; } E2A280;
typedef struct { int first; int count; E2A280* buf; } V2A280;
extern void func_003283F0(E2A280* e, int flag);
void func_0032A280(V2A280* v)
{
    E2A280* b = v->buf;
    E2A280* e = b + v->count;
    while (b < e) {
        --e;
        func_003283F0(e, -1);
    }
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032A280 */
