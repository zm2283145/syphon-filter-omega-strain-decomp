/*
 * main/DME: 3 files, 00429BA0-00429CB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429BA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(func_00429BA0, D_004E0EC0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00429BA0 */

/* merge_units: begin func_00429C00 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern unsigned char D_005723C8;
extern unsigned char D_005724B0;

void func_00429C00(int *arg0) {
    int var_v1;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (*arg0 == 0) {
        var_v1 = D_005721C8 ? D_005721C0 : 1;
        if (var_v1 != 0) {
            D_005724B0 = 0xA;
        } else if (D_005724B0 == 9) {
            D_005724B0 = 0xA;
        } else {
            D_005724B0 = 9;
        }
    } else {
        D_005724B0 = 0xB;
    }
    D_005723C8 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429C00 */

/* merge_units: begin func_00429CB0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
extern float D_005723D8;
extern float D_005723E0;
extern int D_005723E8;

void func_00429CB0(int arg0) {
    if (arg0 < 0x3E8 && 0 <= arg0) {
        D_005723E8 += 1;
        D_005723E0 += 0.001f * (float) arg0;
        D_005723D8 = D_005723E0 / (float) D_005723E8;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00429CB0 */
