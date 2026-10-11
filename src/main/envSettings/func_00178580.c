#pragma opt_propagation off
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
extern "C" {
extern char D_004D9F10[];
extern char D_004D9240[];
extern char D_004D9280[];
extern char D_00535D20[];
extern unsigned char D_00535D62;
void func_00373D70(void* pool, void* p);
}
class S_8580 {
public:
    int a;
    VPAD8(x) VPAD2(y)
    virtual void Shutdown();
    int id;
};
#define VT(p) (*(void**)((char*)(p) + 4))
#pragma opt_common_subs off
extern "C" S_8580* func_00178580(S_8580* self, short flag)
{
    S_8580* s = self;
    if (s) {
        VT(s) = D_004D9F10;
        if (s) {
            VT(s) = D_004D9240;
            s->id = -1;
            self->Shutdown();
            D_00535D62 = 1;
            if (s)
                VT(s) = D_004D9280;
        }
        if (flag > 0)
            func_00373D70(D_00535D20, s);
    }
    return s;
}
#pragma opt_common_subs reset
