#include "types.h"
typedef struct { char b[0x3C]; } E366;
extern void func_001BECC0(E366* d, void* s);
void func_00366E50(E366* d, int n, void* s)
{
    while (n != 0) {
        func_001BECC0(d, s);
        n--;
        d++;
    }
}