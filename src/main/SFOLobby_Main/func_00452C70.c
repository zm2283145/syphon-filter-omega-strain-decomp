#include "SFOLobby_Main_types.h"

extern void func_0044CA30(void);
extern void func_004689B0(void);
extern void func_002E9648(void);

/* Run the requested cleanup operations and clear the lobby's pending field. */
int func_00452C70(LobbyMain* self, int notify)
{
    if (self->unk180 > 0)
        func_0044CA30();
    if (notify) {
        func_004689B0();
        func_002E9648();
    }
    self->unk1EA8 = 0;
    return 1;
}
