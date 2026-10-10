#include "types.h"
typedef struct { char pad[0x40]; int v; } Obj40;
/* Returns whether the field at +0x40 is set. */
int func_003AD2F0(Obj40* o) { return !(o->v == 0); }
