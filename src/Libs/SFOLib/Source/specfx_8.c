/*
 * Libs/SFOLib/Source/specfx: 1 file, 003EC5E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EC5E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
class OC5E0 {
public:
    int m0;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
struct NC5E0 { int m0; NC5E0* next; OC5E0** data; };
extern "C" {
void std_list_deleter_voidPtr_begin_void(int* out, void* list);
void std_list_tItemPtr_generic_iterator_ctor(NC5E0** out, int* in);
void std_list_tItemPtr_end(int* out, void* list);
void cLListIterator_tItemPtr_ctor(NC5E0** out, int* in);
}
extern "C" void cSfxScheduler_Render(void* self)
{
    NC5E0* e;
    NC5E0* it;
    int t1;
    int t2;
    NC5E0* n;
    std_list_deleter_voidPtr_begin_void(&t1, self);
    std_list_tItemPtr_generic_iterator_ctor(&it, &t1);
    for (n = it; std_list_tItemPtr_end(&t2, self), cLListIterator_tItemPtr_ctor(&e, &t2), n != e; n = n->next)
        (*n->data)->v4();
}
static inline void merge_flush_func_003EC5E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EC5E0 */
