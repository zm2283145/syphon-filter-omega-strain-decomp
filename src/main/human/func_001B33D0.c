#include "types.h"
typedef struct { char pad[0x352C]; float t; } O_1B33D0;
const float D_0048A208[2] = { 5.0f, 0.0f };
static const float dat_0048A210[2] = { 0.2f, 0.0f };
float func_001B33D0(O_1B33D0* o)
{
    return 1.0f + ((*(float*)dat_0048A210) - 1.0f) * (o->t / (*(float*)D_0048A208));
}