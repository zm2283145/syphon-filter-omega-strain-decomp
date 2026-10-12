typedef struct { int buf[0x100]; int buf2[0x100]; int f800; int f804; char cwd[0x8C]; int f894; } MC2Cache;
extern MC2Cache D_00512C88[];
extern int func_002BAD00(int, void *, int, int);
int func_002B6B28(int idx)
{
    if (D_00512C88[idx].f800 > 0 && D_00512C88[idx].f894 == 1) {
        if (!func_002BAD00(idx, D_00512C88[idx].buf2, D_00512C88[idx].f800, 1)) return 0;
    }
    D_00512C88[idx].f894 = 0;
    return 1;
}
