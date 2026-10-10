#include "types.h"

extern char* D_00585E60;
extern int func_004505C0(int a, int b, int c, void* data);
extern void memcpy(void* dst, void* src, int size); /* memcpy */

/* If func_004505C0 fails, marks the state dirty (+0x1C8) and copies 0x148 bytes of data to +0xA88. */
void func_00446DB0(int a, int b, int c, void* data) {
    if (!func_004505C0(a, b, c, data)) {
        *(int*)(D_00585E60 + 0x1C8) = 1;
        memcpy(D_00585E60 + 0xA88, data, 0x148);
    }
}
