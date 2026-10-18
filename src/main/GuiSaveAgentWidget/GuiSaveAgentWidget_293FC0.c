/*
 * main/GuiSaveAgentWidget: 2 files, 00293FC0-002940B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00293FC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "guarded_new_init.h"

extern "C" char D_004DD460[];
extern "C" char D_004DD3A0[];

/* Factory: allocate and construct a three-level widget. */
extern "C" { char D_004A9E10[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INIT(GuiAgentSave_ctor, 0x80, D_004A9E10, GuiWidget_ctor, D_004E1220,
                           GN_W(0x48, -2); GN_VT(D_004DD460); GN_F(0x78, 10.0f);
                           GN_B(0x7C, 1); GN_VT(D_004DD3A0))
#pragma pop /* merge_units */
/* merge_units: end func_00293FC0 */

/* merge_units: begin func_002940B0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DD400[];

/* Factory: allocate and construct a three-level widget. */
DEFINE_GUARDED_NEW_VT_INIT(GuiAgentLoad_Create, 0x80, D_004A9E10, GuiWidget_ctor, D_004E1220,
                           GN_W(0x48, -2); GN_VT(D_004DD460); GN_F(0x78, 10.0f);
                           GN_B(0x7C, 0); GN_VT(D_004DD400))
#pragma pop /* merge_units */
/* merge_units: end func_002940B0 */
