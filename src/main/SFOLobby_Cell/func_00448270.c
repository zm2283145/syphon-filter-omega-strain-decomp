#include "loose05_types.h"
#include "SFOLobby_Callback_types.h"

extern SFOLobby* D_00585E60;
extern int func_004505C0(void);
extern void func_0044F470(LobbyRecord1C* pool, const LobbyPoolResult* result);

/* Apply a successful result to the configured pool and record completion. */
void func_00448270(int unused0, int unused1, int unused2, const LobbyPoolResult* result)
{
    if (!func_004505C0()) {
        LobbyRecord1C* pool = &D_00585E60->pool70;
        if (pool->unk10 > 0) {
            if (result->status == 0)
                func_0044F470(pool, result);
            if (result->complete == 1)
                D_00585E60->unk1F4 = 1;
        }
    }
}
