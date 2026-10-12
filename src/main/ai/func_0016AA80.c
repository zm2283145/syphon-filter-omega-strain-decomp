#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern void* D_004EE620;
extern unsigned char D_004EE628;
extern signed char D_0048A100;
extern unsigned char D_005723C8;
extern char D_0049C650[];
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void TeamRelations_Teardown(void)
{
    void* p = D_004EE620;
    if (p && !D_004EE628) {
        AllocGuard g;
        Mem_Free(0, p, D_0049C650, 0x6FE);
    }
    D_004EE620 = 0;
    D_004EE628 = 0;
    D_0048A100 = 1;
}