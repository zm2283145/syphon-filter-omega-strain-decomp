#include "types.h"

/* Clears the word at offset 0x104D4. */
void func_003D4800(char* self)
{
    *(int*)(self + 0x104D4) = 0;
}
