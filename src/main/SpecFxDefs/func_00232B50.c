#include "types.h"
extern void Global_SmokeToronto3(void);
extern void Global_RainTokyo(void);
extern void Global_RainLorelei(void);
extern void Global_SnowBelarus2(void);
extern void Global_FogMyanmar(void);
void func_00232B50(unsigned char weather)
{
    switch (weather) {
    case 0:
        Global_SmokeToronto3();
        break;
    case 1:
        Global_RainTokyo();
        break;
    case 2:
        Global_RainLorelei();
        break;
    case 3:
        Global_SnowBelarus2();
        break;
    case 4:
        Global_FogMyanmar();
        break;
    }
}