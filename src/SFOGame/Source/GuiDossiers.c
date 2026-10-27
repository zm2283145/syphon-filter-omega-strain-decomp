/*
 * SFOGame/Source/GuiDossiers: 2 files, 00349CA0-00349D70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00349CA0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Factory: allocate a 0xA8-byte GuiScreen-derived object and construct it inline. */
extern "C" {
extern char D_004DEB10[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiLobbyScreen_ctor(void* self);
}
struct O349CA0 { void* vtable; char pad[0x80]; int a84; int a88; char pad8C[0x10]; int a9C; };
extern "C" O349CA0* GuiNetMessages_Create(void)
{
    O349CA0* p;
    {
        AllocGuard guard;
        p = (O349CA0*)cMemMan_Allocate(0, 0xA8, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiLobbyScreen_ctor(p);
        p->vtable = D_004DEB10;
        p->a84 = 9;
        p->a88 = 0;
        p->a9C = -1;
    }
    return p;
}
static inline void merge_flush_func_00349CA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00349CA0 */

/* merge_units: begin func_00349D70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

DEFINE_GUARDED_NEW_CTOR(ConcreteWidgetClassRep_GuiNetMessageArray_Create_void_2, 0xB4, D_004BA4A8, GuiNetMessageArray_ctor)
static inline void merge_flush_func_00349D70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00349D70 */
