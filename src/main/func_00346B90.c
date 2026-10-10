#include "types.h"
typedef struct { char b[0x3C]; } E346;
typedef struct { int a; int count; E346* data; } H346;
extern void func_001AEF70(E346* e, int flags);
void func_00346B90(H346* h)
{
    E346* begin = h->data;
    E346* e = begin + h->count;
    while (begin < e) {
        e--;
        func_001AEF70(e, -1);
    }
    h->count = 0;
}