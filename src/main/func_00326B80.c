#include "types.h"

/* Script message object (vtable, base data, parameters). */
typedef struct Msg {
    void* vtable;
    char base[0x18];
    int size;
    char pad[4];
    unsigned char enable;
    char pad2[0xB];
} Msg;

typedef struct ScriptArgs1 {
    int target;
} ScriptArgs1;

extern int GObj_IdentityB(int handle);
extern void Event_Construct(Msg* msg, void* name);
extern void Event_Send(Msg* msg, int target, int flags);
extern void cMessage_dtor(Msg* msg, int flags);
extern char D_0052AF10[];
extern char D_004DE6F0[]; /* super-jump message vtable */
extern char D_004DCF10[]; /* base message vtable */

/* Script native: EnableSuperJump(target) - sends an enable message to the target. */
int Script_EnableSuperJump(ScriptArgs1* args) {
    Msg msg;
    int target = GObj_IdentityB(args->target);
    Event_Construct(&msg, D_0052AF10);
    msg.vtable = D_004DE6F0;
    msg.enable = 1;
    msg.size = 0x40;
    Event_Send(&msg, target, 0);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
    return 0;
}
