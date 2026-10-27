/*
 * SFOGame/Source/NIEvent: 1 file, 0023F890
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023F890 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { char a; } Proto_0023F890;
extern char D_004F7C48[];
extern void cNICameraMsg_NICameraCallback(void);

NETREG_BEGIN_KEEP(cNICameraMsg_InitNet, Proto_0023F890)
NETREG_FIELD(a, 1, 1)
NETREG_END(D_004F7C48, cNICameraMsg_NICameraCallback)
static inline void merge_flush_func_0023F890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F890 */
