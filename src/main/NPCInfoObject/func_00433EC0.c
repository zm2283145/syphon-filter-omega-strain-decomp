#include "types.h"
typedef struct { char pad[0xA]; unsigned char vals[4]; } R1Rec_33EC0;
extern R1Rec_33EC0* func_004361C0(int key, int flag);
unsigned char func_00433EC0(void* self, int key, int idx)
{
    R1Rec_33EC0* r = func_004361C0(key, 0);
    if (r && idx >= 0 && idx < 4)
        return r->vals[idx];
    return 0;
}