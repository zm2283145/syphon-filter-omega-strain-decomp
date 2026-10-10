#include "types.h"

extern unsigned char D_00535D62;

typedef struct { char pad[0x1C]; unsigned char done; } Obj;

/* Sets the +0x1C flag (and the global flag D_00535D62) once. */
void func_00144B80(Obj* self)
{
    if (!self->done) {
        self->done = 1;
        D_00535D62 = 1;
    }
}
