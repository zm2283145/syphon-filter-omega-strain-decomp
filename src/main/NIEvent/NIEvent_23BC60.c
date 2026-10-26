/*
 * main/NIEvent: range (3 files, 0023BC60-0023BD40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "vslot_pad.h"

/* merge_units: begin func_0023BC60 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cNIShuttle_dtor, D_004DC2F0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0023BC60 */

/* merge_units: begin func_0023BCC0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Item0023BCC0 {
public:
    VPAD8(a) VPAD1(b)
    virtual void reset(int how);
};
struct Ev0023BCC0 {
    char pad00[0x2C];
    char b2C;
    char pad2D[0xA0 - 0x2D];
    int count;
    Item0023BCC0** items;
};
#pragma opt_strength_reduction off
extern "C" void cNIEventOBJ_v09(Ev0023BCC0* self)
{
    int i;
    self->b2C = 0;
    for (i = 0; i < self->count; i++)
        self->items[i]->reset(-1);
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023BCC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023BCC0 */

/* merge_units: begin func_0023BD40 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma exceptions off
class G7V { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void fn(int x); };
struct G7Ev { char pad[0x2C]; unsigned char b2C; char pad2[0xA0 - 0x2D]; int count; G7V** arr; };
extern "C" void cNIEventOBJ_v08(G7Ev* e)
{
    int i;
    e->b2C = 1;
    for (i = 0; i < e->count; i++) {
        e->arr[i]->fn(-1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023BD40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023BD40 */
