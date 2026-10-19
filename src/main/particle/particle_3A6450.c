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
extern void func_0010D0D0(int a);
extern int func_00113D88(const char* path, int mode, int a2, int a3, int t0, int t1);
extern int func_00119CD8(int* status);

void func_003A6460(void)
{
    int status;
    WaitSema();
    func_0010D0D0(D_004934C8);
    while (func_00113D88("dev9x:", 0x4402, 0, 0, 0, 0) < 0)
        ;
    do {
        while (!func_00119CD8(&status))
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
extern void func_002B4D08(int a);
extern void func_002B5070(int a);
/* Startup sequence. */
void Iop_LoadMcUsbModules(void)
{
    LibInit_LoadIrxModule("MC2_S1.IRX", 0, 0, 1);
    func_002B4D08(0);
    func_002B5070(1);
    LibInit_LoadIrxModule("USBD.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("USBKB.IRX", 0x10, "keybd=1\0debug=0", 1);
}
#pragma pop /* merge_units */
/* merge_units: end func_003A64F0 */

/* merge_units: begin func_003A6560 */
#pragma push /* merge_units */
extern void LibInit_LoadIrxModule(void* obj, int a, void* b, int c);
extern void sceDbcInit(void);
extern void func_003A8A90(int flag);
extern const unsigned int D_004BC700[];

/* Initializes four subsystems in order, then calls func_003A8A90(1). */
void Iop_LoadPadSoundModules(void) {
    LibInit_LoadIrxModule("DS2U_S1.IRX", 0, 0, 1);
    sceDbcInit();
    LibInit_LoadIrxModule("LIBSD.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("SDRDRV.IRX", 0, 0, 1);
    LibInit_LoadIrxModule("989NOMID.IRX", 0x23, ((char*)D_004BC700), 1);
    func_003A8A90(1);
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
extern int Overlay_Load(int);
extern int Mem_Init(void);
extern int func_00375E50(void* mgr, int a1, int a2, int a3);

int func_003A65F0(int a0) {
    Mem_Init();
    LibInitModules(a0);
    func_00375E50(D_00537F80, 13312, 1075200, 204800);
    return Overlay_Load(1);
}

/* Set the byte flag D_0053BBB0 and return its previous value. */
int func_003A6650(int value) {
    unsigned char old;

    old = D_0053BBB0;
    D_0053BBB0 = value;
    return old;
}

int func_003A6670(int overlay) {
    return Overlay_Load(overlay);
}
#pragma pop /* merge_units */
/* merge_units: end func_003A65F0 */
