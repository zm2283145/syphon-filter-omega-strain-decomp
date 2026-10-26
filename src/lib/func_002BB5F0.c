extern char D_0051AAC0[];
extern void func_002BC808(void);
extern void SyncDCache(char *, char *);
extern int sceDbcGetConnection(int);
char *SyncDmaForRead(int a)
{
    char *p = D_0051AAC0;
    func_002BC808();
    SyncDCache(p, p + 0x7F);
    if (*(int *)p > 0) return p;
    if (sceDbcGetConnection(a) == 3) {
        ((int *)p)[2] = 0;
        return p;
    }
    ((int *)p)[2] = 0;
    return p;
}
