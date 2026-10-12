static unsigned int dat_004861A0[1] = { 0x0 };
extern char D_004E2C00[];
extern void func_0010E4C0(char *);
void func_0010EA70(int c)
{
    int n;
    if ((*(int*)dat_004861A0) >= 0x7E) {
        (*(int*)dat_004861A0) = 0;
        D_004E2C00[0x7F] = 0;
        func_0010E4C0(D_004E2C00);
    }
    if (c == '\n') {
        n = (*(int*)dat_004861A0);
        (*(int*)dat_004861A0) = 0;
        D_004E2C00[n] = c;
        D_004E2C00[n + 1] = 0;
        func_0010E4C0(D_004E2C00);
    } else {
        D_004E2C00[(*(int*)dat_004861A0)++] = c;
    }
}