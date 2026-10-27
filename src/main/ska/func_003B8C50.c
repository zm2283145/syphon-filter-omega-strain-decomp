#include "types.h"

/* Free a block under the allocator guard. */
typedef struct { int w[1]; } Guard_3B8C50;
extern char D_004BC4D0[];
extern void cTimerDisable_ctor(Guard_3B8C50* g);
extern void cTimerDisable_dtor(Guard_3B8C50* g, int flag);
extern void cMemMan_Deallocate(int pool, void* p, char* file, int line);

void cAllocator_cSkaSystem_Request_deallocate(void* self, void* p)
{
    if (p) {
        Guard_3B8C50 g;
        cTimerDisable_ctor(&g);
        cMemMan_Deallocate(0, p, D_004BC4D0, 100);
        cTimerDisable_dtor(&g, -1);
    }
}