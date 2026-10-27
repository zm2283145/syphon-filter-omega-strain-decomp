/*
 * Libs/SFOLib/Source/scriptManager: 1 file, 003DF710
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003DF710 */
#pragma push /* merge_units */
#pragma cplusplus on






#include "types.h"
#include "alloc_guard.h"
/* cScriptInterpreter_callScheduledFunction */
struct Pt2_ArgType { int type; };
struct Pt2_Handler { char* name; char pad4[0xC]; Pt2_ArgType** argTypes; };
struct Pt2_Interp { char pad[0x4EA0]; int ctx; };
struct Pt2_TInfo { char pad[0x45]; unsigned char owned; char pad46[6]; unsigned char isObj; };
struct Pt2_RObj { virtual void Destroy(int); };
extern "C" {
extern char D_004BD4C0[];
void cScriptInterpreter_error(Pt2_Interp*, char*, char*);
Pt2_TInfo* cScriptBase_getClass(int);
int cScriptInterpreter_UseIdInsteadOfPointer(Pt2_Interp*, Pt2_Handler*, Pt2_TInfo*);
int cScriptInterpreter_getObjPtr(int);
int cScriptInterpreter_callFunction(Pt2_Interp*, Pt2_Handler*, int*, int);
void cMemMan_Deallocate(int, void*, char*, int);
}
static inline void Pt2_FreeObj(Pt2_RObj* o) {
    AllocGuard g;
    o->Destroy(-1);
    cMemMan_Deallocate(0, o, D_004BD4C0, 0x752);
}
#pragma opt_strength_reduction off
extern "C" int cScriptInterpreter_callScheduledFunction(Pt2_Interp* in, Pt2_Handler* h, int* args, int n, int ctx) {
    int ret = 0;
    int j;
    int i;
    if (ctx >= 0 && ctx != in->ctx) {
        cScriptInterpreter_error(in, "ignoring scheduled %s call (scheduled before reload)", h->name);
    } else {
        i = 0;
        if (i < n) {
            int* a = args;
            do {
                int t = h->argTypes[i]->type;
                if (t >= 100) {
                    Pt2_TInfo* ti = cScriptBase_getClass(t);
                    if (ti && ti->isObj && !cScriptInterpreter_UseIdInsteadOfPointer(in, h, ti)) *a = cScriptInterpreter_getObjPtr(*a);
                }
                i++;
                a++;
            } while (i < n);
        }
        ret = cScriptInterpreter_callFunction(in, h, args, n);
        j = 0;
        if (j < n) {
            
            do {
                int t = h->argTypes[j]->type;
                if (t >= 100) {
                    Pt2_TInfo* ti = cScriptBase_getClass(t);
                    if (ti && ti->owned) Pt2_FreeObj((Pt2_RObj*)*args);
                }
                j++;
                args++;
            } while (j < n);
        }
    }
    return ret;
}
static inline void merge_flush_func_003DF710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DF710 */
