/*
 * SFOGame/Source/npc: 3 files, 0014D610-0014D6F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014D610 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"

#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cAIMessage_dtor, D_004D9340, cMessage_dtor)
static inline void merge_flush_func_0014D610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D610 */

/* merge_units: begin func_0014D670 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; float x60; } NpcB1;
int cNPC_GetTravelSpeed_void(NpcB1* n) {
    float f = n->x60;
    int r;
    if (f >= 0.0005f) {
        if (f < 0.25f) r = 1;
        else if (f > 0.75f) r = 3;
        else r = 2;
    } else r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D670 */

/* merge_units: begin func_0014D6F0 */
#pragma push /* merge_units */
typedef struct {
    char pad[0x60];
    float value;
    int level;
    char pad2[0x141 - 0x68];
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 1;
    unsigned char flag5 : 1;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
} cNPC;

/* cNPC virtual slot 0x4E: when level <= 100, stores v, sets level to 100 and clears flag bit 6 at +0x141. */
void cNPC_SetTravelSpeed(cNPC* npc, float v)
{
    if (npc->level <= 100) {
        npc->value = v;
        npc->level = 100;
        npc->flag6 = 0;
    }
}
static inline void merge_flush_func_0014D6F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D6F0 */
