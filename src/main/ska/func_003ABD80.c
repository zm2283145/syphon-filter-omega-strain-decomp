#include "types.h"
extern void Event_Send(void* msg, void* target, int flags);
typedef struct { char pad[0x28]; unsigned char kind; char pad29[3]; void* target; unsigned char sent; char pad31[3]; float value; } D6AnimMsg;
void func_003ABD80(D6AnimMsg* m, unsigned char kind, float value)
{
    if (m->target && !m->sent) {
        m->kind = kind;
        m->value = value;
        Event_Send(m, m->target, 1);
    }
    if (kind == 4 || kind == 5) {
        m->sent = 1;
    }
}