#include "types.h"
extern void* D_004FFC04;
extern void func_002CBD40(void* p);
void func_002CC200(int mode)
{
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_002CBD40(D_004FFC04);
        break;
    }
}