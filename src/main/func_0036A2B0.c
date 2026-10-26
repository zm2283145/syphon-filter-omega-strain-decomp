#include "types.h"

extern void sceDbcInit(void);
extern void scePad2Init(int a);

typedef struct { int state; int unk4; char pad[0x3B8]; int unk3C0; } Obj;

/* Initialises the controller subsystem and resets state. */
void cJoystick_Init(Obj* self)
{
    sceDbcInit();
    scePad2Init(0);
    self->state = 2;
    self->unk4 = 0;
    self->unk3C0 = -1;
}
