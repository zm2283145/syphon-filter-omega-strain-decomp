#include "types.h"
extern char D_00587BF0[];
extern char D_00587C00[];
extern char D_00587C10[];
char* func_003489A0(void* self, int k)
{
    switch (k) {
    case 9:
        return D_00587BF0;
    case 0:
    case 1:
        return D_00587C10;
    default:
        return D_00587C00;
    }
}