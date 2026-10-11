typedef struct { int a; int b; int pad; int c; int d[0x800]; } R;
extern R D_005141C0[];
extern int func_002BAD00(int, int *, int, int);
int func_002BAD48(int i)
{
    int r;
    if (D_005141C0[i].a == -1) return 1;
    r = func_002BAD00(i, D_005141C0[i].d, D_005141C0[i].a, D_005141C0[i].c);
    D_005141C0[i].a = -1;
    D_005141C0[i].c = 0;
    return r;
}
