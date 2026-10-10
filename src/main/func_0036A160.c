#include "types.h"

typedef struct {
    char pad[0x100];
    int handle;
    char pad104[0x18];
    float deadzoneX;
    float deadzoneY;
    float scaleX;
    float scaleY;
    char pad12C[0x80];
    int state;
    unsigned char active;
    char pad1B1[0xF];
} Pad;
typedef struct { char pad[4]; int count; char pad8[0x38]; Pad pads[1]; } PadMgr;
typedef struct { int type; int analog; int flags; int reserved[2]; } PadDesc;
extern void func_00369EE0(Pad* pad, int port);
extern int func_0026B298(PadDesc* desc, Pad* pad);

/* Adds a pad to the manager with the given analog dead zone. */
void Pad_Construct(PadMgr* mgr, int analog, int unused, int deadzone)
{
    PadDesc desc;
    Pad* pad = &mgr->pads[mgr->count];
    func_00369EE0(pad, -1);
    pad->deadzoneX = deadzone;
    pad->deadzoneY = deadzone;
    pad->scaleX = 127.5f / (127.5f - pad->deadzoneX);
    pad->scaleY = 127.5f / (127.5f - pad->deadzoneY);
    desc.type = 2;
    desc.analog = analog != 0;
    desc.flags = 0;
    pad->state = 3;
    pad->active = 0;
    pad->handle = func_0026B298(&desc, pad);
    mgr->count++;
}
