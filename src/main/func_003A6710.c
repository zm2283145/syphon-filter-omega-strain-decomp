#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int LibInit_LoadIrxModule(char *, int, char *, int);          
int func_00114F20(char *);                             
int func_0027C3D0();                                  
int func_002BCA88(int);                                 
int func_003A6390();                                  
extern signed char D_004934A0;
extern unsigned char D_004934A8;
extern unsigned char D_004934B0;
extern unsigned char D_004934B8;
extern unsigned char D_004934C0;
extern char D_004BC670;
extern char D_004BC748;
extern char D_004BC758;
extern char D_004BC768;
extern char D_004BC780;
extern char D_004BC7D8;
extern char D_004BC7E8;
extern char D_004BC800;
extern char D_004BC840;
extern int D_0053BBA0;
extern int D_0053BBA8;

int func_003A6710(int arg0) {
    if (D_004934A8 != 0) {
        if (D_004934B0 != 0) {
            LibInit_LoadIrxModule(&D_004BC748, 0xA, &D_004BC758, 1);
            D_0053BBA0 = LibInit_LoadIrxModule(&D_004BC768, 0x58, &D_004BC780, 1);
            D_0053BBA8 = LibInit_LoadIrxModule(&D_004BC7D8, 0, NULL, 1);
            func_0027C3D0();
            func_002BCA88(1);
            D_004934A0 = 1;
            if (arg0 != 0) {
                LibInit_LoadIrxModule(&D_004BC7E8, 0x31, &D_004BC800, 1);
            } else {
                LibInit_LoadIrxModule(&D_004BC7E8, 0x12, &D_004BC840, 1);
            }
            LibInit_LoadIrxModule("PPP.IRX", 0, NULL, 1);
            LibInit_LoadIrxModule("PPPOE.IRX", 0, NULL, 1);
            D_004934B0 = 0;
        }
        if ((D_004934B8 != 0) && (LibInit_LoadIrxModule("DEV9.IRX", 0, NULL, 0) < 0)) {
            return 0;
        }
        if (func_00114F20(&D_004BC670) < 0) {
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
