#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_003D0DE0();                            
int func_003D11A0(void **, int, int, char *, int);                
extern char D_004BD328;

void func_003D10B0(void ***arg0, int *arg1, void ***arg2, void ***arg3) {
    void **temp_a0;
    void **temp_a2;
    void **temp_v1;
    char * temp_a1;

    temp_a2 = *arg2;
    temp_v1 = *arg3;
    if (temp_a2 == temp_v1) {
        *arg0 = temp_v1;
        return;
    }
    temp_a1 = *temp_v1;
    F_((*temp_a2), 0x4, int) = (int)(F_(temp_a1, 0x4, int));
    *(int *)F_(temp_a1, 0x4, int) = (int)(*temp_a2);
    if (*arg2 != *arg3) {
        do {
            func_003D0DE0((char *)*arg2 + 0x10, -1);
            temp_a0 = *arg2;
            *arg2 = (void **)(F_(temp_a0, 0x4, int));
            if (temp_a0 != NULL) {
                func_003D11A0(temp_a0, 0, 0, &D_004BD328, 100);
            }
            *arg1 -= 1;
        } while (*arg2 != *arg3);
    }
    *arg0 = *arg3;
}
