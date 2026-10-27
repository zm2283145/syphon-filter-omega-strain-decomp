/*
 * SFOGame/Source/Generator: 4 files, 00220350-00220480
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00220350 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetGeneratorDeleteMsg_dtor, D_004DE260, cMessage_dtor)
static inline void merge_flush_func_00220350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220350 */

/* merge_units: begin func_002203B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "Generator_types.h"

Word* cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_3(GenListPos* a, GenListPos* b) {
    return 0u < (unsigned int)((int)a->node ^ (int)b->node);
}

void cLList_cSafePtr_cGOBJ_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Iterator increment. */
GenListPos* cLListIterator_cSafePtr_cGOBJ_opInc(GenListPos* it) {
    it->node = it->node->next;
    return it;
}
static inline void merge_flush_func_002203B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002203B0 */

/* merge_units: begin func_00220410 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O00220410 { char p[0xC]; int id; };
struct H00220410 { O00220410* p; int id; };
static inline O00220410* Get00220410(H00220410* h) {
    bool isNull;
bool ok;
O00220410* t;
    t = h->p;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->id != h->id) ok = false;
    return ok ? t : 0;
}
extern "C" bool cSafePtr_cGOBJ_opEq(H00220410* x, H00220410* y)
{
    O00220410* b = Get00220410(y); return Get00220410(x) == b;
}
static inline void merge_flush_func_00220410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220410 */

/* merge_units: begin func_00220480 */
#pragma push /* merge_units */
/* Iterator dereference: address of the node value. */
int* cLListIterator_cSafePtr_cGOBJ_opMul(GenListPos* it) {
    return &it->node->value;
}

Word* cLListIterator_cSafePtr_cGOBJ_opAssign(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void cLList_cSafePtr_cGOBJ_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cLListIterator_cSafePtr_cGOBJ_ctor_void(void* self) {
    return self;
}
static inline void merge_flush_func_00220480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220480 */
