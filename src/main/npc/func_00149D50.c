#include "types.h"

extern float D_00489DD0[];

/* cNPC virtual slot 0x50: looks up a float table entry by byte index. */
float cNPC_v50(void* self, unsigned char i)
{
    return D_00489DD0[i];
}
