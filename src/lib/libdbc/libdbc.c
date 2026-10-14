/*
 * libdbc.c: Sony EE libdbc (dbcman.irx client: controller/device sockets
 * over SIF RPC).  Compiler: EE-GCC 2.9-991111 -O2 -G0.
 */
#include "ee_kernel_types.h"
#include "sif_rpc_types.h"

#define DBC_SERVER       0x80001300
#define DBC_SERVER_SEND2 0x8000131B
#define DBC_SERVER_SEND3 0x8000131C
#define DBC_RPC_SIZE     0x280

/* RPC request/reply layouts in the shared buffer D_004F8640 */
typedef struct { void *f0; void *f4; void *f8; void *fC; void *f10; } DbcHdr;
typedef struct {
    DbcHdr h;
    char name[16];
    int ret;
    int a;
    int b;
} DbcSock;
typedef struct { int x0, x4, x8, xC; unsigned char sdata[0x200]; unsigned char rdata[0x200]; int x410; } DbcSR;
typedef struct { int x0, x4, x8; unsigned char data[0x200]; int x20C; } DbcSD;
typedef struct { int x0, x4, x8; unsigned char data[0x1084]; } DbcSD2;
typedef struct { int x0, x4, x8; unsigned char data[0x2084]; } DbcSD3;
typedef struct { int x0, x4, x8; unsigned char data[0x200]; int x20C; } DbcRD;
/* 64-byte socket state block DMA'd by dbcman.irx */
typedef struct { unsigned char b[64]; } Blk64;

extern int D_0048B238;                  /* initialised flag */
extern SifRpcClientData D_004F85C8;     /* main RPC client */
extern SifRpcClientData D_004F85F0;     /* SendData2 client */
extern SifRpcClientData D_004F8618;     /* SendData3 client */
extern int D_004F8640[];                /* RPC buffer (0x280) */
extern DbcSD2 D_004F88C0;               /* SendData2 buffer */
extern DbcSD3 D_004F99C0;               /* SendData3 buffer */
extern Blk64 D_004FBAC0;                /* socket states (DMA target) */
extern Blk64 D_004FBB40;                /* socket states (copy) */
extern int D_004FBB80;                  /* semaphore id */

