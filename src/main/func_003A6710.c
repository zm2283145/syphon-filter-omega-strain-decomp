#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int LibInit_LoadIrxModule(char *, int, char *, int);          
int sceSifSearchModuleByName(char *);                             
int func_0027C3D0();                                  
int func_002BCA88(int);                                 
int func_003A6390();                                  
extern signed char D_004934A0;
extern unsigned char D_004934A8;
extern unsigned char D_004934B0;
extern unsigned char D_004934B8;
extern unsigned char D_004934C0;
extern char D_004BC670;
extern int D_0053BBA0;
extern int D_0053BBA8;

int func_003A6710(int arg0) {
    if (D_004934A8 != 0) {
        if (D_004934B0 != 0) {
            LibInit_LoadIrxModule("INET.IRX", 0xA, "mem=100KB", 1);
            D_0053BBA0 = LibInit_LoadIrxModule("NETCNF.IRX", 0x58, "icon=cdrom0:\\GAMEDATA\\NETWORK\\SYS_NET.ICO;1\0iconsys=cdrom0:\\GAMEDATA\\NETWORK\\ICON.SYS;1", 1);
            D_0053BBA8 = LibInit_LoadIrxModule("NETCNFIF.IRX", 0, NULL, 1);
            func_0027C3D0();
            func_002BCA88(1);
            D_004934A0 = 1;
            if (arg0 != 0) {
                LibInit_LoadIrxModule("INETCTL.IRX", 0x31, "-no_decode\0cdrom0:\\GAMEDATA\\NETWORK\\NET005.CNF;1", 1);
            } else {
                LibInit_LoadIrxModule("INETCTL.IRX", 0x12, "-no_auto\0-verbose", 1);
            }
            LibInit_LoadIrxModule("PPP.IRX", 0, NULL, 1);
            LibInit_LoadIrxModule("PPPOE.IRX", 0, NULL, 1);
            D_004934B0 = 0;
        }
        if ((D_004934B8 != 0) && (LibInit_LoadIrxModule("DEV9.IRX", 0, NULL, 0) < 0)) {
            return 0;
        }
        if (sceSifSearchModuleByName(&D_004BC670) < 0) {
            return 0;
        }
        func_003A6390();
        D_004934B8 = 0;
        if ((D_004934C0 != 0) && (LibInit_LoadIrxModule("SMAP.IRX", 0, NULL, 0) < 0)) {
            return 0;
        }
        D_004934C0 = 0;
        LibInit_LoadIrxModule("LGAUD.IRX", 0, NULL, 1);
        LibInit_LoadIrxModule("MSIFRPC.IRX", 0, NULL, 1);
        LibInit_LoadIrxModule("LIBNETB.IRX", 0, NULL, 1);
        D_004934A8 = 0;
        goto block_19;
    }
block_19:
    return 1;
}
