extern unsigned char D_004908A0;
extern int D_004908D4;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034B8A8(char *, char *);
extern int func_0034B7E8(char *);
int func_002F6C48(void)
{
    if (D_004908A0 != 1) return 5;
    if (func_0034B8A8(D_00525600, D_00525640) < 0) return 1;
    func_0034B7E8(D_00525600);
    D_004908A0 = 0;
    D_004908D4 = -1;
    return 0;
}
