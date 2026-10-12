#include "types.h"
/* volatile keeps the four flag stores in source order */
extern volatile unsigned char D_005723B0;
extern volatile unsigned char D_005721E0;
extern volatile unsigned char D_005721F0;
extern volatile unsigned char D_005724B0;
extern int D_00572470;
extern int D_00572478;
extern char D_004BFA30[];
extern char D_004BF9B8[];
int Net_ConnectGame(void);
int Net_CreateGame(void);
void func_002EBCE0(int* out);
int func_004147A0(void);
void func_0041E0F0(int a, int b, int c, int d, char* msg);

void Net_StartSession(int join)
{
    int ok;
    D_005723B0 = 0;
    D_005721E0 = 0;
    D_005721F0 = 0;
    D_005724B0 = 5;
    if (join) {
        ok = Net_ConnectGame();
        asm { .set reorder } /* barrier: keeps the pad nop before the else label */
    } else {
        ok = Net_CreateGame();
    }
    if (ok == 0) {
        int tmp;
        func_002EBCE0(&tmp);
        return;
    }
    if (func_004147A0()) {
        func_0041E0F0(func_004147A0(), func_004147A0(), 0x1E, 0, join ? D_004BF9B8 : D_004BFA30);
    }
    D_00572470 = 0;
    D_00572478 = 0;
}





