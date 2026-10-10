#include "types.h"
typedef struct { char pad[0xB8]; int v; } ObjB8;
/* Returns whether the field at +0xB8 is set. */
int func_00362990(ObjB8* o) { return !(o->v == 0); }
