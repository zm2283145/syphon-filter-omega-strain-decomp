#include "types.h"
typedef struct { char pad[0x58]; void* m58; } O9F40;
typedef struct { char pad[0x4E50]; int count; void** groups; } T9F40;
extern int func_003D9C80(void* g, void* o);
extern void Group_RemoveObject(void* g, void* o);
#pragma opt_strength_reduction off
void func_003D9F40(T9F40* self, O9F40* o)
{
    void* sub = o->m58;
    int i;
    for (i = 0; i < self->count; i++) {
        void* g = self->groups[i];
        if (func_003D9C80(g, o) != -1)
            Group_RemoveObject(g, o);
        if (sub && func_003D9C80(g, sub) != -1)
            Group_RemoveObject(g, sub);
    }
}
#pragma opt_strength_reduction reset
