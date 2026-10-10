#include "types.h"

extern char D_0053B540[];
extern void func_00398070(void* list, int value, void* item);

/* Registers the object's +0x60 sub-object in the global list D_0053B540. */
void func_00394720(char* self, int* arg)
{
    func_00398070(D_0053B540, *arg, self + 0x60);
}
