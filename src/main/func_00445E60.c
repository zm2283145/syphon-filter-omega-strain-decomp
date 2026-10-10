#include "types.h"

/* Reads byte +0x2409 when state +0x255C is 3 (result unused). */
typedef struct { char pad00[0x2409]; volatile unsigned char flag; char pad[0x255C - 0x240A]; int state; } Obj_00445E60;
void func_00445E60(Obj_00445E60 *obj) {
    if (obj->state == 3) obj->flag;
}
