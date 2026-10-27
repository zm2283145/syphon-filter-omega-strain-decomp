/*
 * SFOGame/Source/humanAnimData: 8 files, 001F3100-001F31B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3100 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Obj;
#if 0 /* merge_units */
extern void compressed_pair_cAllocator_cSkaSwitchItem_int_ctor_uint(Obj* self, int a);
#endif /* merge_units */
Word * compressed_pair_cAllocator_cSkaSwitchItem_int_ctor_uint(); /* merge_units */


/* Constructor: base init then clears +4/+8. */
Obj* std_vector_deleter_cSkaSwitchItem_ctor_void(Obj* self)
{
    compressed_pair_cAllocator_cSkaSwitchItem_int_ctor_uint(self, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
static inline void merge_flush_func_001F3100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3100 */

/* merge_units: begin func_001F3140 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern Word* details_compressed_pair_imp_cAllocator_cSkaSwitchItem_int_1_ctor_uint(Word*, int);
#if 0 /* merge_units */
extern Word* cAllocator_cSkaSwitchItem_ctor_void(Word*);
#endif /* merge_units */
void * cAllocator_cSkaSwitchItem_ctor_void(); /* merge_units */


Word* compressed_pair_cAllocator_cSkaSwitchItem_int_ctor_uint(Word* self, int value) {
    details_compressed_pair_imp_cAllocator_cSkaSwitchItem_int_1_ctor_uint(self, value);
    return self;
}

Word* details_compressed_pair_imp_cAllocator_cSkaSwitchItem_int_1_ctor_uint(Word* self, int value) {
    cAllocator_cSkaSwitchItem_ctor_void(self);
    self->value = value;
    return self;
}
static inline void merge_flush_func_001F3140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3140 */

/* merge_units: begin func_001F31B0 */
#pragma push /* merge_units */
extern void* D_004DFC50;
extern int cQuaternion_ctor_cQuaternionR(int*, int);

void* cAllocator_cSkaSwitchItem_ctor_void(void* self) {
    return self;
}

MotionNode* cSkaNode_ctor_eType_cQuaternionR(MotionNode* self, int type, int name) {
    self->vtable = &D_004DFC50;
    self->type = type;
    cQuaternion_ctor_cQuaternionR(&self->name, name);
    return self;
}
static inline void merge_flush_func_001F31B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F31B0 */

/* merge_units: begin func_001F3200 */
#pragma push /* merge_units */
#pragma optimization_level 1

#if 0 /* merge_units */
extern void cLList_cSkaSwitchItemPtr_PushBackActual(void*, int*);
#endif /* merge_units */
void cLList_cSkaSwitchItemPtr_PushBackActual(); /* merge_units */



/* Calls cLList_cSkaSwitchItemPtr_PushBackActual(self, &value) and returns self. */
void* cSkaInitListOfPointers_cSkaSwitchItem_opShl(void* self, int value) {
    cLList_cSkaSwitchItemPtr_PushBackActual(self, &value);
    return self;
}
static inline void merge_flush_func_001F3200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3200 */

/* merge_units: begin func_001F3240 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaSwitchItemPtr_push_back(void* self);
#endif /* merge_units */
void std_list_cSkaSwitchItemPtr_push_back(); /* merge_units */



#pragma optimization_level 1
/* Forwards to std_list_cSkaSwitchItemPtr_push_back (unit built at -O1: no tail call). */
void cLList_cSkaSwitchItemPtr_PushBackActual(void* self)
{
    std_list_cSkaSwitchItemPtr_push_back(self);
}
#pragma optimization_level reset
static inline void merge_flush_func_001F3240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3240 */

/* merge_units: begin func_001F3260 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_imp_voidPtr_push_back(void);
#endif /* merge_units */
void std_list_imp_voidPtr_push_back(); /* merge_units */



/* Calls std_list_imp_voidPtr_push_back. */
#pragma optimization_level 1
void std_list_cSkaSwitchItemPtr_push_back(void)
{
    std_list_imp_voidPtr_push_back();
}
#pragma optimization_level reset
static inline void merge_flush_func_001F3260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3260 */

/* merge_units: begin func_001F3280 */
#pragma push /* merge_units */
typedef struct { void* node; } It1F3280;
extern void std_list_deleter_voidPtr_end_void(It1F3280* out, void* list);
extern void std_list_deleter_voidPtr_insert(It1F3280* out, void* list, It1F3280* pos, void* value);
#pragma optimization_level 1
void std_list_imp_voidPtr_push_back(void* list, void* value)
{
    It1F3280 r;
    It1F3280 pos;
    std_list_deleter_voidPtr_end_void(&pos, list);
    std_list_deleter_voidPtr_insert(&r, list, &pos, value);
}
#pragma optimization_level reset
static inline void merge_flush_func_001F3280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3280 */

/* merge_units: begin func_001F32E0 */
#pragma push /* merge_units */
extern int cSkaAnimationSet_GetNode_cString16NR(int, int);
extern int cPointer_cSkaNode_ctor_cSkaNodeP(Unk1F32E0*, int);
extern void cSkaInitListOfPointers_cSkaTransBLEND_CopyPointerContentsToArray(int, ObjVec*);
extern ObjVec* cArray_cSkaTransBLEND_ctor_void(ObjVec*);

Unk1F32E0* cSkaSwitchItem_ctor_cString16NR_cSkaAnimationSetR_cSkaInitListOfPointersR(Unk1F32E0* self, int a1, int a2, int a3) {
    cPointer_cSkaNode_ctor_cSkaNodeP(self, cSkaAnimationSet_GetNode_cString16NR(a2, a1));
    cArray_cSkaTransBLEND_ctor_void(&self->list);
    cSkaInitListOfPointers_cSkaTransBLEND_CopyPointerContentsToArray(a3, &self->list);
    return self;
}
static inline void merge_flush_func_001F32E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F32E0 */
