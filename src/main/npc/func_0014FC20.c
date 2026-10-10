#include "types.h"

typedef struct { char pad[0x120]; int priority; char pad124[0x13D - 0x124]; char kind; } Obj120;

/* Records a new kind/priority pair unless the current priority is higher. */
void func_0014FC20(Obj120* self, char kind, int priority)
{
    if (priority < self->priority)
        return;
    self->kind = kind;
    self->priority = priority;
}
