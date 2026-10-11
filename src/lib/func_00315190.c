extern int func_00315028(int a, int** out);
int func_00315190(int a, int* out)
{
    int* p;
    int r;
    if (out == 0)
        return 0x17;
    r = func_00315028(a, &p);
    if (r == 0)
        *out = p[0xA4 / 4];
    return r;
}
