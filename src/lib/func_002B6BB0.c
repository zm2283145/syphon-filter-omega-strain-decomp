typedef struct { int buf[0x100]; int buf2[0x100]; int f800; int f804; char cwd[0x8C]; int f894; } MC2Cache;
extern MC2Cache D_00512C88[];
extern int func_002B6A00(int, int, int *);
int __attribute__((weak, section(".dtors_drop"))) func_002B6B28(int idx) { return 0; } /* stub: defined in same original TU */
extern int func_002BAD00(int, void *, int, int);
extern int func_002BACB8(int, void *, int, int);
int func_002B6BB0(int idx, int n, int *err)
{
    int lo = n % 256;
    int sec = func_002B6A00(idx, n, err);
    if (*err) return 0;
    if (D_00512C88[idx].f800 != sec) {
        if (!func_002B6B28(idx)) {
            *err = 0x8101006F;
            return 0;
        }
        if (D_00512C88[idx].f800 > 0 && D_00512C88[idx].f894 == 1) {
            if (!func_002BAD00(idx, D_00512C88[idx].buf2, sec, 1)) {
                *err = 0x8101006F;
                return 0;
            }
        }
        if (!func_002BACB8(idx, D_00512C88[idx].buf2, sec, 1)) {
            *err = 0x8101006F;
            return 0;
        }
        D_00512C88[idx].f800 = sec;
    }
    sec = D_00512C88[idx].buf2[lo];
    *err = 0;
    return sec;
}

