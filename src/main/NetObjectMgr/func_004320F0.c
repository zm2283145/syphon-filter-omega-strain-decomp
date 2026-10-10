#include "NetObjectMgr_types.h"

extern volatile unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern void func_0042D360(const GobjId* id, int value);

/* Forward a received object update while the network session is active. */
int func_004320F0(int unused0, int unused1, int unused2, const NetObjectUpdate* update)
{
    GobjId staged[2];
    if (!D_005723C8)
        D_005723C8 = 1;
    if (D_005721D0) {
        staged[0].word = update->id.word;
        func_0042D360(staged, update->value);
    }
    D_005723C8 = 0;
    return 16;
}
