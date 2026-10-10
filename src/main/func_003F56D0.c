#include "types.h"

typedef struct { long a; long b; long unk10; } Pair64; /* 24 bytes; only a and b are used here */
typedef struct { char pad[8]; long a; long b; } Pair64Out;

extern char D_0055C4C8[];
extern void func_003F45C0(void* src, Pair64* out);

/* Fetches a 24-byte record and copies its first 16 bytes from D_0055C4C8 into out+8; returns 1. */
int func_003F56D0(void* self, Pair64Out* out)
{
    Pair64 tmp;
    func_003F45C0(D_0055C4C8, &tmp);
    out->a = tmp.a;
    out->b = tmp.b;
    return 1;
}