extern void func_0010FBC0(int);
extern int func_001161A0(void);         /* DI */
extern int func_001161F8(void);         /* EI */
extern void SyncDCache(void *, void *);
extern int sceSifBindRpc(SifRpcClientData *, unsigned int, int);
extern int sceSifCallRpc(void *cd, unsigned int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int sceSifCheckStatRpc(void *);
extern int scePrintf(const char *, ...);

int func_0026A2D0(void);
int sceDbcSetWorkAddr(int addr);
void func_0026B1C8(const char *fmt, ...);

/* Returns the dbcman.irx module version (major << 8 | minor). */
int func_0026A2D0(void)
{
    sceSifCallRpc(&D_004F85C8, 0x80001363, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0);
    return D_004F8640[0];
}

int sceDbcInit(void)
{
    SemaParam sp;
    int i;
    int ver;

    if (D_0048B238 == 1) return 1;
    D_004FBB80 = 0;
    func_0010FBC0(0);
    for (;;) {
        if (sceSifBindRpc(&D_004F85C8, DBC_SERVER, 0) < 0) {
            func_0026B1C8("libdbc: bind failed\n");
            return 0;
        }
        if (D_004F85C8.server) break;
        i = 0x10000;
        while (i--) {}
    }
    for (;;) {
        if (sceSifBindRpc(&D_004F85F0, DBC_SERVER_SEND2, 0) < 0) {
            func_0026B1C8("libdbc: bind failed\n");
            return 0;
        }
        if (D_004F85F0.server) break;
        i = 0x10000;
        while (i--) {}
    }
    for (;;) {
        if (sceSifBindRpc(&D_004F8618, DBC_SERVER_SEND3, 0) < 0) {
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
    for (i = 15; i >= 0; i--) ((int *)&D_004FBB40)[i] = 0;
    func_0026B1C8("libdbc: SifDmaAddr %08x\n", &D_004FBAC0);
    sceDbcSetWorkAddr((int)&D_004FBAC0);
    D_0048B238 = 1;
    return 1;
}

/* Shutdown: if initialised, clears the flag and deletes the semaphore (if valid); returns 1, else 0. */
int func_0026A568(void)
{
    if (D_0048B238 == 0) return 0;
    D_0048B238 = 0;
    if (D_004FBB80 >= 0) DeleteSema(D_004FBB80);
    return 1;
}

int sceDbcSetWorkAddr(int addr)
{
    D_004F8640[1] = addr;
    if (sceSifCallRpc(&D_004F85C8, 0x80001304, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcSetWorkAddr: rpc error\n");
        return 0;
    }
    return D_004F8640[0];
}

int sceDbcCreateSocket(DbcSock *s, int a, int b)
{
    int i;
    DbcSock *p;
    if (D_0048B238 == 0) return 0;
    p = (DbcSock *)D_004F8640;
    p->h.f0 = s->h.f0;
    p->a = a;
    p->h.f4 = s->h.f4;
    p->b = b;
    p->h.f8 = s->h.f8;
    p->h.fC = s->h.fC;
    p->h.f10 = s->h.f10;
    for (i = 0; i < 16; i++) p->name[i] = s->name[i];
    if (sceSifCallRpc(&D_004F85C8, 0x80001301, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcCreateSocket: rpc error\n");
        return 0;
    }
    return p->ret;
}

int sceDbcDeleteSocket(int a)
{
    if (D_0048B238 == 0) return 0;
    D_004F8640[0] = a;
    if (sceSifCallRpc(&D_004F85C8, 0x80001302, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcDeleteSocket: rpc error\n");
        return 0;
    }
    return D_004F8640[1];
}

int sceDbcGetDepNumber(int sock)
{
    SyncDCache(&D_004FBAC0, (char *)&D_004FBAC0 + 0x80);
    func_001161A0();
    D_004FBB40 = D_004FBAC0;
    func_001161F8();
    if (((int *)&D_004FBB40)[sock] != 1) return -12;
    D_004F8640[0] = sock;
    if (sceSifCallRpc(&D_004F85C8, 0x80001303, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcGetDepNumber: rpc error\n");
        return 0;
    }
    return D_004F8640[1];
}

/* Socket state: 1 if socket `sock` is connected, else 3. */
int func_0026A8C8(int sock)
{
    SyncDCache(&D_004FBAC0, (char *)&D_004FBAC0 + 0x80);
    func_001161A0();
    D_004FBB40 = D_004FBAC0;
    func_001161F8();
    return ((int *)&D_004FBB40)[sock] == 1 ? 1 : 3;
}

int sceDbcInitSocket(int a)
{
    D_004F8640[0] = a;
    if (sceSifCallRpc(&D_004F85C8, 0x80001315, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcInitSocket: rpc error\n");
        return 0;
    }
    return D_004F8640[1];
}

int sceDbcResetSocket(int a)
{
    D_004F8640[0] = a;
    if (sceSifCallRpc(&D_004F85C8, 0x80001316, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcResetSocket: rpc error\n");
        return 0;
    }
    return D_004F8640[1];
}

/* sceDbcGetDeviceStatus (by its message) */
int func_0026AAA0(int a)
{
    D_004F8640[0] = a;
    if (sceSifCallRpc(&D_004F85C8, 0x80001317, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcGetDeviceStatus: rpc error\n");
        return 0;
    }
    return D_004F8640[1];
}

/* RPC 0x1D; reuses the GetDeviceStatus error message. */
int func_0026AB10(int *p)
{
    D_004F8640[2] = 2;
    D_004F8640[4] = p[2];
    D_004F8640[5] = p[3];
    if (sceSifCallRpc(&D_004F85C8, 0x8000131D, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcGetDeviceStatus: rpc error\n");
        return -1;
    }
    return D_004F8640[1];
}

int sceDbcSRData(int a, int b, int *slen, unsigned char *sdata, int *rlen, unsigned char *rdata)
{
    DbcSR *p = (DbcSR *)D_004F8640;
    int i;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *slen;
    p->xC = *rlen;
    for (i = 0; i < *slen; i++) p->sdata[i] = sdata[i];
    if (sceSifCallRpc(&D_004F85C8, 0x80001318, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcSRData: rpc error\n");
        return 0;
    }
    if (p->x410 >= 0) {
        *slen = p->x8;
        *rlen = p->xC;
        for (i = 0; i < p->xC; i++) rdata[i] = p->rdata[i];
    }
    return p->x410;
}

int sceDbcSendData(int a, int b, int *len, unsigned char *in)
{
    DbcSD *p;
    int i;
    WaitSema(D_004FBB80);
    p = (DbcSD *)D_004F8640;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *len;
    for (i = 0; i < *len; i++) p->data[i] = in[i];
    if (sceSifCallRpc(&D_004F85C8, 0x80001319, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcSendData: rpc error\n");
        SignalSema(D_004FBB80);
        return 0;
    }
    if (p->x20C >= 0) *len = p->x8;
    SignalSema(D_004FBB80);
    return p->x20C;
}

int sceDbcSendData2(int a, int b, int *len, unsigned char *in)
{
    DbcSD2 *p;
    int i;
    if (*len > 0x1080) {
        func_0026B1C8("libdbc: SendData2 data length too long [%d]\n", *len);
        return 0;
    }
    WaitSema(D_004FBB80);
    p = &D_004F88C0;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *len;
    for (i = 0; i < *len; i++) p->data[i] = in[i];
    if (sceSifCheckStatRpc(&D_004F85F0) == 1) {
        func_0026B1C8("dbcman : SendData2 BUSY\n");
        SignalSema(D_004FBB80);
        return 0;
    }
    if (sceSifCallRpc(&D_004F85F0, 0x8000131B, 1, &D_004F88C0, 0x1090, &D_004F88C0, 0x1090, 0, 0) < 0) {
        func_0026B1C8("sceDbcSendData2: rpc error\n");
        SignalSema(D_004FBB80);
        return 0;
    }
    SignalSema(D_004FBB80);
    return 1;
}

int sceDbcSendData3(int a, int b, int *len, unsigned char *in, void *endf)
{
    DbcSD3 *p;
    int i;
    if (*len > 0x2080) {
        func_0026B1C8("libdbc: SendData3 data length too long\n");
        return 0;
    }
    WaitSema(D_004FBB80);
    p = &D_004F99C0;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *len;
    for (i = 0; i < *len; i++) p->data[i] = in[i];
    if (sceSifCheckStatRpc(&D_004F8618) == 1) {
        func_0026B1C8("dbcman : SendData3 BUSY\n");
        SignalSema(D_004FBB80);
        return 0;
    }
    if (sceSifCallRpc(&D_004F8618, 0x8000131C, 1, &D_004F99C0, 0x2090, &D_004F99C0, 0x2090, endf, 0) < 0) {
        SignalSema(D_004FBB80);
        return 0;
    }
    SignalSema(D_004FBB80);
    return 1;
}

int sceDbcReceiveData(int a, int b, int *len, unsigned char *out)
{
    DbcRD *p = (DbcRD *)D_004F8640;
    int i;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *len;
    if (sceSifCallRpc(&D_004F85C8, 0x8000131A, 0, D_004F8640, DBC_RPC_SIZE, D_004F8640, DBC_RPC_SIZE, 0, 0) < 0) {
        func_0026B1C8("sceDbcReceiveData: rpc error\n");
        return 0;
    }
    if (p->x20C >= 0) {
        *len = p->x8;
        for (i = 0; i < p->x8; i++) out[i] = p->data[i];
    }
    return p->x20C;
}

/* Debug printf, compiled out in retail. */
void func_0026B1C8(const char *fmt, ...)
{
}
