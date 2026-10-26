#include "types.h"
typedef struct { char p0[0x10]; int n; char p14[0xC]; } E327F20;
typedef struct { char p0[0x4C]; int count; E327F20* data; } L327F20;
#pragma opt_strength_reduction off
/* Total number of sub-items over all entries. */
int GuiSlideShow_GetNumSlides(L327F20* l)
{
    int total = 0; int i;
    for (i = 0; i < *(volatile int*)&l->count; i++) {
        int j; int n = l->data[i].n;
        for (j = 0; j < n; j++) total++;
    }
    return total;
}
