/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_Wrap: 2 files, 00443E60-00443E70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00443E60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after SFOLobby_Support.cc (ends 0x00443100),
 * before SFOLobby_Wrap.cc (starts 0x00443EA0).
 */

#include "types.h"

void SFOLobby_DumpMemInfo(void) {
}
static inline void merge_flush_func_00443E60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00443E60 */

/* merge_units: begin func_00443E70 */
#pragma push /* merge_units */
extern int cTimer_GetMillisecondTime(void);

/* Calls cTimer_GetMillisecondTime and returns its result. */
long long SFOLobby_GetMillisecs(void)
{
    return cTimer_GetMillisecondTime();
}
static inline void merge_flush_func_00443E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00443E70 */
