typedef struct { int x8; int xC; int x10; int x14; } Sub;
typedef struct { int used; int sock; Sub s; int x18; } SBBBB0;
typedef struct { int x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24; } PBBBB0;
typedef struct { int a; void *b; } LBBBB0;
typedef struct { int gen; int x4; int x8; } E2BB520;
extern SBBBB0 D_00518A08[];
extern PBBBB0 D_00518A40;
extern char D_0051AAC0[];
extern int D_0048C09C;
extern int sceDbcGetConnection(int);
extern void *memset(void *, int, unsigned int);
extern int sceDbcSendData3(int, int, void *, void *, void *);
extern void sceMc2SifCallback(void);
extern E2BB520 *SyncDma(int);
extern void *memcpy(void *, const void *, unsigned int);
extern char D_0051AB40[];
extern int scePrintf(const char *, ...);
extern E2BB520 *SyncDmaForRead(int);
int _sceMcCoreReadPage2(int i, char *buf, int sec, int n, int x)
{
    struct { int a; char *b; } l;
    char *src;
    int k;
    l.b = buf;
    if (sceDbcGetConnection(D_00518A08[i].sock) == 3) return 0;
    D_00518A40.x0 = sec;
    D_00518A40.x4 = n;
    D_00518A40.x8 = D_00518A08[i].s.x8;
    D_00518A40.xC = D_00518A08[i].s.xC;
    D_00518A40.x10 = D_00518A08[i].s.x10;
    D_00518A40.x14 = D_00518A08[i].s.x10 / D_00518A08[i].s.xC - 1;
    D_00518A40.x18 = D_00518A08[i].s.x10 / D_00518A08[i].s.xC - 2;
    D_00518A40.x1C = 0;
    D_00518A40.x20 = 0;
    D_00518A40.x24 = x;
    l.a = 0x2080;
    memset(D_0051AAC0, 0, 0x100);
    D_0048C09C = 1;
    while (sceDbcSendData3(D_00518A08[i].sock, D_0048C09C, &l, &D_00518A40, sceMc2SifCallback) != 1)
        scePrintf("SendDataHoge\n");
    if (SyncDmaForRead(D_00518A08[i].sock)->x8 == 0) return 0;
    src = D_0051AB40;
    buf = l.b;
    for (k = 0; k < n; k++) {
        SyncDCache(src, src + D_00518A40.x8);
        memcpy(buf, src, D_00518A40.x8);
        src += D_00518A40.x8;
        buf += D_00518A40.x8;
    }
    return n;
}


