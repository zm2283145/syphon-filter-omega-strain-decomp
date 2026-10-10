#include "types.h"

extern void func_001F2EE0(int* out);
extern void func_001F2E70(void* self, int* value);

/* Fetches a value with func_001F2EE0 and passes it to func_001F2E70. */
void func_001F2E30(void* self)
{
    int value;
    func_001F2EE0(&value);
    func_001F2E70(self, &value);
}
