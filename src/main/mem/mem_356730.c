/*
 * main/mem: 2 files, 00356730-003567B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00356730 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct H356730 { int v; };
struct P356730 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H356730 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
extern "C" void Resource_Construct(void* m);
/* constructor: reset two members, ids, mask, handle (copied through a stack temp) */
#pragma push
#pragma opt_propagation off
extern "C" P356730* GuiPersonnelMenu_ctor(P356730* p)
{
    *(int*)((char*)p + 0x24) = -2;
    *(int*)((char*)p + 0x20) = 0;
    Resource_Construct(p->memberA);
    Resource_Construct(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H356730 h; H356730* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    return p;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00356730 */

/* merge_units: begin func_003567B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiPersonnelScreen_dtor_3567B0, D_004DF0B0, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_003567B0 */
