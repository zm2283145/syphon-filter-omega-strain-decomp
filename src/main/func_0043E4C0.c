#pragma cplusplus on
#include "types.h"
extern "C" { extern char D_004E1040[]; void func_0043DB80(void* self); void func_0043E550(void* p, int flag); void func_0041F370(void* self, int flag); void operator_delete(void* p); }
typedef struct { void* vt; char pad[0x6C]; char m70[0xC]; int x7C; } S_E4C0;
extern "C" S_E4C0* func_0043E4C0(S_E4C0* self, short flag)
{
    if (self) {
        self->vt = D_004E1040;
        self->x7C = 0;
        func_0043DB80(self);
        {
            void* m = self->m70;
            if (m)
                func_0043E550(m, 0);
        }
        func_0041F370(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}