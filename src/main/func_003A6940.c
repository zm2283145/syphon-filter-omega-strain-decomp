#include "types.h"

extern void D_0010FBC0(int a);
extern int sceCdInit(int mode);
extern int func_0010F388(const char* fmt, ...);
extern int sceSifRebootIop(const char* img);
extern int func_00115798(void);
extern int func_00114368(void);
extern int func_00119AF0(void);
extern int func_00119D90(int mode);
extern int func_00111578(void);
extern int LibInit_LoadIrxModule(const char* path, int argc, const char* argv, int flag);
extern char D_00493480[];

void LibInitModules(int flash)
{
    D_0010FBC0(0);
    sceCdInit(0);
    if (flash) {
        func_0010F388("\nLibInitModules(): Flashing IOP... (%s)\n\n", D_00493480);
        while (!sceSifRebootIop(D_00493480)) {
        }
        while (!func_00115798()) {
        }
        D_0010FBC0(0);
    }
    func_00114368();
    sceCdInit(0);
    switch (func_00119AF0()) {
    case 0xFF:
        func_0010F388("Disk Type= IllegalMedia\n");
        break;
    case 0x14:
        func_0010F388("Disk Type= PlayStation2 DVD\n");
        func_00119D90(2);
        break;
    case 0x12:
        func_0010F388("Disk Type= PlayStation2 CD\n");
        func_00119D90(1);
        break;
    default:
        func_0010F388("Disk Type= OTHER DISK\n");
        break;
    }
    func_00111578();
    LibInit_LoadIrxModule("SIO2MAN.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("DBCMAN.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("SIO2D.IRX", 0, 0, 1);
}

