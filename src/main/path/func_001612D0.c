#include "types.h"
typedef struct { char pad[0x7C]; int x7C; } Node_12D0;
typedef struct { char pad[0x4C]; int start; char pad2[0x5C - 0x50]; int val; unsigned char flags; } S_12D0;
extern int func_0015D680(int id);
extern Node_12D0* func_0015DDB0(int id);
int func_001612D0(S_12D0* self)
{
    int r = self->val;
    if (r < 0 && (self->flags & 1)) {
        int id = self->start;
        while (id >= 0 && r < 0) {
            id = func_0015D680(id);
            if (id == self->start)
                break;
            if (id >= 0) {
                int v = func_0015DDB0(id)->x7C;
                if (v)
                    r = v;
            }
        }
    }
    return r;
}