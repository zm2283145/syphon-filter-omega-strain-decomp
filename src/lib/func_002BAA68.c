typedef struct { int w[0x61]; } S2BAA68;
extern S2BAA68 D_0048BD90[];
extern char D_00518200[];
extern int _sceMcCoreReadPage2(int, char *, int, int, int);
int _sceMcpReadSysInfo(int idx)
{
    if (!_sceMcCoreReadPage2(idx, D_00518200, 0, 1, 0)) return 0;
    D_0048BD90[idx] = *(S2BAA68 *)D_00518200;
    return 1;
}
