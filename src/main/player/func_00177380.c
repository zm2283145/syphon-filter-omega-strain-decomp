#pragma cplusplus on
#include "types.h"
#define CMSG_NO_PROTOS
#define CMSG_KIND_T signed char
#include "cmessage.h"
/* Player_DispatchMessage: the player component's message handler (zone enter/leave, pickup
   triggers, teleports, flags); anything else goes to the base receiver. */
struct M4_177380 { float m[16]; } __attribute__((aligned(16)));
struct TMsg_177380 { CMSG_HEADER; signed char mode; char pad25[0xB]; M4_177380 mtx; } __attribute__((aligned(16)));
struct TrigMsg_177380 { CMSG_HEADER; int a24; int a28; int a2C; int a30; int a34; };
struct Msg_177380 { CMSG_HEADER; unsigned char b24; char pad25[3]; int sub; int id; };
/* the same byte read through a signed view: the (unsigned char) compares of case 13 then give
   retail's lbu + move (the function's quad-copy asm keeps the conversion) */
struct MsgS_177380 { CMSG_HEADER; signed char s24; };
struct MsgI_177380 { CMSG_HEADER; int v; };
struct Player_177380 {
    char pad0[0x14];
    unsigned char active;   /* 0x14 */
    char pad15[0x30 - 0x15];
    void* owner;            /* 0x30 */
    char pad34[0x50 - 0x34];
    char input[0x110];      /* 0x50 */
    unsigned char b160;     /* 0x160 */
    char pad161[0x17C - 0x161];
    unsigned char b17C;     /* 0x17C */
    char pad17D[0x180 - 0x17D];
    int f180;               /* 0x180 */
    int f184;               /* 0x184 */
    unsigned char b188;     /* 0x188 */
    char pad189[0x1B8 - 0x189];
    int f1B8;               /* 0x1B8 */
    unsigned char b1BC;     /* 0x1BC */
};
extern "C" {
extern int g_CasEventMsgClass;
extern int D_004EE698;
extern int D_004F53F0;
extern int g_TeleportMsgClass;
extern int D_0055D4D8;
extern int D_004F53F8;
extern int D_004A0318;
extern int D_00588038;
extern char D_004D9360[];
extern char D_004D9DA0[];
extern char D_004DAF10[];
extern char D_004DFD80[];
int* Event_GetType(void* m);
unsigned char Event_Send(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
unsigned char PlayerComp_HandleMessage(Player_177380* self, void* m);
unsigned char Receiver_HandleEventBase(Player_177380* self, void* m);
void InputState_EnterCrouchZone(void* in, void* owner);
void InputState_LeaveCrouchZone(void* in, void* owner);
void InputState_EnterJumpZone(void* in, int kind, int* id);
void InputState_LeaveJumpZone(void* in);
void* Object_LookupById(int* id);
int PlayerInput_IsPickupMenuForZone(void* in, void* zone);
void PlayerInput_ClosePickupMenu(void* in);
void cGOBJTriggerEventMsg_ctor(void* m, int a, int b, void* c, int d);
unsigned char Player_DispatchMessage(Player_177380* self, Msg_177380* m);
}

unsigned char Player_DispatchMessage(Player_177380* self, Msg_177380* m)
{
    int jid;
    int oid;
    TrigMsg_177380 trig;
    TMsg_177380 m1;
    TMsg_177380 m2;
    int t;
    int sub;
    t = *Event_GetType(m);
    if (t == g_CasEventMsgClass)
        return PlayerComp_HandleMessage(self, m);
    t = *Event_GetType(m);
    if (t == D_004EE698) {
        sub = m->sub;
        switch (sub) {
        case 8:
        case 10:
        case 11:
        case 12:
        case 14:
        case 17:
            break;
        case 9:
            switch (m->b24) {
            case 0:
                InputState_EnterCrouchZone(self->input, self->owner);
                break;
            case 2:
                InputState_LeaveCrouchZone(self->input, self->owner);
                break;
            }
            break;
        case 15:
        case 16:
            switch (m->b24) {
            case 0:
                jid = m->id;
                { int* pj = &jid; bool b = sub == 16; InputState_EnterJumpZone(self->input, b ? 2 : 1, pj); }
                break;
            case 2:
                InputState_LeaveJumpZone(self->input);
                break;
            }
            break;
        case 18: {
            void* o;
            oid = m->id;
            o = Object_LookupById(&oid);
            if (o) {
                /* retail reads the word and masks it (lw + andi 0xff) */
                int k = ((MsgI_177380*)m)->v;
                k &= 0xFF;
                if (k == 2) {
                    if (PlayerInput_IsPickupMenuForZone(self->input, o))
                        PlayerInput_ClosePickupMenu(self->input);
                } else if (k == 0) {
                    if (self->active) {
                        self->b17C = 0;
                        self->b1BC = 1;
                        { void* ow = self->owner; cGOBJTriggerEventMsg_ctor(&trig, 4, m->id, ow, 0); }
                        trig.kind = 1;
                        Event_Send(&trig, o, 1);
                        trig.vtable = D_004DAF10;
                        cMessage_dtor(&trig, 0);
                    }
                }
            }
            break;
        }
        case 13:
            if ((unsigned char)((MsgS_177380*)m)->s24 == 0)
                self->f184++;
            else if ((unsigned char)((MsgS_177380*)m)->s24 == 2)
                self->f184--;
            break;
        }
        return 0;
    }
    t = *Event_GetType(m);
    if (t == D_004F53F0) {
        self->b160 = !self->b160;
        return 1;
    }
    t = *Event_GetType(m);
    if (t == g_TeleportMsgClass) {
        void* tg = self->owner;
        if (tg) {
            unsigned char r;
            {
                TMsg_177380* p = &m1;
                TMsg_177380* s = (TMsg_177380*)m;
                __int128 qa;
                __int128 qb;
                p->vtable = D_004DFD80;
                p->type = s->type;
                p->magic = s->magic;
                p->time = s->time;
                p->unk10 = s->unk10;
                p->target = s->target;
                p->stampKind = s->stampKind;
                p->flags = s->flags;
                p->kind = s->kind;
                p->vtable = D_004D9360;
                p->mode = s->mode;
                /* 64-byte matrix copy as an lq/sq interleave (128-bit GPR moves, not expressible in C) */
                __asm__ volatile(
                "lq %0, 0x0(%3)\n"
                "lq %1, 0x10(%3)\n"
                "sq %0, 0x0(%2)\n"
                "lq %0, 0x20(%3)\n"
                "sq %1, 0x10(%2)\n"
                "lq %1, 0x30(%3)\n"
                "sq %0, 0x20(%2)\n"
                "sq %1, 0x30(%2)"
                : "=&r"(qa), "=&r"(qb) : "r"(&p->mtx), "r"(&s->mtx) : "memory");
            }
            r = Event_Send(&m1, tg, 1);
            m1.vtable = D_004D9360;
            cMessage_dtor(&m1, 0);
            return r;
        }
        return 0;
    }
    t = *Event_GetType(m);
    if (t == D_0055D4D8) {
        void* tg = self->owner;
        if (tg) {
            unsigned char r;
            {
                TMsg_177380* p = &m2;
                TMsg_177380* s = (TMsg_177380*)m;
                __int128 qa;
                __int128 qb;
                p->vtable = D_004DFD80;
                p->type = s->type;
                p->magic = s->magic;
                p->time = s->time;
                p->unk10 = s->unk10;
                p->target = s->target;
                p->stampKind = s->stampKind;
                p->flags = s->flags;
                p->kind = s->kind;
                p->vtable = D_004D9DA0;
                p->mode = s->mode;
                /* 64-byte matrix copy as an lq/sq interleave (128-bit GPR moves, not expressible in C) */
                __asm__ volatile(
                "lq %0, 0x0(%3)\n"
                "lq %1, 0x10(%3)\n"
                "sq %0, 0x0(%2)\n"
                "lq %0, 0x20(%3)\n"
                "sq %1, 0x10(%2)\n"
                "lq %1, 0x30(%3)\n"
                "sq %0, 0x20(%2)\n"
                "sq %1, 0x30(%2)"
                : "=&r"(qa), "=&r"(qb) : "r"(&p->mtx), "r"(&s->mtx) : "memory");
            }
            r = Event_Send(&m2, tg, 1);
            m2.vtable = D_004D9DA0;
            cMessage_dtor(&m2, 0);
            return r;
        }
        return 0;
    }
    t = *Event_GetType(m);
    if (t == D_004F53F8) {
        self->f1B8 = ((MsgI_177380*)m)->v;
        return 1;
    }
    t = *Event_GetType(m);
    if (t == D_004A0318) {
        self->f180 = ((MsgI_177380*)m)->v;
        return 1;
    }
    t = *Event_GetType(m);
    if (t == D_00588038) {
        self->b188 = m->b24;
        return 1;
    }
    return Receiver_HandleEventBase(self, m);
}
