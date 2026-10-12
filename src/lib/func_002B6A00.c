typedef struct { int buf[0x200]; int f800; int f804; char cwd[0x8C]; int f894; } MC2Cache;
typedef struct { char pad[0x50]; int ifc[0x4D]; } MC2Super;
extern MC2Cache D_00512C88[];
extern MC2Super D_0048BD90[];
extern int func_002BACB8(int, void *, int, int);
int func_002B6A00(int idx, int n, int *err)
{
    MC2Super *sb = &D_0048BD90[idx];
    int hi = n / 0x10000;
    int lo = n / 0x100 - hi * 0x100;
    int v;
    if (D_00512C88[idx].f804 != hi) {
        if (!func_002BACB8(idx, D_00512C88[idx].buf, sb->ifc[hi], 1)) {
            *err = 0x8101006F;
            return 0;
        }
        D_00512C88[idx].f804 = hi;
    }
    v = D_00512C88[idx].buf[lo];
    if (v < 0) {
        *err = 0x81019001;
        return 0;
    }
    *err = 0;
    return v;
}
