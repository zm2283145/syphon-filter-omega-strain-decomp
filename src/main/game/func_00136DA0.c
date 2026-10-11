#include "types.h"
extern unsigned char D_00533880;
extern int D_00533888;
void Alloc_Lock(int id);
void* func_00136DA0(void* self)
{
    if (D_00533880)
        Alloc_Lock(9);
    D_00533888++;
    return self;
}