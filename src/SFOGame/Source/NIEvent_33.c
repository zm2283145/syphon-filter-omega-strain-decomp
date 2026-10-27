/*
 * SFOGame/Source/NIEvent: 4 files, 0023F350-0023F3F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023F350 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0xC]; unsigned char enabled; } Part;
typedef struct {
    void* vtable;
    char pad[0x98];
    Part a;
    char padA[0xAC - 0x9C - sizeof(Part)];
    Part b;
    char padB[0xC4 - 0xAC - sizeof(Part)];
    Part c;
    char padC[0x134 - 0xC4 - sizeof(Part)];
    float scale;
} Obj;
extern char D_004DC190[];
extern void cGOBJ_ctor(Obj* self, int* id, int a2, int a3);
extern void std_vector_cNIEventBasePtr_ctor(Part* p);
extern void std_vector_VectorKey_ctor(Part* p);
extern void std_vector_VisKey_ctor(Part* p);

/* Constructor: base GOBJ init, then three enabled parts and unit scale. */
Obj* cNIEventBase_ctor(Obj* self, int a2, int a3)
{
    Part* pa;
    Part* pb;
    Part* pc;
    int id = -1;
    cGOBJ_ctor(self, &id, a2, a3);
    self->vtable = D_004DC190;
    pa = &self->a;
    std_vector_cNIEventBasePtr_ctor(pa);
    pa->enabled = 1;
    pb = &self->b;
    std_vector_VectorKey_ctor(pb);
    pb->enabled = 1;
    pc = &self->c;
    std_vector_VisKey_ctor(pc);
    pc->enabled = 1;
    self->scale = 1.0f;
    return self;
}
static inline void merge_flush_func_0023F350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F350 */

/* merge_units: begin func_0023F3F0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "member_dtor_chain.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

#pragma cplusplus on

DEFINE_MEMBER_DTOR_CHAIN(cArray_VisKey_dtor, std_vector_deleter_VisKey_dtor)
static inline void merge_flush_func_0023F3F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F3F0 */

/* merge_units: begin func_0023F460 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_MEMBER_DTOR_CHAIN(cArray_VectorKey_dtor, std_vector_deleter_VectorKey_dtor)
static inline void merge_flush_func_0023F460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F460 */

/* merge_units: begin func_0023F4D0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_BASE_DTOR_CHAIN(cArray_cNIEventBasePtr_dtor, std_vector_imp_cNIEventBasePtr_1_dtor)
static inline void merge_flush_func_0023F4D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F4D0 */
