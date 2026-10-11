extern int D_0048C4B0;
extern int func_00303080(int, int, int);
extern int func_002DCD00(unsigned int);
extern int func_002FC428(int, int);
extern int func_002FC4C8(int, int);
extern int func_002E5008(int, int);
int func_002DD030(unsigned int a, int b, int c)
{
    int r;
    if (a == 0xFFFF || a == 0) {
        if (func_00303080(D_0048C4B0, b, c)) return 0x25;
    } else {
        r = func_002E5008(func_002FC428(func_002DCD00(a), b), 0x18);
        if (r) return r;
        r = func_002E5008(func_002FC4C8(func_002DCD00(a), c), 0x18);
        if (r) return r;
    }
    return 0;
}
