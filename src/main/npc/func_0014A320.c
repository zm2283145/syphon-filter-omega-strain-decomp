#include "types.h"
typedef struct { char pad[0x21]; unsigned char flag : 1; unsigned char rest : 7; } Sub21;
typedef struct { char pad[0x1AC]; Sub21* sub; } Obj1AC;
/* Sets the low flag bit of the sub-object's byte at +0x21. */
void cNPC_v3C(Obj1AC* o) { o->sub->flag = 1; }
