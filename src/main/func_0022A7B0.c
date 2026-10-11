#include "types.h"
extern char D_004DB850[];
extern void func_00177B80(void* p, int flag);
extern void func_00177B80(void* p, int flag);
extern void func_0022A840(void* p, int flag);
extern void Receiver_Destruct(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_D170;
S_D170* func_0022A7B0(S_D170* self, short flag)
{
    if (self) {
        void* m;
        self->vt = D_004DB850;
        m = (char*)self + 0x11C;
        if (m)
            func_00177B80(m, 0);
        m = (char*)self + 0x110;
        if (m)
            func_0022A840(m, 0);
        Receiver_Destruct(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}