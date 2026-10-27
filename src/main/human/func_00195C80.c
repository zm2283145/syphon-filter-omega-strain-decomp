/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern char D_004E0840[];   /* ArgMsg vtable */
extern char g_ActorActionMsgClass[];   /* CAS action message type */
extern Message* cMessage_ctor_cMessageNameR(Message*, void*);

ArgMsg* cCharActionMsg_ctor_int_eParamType(ArgMsg* self, int action, int flag) {
    cMessage_ctor_cMessageNameR(&self->base, g_ActorActionMsgClass);
    self->base.vtable = D_004E0840;
    self->arg0 = action;
    self->arg1 = flag;
    return self;
}
