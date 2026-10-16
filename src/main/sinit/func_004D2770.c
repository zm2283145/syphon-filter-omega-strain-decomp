#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern int D_004A9318;
extern int D_004A9320;
extern int D_004A9328;
extern int D_004A9330;

void StaticInit_AimPitchLimits(void) {
    D_004A9318 = 0x3F9C61AA;
    D_004A9320 = 0x3FC49809;
    D_004A9328 = 0xBD84410B;
    D_004A9330 = 0x3E75C28F;
}
