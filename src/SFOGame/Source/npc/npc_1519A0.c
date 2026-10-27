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
extern int cNPC_Patrol(S1519A0*, int);
extern int cNPC_EnemySeen(S1519A0*, int);
extern int cNPC_TakeCover(S1519A0*, int);
extern int cNPC_AttackFromCover(S1519A0*, int);
extern int cNPC_Attack(S1519A0*, int);
extern int cNPC_SearchLook(S1519A0*, int);
extern int cNPC_Flee(S1519A0*, int);
extern int cNPC_ScriptControl(S1519A0*, int);
extern int cNPC_CarryBody(S1519A0*, int);
extern int cNPC_Follow_cMessageR(S1519A0*, int);
extern int cNPC_AvoidGrenade(S1519A0*, int);
unsigned char cNPC_Update(S1519A0* p, int a) {
    unsigned char r;
    switch (p->state) {
    case 0: r = cNPC_Patrol(p, a); break;
    case 1: r = cNPC_EnemySeen(p, a); break;
    case 2: r = cNPC_TakeCover(p, a); break;
    case 3: r = cNPC_AttackFromCover(p, a); break;
    case 4: r = cNPC_Attack(p, a); break;
    case 5: r = cNPC_SearchLook(p, a); break;
    case 6: r = cNPC_Flee(p, a); break;
    case 7: r = cNPC_ScriptControl(p, a); break;
    case 8: r = cNPC_CarryBody(p, a); break;
    case 9: r = cNPC_Follow_cMessageR(p, a); break;
    case 10: r = cNPC_AvoidGrenade(p, a); break;
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
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern void cMessage_ctor_cMessageNameR(Msg_00151A90* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(Msg_00151A90* msg, void* target, int flags);
extern void cMessage_dtor(Msg_00151A90* msg, int flags);
int cNPC_HandleCASEvent(Self_00151A90* self, Ev_00151A90* ev)
{
    switch (ev->type) {
    case 6: {
        int v = self->mode == 4 ? 0x11 : 0x13;
        Msg_00151A90 msg;
        cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
        msg.value = v;
        msg.b28 = 0;
        msg.vtable = D_004E0840;
        { Tgt_00151A90* t = self->target;
        msg.b20 = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, t, 0); }
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
        break;
    }
    case 9:
        if (self->mode == 4) {
            Msg_00151A90 msg;
            cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0x11;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            QueueMessage_cMessageR_cSystemP_int(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        }
        break;
    case 8:
        {
        int m = self->mode;
        if (m == 4) {
            Msg_00151A90 msg;
            cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0xF;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            QueueMessage_cMessageR_cSystemP_int(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        } else if (m == 11) {
            Msg_00151A90 msg;
            cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0x10;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            QueueMessage_cMessageR_cSystemP_int(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        } else if (m == 3) {
            if (self->target->state != 0x10) {
                Msg_00151A90 msg;
                cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
                msg.b28 = 0;
                msg.vtable = D_004E0840;
                msg.value = 0x1A;
                QueueMessage_cMessageR_cSystemP_int(&msg, self->target, 0);
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
