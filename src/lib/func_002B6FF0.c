typedef struct { int buf[0x100]; int buf2[0x100]; int f800; int f804; char cwd[0x88]; int f890; int f894; } MC2Cache;
typedef struct { char pad[0x170]; int f170; char pad2[0x10]; } MC2Super;
extern MC2Cache D_00512C88[];
extern MC2Super D_0048BD90[];
int __attribute__((weak, section(".dtors_drop"))) func_002B6BB0(int idx, int n, int *err) { return 0; } /* stub: defined in same original TU */
int func_002B6FF0(int idx, int *err)
{
    MC2Super *sb = &D_0048BD90[idx];
    int i;
    int cnt = 0;
    *err = 0;
    for (i = D_00512C88[idx].f890; i < sb->f170; i++) {
        int v = func_002B6BB0(idx, i, err);
        if (*err) return 0;
        if (!(v & 0x80000000)) cnt++;
    }
    return cnt;
}
