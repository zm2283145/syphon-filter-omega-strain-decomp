#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node2D7A80;
typedef struct { float x, y, z; } V2D7A80;
typedef struct { void* vt; char p4[0x28]; int f2C; int f30; unsigned char f34; char p35[3]; V2D7A80 v; } Evt2D7A80;
typedef struct { int kind; int id; int f8; int fC; unsigned char b10; char p11[3]; V2D7A80 v; } Arg2D7A80;
extern "C" {
extern void cMessage_ctor5(Evt2D7A80* e, void* type, Arg2D7A80* a);
extern void MsgQueue_QueueClone(Evt2D7A80* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt2D7A80* e, int f);
extern char D_0055C7A0[];
extern void func_001BB080(Node2D7A80** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node2D7A80** out, void* in);
extern char D_004DE510[];
extern char D_0051F0C0[];
extern unsigned char D_005721D0;
}
static inline int Eq2D7A80(Node2D7A80* a, Node2D7A80* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int func_002D7A80(int a0, int a1, int a2, Arg2D7A80* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt2D7A80 e;
        int k[1];
        Node2D7A80* end[1];
        Node2D7A80* it[1];
        int tmp[1];
        Node2D7A80* n;
Arg2D7A80* a = arg;
void* m = D_0055C7A0;
Evt2D7A80* p = &e;
        cMessage_ctor5(p, D_0051F0C0, a);
        e.vt = D_004DE510;
        e.v.x = -1.0f;
        e.v.y = -1.0f;
        e.v.z = -1.0f;
        p->f2C = -1;
        p->f30 = -1;
        p->v.x = a->v.x;
        p->v.y = a->v.y;
        p->v.z = a->v.z;
        p->f34 = a->b10;
        p->f2C = a->f8;
        p->f30 = a->fC;
        k[0] = a->id;
        func_001BB080(it, m, k);
        n = it[0];
        func_0021D360(tmp, m);
        func_0021D350(end, tmp);
        if (Eq2D7A80(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DE510;
        cMessage_dtor(&e, 0);
    }
    return 0x20;
}
#pragma pop
