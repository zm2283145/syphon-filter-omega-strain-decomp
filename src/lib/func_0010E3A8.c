#include "types.h"
extern int func_0010D590(int cmd, void* arg);
/* Issues request 0x21 with a single-word argument block. */
int func_0010E3A8(int a)
{
    int buf[4];
    buf[0] = a;
    return func_0010D590(0x21, buf);
}
