#include "ee_kernel_types.h"
#include "sif_rpc_types.h"

extern int D_0048B238;
extern int D_004FBB80;
extern SifRpcClientData D_004F85C8;
extern SifRpcClientData D_004F85F0;
extern SifRpcClientData D_004F8618;
extern int D_004FBB40[16];
extern char D_004FBAC0[];
extern void D_0010FBC0(int);
extern int sceSifBindRpc(SifRpcClientData*, unsigned int, int);
extern int func_0026A2D0(void);
extern int scePrintf(const char*, ...);
extern void func_0026B1C8(const char*, ...);
extern int sceDbcSetWorkAddr(int);

int sceDbcInit(void)
{
    SemaParam sp;
    int i;
    int ver;

    if (D_0048B238 == 1) return 1;
    D_004FBB80 = 0;
    D_0010FBC0(0);
    for (;;) {
        if (sceSifBindRpc(&D_004F85C8, 0x80001300, 0) < 0) {
            func_0026B1C8("libdbc: bind failed\n");
            return 0;
        }
        if (D_004F85C8.server) break;
        i = 0x10000;
        while (i--) {}
    }
    for (;;) {
        if (sceSifBindRpc(&D_004F85F0, 0x8000131B, 0) < 0) {
            func_0026B1C8("libdbc: bind failed\n");
            return 0;
        }
        if (D_004F85F0.server) break;
        i = 0x10000;
        while (i--) {}
    }
    for (;;) {
        if (sceSifBindRpc(&D_004F8618, 0x8000131C, 0) < 0) {
            func_0026B1C8("libdbc: bind failed\n");
            return 0;
        }
        if (D_004F8618.server) break;
        i = 0x10000;
        while (i--) {}
    }
    ver = func_0026A2D0();
    if ((ver >> 8) != 3) {
        scePrintf("libdbc: Module version mismatch ");
        scePrintf("[libdbc.a = %d.%d, dbcman.irx = %d.%d]\n", 3, 0, ver >> 8, ver & 0xFF);
        return 0;
    }
    sp.initCount = 1;
    sp.maxCount = 0x7F;
    D_004FBB80 = CreateSema(&sp);
    if (D_004FBB80 < 0) return 0;
    for (i = 15; i >= 0; i--) D_004FBB40[i] = 0;
    func_0026B1C8("libdbc: SifDmaAddr %08x\n", D_004FBAC0);
    sceDbcSetWorkAddr((int)D_004FBAC0);
    D_0048B238 = 1;
    return 1;
}
