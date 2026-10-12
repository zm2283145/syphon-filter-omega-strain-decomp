#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
extern "C" {
extern unsigned char D_005721D0;
void* Object_LookupById(int*);
void Actor_SetHealth(void*, int, int);
}
typedef struct { char pad[8]; char done; char p1[3]; int id; int arg; } T431A70;
#pragma push
#pragma opt_propagation off
extern "C" int func_00431A70(int a0, int a1, int a2, T431A70* m) {
    NetRecvGuard g;
    if (D_005721D0) {
        T431A70* s = m;
        /* .set reorder barrier keeps the empty then-arm */
        if (m->done) asm { .set reorder }
        else {
            int id = s->id;
            void* o = Object_LookupById(&id);
            if (o) Actor_SetHealth(o, s->arg, 1);
        }
    }
    return 0x14;
}
#pragma pop
