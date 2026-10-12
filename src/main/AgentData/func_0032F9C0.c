#pragma opt_strength_reduction off
#include "types.h"
typedef union ScriptArg2F9C0 { int i; float f; void* p; } ScriptArg2F9C0;
typedef struct Lookup2F9C0 { void* name; int pad[5]; } Lookup2F9C0;
typedef struct Pair2F9C0 { int a; int b; } Pair2F9C0;
typedef struct Rec2F9C0 { int value; int pad[7]; } Rec2F9C0;
typedef struct Agent2F9C0 { char p0[0xC8]; int count; Rec2F9C0* recs; } Agent2F9C0;
extern Lookup2F9C0* D_00532AF8;
extern Pair2F9C0* D_00532B98;
extern void* func_003FDAE0(void* name);
extern int String_CompareNoCase(void* a, void* b);

static inline unsigned char Has2F9C0(Agent2F9C0* ag, void* name)
{
    int i;
    for (i = 0; i < ag->count; i++) {
        if (String_CompareNoCase(func_003FDAE0(D_00532AF8[i].name), name) == 0) {
            int v = ag->recs[i].value;
            if (v > 0 && v <= ((int*)D_00532B98)[i * 2]) return 1;
        }
    }
    return 0;
}

/* Script: true when the agent has a positive rating for the named entry within its solo limit. */
int Script_cAgentData_HasSoloPartime(ScriptArg2F9C0* args)
{
    int name[1];
    Agent2F9C0* ag = (Agent2F9C0*)args[0].p;
    name[0] = args[1].i;
    return Has2F9C0(ag, *(void**)name);
}
