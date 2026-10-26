#include "types.h"
typedef struct { char p0[0x3584]; char* sub; } Own2D85D0;
typedef struct { void* vt; char p4[0x40]; char* p44; char* p48; Own2D85D0* owner; short h50; } C2D85D0;
extern char D_004DE530[];
extern void Component_BaseInit(C2D85D0* c);
/* Component constructor: binds the owner and caches its sub-object. */
C2D85D0* cNetPlayer_ctor(C2D85D0* c, char* a, Own2D85D0* owner)
{
    Component_BaseInit(c);
    c->vt = D_004DE530;
    c->p44 = a;
    c->p48 = 0;
    c->owner = owner;
    c->h50 = 0;
    if (c->owner && c->owner->sub) {
        if (!c->p44) c->p44 = c->owner->sub;
        { char* p = c->owner->sub; if (p) p += 0x1C; c->p48 = p; }
    }
    return c;
}
