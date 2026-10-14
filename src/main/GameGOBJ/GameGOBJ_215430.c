/*
 * main/GameGOBJ: range (2 files, 00215430-002154B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00215430 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
class C4It215 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void Fn(int a);
};
struct C4Obj215 { char pad[0x11C]; int count; C4It215** items; };
extern "C" void Lift_DeactivateRecipients(C4Obj215* o) {
    int i;
    for (i = 0; i < o->count; i++) {
        o->items[i]->Fn(-1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00215430(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00215430 */

/* merge_units: begin func_002154B0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C5Item {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Method64(int a); /* +0x64 */
};
struct C5Lift { char pad[0x11C]; int count; C5Item** items; };
#pragma opt_strength_reduction off
extern "C" void Lift_ActivateRecipients(C5Lift* p) {
    int i;
    for (i = 0; i < p->count; i++) {
        p->items[i]->Method64(-1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002154B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002154B0 */
