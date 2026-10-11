extern unsigned char D_0048C4AC;
extern int D_0058DF84;
extern int D_0058D180;
extern int D_0059841C;
extern char D_004ADC00[];
extern int func_002DF708(void);
extern int func_002FC118(char *);
extern int func_002E5008(int, int);
extern int func_001298B8(char *, char *, int);
extern int func_002DD380(char *, char *);
extern int func_002DDFF8(int, char *, int, int, int, int *);
int func_002DF828(int a)
{
    char buf[16];
    char buf2[16];
    int x;
    int r;
    if (D_0048C4AC == 0) {
        r = func_002DF708();
        if (r) return r;
    }
    r = func_002E5008(func_002FC118(buf), 0x18);
    if (r) return r;
    D_0058DF84 = a;
    x = D_0058D180;
    if (func_001298B8(buf, D_004ADC00, 0x10) == 0) return 0x23;
    func_002DD380(buf2, buf);
    return func_002DDFF8(0, buf2, 0, D_0059841C, 4, &x);
}
