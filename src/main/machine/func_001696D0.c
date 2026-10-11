#include "types.h"
typedef struct { void* vt; char pad[0x28]; char sub[0x18]; char a44[0x108]; char a14C[0x12D]; char m279[4]; } S_96D0;
extern char D_004D97B0[];
void func_0042B800(void* p, int f);
void func_00138350(void* p, int f);
void __destroy_array(void* arr, void* dtor, int size, int n);
void func_003CAD70(S_96D0* p, int f);
void operator_delete(void* p);
S_96D0* func_001696D0(S_96D0* self, short del)
{
    if (self) {
        self->vt = D_004D97B0;
        func_0042B800(self->m279, -1);
        if (self->sub) {
            __destroy_array(self->a14C, func_00138350, 0xC, 0x14);
            __destroy_array(self->a44, func_00138350, 0xC, 0x16);
        }
        func_003CAD70(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}