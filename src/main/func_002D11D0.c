#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { int a; void* b; } Ent2D11D0;
typedef struct { void* vt; char p4[0x74]; } Evt2D11D0;
typedef struct { int kind; int id; } Arg2D11D0;
extern "C" {
extern void cNetGeneratorCreateMsg_ctor(Evt2D11D0* e, Arg2D11D0* a);
extern void MsgQueue_QueueClone(Evt2D11D0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt2D11D0* e, int f);
extern char D_0055C7A0[];
extern void** NetMap_Lookup(int);
extern Ent2D11D0* NetRecvMap_Insert(void* map, int* key);
extern char D_004DE240[];
extern unsigned char D_005721D0;
}
#pragma push
#pragma opt_propagation off
extern "C" int cNetGeneratorCreateMsg_GeneratorCreateCallback(int a0, int a1, int a2, Arg2D11D0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt2D11D0 e;
        int k[1];
        Arg2D11D0* a = arg;
void* m = D_0055C7A0;
        cNetGeneratorCreateMsg_ctor(&e, a);
        if (NetMap_Lookup(a->id)) {
            k[0] = a->id;
            MsgQueue_QueueClone(&e, NetRecvMap_Insert(m, k)->b, 0, 0);
        }
        e.vt = D_004DE240;
        cMessage_dtor(&e, 0);
    }
    return 0x34;
}
#pragma pop
