const unsigned int D_004908A0[2] = { 0x0, 0x0 };
const unsigned int D_004908A8[6] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
const unsigned int D_004908C0[5] = { 0x0, 0x0, 0x0, 0x0, 0x0 };
extern int D_004908D4;
extern char D_00525600[];
extern char D_00525640[];
extern void func_00271280(int);
extern void sceLibnetInitialize(char *, int, int, int);
extern int func_0034B868(char *, char *);
extern int func_002F78D0(void);
extern int func_002F7A30(char *);
extern int func_002F7AB0(char *);
int func_002F6B80(void)
{
    int r;
    if ((*(unsigned char*)D_004908A0)) return 4;
    func_00271280(0);
    sceLibnetInitialize(D_00525600, 0x800, 0x2000, 0x20);
    if (func_0034B868(D_00525600, D_00525640) < 0) return 1;
    r = func_002F78D0();
    if (r) return r;
    if (D_004908D4 < 0) return 1;
    r = func_002F7A30(((char*)D_004908A8));
    if (r) return r;
    r = func_002F7AB0(((char*)D_004908C0));
    if (r) return r;
    (*(unsigned char*)D_004908A0) = 1;
    return 0;
}
