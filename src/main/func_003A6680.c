#include "types.h"

/* Load or unload the IRX modules of the sound/pad subsystems. */
extern char D_004BC728[];
extern char D_004BC738[];
extern int LibInit_LoadIrxModule(const char* path, int argc, const char* argv, int flag);
extern void func_0033F508(void);
extern void func_00352CD0(void);
extern void func_0033F608(void);
extern void func_00352DD0(void);

int func_003A6680(int load)
{
    if (load) {
        LibInit_LoadIrxModule(D_004BC728, 0, 0, 1);
        func_0033F508();
        LibInit_LoadIrxModule(D_004BC738, 0, 0, 1);
        func_00352CD0();
    } else {
        func_0033F608();
        func_00352DD0();
    }
    return 1;
}