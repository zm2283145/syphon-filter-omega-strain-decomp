#include "types.h"
extern unsigned char D_00533880;
extern int D_00533888;
void Alloc_Unlock(int id);
void operator_delete(void* p);
void* func_0012F530(void* self, short flags)
{
    if (self) {
        if (D_00533880)
            Alloc_Unlock(9);
        D_00533888--;
        if (flags > 0)
            operator_delete(self);
    }
    return self;
}