#include "types.h"

typedef struct SndReq {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SndReq;

typedef struct SndMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char immediate;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
} __attribute__((aligned(16))) SndMsg;

extern char D_004FFB50[];
extern char D_004DAE10[];
extern char D_004DAE30[];
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern void SoundRequest_Ctor(SndReq* req, signed char kind, int a, int b, int c);
extern void SoundMsg_WrapAction(SndMsg* msg, SndReq* req);
extern void EffectMsg_WrapRequest(SndMsg* msg, SndReq* req);
extern void Event_Send(SndMsg* msg, void* target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(SndMsg* msg, int flags);

static inline int Snd_Allowed(void) { return D_005721C8 ? D_005721C0 : 1; }

void Global_PlaySnd_2(int channel, int a, int b) {
    SndMsg msg1;
    SndMsg msg2;
    SndReq req1;
    SndReq req2;
    if ((signed char)channel == 4) {
        SoundRequest_Ctor(&req1, (signed char)channel, a, b, 0);
        SoundMsg_WrapAction(&msg1, &req1);
        func_0036E220(req1.partB, -1);
        func_0036E220(req1.partA, -1);
        if (!D_005721C8 || !Snd_Allowed()) msg1.immediate = 1;
        Event_Send(&msg1, D_004FFB50, 0);
        msg1.vtbl = D_004DAE10;
        func_0036E220(msg1.partB, -1);
        func_0036E220(msg1.partA, -1);
        cMessage_dtor(&msg1, 0);
    } else {
        SoundRequest_Ctor(&req2, (signed char)channel, a, b, 0);
        EffectMsg_WrapRequest(&msg2, &req2);
        func_0036E220(req2.partB, -1);
        func_0036E220(req2.partA, -1);
        if (!D_005721C8 || !Snd_Allowed()) msg2.immediate = 1;
        Event_Send(&msg2, D_004FFB50, 0);
        msg2.vtbl = D_004DAE30;
        func_0036E220(msg2.partB, -1);
        func_0036E220(msg2.partA, -1);
        cMessage_dtor(&msg2, 0);
    }
}
