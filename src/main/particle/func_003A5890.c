#include "types.h"
#define FLT_MAX 3.4028235e38f
typedef struct { void* vt; char pad[0x88C]; float mn[4]; float mx[4]; } BoundsObj;
extern char D_004DFAA0[];
/* Constructor: sets vtable and empty bounds. */
BoundsObj* func_003A5890(BoundsObj* o)
{
    o->vt = D_004DFAA0;
    o->mn[0] = FLT_MAX; o->mn[1] = FLT_MAX; o->mn[2] = FLT_MAX; o->mn[3] = 1.0f;
    o->mx[0] = -FLT_MAX; o->mx[1] = -FLT_MAX; o->mx[2] = -FLT_MAX; o->mx[3] = 1.0f;
    return o;
}
