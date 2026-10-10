#include "types.h"
typedef struct { int unk0; int unk4; } Obj4;
/* Returns whether the field at +4 is zero. */
int func_002B21D0(Obj4* o) { return o->unk4 == 0; }
