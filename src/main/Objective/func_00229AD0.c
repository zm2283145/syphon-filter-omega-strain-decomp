/*
 * Matched functions (byte-identical with the retail executable).
 * Script globals selecting the objective-screen fonts.
 */

#include "types.h"
#include "Objective_types.h"

extern char D_0048AB20[]; /* objectives body font id */
extern char D_004F7560[]; /* objectives header font id */
extern void Objectives_SetHeaderFont(int);
extern void Objectives_SetFont(int);

int Script_SetObjectivesHeaderFont(ScriptArg* args) {
    Objectives_SetHeaderFont(args[0].u8);
    return 0;
}

/* Sets the objectives header font. */
void Objectives_SetHeaderFont(int font) {
    *(char*)D_004F7560 = font;
}

int Script_SetObjectivesFont(ScriptArg* args) {
    Objectives_SetFont(args[0].u8);
    return 0;
}

/* Sets the objectives body font. */
void Objectives_SetFont(int font) {
    *(char*)D_0048AB20 = font;
}

int cObjective_v04(void) {
    return 1;
}
