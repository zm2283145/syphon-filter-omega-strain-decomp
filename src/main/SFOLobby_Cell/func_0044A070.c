#include "SFOLobby_Cell_types.h"

extern int D_00497800;
extern int func_00443E70(void);
extern void func_00449A00(LobbyCell* cell);

/* Refresh a stale cell and return its embedded object at +0xE8C. */
void* func_0044A070(LobbyCell* cell)
{
    int last = cell->lastUpdate;
    int elapsed = func_00443E70() - last;
    if (last == 0 || D_00497800 < elapsed)
        func_00449A00(cell);
    return cell->unk0E8C;
}
