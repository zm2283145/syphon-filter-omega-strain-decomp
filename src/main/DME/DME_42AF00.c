#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002E9320(char *);                               
int func_002E9480(char *);                               
int func_002E94E0(char *, char *);                        
int func_002EA4F0(char *, char *);                        
int func_002EC168(int, int);                            
extern signed char D_00572418;
extern signed char D_00572419;
extern signed char D_0057241A;
extern signed char D_0057241B;
extern signed char D_005724B0;
extern char func_002CAA70;
extern char sfo_malloc_2CA9B0;

void func_0042AF00(void) {
    int sp40[8];
    int sp20[8];
    int sp10[4];
    int temp_v0;

    D_00572418 = 0;
    D_00572419 = 0;
    D_0057241A = 0;
    D_0057241B = 0;
    temp_v0 = func_002EA4F0(&func_002CAA70, &sfo_malloc_2CA9B0);
    if (temp_v0 == 0) {
        if (temp_v0 == 0) {
            func_002E9480(sp40);
            if (func_002E94E0(sp40, sp20) == 0) {
                func_002E9320(sp10);
                if (func_002EC168(0x6000, 0x6000) == 0) {
                    D_005724B0 = 1;
                }
            } else {
                D_005724B0 = 2;
            }
        } else {
            D_005724B0 = 2;
        }
    }
}
