#include "types.h"
typedef struct { char pad[0x28]; int state; } ElevState;
typedef struct { char pad[0x128]; ElevState* st; } ElevGobj;
extern int func_00214160(ElevGobj* self);
extern int func_00213FA0(ElevGobj* self);
int cElevatorGOBJ_GetState(ElevGobj* self)
{
    if (self->st->state == 1)
        return 1;
    if (func_00214160(self) || func_00213FA0(self))
        return 0;
    return 2;
}