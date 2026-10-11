#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char pad[0xB08]; unsigned int bits[1]; } A2F510;
int Script_cAgentData_UnlockSpecial(ScriptArg* args)
{
    int i = args[1].b;
    A2F510* self = (A2F510*)args[0].p;
    if (i > -1)
        self->bits[i / 32] |= 1 << (i & 31);
    return 0;
}