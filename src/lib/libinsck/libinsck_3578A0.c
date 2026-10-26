extern int *func_003583F0(void);
extern int inet_ntop4(int, int, int);
extern int inet_ntop6(int, int, int);
extern int sceInsockGetErrnoMode(void);
extern int *Newlib_Errno(void);
int sceInsockInetNtop(int op, int a, int b, int c)
{
    int *e;
    switch (op) {
    case 2:
        return inet_ntop4(a, b, c);
    case 0x1C:
        return inet_ntop6(a, b, c);
    }
    *func_003583F0() = 0x6A;
    if (sceInsockGetErrnoMode() != 0) {
        e = Newlib_Errno();
        *e = *func_003583F0();
    }
    return 0;
}