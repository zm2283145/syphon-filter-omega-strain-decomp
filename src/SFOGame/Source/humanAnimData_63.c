/*
 * SFOGame/Source/humanAnimData: 1 file, 00201FE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201FE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char data[0x30]; } Name;
typedef struct { char data[0x50]; } Binding;
typedef struct { int unused; } Handle;
extern Name* cString16N_3_ctor_charP(Name* n, const char* s);
extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier(Binding* b, Name* n, void* obj, int a);
extern void cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(Handle* h, void* obj, Name* n, Binding* b);
extern void cSkaAnim_dtor(Binding* b, int flags);
/* Registers two named bindings on the object. */
#pragma optimization_level 1
void BuildAnimationBlend_Climbs(void* obj)
{
    Binding bindY;
    Name nameC;
    Name nameD;
    Binding bindX;
    Name nameA;
    Name nameB;
    Handle h2;
    Handle h1;
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier(&bindX, cString16N_3_ctor_charP(&nameA, "DATA_ID_Climb4"), obj, 1);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&h1, obj, cString16N_3_ctor_charP(&nameB, "animClimbDown4"), &bindX);
    cSkaAnim_dtor(&bindX, -1);
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier(&bindY, cString16N_3_ctor_charP(&nameC, "DATA_ID_HangClimbUp"), obj, 1);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&h2, obj, cString16N_3_ctor_charP(&nameD, "animClimbDown8"), &bindY);
    cSkaAnim_dtor(&bindY, -1);
}
#pragma optimization_level reset
static inline void merge_flush_func_00201FE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201FE0 */
