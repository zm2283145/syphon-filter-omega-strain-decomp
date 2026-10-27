/*
 * SFOGame/Source/GuiGameScreen: 4 files, 0045EF50-0045F1A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045EF50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cDisplayClientInteractMsg_v01, 0x2C, D_004C2290, 0x78, D_004E1680, NMC_W(0x24); NMC_W(0x28))
static inline void merge_flush_func_0045EF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045EF50 */

/* merge_units: begin func_0045F070 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiGameScreen_types.h"

extern int D_00586178;

void cClearClientInteractMsg_v04(void) {
}

int cClearClientInteractMsg_v05(void) {
    return D_00586178;
}
static inline void merge_flush_func_0045F070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045F070 */

/* merge_units: begin func_0045F090 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_NET_MSG_CLONE(cClearClientInteractMsg_Clone, 0x24, D_004C2290, 0x86, D_004E16A0, (void)0)
static inline void merge_flush_func_0045F090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045F090 */

/* merge_units: begin GuiGameScreen_45F1A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004C2420[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(GuiGameScreen_Create, 0x130, D_004C2420, GuiGameScreen_ctor)
static inline void merge_flush_GuiGameScreen_45F1A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiGameScreen_45F1A0 */
