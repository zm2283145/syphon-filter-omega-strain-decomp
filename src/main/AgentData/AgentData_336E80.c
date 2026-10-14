/*
 * main/AgentData: range (3 files, 00336E80-00336F70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "net_write_one_word.h"

/* merge_units: begin func_00336E80 */
#pragma push /* merge_units */
typedef struct { char d[0xAC]; } E36E80;
extern int D_0052FE80;
extern E36E80 D_0052FE90[];
E36E80* func_00336E80(int unused, int i)
{
    if (i >= 0 && i < D_0052FE80)
        return &D_0052FE90[i];
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336E80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336E80 */

/* merge_units: begin func_00336EC0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char s[0x20]; } S20_36EC0;
typedef struct { char s[0x80]; } S80_36EC0;
typedef struct { int a, b, c; char s1[0x20]; char s2[0x80]; } E336EC0;
#if 0 /* merge_units */
extern E336EC0 D_0052FE90[];
#endif /* merge_units */
#define D_0052FE90 ((E336EC0*)&D_0052FE90) /* merge_units */


/* Appends a copy of e to the fixed 64-entry table. */
extern "C" void func_00336EC0(void* self, E336EC0* e)
{
    if (e && D_0052FE80 < 0x40) {
        D_0052FE90[D_0052FE80++] = *e;
    }
}
#undef D_0052FE90 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336EC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336EC0 */

/* merge_units: begin func_00336F70 */
#pragma push /* merge_units */
/* Serialize the 32-bit message field. */
DEFINE_NET_WRITE_ONE_WORD(cNetAddObjectiveMsg_v04)
#pragma pop /* merge_units */
/* merge_units: end func_00336F70 */
