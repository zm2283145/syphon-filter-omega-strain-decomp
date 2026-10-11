#include "types.h"
typedef struct { void* key; } E0270;
typedef struct { char pad[0x1C]; int count; E0270** items; } T0270;
static inline int IsZ_0270(int v) { return (v != 0) ^ 1; }
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
E0270* func_003E0270(T0270* t, void* key)
{
    int i;
    int n = t->count;
    E0270** items = t->items;
    for (i = 0; !IsZ_0270(((int*)items)[i]) && i < n; i++) {
        if (items[i]->key != key) continue;
        return ((volatile T0270*)t)->items[i];
    }
    return 0;
}
#pragma opt_rotateloops reset
#pragma opt_strength_reduction reset