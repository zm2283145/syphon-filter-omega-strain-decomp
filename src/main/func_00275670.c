#include "types.h"
typedef struct { char pad[0x115]; unsigned char active; char pad2[0x150 - 0x116]; } G7_E275;
extern G7_E275 D_004FFE60[];
extern void func_00276460(G7_E275* e, float f);
void func_00275670(float f)
{
    int i;
    G7_E275* e = D_004FFE60;
    for (i = 0; i < 50; i++, e++) {
        if (e->active) {
            func_00276460(e, f);
        }
    }
}