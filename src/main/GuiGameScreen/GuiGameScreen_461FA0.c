/*
 * main/GuiGameScreen: 4 files, 00461FA0-00462140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00461FA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */

#include "loose05_types.h"

void func_00461FA0(Word4* self) {
    self->unk04 = 0;
}

void func_00461FB0(Word4* self) {
    self->unk04 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00461FA0 */

/* merge_units: begin func_00461FC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004C2538[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(ConcreteWidgetClassRep_GuiEndGameAwards_Create_void_2, 0x510, D_004C2538, GuiEndGameAwards_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_00461FC0 */

/* merge_units: begin func_00462070 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004E1220[]; extern char D_004E16D0[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiWidget_ctor(void* self);
}
struct G00462070 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
extern "C" G00462070* ConcreteWidgetClassRep_GuiAutoSaver_Create(void)
{
    G00462070* p;
    {
        AllocGuard guard;
        p = (G00462070*)cMemMan_Allocate(0, 0x78, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiWidget_ctor(p);
        p->vtable = D_004E1220; GW(0x48) = -2; p->vtable = D_004E16D0;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_00462070 */

/* merge_units: begin func_00462140 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_00462140, D_004E1220, GuiWidget_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00462140 */
