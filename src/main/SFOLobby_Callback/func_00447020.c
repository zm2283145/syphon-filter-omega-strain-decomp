#include "types.h"

typedef struct { char pad[0x1FC]; int dirty; char pad2[0x1B3C - 0x200]; char data[0x90]; } Ctx585;
extern Ctx585* D_00585E60;
extern int func_004505C0(int a, int b, int c);
extern void* memcpy(void* dst, const void* src, unsigned int n);

/* Runs func_004505C0; on success marks the context dirty and copies 0x90 bytes from src into it. */
void func_00447020(int a, int b, int c, void* src)
{
    if (func_004505C0(a, b, c) == 0) {
        D_00585E60->dirty = 1;
        memcpy(D_00585E60->data, src, 0x90);
    }
}
