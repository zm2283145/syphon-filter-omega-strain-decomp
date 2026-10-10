#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

extern void func_00116848(int arg);

/* Handles command 1 by forwarding its argument to func_00116848; always returns 0. */
int func_0010D938(int cmd, int arg)
{
    if (cmd == 1)
        func_00116848(arg);
    return 0;
}
