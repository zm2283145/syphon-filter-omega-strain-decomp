#include "NetObjectMgr_types.h"

extern void* D_00497578;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern int D_00494178;
extern unsigned int D_00583910;
extern int D_005838B8;
extern int D_005838D8;
extern int D_00583900;
extern unsigned char D_005838A0[4];

extern unsigned int func_0042B1A0(int synchronized);
extern int func_002EB650(NetSessionEntry** entry, void* key);
extern int func_002EBAF8(int* id, int session);
extern int func_002EC3C8(void* key);
extern void func_00439390(int peer, void* key, int event);

static inline int current_peer(void)
{
    int session = D_005721A8;
    if (D_005721C8) {
        if (D_00494178 == -1)
            func_002EBAF8(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}

/* Poll pending session changes at 500-tick intervals. */
void func_0043A8B0(void)
{
    if (D_00583910 < func_0042B1A0(1)) {
        if (D_005838B8 || D_005838D8 || D_00583900 ||
            D_005838A0[0] || D_005838A0[1] ||
            D_005838A0[2] || D_005838A0[3]) {
            NetSessionEntry* entry;
            int peer;
            func_002EB650(&entry, D_00497578);
            peer = current_peer();
            if (entry->id != peer) {
                func_002EC3C8(D_00497578);
            } else {
                peer = current_peer();
                func_00439390(peer, D_00497578, -2);
            }
        }
        D_00583910 = func_0042B1A0(1) + 500;
    }
}
