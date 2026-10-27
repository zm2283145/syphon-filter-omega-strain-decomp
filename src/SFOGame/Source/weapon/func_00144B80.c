#include "types.h"

extern unsigned char g_LevelLightsDirty;

typedef struct { char pad[0x1C]; unsigned char done; } Obj;

/* Sets the +0x1C flag (and the global flag g_LevelLightsDirty) once. */
void cLightSrc_Activate(Obj* self)
{
    if (!self->done) {
        self->done = 1;
        g_LevelLightsDirty = 1;
    }
}
