#include "types.h"
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E4557C0;
extern int func_00456160(void* self, E4557C0* e);
extern int func_00423CC0(void* self, E4557C0* e);
int func_004557C0(void* self, E4557C0* e)
{
    int b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x10 && e->a6 == 0;
    if (b) {
        func_00456160(self, e);
        return 1;
    }
    return func_00423CC0(self, e);
}