/*
 * main/GuiNetJoinMission: 3 files, 002A9390-002A9520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A9390 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "triple_member_dtor_de8a0.h"

/* Destructor: members, base, optionally delete. */
DEFINE_TRIPLE_MEMBER_DTOR_DE8A0(GuiMissionLobbyScreen_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002A9390 */

/* merge_units: begin func_002A9430 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(std_vector_deleter_SelectElem_dtor_void)
#pragma pop /* merge_units */
/* merge_units: end func_002A9430 */

/* merge_units: begin func_002A9520 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new_init.h"

/* Factory: allocate, run the base constructor, set the vtable and members. */
extern "C" { char D_004AB6D8[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INIT(GuiNetJoinMission_Create, 0x16C, D_004AB6D8, GuiMenuScreen_ctor, D_004DDA50,
                           GN_W(0x84, 2); GN_W(0x160, 0); GN_W(0x164, 0))
#pragma pop /* merge_units */
/* merge_units: end func_002A9520 */
