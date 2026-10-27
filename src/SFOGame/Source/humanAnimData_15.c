/*
 * SFOGame/Source/humanAnimData: 14 files, 001F37C0-001F3A70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F37C0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Obj3 {
    int a;
    int b;
    int c;
} Obj3;

#if 0 /* merge_units */
extern void compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_uint(Obj3*, int);
#endif /* merge_units */
Word * compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_uint(); /* merge_units */


/* Constructor: compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_uint(self, 0), then clears +4 and +8. */
Obj3* std_vector_deleter_cSkaTransBLEND_ctor_void(Obj3* o) {
    compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_uint(o, 0);
    o->b = 0;
    o->c = 0;
    return o;
}
static inline void merge_flush_func_001F37C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F37C0 */

/* merge_units: begin func_001F3800 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern Word* details_compressed_pair_imp_cAllocator_cSkaTransBLEND_int_1_ctor_uint(Word*, int);
#if 0 /* merge_units */
extern Word* cAllocator_cSkaTransBLEND_ctor_void(Word*);
#endif /* merge_units */
void * cAllocator_cSkaTransBLEND_ctor_void(); /* merge_units */


Word* compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_uint(Word* self, int value) {
    details_compressed_pair_imp_cAllocator_cSkaTransBLEND_int_1_ctor_uint(self, value);
    return self;
}

Word* details_compressed_pair_imp_cAllocator_cSkaTransBLEND_int_1_ctor_uint(Word* self, int value) {
    cAllocator_cSkaTransBLEND_ctor_void(self);
    self->value = value;
    return self;
}
static inline void merge_flush_func_001F3800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3800 */

