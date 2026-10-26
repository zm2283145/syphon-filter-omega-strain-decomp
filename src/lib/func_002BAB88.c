typedef struct { int w[0x61]; } S2BAB88;
extern S2BAB88 D_0048BD90[];
extern char D_00518200[];
extern void *memset(void *, int, unsigned int);
extern int _sceMcCoreWritePage(int, char *, int, int);
int _sceMcpWriteSysInfo(int idx)
{
    memset(D_00518200, 0xFF, 0x800);
    *(S2BAB88 *)D_00518200 = D_0048BD90[idx];
    return _sceMcCoreWritePage(idx, D_00518200, 0, 1) != 0;
}
