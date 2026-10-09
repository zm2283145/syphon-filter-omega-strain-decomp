/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern char D_004E0840[];   /* ArgMsg vtable */
extern char D_0055D480[];   /* CAS action message type */
extern Message* Event_Construct(Message*, void*);

ArgMsg* Actor_SendCasAction(ArgMsg* self, int action, int flag) {
    Event_Construct(&self->base, D_0055D480);
    self->base.vtable = D_004E0840;
    self->arg0 = action;
    self->arg1 = flag;
    return self;
}
