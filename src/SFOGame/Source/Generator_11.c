/*
 * SFOGame/Source/Generator: 1 file, 0021D600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021D600 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { char a; int b; short c; } Proto_0021D600;
extern char D_004F56C8[];
extern void cGeneratorMessageBase_GeneratorMessageBaseCallback(void);

NETREG_BEGIN_KEEP(cGeneratorMessageBase_InitNet, Proto_0021D600)
NETREG_FIELD(a, 1, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 2, 1)
NETREG_END(D_004F56C8, cGeneratorMessageBase_GeneratorMessageBaseCallback)
static inline void merge_flush_func_0021D600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D600 */
