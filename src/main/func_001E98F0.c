#include "types.h"
typedef struct { char pad[0x38]; float level; } W_98F0;
typedef struct { int pad0; int id; char pad8[0xE4 - 8]; float depth; char padE8[0x170 - 0xE8]; W_98F0 water; } A_98F0;
int WaterFx_Remove(int, int);
extern float D_004A0438;
extern int D_004FFC34;
/* drop the water effect when the actor is in water deeper than 0.974 */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void ActorPhys_ReleaseWaterEffect(A_98F0* a)
{
    unsigned char r = 0;
    {
        float k = D_004A0438;
        float d = a->depth;
        if (d != D_004A0438) {
            W_98F0* w = (d != k) ? &a->water : 0;
            if (!(w->level <= 0.974f)) r = 1;
        }
    }
    if (r) WaterFx_Remove(D_004FFC34, a->id);
}
#pragma pop
