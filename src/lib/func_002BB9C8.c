typedef struct { int x8; int xC; int x10; int x14; } Sub;
typedef struct { int used; int sock; Sub s; int x18; } SBBBB0;
typedef struct { int x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24; } PBBBB0;
typedef struct { int a; Sub *b; } LBBBB0;
typedef struct { int gen; int x4; int x8; unsigned char b[0x74]; } E2BB520;
extern SBBBB0 D_00518A08[];
extern PBBBB0 D_00518A40;
extern char D_0051AAC0[];
extern int D_0048C09C;
extern int sceDbcGetConnection(int);
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern void SyncDCache(void *, void *);
extern int sceDbcSendData3(int, int, void *, void *, void *);
extern void sceMc2SifCallback(void);
extern E2BB520 *SyncDma(int);
int _sceMcCoreGetCardSpec(int i, Sub *dst)
{
    int l;
    E2BB520 *r;
    if (sceDbcGetConnection(D_00518A08[i].sock) == 3) return 0;
    l = 0x2080;
    D_00518A40.x8 = 0;
    D_00518A40.xC = 0;
    D_00518A40.x10 = 0;
    D_00518A40.x14 = 0;
    D_00518A40.x18 = 0;
    D_00518A40.x1C = 0;
    D_00518A40.x20 = 0;
    D_00518A40.x24 = 0;
    memset(D_0051AAC0, 0, 0x100);
    SyncDCache(D_0051AAC0, D_0051AAC0 + 0xFF);
    D_0048C09C = 3;
    while (sceDbcSendData3(D_00518A08[i].sock, D_0048C09C, &l, &D_00518A40, sceMc2SifCallback) != 1);
    r = SyncDma(D_00518A08[i].sock);
    if (r->x8 == 0) return 0;
    D_00518A08[i].s.x8 = r->b[0] + (r->b[1] << 8);
    D_00518A08[i].s.xC = r->b[2] + (r->b[3] << 8);
    D_00518A08[i].s.x10 = r->b[4] + (r->b[5] << 8) + (r->b[6] << 16) + (r->b[7] << 24);
    D_00518A08[i].s.x14 = 1;
    *dst = D_00518A08[i].s;
    return 1;
}


