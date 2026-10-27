/*
 * SFOGame/Source/human: 7 files, 00190E50-00190EA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00190E50 */
#pragma push /* merge_units */
#include "types.h"
#include "float_to_int.h"

/* Convert a float to int. */
DEFINE_FLOAT_TO_INT(nSFO_Macros_FTOI)
static inline void merge_flush_func_00190E50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00190E50 */

/* merge_units: begin func_00190E60 */
#pragma push /* merge_units */
typedef struct { unsigned int kind; char pad[0x2C]; char a[0x10]; char b[0x30]; char c[1]; } O_190E60;
void* cSkaAnimData_DataStart(O_190E60* o)
{
    if (o->kind >= 3) return o->c;
    if (o->kind == 2) return o->b;
    return o->a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190E60 */

/* merge_units: begin func_00190EA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cSkaAnimData_GetFrameSize(char* self) {
    return *(int*)(self + 8);
}

int cSkaAnimData_IsLooping(char* self) {
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
float cSkaAnimData_GetDuration(ScaledCount* self)
{
    return (float)self->count * self->scale;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190EC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190EC0 */

/* merge_units: begin func_00190F00 */
#pragma push /* merge_units */
int cSkaAnimData_GetFrameCount(char* self) {
    return *(int*)(self + 4);
}

int cPointer_cSkaAnimData_opArrow(char* self) {
    return *(int*)(self + 0);
}

int* cPointer_cSkaAnimData_ctor(int* self, int value) {
    *self = value;
    return self;
}

int cSkeleton_GetSkeletonData(char* self) {
    return *(int*)(self + 0);
}

int cSkaParams_Skeleton(char* self) {
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
extern int cSkaAnimationSet_GetNodeId(void* owner);
extern Item** cArray_cSkaNodePtr_opIndex(void* table, int key);

/* Looks up the owner's item; returns it unless it is disabled (then 0). */
Item* cSkaSystem_GetAnimation(Holder* self)
{
    char* owner = self->owner;
    Item* item = *cArray_cSkaNodePtr_opIndex(owner + 0x34, cSkaAnimationSet_GetNodeId(owner));
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
extern void std_vector_imp_cTimedEvent_insert(void*, Rec14*, int, Tmp20*);

/* Builds a record from (a1, {a2, a3}) and appends it to the vector at +0x3C. */
Holder_00190F90* cSkaAnimCheckpoints_ScheduleEvent(Holder_00190F90* self, int a1, int a2, int a3) {
    Tmp20 rec;
    int pair[2];
    pair[0] = a2;
    pair[1] = a3;
    func_00191040(&rec, a1, pair);
    std_vector_imp_cTimedEvent_insert(self->vec, self->data + self->count, 1, &rec);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190F90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190F90 */
