#include "types.h"
typedef struct { int a0; int a4; int id; int ac; } S23E0;
extern void func_00142450(void* self, unsigned char slot, int a, int b, int c);
void func_001423E0(S23E0* self)
{
    int i;
    S23E0* p;
    i = 0;
    p = self;
    do {
        if (p->id != -1)
            func_00142450(self, i, 0, 1, 0);
        i++;
        p++;
    } while (i < 6);
}