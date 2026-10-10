#include "types.h"
typedef struct { float x, y, z, w; } V4_e8;
extern V4_e8 D_004ABF60;
extern V4_e8 D_004ABF70;
extern V4_e8 D_004ABF80;
extern V4_e8 D_004ABF90;
void func_004D33D0(void)
{
    D_004ABF60.x = -1.0f; D_004ABF60.y = -1.0f; D_004ABF60.z = 0.0f; D_004ABF60.w = 0.0f;
    D_004ABF70.x = -1.0f; D_004ABF70.y = 1.0f; D_004ABF70.z = 0.0f; D_004ABF70.w = 0.0f;
    D_004ABF80.x = 1.0f; D_004ABF80.y = -1.0f; D_004ABF80.z = 0.0f; D_004ABF80.w = 0.0f;
    D_004ABF90.x = 1.0f; D_004ABF90.y = 1.0f; D_004ABF90.z = 0.0f; D_004ABF90.w = 0.0f;
}