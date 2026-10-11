#include "types.h"
typedef struct { unsigned char pad[0x2D96]; short v; } Obj_383680;
void func_00383680(Obj_383680* o)
{
    o->v -= 2;
    if (o->v < 0) o->v = 0;
}