#include "loose05_types.h"
#include "SFOLobby_Callback_types.h"

extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(void);
extern void LobbyArray_Append(LobbyRecord1C* pool, const LobbyPoolResult* result);

/* Apply a successful result to the configured pool and record completion. */
void func_00448270(int unused0, int unused1, int unused2, const LobbyPoolResult* result)
{
    if (!SFOLobby_NoInstance()) {
        LobbyRecord1C* pool = &D_00585E60->pool70;
        if (pool->elemSize > 0) {
            if (result->status == 0)
                LobbyArray_Append(pool, result);
            if (result->complete == 1)
                D_00585E60->gotReply1F4 = 1;
        }
    }
}
