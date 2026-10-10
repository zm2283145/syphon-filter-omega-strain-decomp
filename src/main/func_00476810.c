#include "types.h"

/* Body-toss message (vtable, base data, parameters). */
typedef struct TossMsg {
    void* vtable;
    char base[0x18];
    int size;
    unsigned char kind;
    char pad[3];
    unsigned char enable;
    char pad2[0xB];
} TossMsg;

typedef struct ScriptArgs1 {
    int target;
} ScriptArgs1;

extern int GObj_IdentityB(int handle);
extern void Event_Construct(TossMsg* msg, void* name);
extern void Event_Send(TossMsg* msg, void* target, int flags);
extern void cMessage_dtor(TossMsg* msg, int flags);
extern char D_00588038[];
extern char D_004E1AE0[]; /* body-toss message vtable */
extern char D_004DCF10[]; /* base message vtable */

/* Script native: ActivateBodyToss(target). */
int Script_ActivateBodyToss(ScriptArgs1* args) {
    TossMsg sent, unused;
    int target = GObj_IdentityB(args->target);
    Event_Construct(&unused, D_00588038);
    unused.vtable = D_004E1AE0;
    unused.enable = 1;
    unused.kind = 8;
    unused.size = 0x40;
    Event_Construct(&sent, D_00588038);
    sent.vtable = D_004E1AE0;
    sent.enable = 1;
    Event_Send(&sent, (void*)target, 0);
    sent.vtable = D_004DCF10;
    cMessage_dtor(&sent, 0);
    unused.vtable = D_004DCF10;
    cMessage_dtor(&unused, 0);
    return 0;
}
