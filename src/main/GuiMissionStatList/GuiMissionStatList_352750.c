/*
 * main/GuiMissionStatList: 2 files, 00352750-003527A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00352750 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Container assignment: assign [src.data, src.data + src.count) unless self-assignment. */
struct Tag352750 { char c; };
struct V352750 { int capacity; int count; char* data; };
extern "C" {
void func_00352910(V352750* self, char* first, char* last, Tag352750 tag);
V352750* func_00352750(V352750* self, V352750* src);
}
V352750* func_00352750(V352750* self, V352750* src)
{
    if (self != src) {
        Tag352750 tag;
        func_00352910(self, src->data, src->data + src->count, tag);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00352750 */

/* merge_units: begin func_003527A0 */
#pragma push /* merge_units */
typedef struct { char unused; } Alloc;
typedef struct { int begin; int end; int cap; } Vec;
typedef struct { int unk0; int count; int data; } Src;
extern void func_003527F0(Vec* self, int first, int last, Alloc alloc);

/* Copy-constructs a range container from src's [data, data+count). */
Vec* func_003527A0(Vec* self, Src* src)
{
    Alloc alloc;
    self->begin = 0;
    self->end = 0;
    self->cap = 0;
    func_003527F0(self, src->data, src->data + src->count, alloc);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003527A0 */
