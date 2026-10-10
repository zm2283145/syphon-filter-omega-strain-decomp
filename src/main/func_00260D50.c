#include "types.h"

extern void* func_003EEB30(void* p);
extern int func_003EF010(void* obj);

/* Resolves an object with func_003EEB30 and returns func_003EF010 of it, or 0 if none. */
int func_00260D50(void* p)
{
    void* obj = func_003EEB30(p);
    if (obj)
        return func_003EF010(obj);
    return 0;
}
