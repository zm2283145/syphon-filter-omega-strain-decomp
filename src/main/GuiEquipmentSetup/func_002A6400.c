#include "types.h"
typedef struct { char pad[0x3C]; } E2A64;
extern void func_001BECC0(E2A64* e, int a);
void func_002A6400(E2A64* p, int n, int a)
{
    while (n != 0) {
        func_001BECC0(p, a);
        n--;
        p++;
    }
}