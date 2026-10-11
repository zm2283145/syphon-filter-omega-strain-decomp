#include "types.h"
typedef struct { char pad[0x352C]; float t; } O_1B33D0;
extern float D_0048A208;
extern float D_0048A210;
float func_001B33D0(O_1B33D0* o)
{
    return 1.0f + (D_0048A210 - 1.0f) * (o->t / D_0048A208);
}