#include "types.h"

extern void LibInit_LoadIrxModule(void* obj, int a, void* b, int c);
extern void sceDbcInit(void);
extern void func_003A8A90(int flag);
extern const unsigned int D_004BC700[];

/* Initializes four subsystems in order, then calls func_003A8A90(1). */
void func_003A6560(void) {
    LibInit_LoadIrxModule("DS2U_S1.IRX", 0, 0, 1);
    sceDbcInit();
    LibInit_LoadIrxModule("LIBSD.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("SDRDRV.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("989NOMID.IRX", 0x23, ((char*)D_004BC700), 1);
    func_003A8A90(1);
}
const unsigned int D_004BC700[10] = { 0x65727473, 0x705F6D61, 0x726F6972, 0x3D797469, 0x72003931, 0x705F6370, 0x726F6972, 0x3D797469, 0x3731, 0x0 };
