/*
 * Matched functions (byte-identical with the retail executable).
 * Objective notification: forwards a text to the HUD notification queue of the
 * global UI receiver (null text is ignored by the callee).
 */

#include "types.h"
#include "Objective_types.h"

extern char D_004FFC2C[]; /* global UI receiver */
extern void Hud_PostNotification(int, char*);

void ObjMan_Notify(cObjectiveMan* mgr, char* text) {
    Hud_PostNotification(*(int*)D_004FFC2C, text);
}
