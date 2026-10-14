/*
 * main/npc: range (2 files, 001519A0-00151A90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001519A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x44]; int state; } S1519A0;
extern int NpcAi_ModePatrol(S1519A0*, int);
extern int NpcAi_ModeAlert(S1519A0*, int);
extern int NpcAi_ModeTakeCover(S1519A0*, int);
extern int NpcAi_ModeAttackFromCover(S1519A0*, int);
extern int NpcAi_ModeAttack(S1519A0*, int);
extern int NpcAi_ModeSearch(S1519A0*, int);
extern int NpcAi_ModeFlee(S1519A0*, int);
extern int NpcAi_ScriptControlMode(S1519A0*, int);
extern int NpcAi_ModeCarryBody(S1519A0*, int);
extern int NpcAi_ModeFollow(S1519A0*, int);
extern int NpcAi_ModeGrenadeEvasion(S1519A0*, int);
unsigned char NpcAi_DispatchMode(S1519A0* p, int a) {
    unsigned char r;
    switch (p->state) {
    case 0: r = NpcAi_ModePatrol(p, a); break;
    case 1: r = NpcAi_ModeAlert(p, a); break;
    case 2: r = NpcAi_ModeTakeCover(p, a); break;
    case 3: r = NpcAi_ModeAttackFromCover(p, a); break;
    case 4: r = NpcAi_ModeAttack(p, a); break;
    case 5: r = NpcAi_ModeSearch(p, a); break;
    case 6: r = NpcAi_ModeFlee(p, a); break;
    case 7: r = NpcAi_ScriptControlMode(p, a); break;
    case 8: r = NpcAi_ModeCarryBody(p, a); break;
    case 9: r = NpcAi_ModeFollow(p, a); break;
    case 10: r = NpcAi_ModeGrenadeEvasion(p, a); break;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001519A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001519A0 */

/* merge_units: begin func_00151A90 */
#pragma push /* merge_units */
typedef struct Msg_00151A90 {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
    char pad29[7];
} Msg_00151A90;
typedef struct Tgt_00151A90 { char pad[0x320C]; int state; } Tgt_00151A90;
typedef struct Self_00151A90 { char pad[0x30]; Tgt_00151A90* target; char pad34[0x114 - 0x34]; int mode; } Self_00151A90;
typedef struct Ev_00151A90 { char pad[0x24]; int type; } Ev_00151A90;
extern char D_0055D480[];
extern char D_004E0840[];
extern void Event_Construct(Msg_00151A90* msg, void* name);
extern void Event_Send(Msg_00151A90* msg, void* target, int flags);
extern void cMessage_dtor(Msg_00151A90* msg, int flags);
int NpcAi_HandleLivingMessage(Self_00151A90* self, Ev_00151A90* ev)
{
    switch (ev->type) {
    case 6: {
        int v = self->mode == 4 ? 0x11 : 0x13;
        Msg_00151A90 msg;
        Event_Construct(&msg, D_0055D480);
        msg.value = v;
        msg.b28 = 0;
        msg.vtable = D_004E0840;
        { Tgt_00151A90* t = self->target;
        msg.b20 = 1;
        Event_Send(&msg, t, 0); }
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
        break;
    }
    case 9:
        if (self->mode == 4) {
            Msg_00151A90 msg;
            Event_Construct(&msg, D_0055D480);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0x11;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            Event_Send(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        }
        break;
    case 8:
        {
        int m = self->mode;
        if (m == 4) {
            Msg_00151A90 msg;
            Event_Construct(&msg, D_0055D480);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0xF;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            Event_Send(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        } else if (m == 11) {
            Msg_00151A90 msg;
            Event_Construct(&msg, D_0055D480);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0x10;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            Event_Send(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        } else if (m == 3) {
            if (self->target->state != 0x10) {
                Msg_00151A90 msg;
                Event_Construct(&msg, D_0055D480);
                msg.b28 = 0;
                msg.vtable = D_004E0840;
                msg.value = 0x1A;
                Event_Send(&msg, self->target, 0);
                msg.vtable = D_004E0840;
                cMessage_dtor(&msg, 0);
            }
        }
        }
        break;
    default:
        return 0;
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00151A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00151A90 */
