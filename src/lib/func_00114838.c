extern int D_00486258;
extern char D_004E6000[];
extern int D_004E6040[];
extern int D_004E6080[];
extern int func_00110528(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
unsigned int func_00114838(int a0)
{
    if (D_00486258 < 0) return 0;
    D_004E6080[0] = a0;
    if (func_00110528(D_004E6000, 9, 0, D_004E6080, 4, D_004E6040, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_004E6040[0];
}
