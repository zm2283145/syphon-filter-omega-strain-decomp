/*
 * Libs/SFOLib/Source/libinit: 9 files, 003A6450-003A6680
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A6450 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void iSignalSema(void);

void func_003A6450(void) {
    iSignalSema();
}
static inline void merge_flush_func_003A6450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6450 */

/* merge_units: begin func_003A6460 */
#pragma push /* merge_units */
/* Fatal path: reset the IOP, wait until it is back, then hang. */
extern int D_004934C8;
extern void WaitSema(void);
extern void SuspendThread_2(int a);
extern int sceDevctl(const char* path, int mode, int a2, int a3, int t0, int t1);
extern int sceCdPowerOff(int* status);

void SFOPowerOffThread(void)
{
    int status;
    WaitSema();
    SuspendThread_2(D_004934C8);
    while (sceDevctl("dev9x:", 0x4402, 0, 0, 0, 0) < 0)
        ;
    do {
        while (!sceCdPowerOff(&status))
            ;
    } while (status != 0);
    for (;;)
        ;
}
static inline void merge_flush_func_003A6460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6460 */

/* merge_units: begin func_003A64F0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void LibInit_LoadIrxModule(void* a, int b, void* c, int d);
#endif /* merge_units */
int LibInit_LoadIrxModule(const char* path, int argc, const char* argv, int flag); /* merge_units */
#define LibInit_LoadIrxModule(a0, a1, a2, a3) ((void)LibInit_LoadIrxModule((const char *)(a0), (a1), (const char *)(a2), (a3))) /* merge_units */

