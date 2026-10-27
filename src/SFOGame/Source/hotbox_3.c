/*
 * SFOGame/Source/hotbox: 1 file, 0016FBE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016FBE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vtable; char pad04[0x18]; int size; int pad20; int target; char pad28[0x8]; } Msg_1C5680;
typedef struct { char pad[0x10]; int id; char pad14[0x18]; unsigned char state; } S_1C5680;
extern unsigned char g_IsMultiplayer;
void cMessage_ctor_cMessageNameR(Msg_1C5680* msg, void* type);
void cMessage_dtor(Msg_1C5680* msg, int flags);
extern char g_cDisableMsgClass[];
extern void cDisableMsg_dtor();
extern void cDisableMsg_Clone();
extern void cDisableMsg_Pack();
extern void cDisableMsg_getSOBJClassId();
void * const D_004E0860[8] = { (void*)0x0, (void*)0x0, (void*)cDisableMsg_dtor, (void*)cDisableMsg_Clone, (void*)cDisableMsg_Pack, (void*)cDisableMsg_getSOBJClassId, (void*)0x0, (void*)0x0 };
void cDisableMsg_SendDisabled(Msg_1C5680* msg, int id, int x);
void cHotbox_Disable(S_1C5680* self)
{
    if (g_IsMultiplayer) {
        Msg_1C5680 msg;
        cMessage_ctor_cMessageNameR(&msg, g_cDisableMsgClass);
        msg.vtable = ((char*)D_004E0860);
        msg.target = -1;
        msg.size = 0x40;
        cDisableMsg_SendDisabled(&msg, self->id, -1);
        msg.vtable = ((char*)D_004E0860);
        cMessage_dtor(&msg, 0);
    }
    self->state = 0;
}
static inline void merge_flush_func_0016FBE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016FBE0 */
