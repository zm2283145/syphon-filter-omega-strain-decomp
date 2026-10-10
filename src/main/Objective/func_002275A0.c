#include "types.h"
typedef struct { char p[0x20]; int id; } C1Obj_2275;
typedef struct {
    char p0[0xB0];
    C1Obj_2275* lists[32][32];
    C1Obj_2275* extra[32];
    int counts[32];
    int nExtra;
} C1Man_2275;
C1Obj_2275* ObjMan_GetObjective(C1Man_2275* m, int id)
{
    int i;
    int j;
    int k;
    for (k = 0; k < m->nExtra; k++) {
        if (id == m->extra[k]->id)
            return m->extra[k];
    }
    for (i = 0; i < 32; i++) {
        for (j = 0; j < m->counts[i]; j++) {
            if (id == m->lists[i][j]->id)
                return m->lists[i][j];
        }
    }
    return 0;
}