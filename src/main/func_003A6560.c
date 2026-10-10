#include "types.h"

extern void LibInit_LoadIrxModule(void* obj, int a, void* b, int c);
extern void sceDbcInit(void);
extern void func_003A8A90(int flag);
extern char D_004BC6C0[], D_004BC6D0[], D_004BC6E0[], D_004BC6F0[], D_004BC700[];

/* Initializes four subsystems in order, then calls func_003A8A90(1). */
void func_003A6560(void) {
    LibInit_LoadIrxModule(D_004BC6C0, 0, 0, 1);
    sceDbcInit();
    LibInit_LoadIrxModule(D_004BC6D0, 0, 0, 1);
    LibInit_LoadIrxModule(D_004BC6E0, 0, 0, 1);
    LibInit_LoadIrxModule(D_004BC6F0, 0x23, D_004BC700, 1);
    func_003A8A90(1);
}
