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

extern void cAITarget_AddAwareness(int ai, int arg, int mode, float value);
extern void cMessage_ctor_cMessageNameR(NpcMsg* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(NpcMsg* msg, cNPC* target, int flags);
extern void cMessage_dtor(NpcMsg* msg, int flags);
extern char D_004EE550[];
extern char D_004D9340[]; /* AI mode message vtable */

/* cNPC vtable slot 0x1C: switches the AI to mode 8 and notifies itself. */
void cNPC_NoticeDamage(cNPC* self, int arg) {
    NpcMsg msg;
    cAITarget_AddAwareness(self->ai, arg, 8, 0.0f);
    cMessage_ctor_cMessageNameR(&msg, D_004EE550);
    msg.vtable = D_004D9340;
    msg.mode = 8;
    msg.target = -1;
    QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
    msg.vtable = D_004D9340;
    cMessage_dtor(&msg, 0);
}
