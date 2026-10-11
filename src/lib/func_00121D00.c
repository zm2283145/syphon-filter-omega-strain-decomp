#include "types.h"
extern void* D_00489738;
extern void func_001261B0(void* r);
extern void func_00126230(void* r);
extern void* func_00121D68(void* reent, unsigned int n, unsigned int elem_size);
void* func_00121D00(unsigned int n, unsigned int size)
{
    void* r;
    func_001261B0(D_00489738);
    r = func_00121D68(D_00489738, n, size);
    func_00126230(D_00489738);
    return r;
}