#include "types.h"
char* Agent_GetSelected(int, int);
int NetGame_InitLocalSlot(int*, int);
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;

void func_0012EE30(int arg0)
{
    int i;
    i = 0;
    do {
        int v;
        int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
        if (D_005721C8) {
            if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a);
            v = D_00494178;
        } else v = 0;
        if (i != v) {
            char* p = Agent_GetSelected(arg0, i);
            if (p) p[0xB70] = 0;
        }
        i++;
    } while (i < 4);
}
