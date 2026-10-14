/*
 * main/AgentData: range (2 files, 0032F680-0032F740)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "agent_record_has.h"
#pragma pop

/* merge_units: begin func_0032F680 */
#pragma push /* merge_units */
#pragma cplusplus on

#pragma opt_strength_reduction off
DEFINE_AGENT_RECORD_HAS(cAgentData_HasBonusLevel, D_00532AA4, D_00532AA8, 0xAE0)
#pragma opt_strength_reduction reset
#pragma pop /* merge_units */
/* merge_units: end func_0032F680 */

/* merge_units: begin func_0032F740 */
#pragma push /* merge_units */
#pragma cplusplus on
union ScriptArg { int i; float f; void* p; };
struct E2F740 { int id; int a; unsigned char stat; char p9[7]; int need; int p14; };
struct A2F740 { int p0, p4; int stats[1]; };
extern "C" {
extern char D_00532AD0[];
int func_0032F850(void* t);
int func_0032F820(void* t);
void func_0032F840(E2F740** out, void* t, int* raw);
}

static inline bool Neq2F740(E2F740* a, E2F740* b) { return !(a == b); }
static inline unsigned char All2F740(A2F740* self)
{
    E2F740* b;
    E2F740* e;
    int t1;
    int t2;
    E2F740* first;
    t1 = func_0032F850(D_00532AD0);
    func_0032F840(&b, D_00532AD0, &t1);
    first = b;
    t2 = func_0032F820(D_00532AD0);
    func_0032F840(&e, D_00532AD0, &t2);
    for (E2F740* last = e; Neq2F740(first, last); first++) {
        if (self->stats[first->stat] < first->need)
            return 0;
    }
    return 1;
}

#pragma push
#pragma opt_common_subs off
extern "C" int Script_cAgentData_HasAllRatings(ScriptArg* args)
{
    return All2F740((A2F740*)args[0].p);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F740 */
