#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003F6A90(char * arg0) {
    unsigned char temp_v1;

    temp_v1 = F_(arg0, 0x4, unsigned char);
    switch (temp_v1) {                              
    case 4:
    case 2:
        return F_(arg0, 0x50, int) >= F_(arg0, 0x4C, int);
    case 3:
        return (F_(arg0, 0x50, int) >= 0x1000) & 0xFF;
    default:
        return 1;
    }
}
