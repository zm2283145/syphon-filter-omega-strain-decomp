/*
 * SFOGame/Source/Generator: 3 files, 0021D4D0-0021D600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021D4D0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define BASE_BODY(e, b) MP_I(b, 0xC) = MP_I(MP_P(e, 0x24), 0xC); MP_S(b, 8) = 0;
DEFINE_MESSAGE_PACK_INLINE(GeneratorMessageBase_Pack, 0x14, D_004F56C8, BASE_BODY)

#define PACK_TAIL(e, b) MP_S(b, 8) = 1;
DEFINE_MESSAGE_PACK_DERIVED(cSpawnedNPCMsg_Pack, 0x14, GeneratorMessageBase_Pack, PACK_TAIL)
static inline void merge_flush_func_0021D4D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D4D0 */

/* merge_units: begin func_0021D580 */
#pragma push /* merge_units */
#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(MP_P(e, 0x24), 0xC); MP_S(b, 8) = 0;

DEFINE_MESSAGE_PACK(cGeneratorMessageBase_Pack, 20, D_004F56C8, PACK_BODY)
static inline void merge_flush_func_0021D580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D580 */

/* merge_units: begin func_0021D600 */
#pragma push /* merge_units */
#include "net_register_type.h"

typedef struct { char a; int b; short c; } Proto_0021D600;
#if 0 /* merge_units */
extern char D_004F56C8[];
#endif /* merge_units */
#define D_004F56C8 ((char*)&D_004F56C8) /* merge_units */

extern void cGeneratorMessageBase_GeneratorMessageBaseCallback(void);

NETREG_BEGIN_KEEP(cGeneratorMessageBase_InitNet, Proto_0021D600)
NETREG_FIELD(a, 1, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 2, 1)
NETREG_END(D_004F56C8, cGeneratorMessageBase_GeneratorMessageBaseCallback)
#undef D_004F56C8 /* merge_units */
static inline void merge_flush_func_0021D600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D600 */
