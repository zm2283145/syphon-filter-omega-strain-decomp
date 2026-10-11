#include "types.h"
#include "net_write_two_words.h"
typedef struct { char pad[0x24]; int a; char pad28[8]; float x, y, z; } TS_1B9900;
extern void func_001B99E0(float f);
void cNetThrowStarMsg_v04(TS_1B9900* self)
{
    NetW2_write32(self->a);
    func_001B99E0(self->x);
    func_001B99E0(self->y);
    func_001B99E0(self->z);
}