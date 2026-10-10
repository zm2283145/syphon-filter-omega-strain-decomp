#include "types.h"
typedef struct { char pad[0x58]; void* other; } Obj58;
/* Returns the linked object at +0x58, or the object itself. */
void* func_00364800(Obj58* p) { if (p->other) return p->other; return p; }
