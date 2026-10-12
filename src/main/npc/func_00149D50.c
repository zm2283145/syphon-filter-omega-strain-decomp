#include "types.h"

const float D_00489DD0[4] = { 0.0f, 0.1f, 0.5f, 0.9f };

/* cNPC virtual slot 0x50: looks up a float table entry by byte index. */
float cNPC_v50(void* self, unsigned char i)
{
    return ((float*)D_00489DD0)[i];
}
