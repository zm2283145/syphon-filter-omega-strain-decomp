#pragma cplusplus on
#include "types.h"
struct O0022D820 { char p[0xC]; int id; };
struct H0022D820 { O0022D820* p; int id; };
static inline O0022D820* Get0022D820(H0022D820* h) {
    bool isNull;
bool ok;
O0022D820* t;
    t = h->p;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->id != h->id) ok = false;
    return ok ? t : 0;
}
extern "C" bool func_0022D820(void* self, H0022D820* x, H0022D820* y)
{
    O0022D820* b = Get0022D820(y); return Get0022D820(x) == b;
}
