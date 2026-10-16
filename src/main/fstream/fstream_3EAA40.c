/*
 * main/fstream: range (2 files, 003EAA40-003EAA60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003EAA40 */
#pragma push /* merge_units */
typedef struct { char pad[0x94]; unsigned char flag; } Obj94;

/* Returns 1 if the byte flag at +0x94 of the second argument is set. */
unsigned char func_003EAA40(void* self, Obj94* obj)
{
    unsigned char result = 0;
    if (obj->flag)
        result = 1;
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003EAA40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003EAA40 */

/* merge_units: begin func_003EAA60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */


extern int AsyncLoader_QueueUnload(int a0, int a1, int a2, int a3, int a4);

/* Forward to AsyncLoader_QueueUnload with the two middle arguments zero. */
int Fstream_ReleaseNoCallback(int a0, int a1, int a4) {
    return AsyncLoader_QueueUnload(a0, a1, 0, 0, a4);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003EAA60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003EAA60 */
