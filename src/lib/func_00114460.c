extern int D_00486258;
extern char D_004E6000[];
extern int D_004E6040[];
extern int D_004E6080[];
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);

int func_00114460(int a0, int a1, int a2)
{
    if (D_00486258 < 0) return 0;
    D_004E6080[0] = a1;
    D_004E6080[1] = a0;
    D_004E6080[2] = a2;
    if (sceSifCallRpc(D_004E6000, 4, 0, D_004E6080, 12, D_004E6040, 4, 0, 0) < 0) return 0;
    return D_004E6040[0];
}