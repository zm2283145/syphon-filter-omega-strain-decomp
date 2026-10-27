/*
 * main/particle: 5 files, 003A6450-003A65F0
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
#pragma pop /* merge_units */
/* merge_units: end func_003A6460 */

/* merge_units: begin func_003A64F0 */
#pragma push /* merge_units */
extern void LibInit_LoadIrxModule(void* a, int b, void* c, int d);
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
#pragma pop /* merge_units */
/* merge_units: end func_003A64F0 */

/* merge_units: begin func_003A6560 */
#pragma push /* merge_units */
extern void LibInit_LoadIrxModule(void* obj, int a, void* b, int c);
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
extern int LibInitModules(int);
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
#pragma pop /* merge_units */
/* merge_units: end func_003A65F0 */
