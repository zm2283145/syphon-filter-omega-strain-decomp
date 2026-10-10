#include "types.h"
extern void func_003F44E0(void* p, float x);
typedef struct { char pad[0x70]; void* meter; } D6Hud;
void func_00244180(D6Hud* hud, int cur, int max)
{
    if (hud->meter) {
        func_003F44E0(hud->meter, 45.0f * (((float)max - (float)cur) / (float)max));
    }
}