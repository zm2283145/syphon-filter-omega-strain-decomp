#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Card40E4C0 { char pad[0x5A0]; unsigned char done; };
struct Ctx40E4C0 { Card40E4C0* card; bool busy; char pad[3]; void (*cb)(void); unsigned char cancel; };
extern "C" {
extern char D_004BED38[];
void* Mem_Alloc(int pool, int size, char* file, int line);
Card40E4C0* MemCard_SetupIconSys(void* p);
int func_0040E5D0(Card40E4C0* c);
void func_0040E4C0(Ctx40E4C0* c);
}
static inline void* new40E4C0(void) {
    AllocGuard guard;
    return Mem_Alloc(0, 0x5C0, D_004BED38, 0x2F9);
}
void func_0040E4C0(Ctx40E4C0* c)
{
    Card40E4C0* m = (Card40E4C0*)new40E4C0();
    if (m)
        m = MemCard_SetupIconSys(m);
    c->card = m;
    bool idle;
    do {
        c->busy = func_0040E5D0(c->card) != 0;
        if (!c->busy)
            c->cancel = 0;
        if (c->cb)
            c->cb();
        idle = !c->busy;
    } while (!idle || !c->card->done);
}


