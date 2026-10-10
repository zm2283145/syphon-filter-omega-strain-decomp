#include "types.h"
extern char D_004BC680[];
extern char D_004BC690[];
extern char D_004BC6A0[];
extern char D_004BC6B0[];
extern void LibInit_LoadIrxModule(void* a, int b, void* c, int d);
extern void func_002B4D08(int a);
extern void func_002B5070(int a);
/* Startup sequence. */
void func_003A64F0(void)
{
    LibInit_LoadIrxModule(D_004BC680, 0, 0, 1);
    func_002B4D08(0);
    func_002B5070(1);
    LibInit_LoadIrxModule(D_004BC690, 0, 0, 1);
    LibInit_LoadIrxModule(D_004BC6A0, 0x10, D_004BC6B0, 1);
}
