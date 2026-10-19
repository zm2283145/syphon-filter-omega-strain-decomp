/* lgAudInit: bind the lgaud.irx RPC server, check its version, set up the RPC packet buffer
 * (static for small packets, else from the caller's allocator) and the library semaphore. */
#include "lgaud.h"

typedef struct lgAudSemaParam {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    unsigned int attr;
    unsigned int option;
} lgAudSemaParam;

extern void func_0010FBC0(int mode);
extern int sceSifBindRpc(void* cd, unsigned int id, int mode);
extern void* Libc_Malloc(int size);
extern void Libc_Free(void* p);
extern void* memset(void* d, int c, unsigned int n);
extern int CreateSema(lgAudSemaParam* p);
extern void InvalidDCache(void* start, void* end);
extern int D_00491468[1];
extern void* (*D_00491480[1])(int);
extern char* D_00491488[6];
extern int D_0052AEB8;
extern int D_0052AEC0[16];
extern char D_004B7D40[];
extern char D_004B7D70[];
extern char D_004B7DB8[];
extern char D_004B7DD8[];
extern char D_004B7DF8[];
extern char D_004B7E10[];
extern char D_004B7E38[];
extern char D_004B7E80[];
extern char D_004B7E98[];
extern char D_004B7EC8[];
extern char D_004B7EF0[];

#define PKT ((lgAudRpcPkt*)D_0052AD40)

int lgAudInit(void* (*allocFunc)(int), void (*freeFunc)(void*))
{
    int i;
    int ver;
    int size;
    lgAudSemaParam sp;

    func_0010FBC0(0);
    lgAud_enumHint = (int*)((unsigned int)D_0052AEC0 | 0x20000000);
    *lgAud_enumHint = 0;
    D_0052AEB8 = 0;
    for (;;) {
        i = 0x10000;
        if (sceSifBindRpc(&lgAud_cd, 0x50494C42, 0) < 0) {
            printf(D_004B7DB8);
            printf(D_004B7DD8);
            for (;;)
                ;
        }
        if (lgAud_cd.server != 0)
            break;
        while (i--)
            ;
    }
    PKT->arg = 0;
    if (sceSifCallRpc(&lgAud_cd, 0x10, 0, PKT, 0x20, PKT, 0x30, 0, 0) != 0) {
        printf(D_004B7DF8);
        printf(D_004B7DD8);
        for (;;)
            ;
    }
    if (PKT->arg != 0x01090400) {
        if ((PKT->arg & 0xFFFF0000) != 0x01090000) {
            printf(D_004B7E10);
            ver = PKT->arg;
            printf(D_004B7D40, 1, 9, 4);
            printf(D_004B7D70, ver >> 24, (ver >> 16) & 0xFF, (ver >> 8) & 0xFF);
            printf(D_004B7DD8);
            for (;;)
                ;
        }
        printf(D_004B7E38);
        ver = PKT->arg;
        printf(D_004B7D40, 1, 9, 4);
        printf(D_004B7D70, ver >> 24, (ver >> 16) & 0xFF, (ver >> 8) & 0xFF);
        printf(D_004B7E80);
    }
    if (allocFunc == 0)
        allocFunc = Libc_Malloc;
    if (freeFunc == 0)
        freeFunc = Libc_Free;
    D_00491480[0] = allocFunc;
    lgAud_freeFunc = (void (*)(int))freeFunc;
    if (lgAud_heapBuf != 0 && D_00491468[0] != PKT->u.size) {
        freeFunc((void*)lgAud_heapBuf);
        lgAud_heapBuf = 0;
    }
    if (lgAud_heapBuf == 0) {
        if ((unsigned int)PKT->u.size < 0x171) {
            lgAud_pkt = PKT;
            D_00491468[0] = 0x170;
            lgAud_maxDataSize = 0x140;
        } else {
            size = (PKT->u.size + 0x3F) & ~0x3F;
            size += 0x40;
            lgAud_heapBuf = (int)allocFunc(size);
            if (lgAud_heapBuf == 0) {
                printf(D_004B7E98, size);
                printf(D_004B7DD8);
                for (;;)
                    ;
            }
            lgAud_pkt = (lgAudRpcPkt*)((lgAud_heapBuf + 0x3F) & ~0x3F);
            D_00491468[0] = PKT->u.size;
            lgAud_maxDataSize = PKT->u.size - 0x30;
        }
    }
    if (lgAud_sema == -1) {
        memset(&sp, 0, sizeof(sp));
        sp.init_count = 1;
        sp.max_count = 1;
        sp.option = 0;
        if ((lgAud_sema = CreateSema(&sp)) == -1) {
            printf(D_004B7EC8);
            printf(D_004B7DD8);
            for (;;)
                ;
        }
    }
    InvalidDCache(D_0052AEC0, (char*)D_0052AEC0 + 0x3F);
    PKT->u.size = (int)D_0052AEC0;
    sceSifCallRpc(&lgAud_cd, 0x17, 0, PKT, 0x30, PKT, 0, 0, 0);
    printf(D_004B7EF0, D_00491488[0], lgAud_maxDataSize);
    return 0;
}
