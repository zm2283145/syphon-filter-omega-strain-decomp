#include "types.h"
typedef struct { char pad[0xB10]; Vec4 v; } ObjB10;
/* Copies a vector into the object's field at +0xB10. */
#pragma peephole off
void func_0017A600(ObjB10* obj, Vec4* v) { obj->v = *v; }
#pragma peephole reset
