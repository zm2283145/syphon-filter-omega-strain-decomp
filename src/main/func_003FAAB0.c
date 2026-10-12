#include "types.h"
#include "net_local_id.h"
typedef struct { int busy; int addr; int slot; } Join_AAB0;
extern char D_00493A10[];
extern char D_00572418[];
extern char D_0055C7C0[];
extern char D_0055C7D0[];
extern char D_0055C7D4[];
extern unsigned char D_005724B0;
void func_00127358(void* fmt, int a, int b);
int func_002EB9A8(void* slot, int addr, int idx);
void Net_OnRemoteClientJoined(Join_AAB0* j)
{
    if (j->busy == 0) {
        int s;
        int off;
        func_00127358("\n\n\n\tRemote client joined the game: %d[%d]\n", j->addr, j->slot);
        {
            int ok = 1;
            if (D_005721C8) ok = D_005721C0;
            if (ok) D_005724B0 = 10; else if (D_005724B0 == 9) D_005724B0 = 10; else D_005724B0 = 9;
        }
        D_00493A10[j->slot] = 0;
        s = j->slot;
        s = s < NetLocalId() ? s : s - 1;
        D_00572418[j->slot] = 0;
        off = s * 0x98;
        if (func_002EB9A8(D_0055C7C0 + off, j->addr, j->slot) == 0) {
            *(unsigned char*)(D_0055C7D4 + off) = 1;
            *(int*)(D_0055C7D0 + off) = j->slot;
        }
    }
}