/*
 * main/human: range (5 files, 00190EA0-00190F90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00190EA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_00190EA0(char* self) {
    return *(int*)(self + 8);
}

int func_00190EB0(char* self) {
    return *(unsigned int*)(self + 16) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190EA0 */

/* merge_units: begin func_00190EC0 */
#pragma push /* merge_units */
typedef struct { int unk0; unsigned int count; int unk8; float scale; } ScaledCount;

/* Returns count (unsigned) * scale. */
float func_00190EC0(ScaledCount* self)
{
    return (float)self->count * self->scale;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190EC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190EC0 */

/* merge_units: begin func_00190F00 */
#pragma push /* merge_units */
int func_00190F00(char* self) {
    return *(int*)(self + 4);
}

int func_00190F10(char* self) {
    return *(int*)(self + 0);
}

int* func_00190F20(int* self, int value) {
    *self = value;
    return self;
}

int func_00190F30(char* self) {
    return *(int*)(self + 0);
}

int func_00190F40(char* self) {
    return *(int*)(self + 32);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190F00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190F00 */

/* merge_units: begin func_00190F50 */
#pragma push /* merge_units */
typedef struct { int unk0; unsigned char disabled; } Item;
typedef struct { void* owner; } Holder;
extern int NodeNameMap_Find(void* owner);
extern Item** Registry_At(void* table, int key);

/* Looks up the owner's item; returns it unless it is disabled (then 0). */
Item* ModelCtx_FindNodeByName(Holder* self)
{
    char* owner = self->owner;
    Item* item = *Registry_At(owner + 0x34, NodeNameMap_Find(owner));
    return item->disabled == 0 ? item : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190F50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190F50 */

/* merge_units: begin func_00190F90 */
#pragma push /* merge_units */
typedef struct Rec14 {
    char b[0x14];
} Rec14;

typedef struct Tmp20 {
    char b[0x14];
} Tmp20;

typedef struct Holder_00190F90 {
    char pad[0x3C];
    char vec[4];
    int count;
    Rec14* data;
} Holder_00190F90;

extern void func_00191040(Tmp20*, int, int*);
extern void func_001BDA10(void*, Rec14*, int, Tmp20*);

/* Builds a record from (a1, {a2, a3}) and appends it to the vector at +0x3C. */
Holder_00190F90* func_00190F90(Holder_00190F90* self, int a1, int a2, int a3) {
    Tmp20 rec;
    int pair[2];
    pair[0] = a2;
    pair[1] = a3;
    func_00191040(&rec, a1, pair);
    func_001BDA10(self->vec, self->data + self->count, 1, &rec);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190F90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190F90 */
