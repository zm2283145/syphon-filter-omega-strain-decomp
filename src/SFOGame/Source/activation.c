/*
 * SFOGame/Source/activation: 1 file, 002240E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002240E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Obj002240E0 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void on(int arg);
    virtual void off(int arg);
    char pad[0x2A];
    char b2E;
};
extern "C" void cGOBJActivationMan_StreamCB(void* unused, Obj002240E0* o, int enable)
{
    if (enable) {
        o->on(0);
        o->b2E = 0;
    } else {
        o->off(0);
    }
}
static inline void merge_flush_func_002240E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002240E0 */
