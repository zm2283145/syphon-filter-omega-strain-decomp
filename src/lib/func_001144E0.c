extern int D_00486258;
extern char D_004E6000[];
extern int D_004E6040[];
extern int D_004E6080[];
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
int func_001144E0(int a0)
{
    if (D_00486258 < 0) return 0;
    D_004E6080[0] = a0;
    if (sceSifCallRpc(D_004E6000, 2, 0, D_004E6080, 4, D_004E6040, 4, 0, 0) < 0) return -1;
    return D_004E6040[0];
}