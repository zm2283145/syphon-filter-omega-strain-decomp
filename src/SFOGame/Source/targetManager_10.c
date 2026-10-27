/*
 * SFOGame/Source/targetManager: 1 file, 0022D820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022D820 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct O0022D820 { char p[0xC]; int id; };
struct H0022D820 { O0022D820* p; int id; };
static inline O0022D820* Get0022D820(H0022D820* h) {
    bool isNull;
bool ok;
O0022D820* t;
    t = h->p;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->id != h->id) ok = false;
    return ok ? t : 0;
}
extern "C" bool std_equal_to_cSafePtr_cGOBJ_opCall(void* self, H0022D820* x, H0022D820* y)
{
    O0022D820* b = Get0022D820(y); return Get0022D820(x) == b;
}
static inline void merge_flush_func_0022D820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022D820 */
