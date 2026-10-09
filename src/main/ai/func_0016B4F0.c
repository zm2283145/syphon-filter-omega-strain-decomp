/*
 * Matched functions (byte-identical with the retail executable).
 * Action-message constructor with sender identity and two float parameters.
 */

#include "types.h"
#include "ai_types.h"

extern char D_004D92A0[];
extern char D_004D92C0[];
extern char D_004EE5C8[];
extern int Event_Construct(cActionMsg*, int);

cActionMsg* func_0016B4F0(cActionMsg* msg, int* sender, int action, float amplitude, float f2C) {
    Event_Construct(msg, (int)D_004EE5C8);
    msg->base.vtable = D_004D92A0;
    msg->event = 0;
    msg->action = action;
    msg->amplitude = amplitude;
    msg->unk2C = f2C;
    msg->base.vtable = D_004D92C0;
    msg->sender = *sender;
    return msg;
}
