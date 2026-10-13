#include "types.h"
extern unsigned char D_0055C740;
extern volatile int D_0055C210;
extern volatile int D_0055C218;
extern int sceGsSyncV(int);

void func_003F6FA0(int id)
{
    if (!D_0055C740) {
        while (sceGsSyncV(0) == id) {
        }
    }
    D_0055C210 = 1;
    D_0055C218 = 0;
}