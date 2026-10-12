#include "types.h"

typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;
typedef struct EffectMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
} EffectMsg;

extern char D_004FFB50[];
extern char D_004F2CC0[];
extern char D_004DAE30[];
extern char* D_0048C148[];
extern int Service_Lookup(void*, void*);
extern void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
extern void EffectMsg_WrapRequest(EffectMsg* msg, SoundRequest* req);
extern void Event_Send(EffectMsg* msg, int target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(EffectMsg* msg, int flags);

void func_002C9AF0(char* self, unsigned char kind) {
    EffectMsg msg;
    SoundRequest req;
    int target;

    if (*(int*)(self + 0x30C) != kind) {
        target = Service_Lookup(D_004FFB50, D_004F2CC0);
        SoundRequest_Ctor(&req, 5, D_0048C148[kind], 0, 0);
        EffectMsg_WrapRequest(&msg, &req);
        func_0036E220(req.partB, -1);
        func_0036E220(req.partA, -1);
        msg.flag = 1;
        Event_Send(&msg, target, 1);
        *(int*)(self + 0x30C) = kind;
        msg.vtbl = D_004DAE30;
        func_0036E220(msg.partB, -1);
        func_0036E220(msg.partA, -1);
        cMessage_dtor(&msg, 0);
    }
}