/* merge_units: begin func_001F3870 */
#pragma push /* merge_units */
void* cAllocator_cSkaTransBLEND_ctor_void(void* self) {
    return self;
}
static inline void merge_flush_func_001F3870(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3870 */

/* merge_units: begin func_001F3880 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cLList_cSkaTransBLENDPtr_PushBackActual(void* s, int* v);
#endif /* merge_units */
void cLList_cSkaTransBLENDPtr_PushBackActual(); /* merge_units */


#pragma optimization_level 1
void* cSkaInitListOfPointers_cSkaTransBLEND_opShl(void* s, int v) { cLList_cSkaTransBLENDPtr_PushBackActual(s, &v); return s; }
#pragma optimization_level reset
static inline void merge_flush_func_001F3880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3880 */

/* merge_units: begin func_001F38C0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaTransBLENDPtr_push_back(void);
#endif /* merge_units */
void std_list_cSkaTransBLENDPtr_push_back(); /* merge_units */


/* Wrapper around std_list_cSkaTransBLENDPtr_push_back. */
#pragma optimization_level 1
void cLList_cSkaTransBLENDPtr_PushBackActual(void) { std_list_cSkaTransBLENDPtr_push_back(); }
#pragma optimization_level reset
static inline void merge_flush_func_001F38C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F38C0 */

/* merge_units: begin func_001F38E0 */
#pragma push /* merge_units */
/* This wrapper keeps a stack frame and a real call (no tail call): built at a lower optimization level. */
#pragma optimization_level 2

extern void std_list_imp_voidPtr_push_back(void* self);

/* Forwards to std_list_imp_voidPtr_push_back. */
void std_list_cSkaTransBLENDPtr_push_back(void* self)
{
    std_list_imp_voidPtr_push_back(self);
}
static inline void merge_flush_func_001F38E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F38E0 */

/* merge_units: begin func_001F3900 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cLList_cSkaTransBLENDPtr_ctor(void* s);
#endif /* merge_units */
void * cLList_cSkaTransBLENDPtr_ctor(); /* merge_units */

#pragma optimization_level 1
void* cSkaInitListOfPointers_cSkaTransBLEND_ctor(void* s) { cLList_cSkaTransBLENDPtr_ctor(s); return s; }
#pragma optimization_level reset
static inline void merge_flush_func_001F3900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3900 */

/* merge_units: begin func_001F3940 */
#pragma push /* merge_units */
/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

#if 0 /* merge_units */
extern void std_list_cSkaTransBLENDPtr_ctor(void* obj);
#endif /* merge_units */
void * std_list_cSkaTransBLENDPtr_ctor(); /* merge_units */


/* Runs std_list_cSkaTransBLENDPtr_ctor on obj and returns obj. */
void* cLList_cSkaTransBLENDPtr_ctor(void* obj) {
    std_list_cSkaTransBLENDPtr_ctor(obj);
    return obj;
}

#pragma pop
static inline void merge_flush_func_001F3940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3940 */

/* merge_units: begin func_001F3980 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_imp_voidPtr_ctor(void* self);
#endif /* merge_units */
ScalarCollection * std_list_imp_voidPtr_ctor(); /* merge_units */


#pragma optimization_level 1
/* Calls std_list_imp_voidPtr_ctor on self and returns self (unit built at -O1). */
void* std_list_cSkaTransBLENDPtr_ctor(void* self)
{
    std_list_imp_voidPtr_ctor(self);
    return self;
}
#pragma optimization_level reset
static inline void merge_flush_func_001F3980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3980 */

/* merge_units: begin func_001F39C0 */
#pragma push /* merge_units */
extern void std_list_deleter_voidPtr_ctor_void(ScalarCollection*);

ScalarCollection* std_list_imp_voidPtr_ctor(ScalarCollection* self) {
    std_list_deleter_voidPtr_ctor_void(self);
    return self;
}
static inline void merge_flush_func_001F39C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F39C0 */

/* merge_units: begin func_001F39F0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cLList_cSkaSwitchItemPtr_ctor(void* p);
#endif /* merge_units */
void * cLList_cSkaSwitchItemPtr_ctor(); /* merge_units */

/* Calls cLList_cSkaSwitchItemPtr_ctor on the object and returns it. */
#pragma optimization_level 1
void* cSkaInitListOfPointers_cSkaSwitchItem_ctor(void* p) { cLList_cSkaSwitchItemPtr_ctor(p); return p; }
#pragma optimization_level reset
static inline void merge_flush_func_001F39F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F39F0 */

/* merge_units: begin func_001F3A30 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaSwitchItemPtr_ctor(void*);
#endif /* merge_units */
void * std_list_cSkaSwitchItemPtr_ctor(); /* merge_units */

#pragma optimization_level 1
/* Calls the initializer on p and returns p. */
void* cLList_cSkaSwitchItemPtr_ctor(void* p) { std_list_cSkaSwitchItemPtr_ctor(p); return p; }
#pragma optimization_level reset
static inline void merge_flush_func_001F3A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3A30 */

/* merge_units: begin func_001F3A70 */
#pragma push /* merge_units */
/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

#if 0 /* merge_units */
extern void std_list_imp_voidPtr_ctor(void* self);
#endif /* merge_units */
#define std_list_imp_voidPtr_ctor(a0) ((void)std_list_imp_voidPtr_ctor((ScalarCollection *)(a0))) /* merge_units */


/* Runs std_list_imp_voidPtr_ctor on self and returns self. */
void* std_list_cSkaSwitchItemPtr_ctor(void* self)
{
    std_list_imp_voidPtr_ctor(self);
    return self;
}
#undef std_list_imp_voidPtr_ctor /* merge_units */
static inline void merge_flush_func_001F3A70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3A70 */

/* merge_units: begin func_001F3AB0 */
#pragma push /* merge_units */
extern ObjVec* cArray_cSkaBlendSequenceItem_ctor_void(ObjVec*);
extern ObjVec* std_vector_cSkaBlendSequenceItem_ctor_void(ObjVec*);
extern ObjVec* std_vector_imp_cSkaBlendSequenceItem_ctor_void(ObjVec*);
extern ObjVec* std_vector_deleter_cSkaBlendSequenceItem_ctor_void(ObjVec*);

MotionEntry24* cSkaTransBLEND_ctor_float_bool_bool(MotionEntry24* self, int a1, int a2, float f) {
    cArray_cSkaBlendSequenceItem_ctor_void(&self->list);
    self->unk10 = f;
    self->unk14 = f;
    self->unk18 = -1;
    self->unk1C = a1;
    self->unk1D = a2;
    self->unk20 = -1;
    return self;
}

/* Array constructor: sets the owns-storage flag. */
ObjVec* cArray_cSkaBlendSequenceItem_ctor_void(ObjVec* self) {
    std_vector_cSkaBlendSequenceItem_ctor_void(self);
    self->owned = 1;
    return self;
}

ObjVec* std_vector_cSkaBlendSequenceItem_ctor_void(ObjVec* self) {
    std_vector_imp_cSkaBlendSequenceItem_ctor_void(self);
    return self;
}

ObjVec* std_vector_imp_cSkaBlendSequenceItem_ctor_void(ObjVec* self) {
    std_vector_deleter_cSkaBlendSequenceItem_ctor_void(self);
    return self;
}
static inline void merge_flush_func_001F3AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3AB0 */
