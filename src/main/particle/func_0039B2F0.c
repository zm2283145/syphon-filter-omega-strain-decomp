#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int operator_delete(char **);                            
extern char D_004DFAD8;
extern char D_004DFAF0;
extern char D_004DFB50;
extern char D_0053B560;
extern char D_0053B564;

char **func_0039B2F0(char **arg0, long long arg1) {
    int var_a0;
    char *var_v1;

    if (arg0 != NULL) {
        var_a0 = 0;
        *arg0 = &D_004DFAF0;
        var_v1 = &D_0053B560;
loop_2:
        if ((int)(F_(var_v1, 0x4, int)) == (int)(arg0)) {
            F_(&D_0053B564, (var_a0 * 0x10), int) = 0;
        } else {
            var_a0 += 1;
            var_v1 += 0x10;
            if (var_a0 < 4) {
                goto loop_2;
            }
        }
        if (arg0 != NULL) {
            *arg0 = &D_004DFB50;
            if (arg0 != NULL) {
                *arg0 = &D_004DFAD8;
            }
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
