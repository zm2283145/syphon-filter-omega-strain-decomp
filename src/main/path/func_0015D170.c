#include "types.h"
extern char D_004D96C0[];
extern void func_0015D200(void* p, int flag);
extern void Receiver_Destruct(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_D170;
S_D170* func_0015D170(S_D170* self, short flag)
{
    if (self) {
        void* m;
        self->vt = D_004D96C0;
        m = (char*)self + 0x2C;
        if (m)
            func_0015D200(m, 0);
        m = (char*)self + 0x20;
        if (m)
            func_0015D200(m, 0);
        Receiver_Destruct(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}