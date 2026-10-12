#include "types.h"
extern unsigned char D_0055D470;
extern int func_00326130(int);
void func_003FE110(int arg) {
    int r = func_00326130(arg);
    if (r >= 0 && r < 7) {
        switch (r) {
        case 1:
            if (arg) D_0055D470 = 1;
            else D_0055D470 = 0;
            break;
        case 2: D_0055D470 = 2; break;
        case 5: D_0055D470 = 3; break;
        case 4: D_0055D470 = 4; break;
        case 3: D_0055D470 = 5; break;
        case 0: D_0055D470 = 6; break;
        }
    } else {
        D_0055D470 = 0;
    }
}