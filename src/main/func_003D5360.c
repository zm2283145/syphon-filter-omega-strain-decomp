#include "types.h"
typedef struct { char pad[0x104D0]; int v; } BigObj;
/* Clears the word at +0x104D0. */
void Shadow_ResetCasters(BigObj* o) { o->v = 0; }
