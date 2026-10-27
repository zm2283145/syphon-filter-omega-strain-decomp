#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { void cMemMan_Deallocate(int pool, void* p, char* file, int line); extern char D_0049C390[]; void cHudNetLobby_dtor(void* p, int flags); }
struct O_166F20 { char pad[0x27C]; void* m; };
extern "C" void cMachine_DestroyNetworkLobbyScreen(O_166F20* self)
{
    void* m = self->m;
    if (m) {
        {
            AllocGuard g;
            cHudNetLobby_dtor(m, -1);
            cMemMan_Deallocate(0, m, D_0049C390, 0x607);
        }
        self->m = 0;
    }
}