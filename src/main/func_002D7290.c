#include "types.h"

typedef struct NetEventMsg {
    void* vtbl;
    char pad04[0x18];
    int size;              /* 0x1C */
    unsigned char len;     /* 0x20 */
    char pad21[0xB];
    unsigned char type;    /* 0x2C */
    char pad2D[3];
    int a;                 /* 0x30 */
    int b;                 /* 0x34 */
    int c;                 /* 0x38 */
    char pad3C[4];
} NetEventMsg;

extern char D_0051F0A8[];
extern char D_004DE4D0[];
extern void Event_Construct(NetEventMsg* msg, void* type);
extern void Event_Send(NetEventMsg* msg, void* target, int flags);
extern void cMessage_dtor(NetEventMsg* msg, int flags);

/* Builds a network event message (type, len, three payload words) and sends it to target. */
void NetEvent_Send(void* target, int type, int len, int a, int b, int c, int flags) {
    NetEventMsg msg;
    Event_Construct(&msg, D_0051F0A8);
    msg.vtbl = D_004DE4D0;
    msg.type = type;
    msg.size = 0x40;
    msg.a = a;
    msg.b = b;
    msg.c = c;
    msg.len = len;
    Event_Send(&msg, target, flags);
    msg.vtbl = D_004DE4D0;
    cMessage_dtor(&msg, 0);
}
