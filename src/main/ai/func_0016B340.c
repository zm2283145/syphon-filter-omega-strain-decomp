/*
 * Matched functions (byte-identical with the retail executable).
 * AI receiver and action-message constructors.
 */

#include "types.h"
#include "ai_types.h"

extern char D_004D92A0[]; /* action message vtable */
extern char D_004D92C0[]; /* action message with sender vtable */
extern char D_004D9810[];
extern char D_004D9870[]; /* action message with sender and target vtable */
extern char D_004EE5C0[];
extern char D_004EE5C8[];
extern int Event_Construct(cActionMsg*, int);
extern int Receiver_Construct(void*, int);

void* func_0016B340(void* self) {
    Receiver_Construct(self, (int)D_004EE5C0);
    *(int*)self = (int)D_004D9810;
    return self;
}

/* Builds an action message carrying sender and target identities (event byte ends as 2). */
cActionMsg* func_0016B380(cActionMsg* msg, int* sender, int* target, int action) {
    Event_Construct(msg, (int)D_004EE5C8);
    msg->base.vtable = D_004D92A0;
    msg->event = 0;
    msg->action = action;
    *(int*)&msg->amplitude = 0;
    *(int*)&msg->unk2C = 0;
    msg->base.vtable = D_004D92C0;
    msg->sender = *sender;
    msg->base.vtable = D_004D9870;
    msg->target = *target;
    msg->event = 2;
    return msg;
}
