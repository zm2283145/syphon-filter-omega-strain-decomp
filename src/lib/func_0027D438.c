extern volatile int D_0048B378;
extern int WaitSema(int);
extern int PollSema(int);
extern int sce_delete_sema(void);

int sce_sync(int mode)
{
    int r = 1;
    if (D_0048B378 < 0) return -1;
    switch (mode) {
    case 0:
        WaitSema(D_0048B378);
        r = 0;
        sce_delete_sema();
        break;
    case 1:
        if (PollSema(D_0048B378) == -1) break;
        r = 0;
        sce_delete_sema();
        break;
    default:
        return -0x65;
    }
    return r;
}