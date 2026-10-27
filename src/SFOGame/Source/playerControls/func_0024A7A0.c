#include "types.h"
typedef struct { void* vt; char pad[0x1C]; unsigned char x20; int x24; unsigned char x28; char pad2[7]; } Ev24A7A0;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern void cMessage_ctor_cMessageNameR(Ev24A7A0*, void*);
extern void QueueMessage_cMessageR_cSystemP_int(Ev24A7A0*, void*, int);
extern void cMessage_dtor(void*, int);
int cPlayerControls_EnterCrawl(void* self, void* target) {
    Ev24A7A0 ev;
    cMessage_ctor_cMessageNameR(&ev, g_ActorActionMsgClass);
    ev.vt = D_004E0840;
    ev.x24 = 9;
    ev.x20 = 1;
    ev.x28 = 0;
    QueueMessage_cMessageR_cSystemP_int(&ev, target, 1);
    ev.vt = D_004E0840;
    cMessage_dtor(&ev, 0);
    return 1;
}