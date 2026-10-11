extern int D_00486258;
extern char D_004E6000[];
extern int D_004E6040[];
extern int D_004E6080[];
extern int func_00110528(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
unsigned int func_001146D8(void)
{
    if (D_00486258 < 0) return 0;
    if (func_00110528(D_004E6000, 6, 0, 0, 0, D_004E6040, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_004E6040[0];
}
