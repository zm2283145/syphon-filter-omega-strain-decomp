#include "types.h"

extern void Dma4_Stop(void* member);
extern void func_0010B208(void* self);

/* Releases the member at +0x48, then the object itself; returns 1. */
int func_003F5D00(char* self) {
    Dma4_Stop(self + 0x48);
    func_0010B208(self);
    return 1;
}
