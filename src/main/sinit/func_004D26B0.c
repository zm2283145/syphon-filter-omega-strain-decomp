#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern int D_004A9260;
extern int D_004A9264;
extern int D_004A9268;
extern int D_004A926C;

void StaticInit_hud_netlobby(void) {
    D_004A9260 = 0x3F27AE14;
    D_004A9264 = 0x3F4DD2F2;
    D_004A9268 = 0x3F6B020C;
    D_004A926C = 0x3F800000;
}
