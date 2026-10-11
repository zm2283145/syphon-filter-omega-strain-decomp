#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int IdMgr_FindCollision(int, int);                  
extern char D_00571780;

void IdMgr_Allocate(int *arg0, int arg1) {
    int temp_v0;
    int *temp_s2;
    int temp_s1;

    temp_s1 = arg1 & 0xFF;
    temp_s2 = &D_00571780 + (temp_s1 * 4);
    do {
        temp_v0 = *temp_s2 + 1;
        *temp_s2 = temp_v0;
        if (temp_v0 > 0xFFFF) {
            *temp_s2 = 0;
        }
    } while (IdMgr_FindCollision(temp_s1, *temp_s2) != 0);
    *arg0 = *temp_s2 | (temp_s1 << 0x10);
}
