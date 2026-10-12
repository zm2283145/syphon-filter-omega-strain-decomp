#include "types.h"
typedef struct { char pad[0x7C]; int x7C; } Node_12D0;
typedef struct { char pad[0x4C]; int start; char pad2[0x5C - 0x50]; int val; unsigned char flags; } S_12D0;
extern int NpcPath_NextPatrolNode(int id);
extern Node_12D0* NpcPath_GetNode(int id);
int func_001612D0(S_12D0* self)
{
    int r = self->val;
    if (r < 0 && (self->flags & 1)) {
        int id = self->start;
        while (id >= 0 && r < 0) {
            id = NpcPath_NextPatrolNode(id);
            if (id == self->start)
                break;
            if (id >= 0) {
                int v = NpcPath_GetNode(id)->x7C;
                if (v)
                    r = v;
            }
        }
    }
    return r;
}