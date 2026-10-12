extern int Name_Compare48(const char *, const char *, int);
extern char D_004E63E8[];
extern char D_0048618C[];
extern char D_00498B70[];
static char *D_00486264 = D_00498B70;
int func_001149B8(void)
{
    char *b = D_0048618C;
    char *a = D_004E63E8;
    int r = 0;
    if (Name_Compare48(a, b, 4) && Name_Compare48(a, D_00486264, 4))
        r = Name_Compare48(b, D_00486264, 4) != 0;
    return r;
}