#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { int kind; int id; short len; short idx; unsigned char data[1]; } Pk2822F0;
typedef void (*Fn2822F0)(void*);
typedef struct { int a; int b; Fn2822F0* data; } Vec2822F0;
extern "C" {
extern unsigned char D_005721D0;
extern int D_005061D8;
extern unsigned char* D_005061D0;
void** NetMap_Lookup(int);
Vec2822F0* func_00282550(void);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_002822F0(int a0, int a1, int a2, Pk2822F0* arg) {
    NetRecvGuard g;
    Pk2822F0* p = arg;
    if (D_005721D0) {
        void** e = NetMap_Lookup(p->id);
        void* obj;
        short idx;
        obj = 0; if (e) obj = *e;
        idx = p->idx;
        if (idx < D_005061D8 && idx >= 0) {
            Fn2822F0 fn = func_00282550()->data[(short)idx];
            unsigned char* save = D_005061D0;
            D_005061D0 = p->data;
            fn(obj);
            D_005061D0 = save;
        }
    }
    return p->len + 0xC;
}
#pragma pop
