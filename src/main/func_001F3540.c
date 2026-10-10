#include "types.h"

typedef struct { int value; } Temp;
extern void func_001F35E0(Temp* out);
extern void func_001F3580(void* self, Temp* in);

/* Builds a temporary with func_001F35E0 and applies it to self. */
void func_001F3540(void* self)
{
    Temp t;
    func_001F35E0(&t);
    func_001F3580(self, &t);
}
