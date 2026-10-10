#include "types.h"

typedef struct Sys3F83 {
    char pad00[0x30];
    void* device;      /* 0x30 */
    char pad34[0x1C];
    int sema50;        /* 0x50 */
    int sema54;        /* 0x54 */
    char part58[4];    /* 0x58 */
} Sys3F83;

extern char D_0055C460[];
extern char D_0055C480[];
extern char D_0055C540[];
extern char D_00571CF0[];
extern int D_0055C530;
extern void func_003F7830(void* device);
extern void func_003F6030(void* obj);
extern void func_0010CFB0(int sema);
extern void func_0010CF70(int sema);
extern void func_0010DD10(int channel);
extern void func_0010CE90(int channel, int handler);
extern void func_00103AC0(int arg);
extern void func_003F5D00(void* obj);
extern void func_003F6EB0(void* obj);
extern void func_003F78F0(void* part);
extern void func_003A6C60(void);
extern void func_00412320(void* obj);

/* Shuts the subsystem down: stops the device, releases semaphores and handlers, clears the DMA flag. */
void func_003F8390(Sys3F83* sys) {
    func_003F7830(sys->device);
    func_003F6030(D_0055C460);
    func_0010CFB0(sys->sema50);
    func_0010CF70(sys->sema50);
    func_0010CFB0(sys->sema54);
    func_0010CF70(sys->sema54);
    func_0010DD10(2);
    func_0010CE90(2, D_0055C530);
    func_00103AC0(0);
    func_003F5D00(D_0055C480);
    func_003F6EB0(D_0055C540);
    func_003F78F0(sys->part58);
    *(volatile unsigned int*)0x1000E000 &= ~2;
    func_003A6C60();
    func_00412320(D_00571CF0);
}
