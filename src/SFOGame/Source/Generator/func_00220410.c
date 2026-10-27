#pragma cplusplus on
#include "types.h"
struct O00220410 { char p[0xC]; int id; };
struct H00220410 { O00220410* p; int id; };
static inline O00220410* Get00220410(H00220410* h) {
    bool isNull;
bool ok;
O00220410* t;
    t = h->p;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->id != h->id) ok = false;
    return ok ? t : 0;
}
extern "C" bool cSafePtr_cGOBJ_opEq(H00220410* x, H00220410* y)
{
    O00220410* b = Get00220410(y); return Get00220410(x) == b;
}
