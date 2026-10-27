#include "types.h"

extern float D_00489DD0[];

/* Looks up a float table entry by byte index. */
float cNetNPC_GetTravelSpeed_eTravelSpeed(int unused, unsigned char i) {
    return D_00489DD0[i];
}
