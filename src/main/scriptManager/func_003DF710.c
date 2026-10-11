#pragma cplusplus on






#include "types.h"
#include "alloc_guard.h"
/* ScriptEvent_Replay */
struct Pt2_ArgType { int type; };
struct Pt2_Handler { char* name; char pad4[0xC]; Pt2_ArgType** argTypes; };
struct Pt2_Interp { char pad[0x4EA0]; int ctx; };
struct Pt2_TInfo { char pad[0x45]; unsigned char owned; char pad46[6]; unsigned char isObj; };
struct Pt2_RObj { virtual void Destroy(int); };
extern "C" {
extern char D_004BD7C0[];
extern char D_004BD4C0[];
void Script_InvalidArgNop(Pt2_Interp*, char*, char*);
Pt2_TInfo* func_003D7590(int);
int func_003E0A70(Pt2_Interp*, Pt2_Handler*, Pt2_TInfo*);
int Script_LookupObjectById(int);
int Script_CallHandler(Pt2_Interp*, Pt2_Handler*, int*, int);
void Mem_Free(int, void*, char*, int);
}
static inline void Pt2_FreeObj(Pt2_RObj* o) {
    AllocGuard g;
    o->Destroy(-1);
    Mem_Free(0, o, D_004BD4C0, 0x752);
}
#pragma opt_strength_reduction off
extern "C" int ScriptEvent_Replay(Pt2_Interp* in, Pt2_Handler* h, int* args, int n, int ctx) {
    int ret = 0;
    int j;
    int i;
    if (ctx >= 0 && ctx != in->ctx) {
        Script_InvalidArgNop(in, D_004BD7C0, h->name);
    } else {
        i = 0;
        if (i < n) {
            int* a = args;
            do {
                int t = h->argTypes[i]->type;
                if (t >= 100) {
                    Pt2_TInfo* ti = func_003D7590(t);
                    if (ti && ti->isObj && !func_003E0A70(in, h, ti)) *a = Script_LookupObjectById(*a);
                }
                i++;
                a++;
            } while (i < n);
        }
        ret = Script_CallHandler(in, h, args, n);
        j = 0;
        if (j < n) {
            
            do {
                int t = h->argTypes[j]->type;
                if (t >= 100) {
                    Pt2_TInfo* ti = func_003D7590(t);
                    if (ti && ti->owned) Pt2_FreeObj((Pt2_RObj*)*args);
                }
                j++;
                args++;
            } while (j < n);
        }
    }
    return ret;
}
