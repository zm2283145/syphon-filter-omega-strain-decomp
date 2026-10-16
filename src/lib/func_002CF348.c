extern short D_0048C414;
extern char D_004AD230[];
extern int func_002CEAD8(void);
extern int func_002EC4F8(void);
extern int printf(const char *, ...);
int MGCLUpdate(void)
{
    int r;
    if (D_0048C414 != 1) return -0xC;
    r = func_002CEAD8();
    if (r != 0) return r;
    r = func_002EC4F8();
    if (r != 0) {
        printf(D_004AD230, r);
        return -8;
    }
    return r;
}
