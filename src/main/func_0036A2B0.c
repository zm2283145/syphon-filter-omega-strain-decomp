#include "types.h"

extern void sceDbcInit(void);
extern void func_0026B1F0(int a);

typedef struct { int state; int unk4; char pad[0x3B8]; int unk3C0; } Obj;

/* Initialises the controller subsystem and resets state. */
void func_0036A2B0(Obj* self)
{
    sceDbcInit();
    func_0026B1F0(0);
    self->state = 2;
    self->unk4 = 0;
    self->unk3C0 = -1;
}
