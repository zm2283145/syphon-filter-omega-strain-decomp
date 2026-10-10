#include "types.h"
typedef struct { int a[3]; unsigned char c; char pad[3]; } E1C4;
extern void func_001C50A0(E1C4* d, E1C4* s);
void func_001C4E40(E1C4* d, int n, E1C4* s)
{
    while (n != 0) {
        func_001C50A0(d, s);
        d->c = s->c;
        n--;
        d++;
    }
}