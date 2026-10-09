/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "npc_types.h"

extern int D_005827F0;
extern int D_005827F8;
extern int D_00582800;
extern int D_00582808;
extern int D_00582810;
extern char D_00582778;
extern char D_00582780;
extern char D_00582788;
extern char D_00582790;
extern char D_00582798;

/* Resets the five NPC info slots (word and flag of each). */
void func_004321D0(void) {
    D_005827F0 = 0;
    D_005827F8 = 0;
    D_00582800 = 0;
    D_00582808 = 0;
    D_00582810 = 0;
    D_00582778 = 0;
    D_00582780 = 0;
    D_00582788 = 0;
    D_00582790 = 0;
    D_00582798 = 0;
}
