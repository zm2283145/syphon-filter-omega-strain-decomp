#include "types.h"
static const unsigned int dat_0048C2B0[6] = { 0xA, 0x14, 0x23, 0x32, 0x3C, 0x0 };
int func_002C8FD0(int x)
{
 int i;
 for (i = 0; i < 5; i++) { if (x <= ((int*)dat_0048C2B0)[i]) return i + 1; } return 5;
}
