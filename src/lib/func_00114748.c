extern int D_00486258;
extern char D_004E6000[];
extern int D_004E6040[];
extern int D_004E6080[];
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
unsigned int func_00114748(void)
{
    if (D_00486258 < 0) return 0;
    if (sceSifCallRpc(D_004E6000, 7, 0, 0, 0, D_004E6040, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_004E6040[0];
}
