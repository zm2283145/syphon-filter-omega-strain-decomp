#include "SFOLobby_Cell_types.h"

extern int D_00497800;
extern int Lobby_GetTime(void);
extern void func_00449A00(LobbyCell* cell);

/* Refresh a stale cell and return its embedded object at +0xE8C. */
void* func_0044A070(LobbyCell* cell)
{
    int last = cell->lastUpdate;
    int elapsed = Lobby_GetTime() - last;
    if (last == 0 || D_00497800 < elapsed)
        func_00449A00(cell);
    return cell->unk0E8C;
}
