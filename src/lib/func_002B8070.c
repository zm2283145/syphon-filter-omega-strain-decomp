typedef struct { int buf[0x100]; int buf2[0x100]; int f800; int f804; char cwd[0x84]; int f88C; int f890; int f894; } MC2Cache;
typedef struct { char c[2]; } MC2Str2;
extern MC2Cache D_00512C88[];
extern const char D_004AC1C8[];
extern int func_002BC788(int);
extern int func_002BAA20(int, int *);
extern int _sceMcCoreBlockErase(int, int);
int _sceMcFatUnFormat(int idx)
{
    int info[4];
    int i, n;
    if (!func_002BC788(idx)) return 0x81010013;
    if (!func_002BAA20(idx, info)) return 0x8101006F;
    D_00512C88[idx].f894 = 0;
    D_00512C88[idx].f800 = -1;
    D_00512C88[idx].f804 = -1;
    D_00512C88[idx].f890 = 0;
    D_00512C88[idx].f88C = 0;
    __builtin_memcpy(D_00512C88[idx].cwd, D_004AC1C8, 2);
    n = info[2] / info[1];
    for (i = 0; i < n; i++) {
        if (!_sceMcCoreBlockErase(idx, i)) return 0x8101006F;
    }
    return 0;
}


