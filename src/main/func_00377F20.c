#include "types.h"
typedef struct { int first; unsigned int last; } R377F20;
typedef struct { int count; R377F20 r[20]; } G377F20;
extern G377F20 D_00492F80[5];
extern unsigned int D_00493300[5];

void cVU1Man_BuildAddressTable(int* out)
{
    int k;
int acc;
int g;
G377F20* gp;
int j;
unsigned int* ep;
    k = 0;
    acc = 0;
    for (g = 0, gp = D_00492F80, ep = D_00493300; g < 5; g++, gp++, ep++) {
        G377F20* gq = gp;
        for (j = 0; j < gp->count; j++) {
            int* fp = &gp->r[j].first;
            if (k != *fp) { do { out[k++] = -1; } while (k != *fp); }
            out[k++] = acc;
            if (j < gp->count - 1)
                acc += (gq->r[j + 1].last - fp[1]) >> 3;
            else
                acc += ((unsigned int)*ep - fp[1]) >> 3;
        }
        acc = 0;
    }
}




