#include "types.h"
typedef struct { int unk0; void* p; } S;
/* Returns whether the second field is null. */
int func_001E0F70(S* s) { return s->p == 0; }
