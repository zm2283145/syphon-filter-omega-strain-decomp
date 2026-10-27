#include "types.h"
typedef struct { int first; int last; } R378020;
typedef struct { int count; R378020 r[20]; } G378020;
typedef struct { char p0[0x78]; int map[1]; } O378020;
extern G378020 D_00492F80[5];
/* Builds the index -> group map: -1 for gaps, the group number inside each range. */
void cVU1Man_BuildPageTable(O378020* o)
{
    int k;
int g;
G378020* gp;
int j;
    k = 0;
    for (g = 0, gp = D_00492F80; g < 5; g++, gp++) {
        for (j = 0; j < gp->count; j++) {
            int* fp = &gp->r[j].first;
            if (k != *fp) { do { o->map[k++] = -1; } while (k != *fp); }
            o->map[k++] = g;
        }
    }
}
