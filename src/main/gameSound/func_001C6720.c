#include "types.h"

typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];   /* 0x048 */
    char partB[0xAC];   /* 0x0E4 */
} SoundRequest; /* size 0x190 */

typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x74];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
} SoundMsg; /* size 0x1C0 */

extern char D_004FFB50[];
extern char D_004DAE10[];
extern void SoundRequest_Ctor(SoundRequest* req, int kind, int a, int b, int c);
extern void SoundMsg_WrapAction(SoundMsg* msg, SoundRequest* req);
extern void Event_Send(SoundMsg* msg, void* target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(SoundMsg* msg, int flags);

/* Builds a quip sound request and broadcasts it as a sound message. */
void Global_PlayQuip(int a, int b, int c) {
    SoundMsg msg;
    SoundRequest req;
    SoundRequest_Ctor(&req, 4, a, b, c);
    SoundMsg_WrapAction(&msg, &req);
    Event_Send(&msg, D_004FFB50, 0);
    msg.vtbl = D_004DAE10;
    func_0036E220(msg.partB, -1);
    func_0036E220(msg.partA, -1);
    cMessage_dtor(&msg, 0);
    func_0036E220(req.partB, -1);
    func_0036E220(req.partA, -1);
}
