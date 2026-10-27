/*
 * SFOGame/Source/hotbox: 1 file, 0016FD00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016FD00 */
#pragma push /* merge_units */
#include "types.h"
#include "event_toggle_send.h"

/* Post the "on" event and set the state flag. */
extern char g_cEnableMsgClass[];
extern void cEnableMsg_dtor();
extern void cEnableMsg_Clone();
extern void cEnableMsg_Pack();
extern void cEnableMsg_getSOBJClassId();
void * const D_004E0880[8] = { (void*)0x0, (void*)0x0, (void*)cEnableMsg_dtor, (void*)cEnableMsg_Clone, (void*)cEnableMsg_Pack, (void*)cEnableMsg_getSOBJClassId, (void*)0x0, (void*)0x0 };
void cEnableMsg_SendEnabled(ToggleEventMsg* msg, int id);
void cHotbox_Enable(ToggleSender* self)
{
    if (g_IsMultiplayer) {
        ToggleEventMsg msg;
        cMessage_ctor_cMessageNameR(&msg, g_cEnableMsgClass);
        msg.vtable = ((char*)D_004E0880);
        msg.target = -1;
        msg.size = 0x40;
        cEnableMsg_SendEnabled(&msg, self->id);
        msg.vtable = ((char*)D_004E0880);
        cMessage_dtor(&msg, 0);
    }
    self->state = (1);
}
static inline void merge_flush_func_0016FD00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016FD00 */
