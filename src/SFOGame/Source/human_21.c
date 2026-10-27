/*
 * SFOGame/Source/human: 2 files, 00189540-00189560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00189540 */
#pragma push /* merge_units */
#include "types.h"
#include "short_string_data.h"

/* String character data. */
DEFINE_SHORT_STRING_DATA(cString_CStr)
static inline void merge_flush_func_00189540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00189540 */

/* merge_units: begin func_00189560 */
#pragma push /* merge_units */
typedef struct { char data[0x124]; } Entry124;
typedef struct { char pad[8]; Entry124* entries; } EntryTable;
typedef struct { char unk0; unsigned char index; } EntryRef;
extern EntryTable* D_0053BB94;

/* Returns the 0x124-byte table entry selected by ref->index. */
Entry124* cCollisionModel_FaceProperties_GetMaterialProperties(EntryRef* ref)
{
    return &D_0053BB94->entries[ref->index];
}
static inline void merge_flush_func_00189560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00189560 */
