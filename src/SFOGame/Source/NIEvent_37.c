/*
 * SFOGame/Source/NIEvent: 1 file, 0023FAA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023FAA0 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { int a; } Proto_0023FAA0;
extern char D_004F7C40[];
extern void cNIShuttle_NIShuttleCallback(void);

NETREG_BEGIN_KEEP(cNIShuttle_InitNet, Proto_0023FAA0)
NETREG_FIELD(a, 4, 1)
NETREG_END(D_004F7C40, cNIShuttle_NIShuttleCallback)
static inline void merge_flush_func_0023FAA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023FAA0 */
