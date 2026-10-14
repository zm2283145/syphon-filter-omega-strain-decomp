/*
 * main/gameobj: range (4 files, 003961E0-003963B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_release_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_003961E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector through its allocator, optionally delete. */
extern "C" {
char D_004BC4E0[] = "allocator.hh";
}
DEFINE_VECTOR_RELEASE_DTOR(func_003961E0, func_00396D00, func_00396260, D_004BC4E0)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003961E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003961E0 */

/* merge_units: begin func_00396260 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
extern "C" void* func_00396340(void* self, short deleteFlag); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then Mem_Free under the guard. */
extern "C" {
#if 0 /* merge_units */
void* func_00396340(void* self, short flags);
#endif /* merge_units */
#define func_00396340(a0, a1) (func_00396340((a0), (a1))) /* merge_units */

void func_00396260(void* allocation, int pool, int destroy, char* file, int line);
}
void func_00396260(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            func_00396340((char*)allocation + 16, -1);
    }
    Mem_Free(pool, allocation, file, line);
}
#undef func_00396340 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396260 */

/* merge_units: begin func_00396340 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
typedef struct Node_3963B0 { unsigned char pad[0xB0]; struct Node_3963B0* owner; int children; } Node_3963B0;
extern "C" Node_3963B0* func_003963B0(Node_3963B0* self, short deleteFlag); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on

/* Deleting destructor: member cleanup, then base destructor. */
#if 0 /* merge_units */
extern "C" void operator_delete(void* allocation);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

extern "C" void func_00393380(void* self);
extern "C" void func_003965A0(void* self);
#if 0 /* merge_units */
extern "C" void* func_003963B0(void* self, short deleteFlag);
#endif /* merge_units */
#define func_003963B0(a0, a1) ((void *)func_003963B0((Node_3963B0 *)(a0), (a1))) /* merge_units */


extern "C" void* func_00396340(void* self, short deleteFlag)
{
    if (self) {
        if (self) {
            func_00393380(self);
            func_003965A0(self);
            func_003963B0(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
#undef func_003963B0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396340 */

/* merge_units: begin func_003963B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: unlink from the owner, orphan all children, free the list. */
typedef struct { int w[1]; } It_3963B0;


extern "C" {
void func_00393600(void* vec, Node_3963B0** value);
void func_001913C0(It_3963B0* out, void* vec);
void func_001913A0(It_3963B0* out, void* vec);
bool func_001912A0(It_3963B0* a, It_3963B0* b);
Node_3963B0** func_00191390(It_3963B0* it);
void func_001912C0(It_3963B0* it);
void func_00396590(void* vec);
void* func_003964A0(void* vec, short deleteFlag);
#if 0 /* merge_units */
void operator_delete(void* allocation);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

}

extern "C" Node_3963B0* func_003963B0(Node_3963B0* self, short deleteFlag)
{
    if (self) {
        Node_3963B0* me = self;
        It_3963B0 it;
        It_3963B0 end;
        if (self->owner) {
            func_00393600(&self->owner->children, &me);
            me->owner = 0;
        }
        func_001913C0(&it, &self->children);
        func_001913A0(&end, &self->children);
        for (; func_001912A0(&it, &end); func_001912C0(&it))
            (*func_00191390(&it))->owner = 0;
        func_00396590(&self->children);
        {
            void* v = &self->children;
            if (v)
                func_003964A0(v, -1);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003963B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003963B0 */
