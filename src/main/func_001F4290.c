#include "types.h"
extern void func_001F42D0(int* out);
extern void func_001F41C0(void* obj, int* value);
/* Fetch a value with func_001F42D0 and pass it to func_001F41C0. */
void func_001F4290(void* obj)
{
    int value;
    func_001F42D0(&value);
    func_001F41C0(obj, &value);
}
