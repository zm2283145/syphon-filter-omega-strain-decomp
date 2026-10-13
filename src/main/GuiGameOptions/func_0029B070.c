#include "types.h"
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;
typedef struct SoundEventMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
    char pad1C0[0x10];
} SoundEventMsg;
typedef struct { char pad[0x400]; unsigned char b400; } G_B070;
extern char* D_0048B908;
extern char D_004AA780[];
extern char D_004FFB50[];
extern char D_004DADF0[];
void func_0041EBF0(G_B070*);
void func_0026BD60(void);
int func_003EBA50(void);
void func_003EB750(int);
void func_0036B250(int);
void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
void SoundEvent_Ctor(SoundEventMsg* msg, void* action, int flags);
void Event_Send(void* msg, void* target, int flags);
void func_0036E220(void* part, int flags);
void cMessage_dtor(void* msg, int flags);

void func_0029B070(G_B070* self) {
    SoundEventMsg evm;
    SoundEventMsg evm2;
    SoundRequest req;
    SoundRequest req2;
    func_0041EBF0(self);
    func_0026BD60();
    SoundRequest_Ctor(&req, 4, D_0048B908, 0, 0);
    SoundEvent_Ctor(&evm, &req, 0);
    func_0036E220(req.partB, -1);
    func_0036E220(req.partA, -1);
    evm.flag = 1;
    Event_Send(&evm, D_004FFB50, 1);
    if (!self->b400) {
        SoundRequest_Ctor(&req2, 4, D_004AA780, 0, 0);
        SoundEvent_Ctor(&evm2, &req2, 0);
        func_0036E220(req2.partB, -1);
        func_0036E220(req2.partA, -1);
        evm2.flag = 1;
        Event_Send(&evm2, D_004FFB50, 1);
        func_003EB750(func_003EBA50());
        func_0036B250(1);
        evm2.vtbl = D_004DADF0;
        func_0036E220(evm2.partB, -1);
        func_0036E220(evm2.partA, -1);
        cMessage_dtor(&evm2, 0);
    }
    evm.vtbl = D_004DADF0;
    func_0036E220(evm.partB, -1);
    func_0036E220(evm.partA, -1);
    cMessage_dtor(&evm, 0);
}