#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
extern "C" {
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
int func_0015B060(void* self, int a);
void func_0015B220(void* self, int a, int b);
void func_002EBAF8(int* p, int v);
void func_0042E180(void* ctl, int v);
}
typedef struct { char pad[0xC]; unsigned int flags; } Obj_7940;
class NPC_7940 {
public:
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d)
    virtual Obj_7940* GetBody();
    char pad[0x2C];
    void* ctl;
};
static inline int DefaultBody()
{
    int a = D_005721A8;
    if (D_005721C8) {
        if (D_00494178 == -1)
            func_002EBAF8(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}
extern "C" void func_00157940(NPC_7940* self, int v)
{
    int r = func_0015B060(self, -1);
    if (v >= 0) {
        func_0015B220(self, v, 1);
    } else {
        Obj_7940* o;
        func_0015B220(self, -1, 1);
        o = self->GetBody();
        if (o) {
            v = ((o->flags & 0x7F000000) >> 24) - 1;
        } else {
            v = DefaultBody();
        }
    }
    if (!r)
        func_0042E180(self->ctl, v);
}