extern void sceMc2Init(int a);
extern void sceMc2ChangeThreadPriority(int a);
/* Startup sequence. */
void Iop_LoadMcUsbModules(void)
{
    LibInit_LoadIrxModule("MC2_S1.IRX", 0, 0, 1);
    sceMc2Init(0);
    sceMc2ChangeThreadPriority(1);
    LibInit_LoadIrxModule("USBD.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("USBKB.IRX", 0x10, "keybd=1\0debug=0", 1);
}
#undef LibInit_LoadIrxModule /* merge_units */
static inline void merge_flush_func_003A64F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A64F0 */

/* merge_units: begin func_003A6560 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void LibInit_LoadIrxModule(void* obj, int a, void* b, int c);
#endif /* merge_units */
#define LibInit_LoadIrxModule(a0, a1, a2, a3) ((void)LibInit_LoadIrxModule((const char *)(a0), (a1), (const char *)(a2), (a3))) /* merge_units */

extern void sceDbcInit(void);
extern void snd_StartSoundSystemEx(int flag);
extern const unsigned int D_004BC700[];

/* Initializes four subsystems in order, then calls snd_StartSoundSystemEx(1). */
void Iop_LoadPadSoundModules(void) {
    LibInit_LoadIrxModule("DS2U_S1.IRX", 0, 0, 1);
    sceDbcInit();
    LibInit_LoadIrxModule("LIBSD.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("SDRDRV.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("989NOMID.IRX", 0x23, ((char*)D_004BC700), 1);
    snd_StartSoundSystemEx(1);
}
const unsigned int D_004BC700[10] = { 0x65727473, 0x705F6D61, 0x726F6972, 0x3D797469, 0x72003931, 0x705F6370, 0x726F6972, 0x3D797469, 0x3731, 0x0 };
#undef LibInit_LoadIrxModule /* merge_units */
static inline void merge_flush_func_003A6560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6560 */

/* merge_units: begin func_003A65F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Startup helpers: memory init (mem.cc), library modules, DMA manager setup
 * (dmaman.cc) and overlay loading.
 */

#include "loose03_types.h"

extern char D_00537F80[];       /* DMA manager instance */
extern unsigned char D_0053BBB0;
#if 0 /* merge_units */
extern int LibInitModules(int);
#endif /* merge_units */
void LibInitModules(); /* merge_units */

extern int SFO_RequestOverlay(int);
extern int cMemMan_Init_void(void);
extern int cDmaMan_Init(void* mgr, int a1, int a2, int a3);

int SFOLibInit(int a0) {
    cMemMan_Init_void();
    LibInitModules(a0);
    cDmaMan_Init(D_00537F80, 13312, 1075200, 204800);
    return SFO_RequestOverlay(1);
}

/* Set the byte flag D_0053BBB0 and return its previous value. */
int SFOLibInit_RequestCancel(int value) {
    unsigned char old;

    old = D_0053BBB0;
    D_0053BBB0 = value;
    return old;
}

int SFOLibInit_RequestOverlay(int overlay) {
    return SFO_RequestOverlay(overlay);
}
static inline void merge_flush_func_003A65F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A65F0 */

/* merge_units: begin func_003A6680 */
#pragma push /* merge_units */
/* Load or unload the IRX modules of the sound/pad subsystems. */
extern int LibInit_LoadIrxModule(const char* path, int argc, const char* argv, int flag);
extern void ezNetCnfInit(void);
extern void ezNetCtlInit(void);
extern void ezNetCnfExit(void);
extern void ezNetCtlExit(void);

int SFOLibInit_RequestEzNetConfig(int load)
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
static inline void merge_flush_func_003A6680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6680 */

/* merge_units: begin func_003A6700 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int SFOLibInit_RequestNetworkIRX(void) {
    return 1;
}
static inline void merge_flush_func_003A6700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6700 */

/* merge_units: begin func_003A6710 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int LibInit_LoadIrxModule(char *, int, char *, int);
#endif /* merge_units */
#define LibInit_LoadIrxModule(a0, a1, a2, a3) (LibInit_LoadIrxModule((const char *)(a0), (a1), (const char *)(a2), (a3))) /* merge_units */

          
int sceSifSearchModuleByName(char *);                             
int sceNetcnfifInit();                                  
int sceNetcnfifCreateMc2Thread(int);                                 
int SFOPreparePowerOff();                                  
extern signed char D_004934A0;
extern unsigned char D_004934A8;
extern unsigned char D_004934B0;
extern unsigned char D_004934B8;
extern unsigned char D_004934C0;
extern char D_004BC670;
extern int D_0053BBA0;
extern int D_0053BBA8;

int Iop_LoadNetModules(int arg0) {
    if (D_004934A8 != 0) {
        if (D_004934B0 != 0) {
            LibInit_LoadIrxModule("INET.IRX", 0xA, "mem=100KB", 1);
            D_0053BBA0 = LibInit_LoadIrxModule("NETCNF.IRX", 0x58, "icon=cdrom0:\\GAMEDATA\\NETWORK\\SYS_NET.ICO;1\0iconsys=cdrom0:\\GAMEDATA\\NETWORK\\ICON.SYS;1", 1);
            D_0053BBA8 = LibInit_LoadIrxModule("NETCNFIF.IRX", 0, NULL, 1);
            sceNetcnfifInit();
            sceNetcnfifCreateMc2Thread(1);
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
        SFOPreparePowerOff();
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
#undef LibInit_LoadIrxModule /* merge_units */
static inline void merge_flush_func_003A6710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6710 */

/* merge_units: begin func_003A6940 */
#pragma push /* merge_units */
extern void sceSifInitRpc(int a);
extern int sceCdInit(int mode);
extern int scePrintf(const char* fmt, ...);
extern int sceSifRebootIop(const char* img);
extern int sceSifSyncIop(void);
extern int sceSifInitIopHeap(void);
extern int sceCdGetDiskType(void);
extern int sceCdMmode(int mode);
extern int sceFsReset(void);
extern char D_00493480[];

void LibInitModules(int flash)
{
    sceSifInitRpc(0);
    sceCdInit(0);
    if (flash) {
        scePrintf("\nLibInitModules(): Flashing IOP... (%s)\n\n", D_00493480);
        while (!sceSifRebootIop(D_00493480)) {
        }
        while (!sceSifSyncIop()) {
        }
        sceSifInitRpc(0);
    }
    sceSifInitIopHeap();
    sceCdInit(0);
    switch (sceCdGetDiskType()) {
    case 0xFF:
        scePrintf("Disk Type= IllegalMedia\n");
        break;
    case 0x14:
        scePrintf("Disk Type= PlayStation2 DVD\n");
        sceCdMmode(2);
        break;
    case 0x12:
        scePrintf("Disk Type= PlayStation2 CD\n");
        sceCdMmode(1);
        break;
    default:
        scePrintf("Disk Type= OTHER DISK\n");
        break;
    }
    sceFsReset();
    LibInit_LoadIrxModule("SIO2MAN.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("DBCMAN.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("SIO2D.IRX", 0, 0, 1);
}
static inline void merge_flush_func_003A6940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6940 */
