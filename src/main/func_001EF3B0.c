#include "types.h"
extern void func_001EF410(void*, int);
typedef struct { int a[4]; } G6E1E;
void func_001EF3B0(G6E1E* p, int n, int x)
{
    while (n != 0) {
        func_001EF410(p, x);
        n--;
        p++;
    }
}