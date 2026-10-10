#include "types.h"

extern char* D_00585E60;
extern int func_004505C0(int a, int b, int c, void* data);
extern void memcpy(void* dst, void* src, int size); /* memcpy */

/* If func_004505C0 fails, marks the state dirty (+0x198) and copies 0x20 bytes of data to +0x314. */
void func_00447270(int a, int b, int c, void* data) {
    if (!func_004505C0(a, b, c, data)) {
        *(int*)(D_00585E60 + 0x198) = 1;
        memcpy(D_00585E60 + 0x314, data, 0x20);
    }
}
