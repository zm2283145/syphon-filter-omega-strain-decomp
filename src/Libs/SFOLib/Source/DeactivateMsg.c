/*
 * Libs/SFOLib/Source/DeactivateMsg: 1 file, 00429190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_classes.h"
extern "C" {
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
VSlots67** cNetObj_GetNetSystem(int id);
}
#pragma define_section GUARD_DTOR ".dtors_drop" far_absolute RX
struct Guard429190 {
    Guard429190() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(GUARD_DTOR) ~Guard429190() { D_005723C8 = 0; }
};
typedef struct { char pad[4]; int id; } M429190;
extern "C" int cDeactivateMsg_DeactivateCallback(int a0, int a1, int a2, M429190* m) {
    Guard429190 g;
    if (D_005721D0) {
        VSlots67** e = cNetObj_GetNetSystem(m->id);
        if (e) (*e)->slot7();
    }
    return 8;
}
static inline void merge_flush_func_00429190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429190 */
