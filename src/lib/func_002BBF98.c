typedef struct { int a; int h; int b, c, d, e, f; } E2BBF98;
typedef struct { int a, b; } O2BBF98;
typedef struct { int a, b, n; O2BBF98 v; } R2BBF98;
extern E2BBF98 D_00518A08[];
extern char D_0051AAC0[], D_00518A40[];
extern int D_0048C09C;
extern int sceDbcGetConnection(int);
extern void *memset(void *, int, unsigned int);
extern int sceDbcSendData3(int, int, void *, void *, void *);
extern void sceMc2SifCallback();
extern R2BBF98 *SyncDma(int);
int _sceMcCoreReadClock(int idx, O2BBF98 *out)
{
    int cmd[4];
    R2BBF98 *r;
    if (sceDbcGetConnection(D_00518A08[idx].h) == 3) return 0;
    cmd[0] = 0x2080;
    memset(D_0051AAC0, 0, 0x100);
    D_0048C09C = 10;
    while (sceDbcSendData3(D_00518A08[idx].h, D_0048C09C, cmd, D_00518A40, sceMc2SifCallback) != 1);
    r = SyncDma(D_00518A08[idx].h);
    if (r->n == 0) return 0;
    *out = r->v;
    return r->n;
}