typedef struct { int x0, x4, x8, xC, x10, x14, x18; } E2BBD00;
extern E2BBD00 D_00518A08[];
extern char D_0051AAC0[];
extern char D_00518A40[];
extern int D_0048C09C;
extern int sceDbcGetConnection(int);
extern void *memset(void *, int, unsigned int);
extern void SyncDCache(char *, char *);
extern int sceDbcSendData3(int, int, int *, char *, void (*)(void));
extern void sceMc2SifCallback(void);
extern char *SyncDma(int);
int _sceMcCoreCheckNewCard(int i)
{
    int hdr[4];
    if (sceDbcGetConnection(D_00518A08[i].x4) == 3) return 0;
    hdr[0] = 0x2080;
    memset(D_0051AAC0, 0, 0x100);
    SyncDCache(D_0051AAC0, D_0051AAC0 + 0xFF);
    D_0048C09C = 0xC;
    while (sceDbcSendData3(D_00518A08[i].x4, D_0048C09C, hdr, D_00518A40, sceMc2SifCallback) != 1)
        ;
    return *(int *)(SyncDma(D_00518A08[i].x4) + 8) != 0;
}
