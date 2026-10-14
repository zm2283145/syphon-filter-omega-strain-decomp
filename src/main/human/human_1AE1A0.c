/*
 * main/human: range (2 files, 001AE1A0-001AE230)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "canonical_key_copy.h"
#include "vc_copy.h"

/* merge_units: begin func_001AE1A0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
char* CanonicalKey_Construct(char* d, char* s)
{
    CANONICAL_KEY_INIT(d, s)
    return d;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE1A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE1A0 */

/* merge_units: begin func_001AE230 */
#pragma push /* merge_units */
typedef struct { char pad[5]; char flag; char pad6[10]; __int128 q; char pad20[0x50]; } E_E230;
typedef struct { char pad[0x3A0]; E_E230 e[4]; } O_E230;
void LookCtl_SetSlotPoint(O_E230* o, unsigned char i, __int128* src) {
    E_E230* e = (E_E230*)((char*)o->e + i * sizeof(E_E230));
    __int128* d = &e->q;
    VCopyF(d, src);
    e->flag = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE230(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE230 */
