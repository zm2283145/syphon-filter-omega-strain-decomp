/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Global_FogMyanmar(void);
extern int Global_RainLorelei(void);
extern int Global_RainTokyo(void);
extern int Global_SmokeToronto3(void);
extern int Global_SnowBelarus2(void);

int Script_SnowBelarus2(void) {
    Global_SnowBelarus2();
    return 0;
}

int Script_RainLorelei(void) {
    Global_RainLorelei();
    return 0;
}

int Script_RainTokyo(void) {
    Global_RainTokyo();
    return 0;
}

int Script_SmokeToronto3(void) {
    Global_SmokeToronto3();
    return 0;
}

int Script_FogMyanmar(void) {
    Global_FogMyanmar();
    return 0;
}
