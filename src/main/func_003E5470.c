#include "types.h"
typedef struct { char pad[0xC]; int a; int b; int c; int d; } Hdr;
extern char D_0055A1E8[];
extern int func_002E9A10(void);
extern int func_003FF2C0(void);
extern int func_002E9A98(Hdr* h, void* dst, int size, int count);
extern int func_002E9F08(void* table, void* fn);
extern void func_003E4DA0(void);
/* Reads four header words and registers the handler; returns 1 on success. */
unsigned char func_003E5470(void)
{
    Hdr h;
    unsigned char ok = 0;
    if (func_002E9A10() == 0 && func_003FF2C0() != 0 &&
        func_002E9A98(&h, &h.a, 4, 1) == 0 &&
        func_002E9A98(&h, &h.b, 4, 1) == 0 &&
        func_002E9A98(&h, &h.c, 4, 1) == 0 &&
        func_002E9A98(&h, &h.d, 4, 1) == 0 &&
        func_002E9F08(D_0055A1E8, func_003E4DA0) == 0)
        ok = 1;
    return ok;
}
