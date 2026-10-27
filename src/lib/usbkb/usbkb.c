/*
 * lib/usbkb: 2 files, 00222B78-00222D70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00222B78 */
#include "ee_kernel_types.h"
#include "sif_rpc_types.h"

typedef struct {
    int f0; int f4; int f8; int raw;
    int state; int cnt; int delay; int interval;
    unsigned short last; unsigned short buf[4]; short pad;
    int wr; int rd; int count;
} KbEnt;
typedef struct {
    int max; KbEnt* ents; int led; int mkey; int len;
    char pad[0x9C - 0x14];
    int handler;
} KbCtx;
typedef struct { int max_connect; int now_connect; int info; unsigned char status[0x84]; } KbInfo;

extern KbCtx D_004F5780;
extern SifRpcClientData D_004F5820;
extern KbEnt D_004F5950[];
extern int D_0048AB18;
extern void func_0010FBC0(int);
char D_004A4CC8[] = "libusbkb : bind errr\n";
char D_004A4CE0[] = "libusbkb : CreateSema Error\n";
extern int sceSifBindRpc(SifRpcClientData *, unsigned int, int);
extern int scePrintf(const char *, ...);
extern int sceUsbKbGetInfo(KbInfo *);
extern int sceUsbKbSync(int, int *);
extern int AddIntcHandler(int, int (*)(int), int);
extern int EnableIntc(int);
extern int vblank_e_handler(int);

int sceUsbKbInit(int *max_connect)
{
    KbInfo info;
    SemaParam sp;
    int r;
    unsigned int i;

    func_0010FBC0(0);
    while (1) {
        if (sceSifBindRpc(&D_004F5820, 0x80000211, 0) < 0) {
            scePrintf(D_004A4CC8);
            return -1;
        }
        if (D_004F5820.server != 0) break;
        i = 0x10000;
        do { i--; __asm__ volatile ("nop"); __asm__ volatile ("nop"); __asm__ volatile ("nop"); __asm__ volatile ("nop"); } while (i != -1);
    }
    sp.initCount = 1;
    sp.maxCount = 1;
    D_0048AB18 = CreateSema(&sp);
    if (D_0048AB18 == -1) {
        scePrintf(D_004A4CE0);
        return -1;
    }
    if (sceUsbKbGetInfo(&info) != 0) {
        DeleteSema(D_0048AB18);
        D_0048AB18 = -1;
        return -1;
    }
    sceUsbKbSync(0, &r);
    if (r != 0) {
        DeleteSema(D_0048AB18);
        D_0048AB18 = -1;
        return -1;
    }
    if (info.max_connect <= 0) {
        DeleteSema(D_0048AB18);
        D_0048AB18 = -1;
        return -1;
    }
    if (info.max_connect >= 0x80) {
        DeleteSema(D_0048AB18);
        D_0048AB18 = -1;
        return -1;
    }
    D_004F5780.max = info.max_connect;
    *max_connect = info.max_connect;
    D_004F5780.ents = D_004F5950;
    if (D_004F5780.ents == 0) {
        DeleteSema(D_0048AB18);
        D_0048AB18 = -1;
        return -1;
    }
    for (i = 0; i < info.max_connect; i++) {
        D_004F5780.ents[i].f0 = 1;
        D_004F5780.ents[i].f4 = 1;
                D_004F5780.ents[i].f8 = 1;
        D_004F5780.ents[i].raw = 0;
        D_004F5780.ents[i].state = 0;
        D_004F5780.ents[i].cnt = 0;
        D_004F5780.ents[i].delay = 0;
        D_004F5780.ents[i].interval = 0;
        D_004F5780.ents[i].last = 0;
        D_004F5780.ents[i].wr = 0;
        D_004F5780.ents[i].rd = 0;
        D_004F5780.ents[i].count = 0;
    }
    D_004F5780.len = 0;
    D_004F5780.handler = AddIntcHandler(3, vblank_e_handler, -1);
    if (D_004F5780.handler < 0) {
        DeleteSema(D_0048AB18);
        D_0048AB18 = -1;
        return -1;
    }
    EnableIntc(3);
    return 0;
}
/* merge_units: end func_00222B78 */

/* merge_units: begin func_00222D70 */
extern int DIntr(void);
extern void EIntr(void);
extern int RemoveIntcHandler(int, int);
extern int Alloc_Lock(int);
extern int DeleteSema(int);
extern int D_004F581C;

int sceUsbKbEnd(void)
{
    int err = 0;
    int s = DIntr();
    int r = RemoveIntcHandler(3, D_004F581C);
    if (r == 0) Alloc_Lock(3);
    if (s) EIntr();
    if (r < 0) {
        err = 1;
        scePrintf("libusbkb.a : RemoveIntcHandler() --> error
");
    }
    if (D_0048AB18 != -1) {
        if (DeleteSema(D_0048AB18) < 0) {
            err++;
            scePrintf("libusbkb.a : DeleteSema() --> error
");
        } else {
            D_0048AB18 = -1;
        }
    }
    return err ? -1 : 0;
}
/* merge_units: end func_00222D70 */
