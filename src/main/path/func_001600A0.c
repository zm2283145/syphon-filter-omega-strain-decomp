#include "types.h"
typedef struct { char pad[0x20]; int* ids; int pad24; int count; } Path_00A0;
typedef struct { char pad[0x48]; int cur; char pad2[0x74 - 0x4C]; Path_00A0* path; } S_00A0;
int func_001600A0(S_00A0* self, int id)
{
    Path_00A0* p = self->path;
    int r = 0;
    int found = -1;
    int i;
    int n = p->count;
    for (i = 0; i < n; i++) {
        if (id == p->ids[i]) {
            found = i;
            break;
        }
    }
    if (found >= 0) {
        int next = self->cur + 1;
        if (found == next)
            r = 1;
        else if (next < found)
            r = 3;
        else
            r = 2;
    }
    return r;
}