#include "types.h"
typedef struct { int unk0; void* p; } S;
/* Returns whether the second field is null. */
int cArray_cCollisionEdgePtr_Empty(S* s) { return s->p == 0; }
