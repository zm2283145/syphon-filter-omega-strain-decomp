extern int D_004861A0;
extern char D_004E2C00[];
extern void func_0010E4C0(char *);
void func_0010EA70(int c)
{
    int n;
    if (D_004861A0 >= 0x7E) {
        D_004861A0 = 0;
        D_004E2C00[0x7F] = 0;
        func_0010E4C0(D_004E2C00);
    }
    if (c == '\n') {
        n = D_004861A0;
        D_004861A0 = 0;
        D_004E2C00[n] = c;
        D_004E2C00[n + 1] = 0;
        func_0010E4C0(D_004E2C00);
    } else {
        D_004E2C00[D_004861A0++] = c;
    }
}