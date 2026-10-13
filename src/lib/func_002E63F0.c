extern unsigned int D_0048C4B0;
extern char D_005880A0[];
extern unsigned short D_0058D178;
extern int func_003029B8(unsigned int, int, int *);
extern int func_00302A38(unsigned int, int, int, char *, unsigned short *);
extern int func_002E51B8(unsigned int, char **);
extern int func_002DD5B8(int, int, char *, unsigned int);
extern int func_002DEF70(int, int);
void func_002E63F0(int a, unsigned int b)
{
    int x;
    char *p;
    int r;
    switch (b) {
    case 0:
        x = -1;
        p = 0;
        r = func_003029B8(D_0048C4B0, a, &x);
        if (r) return;
        r = func_00302A38(D_0048C4B0, a, x, D_005880A0, &D_0058D178);
        if (r) return;
        if (func_002E51B8(0, &p) == 0 && p) (*(int *)(p + 0x440))++;
        func_002DD5B8(0, a, D_005880A0, D_0058D178);
        break;    case 1:
    case 2:
        func_002DEF70(0, a);
        break;
    }
}

