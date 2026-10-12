#include "types.h"
typedef struct { void* vt; char pad[0x20]; unsigned char on; char pad25[3]; int target; char pad2C[4]; } Ev_F2D0;
typedef struct { char pad[0x50]; unsigned char pending; char pad51[7]; float timer; } S_F2D0;
extern char D_004EE550[];
extern char D_004D9340[];
extern char g_ScriptAITimeElapsedMsgKey[];
extern char D_004DCC10[];
void Event_Construct(Ev_F2D0* e, void* type);
void Event_Send(Ev_F2D0* e, void* target, int a);
void cMessage_dtor(Ev_F2D0* e, int f);
void cAI_v0E(S_F2D0* self, float dt)
{
    Ev_F2D0 c;
    Ev_F2D0 a;
    Ev_F2D0 b;
    if (self->pending) {
        if (self->pending) {
            Event_Construct(&a, D_004EE550);
            a.vt = D_004D9340;
            a.on = 1;
            a.target = -1;
            Event_Construct(&b, D_004EE550);
            b.on = 0;
            b.vt = D_004D9340;
            b.target = -1;
            self->pending = 0;
            Event_Send(&a, self, 1);
            Event_Send(&b, self, 1);
            b.vt = D_004D9340;
            cMessage_dtor(&b, 0);
            a.vt = D_004D9340;
            cMessage_dtor(&a, 0);
        }
    }
    if (!(self->timer < 0.0f)) {
        self->timer -= dt;
        if (self->timer < 0.0f) {
            Event_Construct(&c, g_ScriptAITimeElapsedMsgKey);
            c.vt = D_004DCC10;
            Event_Send(&c, self, 0);
            c.vt = D_004DCC10;
            cMessage_dtor(&c, 0);
        }
    }
}