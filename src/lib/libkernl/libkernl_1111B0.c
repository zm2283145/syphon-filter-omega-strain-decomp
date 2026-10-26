extern void _sceFsSemInit(void);
extern void WaitSema(int a);
extern int D_00486244;
int _sceFsWaitS(void)
{
    _sceFsSemInit();
    WaitSema(D_00486244);
    return 0;
}