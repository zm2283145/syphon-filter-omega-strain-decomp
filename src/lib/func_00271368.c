int sceSifSetSreg(int, int);
extern int D_0048B2C8;

void _iopnotify(int a) {
    if (a == 1) {
        D_0048B2C8 = 0;
        sceSifSetSreg(1, 0);
    }
}