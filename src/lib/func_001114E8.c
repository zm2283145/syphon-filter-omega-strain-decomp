extern int Name_Compare48(const char *, const char *, int);
extern char D_004E5F28[];
extern char D_0048618C[];
extern char D_00498B68[];
static void * const dat_00486250[2] = { (void*)D_00498B68, (void*)0x0 };

int func_001114E8(void)
{
    char *b = D_0048618C;
    char *a = D_004E5F28;
    int r = 0;
    if (Name_Compare48(a, b, 4) && Name_Compare48(a, (*(char **)dat_00486250), 4))
        r = Name_Compare48(b, (*(char **)dat_00486250), 4) != 0;
    return r;
}