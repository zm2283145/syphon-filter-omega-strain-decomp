#include "types.h"
extern int D_004F8354;
extern void** D_004F8358;
extern void cAirTaser_Render(void* p);
#pragma push
#pragma opt_strength_reduction off
void cAirTaser_RenderAll(void)
{
    int i;
    for (i = 0; i < D_004F8354; i++) cAirTaser_Render(D_004F8358[i]);
}
#pragma pop
