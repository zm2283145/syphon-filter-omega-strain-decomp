#pragma cplusplus on
#include "types.h"
struct E247720 { unsigned char used; char p1[3]; int v; };
struct V247720 { int pad; int count; E247720* data; };
extern "C" void func_00250E70(V247720* v, int n, E247720* fill);
static inline int Used247720(E247720* e) { return e->used != 0; }
#pragma push
#pragma bool off
#pragma opt_strength_reduction off
extern "C" void func_00247720(V247720* v, int idx)
{
    int n;
    int i;
    E247720 f;
    v->data[idx].used = 0;
    n = 0;
    for (i = v->count - 1; i >= 0; i--) { if (Used247720(&v->data[i]) ^ 1) continue; n = i + 1; break; }
    f.used = 1;
    f.v = 0;
    func_00250E70(v, n, &f);
}
#pragma pop
