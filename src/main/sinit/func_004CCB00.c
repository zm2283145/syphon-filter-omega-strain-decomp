#include "types.h"
extern float g_GameGravity[2];
extern float g_ThrowGravity;
extern float D_004F543C;
void StaticInit_gamePhysics(void) {
    float g = 32.18504f;
    float s = 1.0f;
    g_GameGravity[0] = 0.0f;
    g_GameGravity[1] = 0.0f;
    D_004F543C = 0.0f;
    g_ThrowGravity = -g / s;
}