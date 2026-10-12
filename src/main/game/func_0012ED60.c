#include "types.h"
unsigned char* Agent_GetSelected(int, int);
int func_002EBAF8(int*, int);
int PlayerSlots_Get(int);
unsigned int D_00494178[2] = { 0xFFFFFFFF, 0x0 };
extern int D_005721A8;
extern unsigned char D_005721C8;
int func_0012ED60(int arg0)
{
    int i;
    i = 0;
    do {
        int v;
        int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
        if (D_005721C8) {
            if ((*(int*)D_00494178) == -1) func_002EBAF8(&(*(int*)D_00494178), a);
            v = (*(int*)D_00494178);
        } else v = 0;
        if (i != v && PlayerSlots_Get(i)) {
            unsigned char* p = Agent_GetSelected(arg0, i);
            if (p && p[0xB70] == 0) return 0;
        }
        i++;
    } while (i < 4);
    return 1;
}