#include "types.h"
typedef struct { long magic; char pad08[0x10]; unsigned char state; char pad19[3]; void* inner; } Handle_003215C8;
extern void func_0031FC18(void* p);
int func_003215C8(Handle_003215C8* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 11) return 0x17E3;
    func_0031FC18(h->inner);
    return 0;
}
