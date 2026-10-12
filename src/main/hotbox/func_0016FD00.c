#include "types.h"
#include "event_toggle_send.h"

/* Post the "on" event and set the state flag. */
extern char g_cEnableMsgClass[];
extern void cEnableMsg_dtor();
extern void cEnableMsg_v01();
extern void cEnableMsg_v02();
extern void cEnableMsg_v03();
void * const D_004E0880[8] = { (void*)0x0, (void*)0x0, (void*)cEnableMsg_dtor, (void*)cEnableMsg_v01, (void*)cEnableMsg_v02, (void*)cEnableMsg_v03, (void*)0x0, (void*)0x0 };
void func_003FF930(ToggleEventMsg* msg, int id);
void Hotbox_Enable(ToggleSender* self)
{
    if (D_005721C8) {
        ToggleEventMsg msg;
        Event_Construct(&msg, g_cEnableMsgClass);
        msg.vtable = ((char*)D_004E0880);
        msg.target = -1;
        msg.size = 0x40;
        func_003FF930(&msg, self->id);
        msg.vtable = ((char*)D_004E0880);
        cMessage_dtor(&msg, 0);
    }
    self->state = (1);
}
