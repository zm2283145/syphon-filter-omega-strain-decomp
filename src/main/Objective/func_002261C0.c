/*
 * Matched functions (byte-identical with the retail executable).
 * Objective manager teardown helper: if flag +0xAC is set, notifies the global
 * UI receiver and clears the flag.
 */

#include "types.h"
#include "Objective_types.h"

extern char D_004FFC2C[]; /* global UI receiver */
extern void func_00242900(int);

void func_002261C0(cObjectiveMan* mgr) {
    if (mgr->unkAC != 0) {
        func_00242900(*(int*)D_004FFC2C);
        mgr->unkAC = 0;
    }
}
