/*
 * main/fireObj: range (2 files, 00261C00-00261C90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "event_toggle_send.h"

/* merge_units: begin func_00261C00 */
#pragma push /* merge_units */
/* Post the "on" event and set the state flag. */
DEFINE_EVENT_TOGGLE_SEND(cFireObj_v17, g_cEnableMsgClass, D_004E0880, func_003FF930, 1)
#pragma pop /* merge_units */
/* merge_units: end func_00261C00 */

/* merge_units: begin func_00261C90 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x18]; int flags; char pad2[4]; int target; char pad3[8]; } Msg_261C90;
typedef struct { char pad[0x10]; int id; char pad14[0x18]; unsigned char state; } S_261C90;
extern char g_cDisableMsgClass[];
extern char D_004E0860[];
#if 0 /* merge_units */
extern void Event_Construct(Msg_261C90* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

extern void NetMsg_Send(Msg_261C90* m, int id, int x);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg_261C90* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void cFireObj_v18(S_261C90* s)
{
    Msg_261C90 msg;
    Event_Construct(&msg, g_cDisableMsgClass);
    msg.vtable = D_004E0860;
    msg.target = -1;
    msg.flags = 0x40;
    NetMsg_Send(&msg, s->id, -1);
    s->state = 0;
    msg.vtable = D_004E0860;
    cMessage_dtor(&msg, 0);
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261C90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00261C90 */
