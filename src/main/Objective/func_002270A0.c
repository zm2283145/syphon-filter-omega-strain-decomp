/*
 * Matched functions (byte-identical with the retail executable).
 * Wrappers around the objective enumeration ObjMan_GatherObjectives(mgr, out, max, ...),
 * which collects up to max matching objectives (globals first, then the
 * current stage). The trailing five arguments are filters; -1 disables one.
 */

#include "types.h"
#include "Objective_types.h"

extern int ObjMan_GatherObjectives(cObjectiveMan*, cObjective**, int, int, int, int, int, int);

int func_002270A0(cObjectiveMan* mgr, cObjective** out, int max) {
    return ObjMan_GatherObjectives(mgr, out, max, 1, -1, -1, -1, 1);
}
