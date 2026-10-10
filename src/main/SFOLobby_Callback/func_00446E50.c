#include "types.h"
typedef struct { char pad[0x1B0]; int dirty; char pad1B4[0x400 - 0x1B4]; char data[0x1C]; } State00446E50;
extern State00446E50* D_00585E60;
extern int func_004505C0(int a, int b, int c);
extern void memcpy(void* dst, void* src, int size);
/* Unless func_004505C0 handles it, copy 0x1C bytes into the global state and mark it dirty. */
void func_00446E50(int a, int b, int c, void* src)
{
    if (!func_004505C0(a, b, c)) {
        D_00585E60->dirty = 1;
        memcpy(D_00585E60->data, src, 0x1C);
    }
}
