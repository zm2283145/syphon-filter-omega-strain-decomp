#include "types.h"
#pragma optimization_level 1
typedef struct { char d[0x24]; } E_20BEB0;
typedef struct { int a; int n; } V_20BEB0;
extern E_20BEB0** func_0020BF00(V_20BEB0* v);
E_20BEB0* func_0020BEB0(V_20BEB0* v)
{
    return *func_0020BF00(v) + v->n;
}
#pragma optimization_level reset