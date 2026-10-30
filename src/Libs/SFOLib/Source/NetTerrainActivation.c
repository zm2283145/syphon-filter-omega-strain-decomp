/*
 * Libs/SFOLib/Source/NetTerrainActivation: 2 files, 00431E00-00431EA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00431E00 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { short a; short b; } Proto_0020E420;
extern int D_00582758;
extern void cNetTerrainActivation_NetTerrainActivationCallback(void);

NETREG_BEGIN(cNetTerrainActivation_InitNet, Proto_0020E420)
NETREG_FIELD(b, 2, 1)
NETREG_FIELD(a, 2, 1)
NETREG_END(&D_00582758, cNetTerrainActivation_NetTerrainActivationCallback)
static inline void merge_flush_func_00431E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00431E00 */

/* merge_units: begin func_00431EA0 */
#pragma push /* merge_units */
#include "message_pack.h"
#define PACK_BODY(e, b) MP_H(b, 0x8) = MP_I(e, 0x24); MP_H(b, 0xA) = MP_U(e, 0x28); MP_I(e, 0x1C) = 0x40;
DEFINE_MESSAGE_PACK(cNetTerrainActivation_Pack, 12, D_00582758, PACK_BODY)
static inline void merge_flush_func_00431EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00431EA0 */
