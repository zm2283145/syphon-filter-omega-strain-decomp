#include "types.h"

/* Load or unload the IRX modules of the sound/pad subsystems. */
extern int LibInit_LoadIrxModule(const char* path, int argc, const char* argv, int flag);
extern void ezNetCnfInit(void);
extern void ezNetCtlInit(void);
extern void ezNetCnfExit(void);
extern void ezNetCtlExit(void);

int func_003A6680(int load)
{
    if (load) {
        LibInit_LoadIrxModule("EZNETCNF.IRX", 0, 0, 1);
        ezNetCnfInit();
        LibInit_LoadIrxModule("EZNETCTL.IRX", 0, 0, 1);
        ezNetCtlInit();
    } else {
        ezNetCnfExit();
        ezNetCtlExit();
    }
    return 1;
}