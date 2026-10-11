extern void func_0010D210(void *);
extern int func_003260F0(void);
extern int func_0010D470(void *, int, int);
typedef struct { unsigned char lo:4; unsigned char b4:1; unsigned char b5:1; unsigned char top:2; } Cfg6280;
extern unsigned char D_004914A7;
int func_00326350(void)
{
    struct { unsigned int c; unsigned char b[4]; } s;
    int r;
    if (func_003260F0()) {
        r = D_004914A7;
    } else {
        func_0010D210(&s.c);
        if (((s.c >> 13) & 7) == 0) r = 0;
        else {
            func_0010D470(s.b, 1, 1);
            r = ((Cfg6280 *)s.b)->b5;
        }
    }
    return r;
}
