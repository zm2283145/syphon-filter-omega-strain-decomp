#include "types.h"
typedef struct { char pad[0x34]; float f34; } A5_Curve;
int Curve_HasRemaining(A5_Curve* c) { return !(c->f34 == 0.0f); }