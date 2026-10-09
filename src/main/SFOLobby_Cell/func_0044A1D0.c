/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "SFOLobby_Cell_types.h"

extern int D_00497800; /* refresh interval */
extern int func_00443E70(void); /* current time */
extern void func_00449A00(LobbyCell* cell);

/* Returns byte +0x265C after refreshing the cell if it is stale. */
int func_0044A1D0(LobbyCell* cell) {
    int last = cell->lastUpdate;
    int elapsed = func_00443E70() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(cell);
    }
    return cell->unk265C;
}

/* Returns byte +0x265D after refreshing the cell if it is stale. */
int func_0044A230(LobbyCell* cell) {
    int last = cell->lastUpdate;
    int elapsed = func_00443E70() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(cell);
    }
    return cell->unk265D;
}
