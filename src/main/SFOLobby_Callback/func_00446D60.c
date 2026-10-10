#include "types.h"

extern char* D_00585E60;
extern int func_004505C0(void* a0, void* a1, void* a2);
extern void* memcpy(void* dst, const void* src, int n); /* memcpy */

/* If func_004505C0 succeeds (returns 0), sets the ready flag at +0x1D0 and copies 0x5C bytes of data to +0xFD8. */
void func_00446D60(void* a0, void* a1, void* a2, void* data)
{
    if (func_004505C0(a0, a1, a2) == 0) {
        *(int*)(D_00585E60 + 0x1D0) = 1;
        memcpy(D_00585E60 + 0xFD8, data, 0x5C);
    }
}
