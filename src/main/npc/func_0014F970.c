#include "types.h"

/* NPC message object (vtable, base data, parameters). */
typedef struct NpcMsg {
    void* vtable;
    char base[0x20];
    unsigned char mode;
    char pad[3];
    int target;
    char pad2[4];
} NpcMsg;

typedef struct cNPC {
    char pad[0x1AC];
    int ai;
} cNPC;

extern void func_0016C9D0(int ai, int arg, int mode, float value);
extern void Event_Construct(NpcMsg* msg, void* name);
extern void Event_Send(NpcMsg* msg, cNPC* target, int flags);
extern void cMessage_dtor(NpcMsg* msg, int flags);
extern char D_004EE550[];
extern char D_004D9340[]; /* AI mode message vtable */

/* cNPC vtable slot 0x1C: switches the AI to mode 8 and notifies itself. */
void cNPC_v1C(cNPC* self, int arg) {
    NpcMsg msg;
    func_0016C9D0(self->ai, arg, 8, 0.0f);
    Event_Construct(&msg, D_004EE550);
    msg.vtable = D_004D9340;
    msg.mode = 8;
    msg.target = -1;
    Event_Send(&msg, self, 0);
    msg.vtable = D_004D9340;
    cMessage_dtor(&msg, 0);
}
