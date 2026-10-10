#include "types.h"
typedef struct AcPair { int token; int target; } AcPair;
typedef struct AcHost { unsigned char active; char p1[3]; AcPair pairs[6]; } AcHost;
typedef struct AcMsg { void* vt; char p4[0x20]; int token; char p28[8]; } AcMsg;
extern char D_00542B68[];
extern char D_004DFBD0[];
extern void Event_Construct(void*, void*);
extern void Event_Send(void*, int, int);
extern void cMessage_dtor(void*, int);
static inline int AcPair_Valid(AcPair* p) { return p->target != 0 && ~p->token != 0; }
#pragma opt_common_subs off
void func_003ABC80(AcHost* h, int idx, unsigned char clear)
{
    AcPair* p;
    if (h->active) {
        p = &((AcPair*)((char*)h + 4))[(signed char)idx];
        if (AcPair_Valid(p)) {
            AcMsg msg;
            int tok = p->token;
            Event_Construct(&msg, D_00542B68);
            msg.token = tok;
            msg.vt = D_004DFBD0;
            Event_Send(&msg, p->target, 1);
            msg.vt = D_004DFBD0;
            cMessage_dtor(&msg, 0);
            if ((signed char)idx >= 5) h->active = 0;
            if (clear) { p->token = -1; p->target = 0; }
        }
    }
}