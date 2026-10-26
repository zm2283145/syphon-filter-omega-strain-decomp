#include "types.h"
typedef struct { char pad[0x90]; Vec4 v; } Obj90;
/* Copies the vector at +0x90 out. */
#pragma peephole off
void cXformNode_GetTranslation_ParentRelative(Vec4* out, Obj90* o) { *out = o->v; }
#pragma peephole reset
