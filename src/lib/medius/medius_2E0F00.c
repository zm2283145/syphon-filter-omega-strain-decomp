#include "types.h"
typedef struct { unsigned char b[24]; } B2E0F00;
extern B2E0F00 D_005202E8;
int func_002E0F00(B2E0F00* p)
{
    if (p == 0) return 0x17;
    D_005202E8 = *p;
    return 0;
}