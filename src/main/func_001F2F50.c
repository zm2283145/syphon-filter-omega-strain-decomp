#include "types.h"

extern void func_001F2F90(int* out, int a1);
extern void func_001F2E70(void* self, int* value);

/* Fetches a value with func_001F2F90 into a temporary and passes it to func_001F2E70. */
void func_001F2F50(void* self, int a1)
{
    int value;
    func_001F2F90(&value, a1);
    func_001F2E70(self, &value);
}
