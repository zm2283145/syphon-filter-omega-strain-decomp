#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Snd_9B70 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsA(); virtual int IsB(); };
struct Obj_9B70 { char pad[0x58]; Snd_9B70* snd; char pad5c[0x31F8 - 0x5C]; float radius; };
union Arg_9B70 { int i; float f; };
extern "C" Obj_9B70* GObj_IdentityB(int);
/* script: set the footstep sound radius (float argument staged via the stack) */
extern "C" int Script_SetFootstepSoundRadius(Arg_9B70* args)
{
    volatile int w[1];
    float r;
    Obj_9B70* g;
    w[0] = args[1].i;
    r = *(volatile float*)w;
    g = GObj_IdentityB(args[0].i);
    if (g->snd && (g->snd->IsA() || g->snd->IsB())) g->radius = r;
    return 0;
}
