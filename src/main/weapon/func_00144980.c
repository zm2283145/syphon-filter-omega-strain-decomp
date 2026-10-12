#include "types.h"
typedef struct { char pad[0x1C]; unsigned char flag; } F44980;
extern unsigned char D_00535D62;
void Light_Disable(F44980* p)
{
    if (p->flag) {
        p->flag = 0;
        D_00535D62 = 1;
    }
}