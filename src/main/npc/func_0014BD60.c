#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Obj_BD60 {
public:
    VPAD32(a) VPAD32(b)
    virtual unsigned char GetState();
    char pad[0x8];
    int id;
    char pad2[0x48];
    void* x58;
};
typedef struct { char pad[0x78]; int x78; } Src_BD60;
typedef struct { char pad[0x44]; int mode; char pad2[0xF0 - 0x48]; int xF0; int xF4; } NPC_BD60;
extern "C" void func_0016E170(int* mode, int m, int t);
extern "C" int cNPC_v40(NPC_BD60* self, Obj_BD60* o, Src_BD60* src)
{
    unsigned char s = o->GetState();
    unsigned char ok = 1; if ((unsigned)(s - 2) > 1) ok = 0;
    if (ok && o->x58 && self->mode != 8) {
        func_0016E170(&self->mode, 8, 100);
        self->xF0 = src->x78;
        self->xF4 = o->id;
    }
    return 0;
}