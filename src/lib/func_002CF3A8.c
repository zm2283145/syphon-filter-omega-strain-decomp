extern short D_0048C414;
extern int D_0048C418;
extern char D_004AD288[];
extern int NetClose(void);
extern int printf(const char *, ...);
int Medius_CloseReportLib(void)
{
    int r = 0;
    if (D_0048C414 != 1) return -0xC;
    if (D_0048C418 == 1) r = NetClose();
    if (r == 0) {
        D_0048C414 = 0;
        return 0;
    }
    printf(D_004AD288, r);
    return -7;
}
