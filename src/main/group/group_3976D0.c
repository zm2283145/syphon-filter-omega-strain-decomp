#include "types.h"
typedef struct { int a; } GroupInnerD4;
typedef struct { GroupInnerD4 inner; } GroupD4;
extern void Group_Clear(GroupInnerD4* g, int n);
extern void operator_delete(void*);
GroupD4* Group_Cleanup(GroupD4* g, short flag)
{
    if (g) {
        GroupInnerD4* m = &g->inner;
        if (m) Group_Clear(m, 0);
        if (flag > 0) operator_delete(g);
    }
    return g;
}