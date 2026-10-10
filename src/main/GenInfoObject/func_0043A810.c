#include "NetObjectMgr_types.h"

extern void* D_00497578;
extern unsigned char D_00583890;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern int D_00494178;
extern int func_002EB650(NetSessionEntry** entry, void* key);
extern int func_002EBAF8(int* id, int session);
extern int func_002EC460(void* key);

/* Process a pending session request only when its peer ID matches. */
void func_0043A810(void)
{
    NetSessionEntry* entry;
    func_002EB650(&entry, D_00497578);
    if (D_00583890) {
        int session = D_005721A8;
        int peer;
        if (D_005721C8) {
            if (D_00494178 == -1)
                func_002EBAF8(&D_00494178, session);
            peer = D_00494178;
        } else {
            peer = 0;
        }
        if (entry->id == peer)
            func_002EC460(D_00497578);
    }
    D_00583890 = 0;
}
