#include "types.h"
extern int func_002071C0(void* obj);
extern int* func_00207260(void* obj);
extern unsigned char func_00207280(void* obj);
/* Return the stored value if present, else a default byte value. */
int func_00207210(void* obj)
{
    if (func_002071C0(obj)) {
        return *func_00207260(obj);
    }
    return func_00207280(obj);
}
