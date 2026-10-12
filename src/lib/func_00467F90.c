#include "types.h"
typedef struct { char b[0xC4]; } S_C4;
typedef struct { char b[0xEC]; } S_EC;
extern int D_00497E24;
extern S_C4 D_00587E08;
extern S_EC D_00587ED0;
void func_00467F90(int type, void* data)
{
    D_00497E24 = type;
    switch (type) {
    case 0x2C:
        D_00587E08 = *(S_C4*)data;
        break;
    case 0x12:
        D_00587ED0 = *(S_EC*)data;
        break;
    }
}

