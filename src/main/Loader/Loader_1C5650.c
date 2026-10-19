/*
 * main/Loader: 2 files, 001C5650-001C5680
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C5650 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Accessors of the object built by ParticleGob_Create. */
void func_001C5650(UnkGobj001C5950* self) {
    self->base.unk2C = 1;
}

void func_001C5660(UnkGobj001C5950* self) {
    self->base.unk2C = 0;
}

void ParticleGob_ScaleBBox(UnkGobj001C5950* self, float value) {
    self->unk70 = value;
}
#pragma pop /* merge_units */
/* merge_units: end func_001C5650 */

/* merge_units: begin func_001C5680 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad04[0x18]; int size; int pad20; int target; char pad28[0x8]; } Msg_1C5680;
typedef struct { char pad[0x10]; int id; char pad14[0x18]; unsigned char state; } S_1C5680;
extern unsigned char g_IsMultiplayer;
void Event_Construct(Msg_1C5680* msg, void* type);
void cMessage_dtor(Msg_1C5680* msg, int flags);
extern char g_cDisableMsgClass[];
extern char D_004E0860[];
void NetMsg_Send(Msg_1C5680* msg, int id, int x);
void ParticleGob_Disable(S_1C5680* self)
{
    if (g_IsMultiplayer) {
        Msg_1C5680 msg;
        Event_Construct(&msg, g_cDisableMsgClass);
        msg.vtable = D_004E0860;
        msg.target = -1;
        msg.size = 0x40;
        NetMsg_Send(&msg, self->id, -1);
        msg.vtable = D_004E0860;
        cMessage_dtor(&msg, 0);
    }
    self->state = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_001C5680 */
