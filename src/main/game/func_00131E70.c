#include "types.h"
#pragma peephole off
#pragma opt_common_subs off
typedef struct { Vec4 r[3]; Vec4 t; } Mtx;
/* Sets the translation row (+0x30) of a matrix and returns it. */
Mtx* Mtx_SetTranslation(Mtx* m, Vec4* t) { m->t = *t; return m; }
#pragma opt_common_subs reset
#pragma peephole reset
