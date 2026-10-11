extern int D_0048C4B0;
extern char D_005880A0[];
extern unsigned short D_0058D178;
extern int func_003029B8(int, int, int *);
extern int func_00302A38(int, int, int, char *, unsigned short *);
extern int func_002DD280(void);
extern void Net_DispatchRecv(int, int, int, int, unsigned short);
void func_002E64E0(int a, int b, unsigned short c)
{
    int st = -1;
    if (func_003029B8(D_0048C4B0, a, &st)) return;
    if (func_00302A38(D_0048C4B0, a, st, D_005880A0, &D_0058D178)) return;
    Net_DispatchRecv(func_002DD280(), 0, (unsigned short)a, b, c);
}
