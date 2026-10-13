typedef void (*CB0E28)(int, int);
typedef struct { int f0; int f4; int f8; int fC; } A0E28;
extern int D_0048C3D8;
extern char D_004AD480[];
extern void printf(char *, ...);
extern CB0E28 func_002CEBB0(void);
void func_002D0E28(A0E28 *a)
{
    int r;
    if (a->f4 == 1) {
        D_0048C3D8 = a->f0;
        r = 0;
    } else {
        D_0048C3D8 = a->f0;
        r = -2;
        printf(D_004AD480, a->fC, a->f8);
    }
    if (func_002CEBB0() != 0) func_002CEBB0()(D_0048C3D8, r);
}
