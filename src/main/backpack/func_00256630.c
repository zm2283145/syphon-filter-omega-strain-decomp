#include "types.h"
typedef struct { int pad[3]; int id; } WRObj;
typedef struct { WRObj* obj; int id; } WeakRefD4;
WeakRefD4* WeakRef_Capture(WeakRefD4* r, WRObj* o)
{
    int def;
    int* p;
    r->id = -1;
    r->obj = o;
    if (o) {
        p = &o->id;
    } else {
        def = -1;
        p = &def;
    }
    r->id = *p;
    return r;
}