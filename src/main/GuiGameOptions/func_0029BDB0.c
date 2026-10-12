#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int PlayerSlots_Get(int);                             
extern unsigned char D_005721C8;

int func_0029BDB0(void) {
    int var_s1;
    int var_s0;

    if (D_005721C8 == 0) {
        return 1;
    }
    var_s1 = 0;
    var_s0 = 0;
    do {
        if (PlayerSlots_Get(var_s0) != 0) {
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 < 4);
    return var_s1;
}
