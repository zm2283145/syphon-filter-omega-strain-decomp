#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
extern int func_00107A38(void *, int);
extern void func_0010BD90(void *, const char *);
extern int func_00107ED8(void *, int);
extern void func_00107DC8(void *, int);
extern void func_00107428(void *, int *, int *, int *, int, int, int, int, int, int, int);
extern void func_001075C8(void *, int *, int *, int, int, int, int, int);
extern void func_00109700(int, int);
extern void func_00107748(void *);
extern void func_00107718(void *, int);

int func_00106EF8(void *m, int *macroblock_type, int *motion_type, int *dct_type,
                  int *PMV, int *mvfs, int *dmvector)
{
    int motion_vector_count;
    int mv_format;
    int dmv;
    int mvscale;

    REG(0x10002010) = (REG(0x10002010) & 0xF8FFFFFF) | (F(m, 0x168, int) << 24);
    *macroblock_type = func_00107A38(m, 1);
    if (!*macroblock_type) {
        func_0010BD90(m, "Invalid macroblock_type code: 0");
        F(m, 0x134, int) = 1;
        return 0;
    }
    if (*macroblock_type & 0xC) {
        if (F(m, 0x18C, int) == 3 && F(m, 0x194, int))
            *motion_type = 2;
        else
            *motion_type = func_00107ED8(m, 2);
    } else if ((*macroblock_type & 1) && F(m, 0x198, int)) {
        *motion_type = F(m, 0x18C, int) == 3 ? 2 : 1;
    }

    if (F(m, 0x18C, int) == 3) {
        motion_vector_count = *motion_type == 1 ? 2 : 1;
        mv_format = *motion_type == 2;
    } else {
        motion_vector_count = *motion_type == 2 ? 2 : 1;
        mv_format = 0;
    }
    dmv = *motion_type == 3;
    mvscale = !mv_format && F(m, 0x18C, int) == 3;

    *dct_type = (F(m, 0x18C, int) == 3 && !F(m, 0x194, int) && (*macroblock_type & 3))
                    ? func_00107ED8(m, 1) : 0;

    if (*macroblock_type & 0x10)
        F(m, 0x1CC, int) = func_00107ED8(m, 5);

    if ((*macroblock_type & 8) || ((*macroblock_type & 1) && F(m, 0x198, int))) {
        if (F(m, 0x860, int))
            func_00107428(m, PMV, dmvector, mvfs, 0, motion_vector_count, mv_format,
                          F(m, 0x17C, int) - 1, F(m, 0x180, int) - 1, dmv, mvscale);
        else
            func_001075C8(m, PMV, dmvector, F(m, 0x170, int) - 1, F(m, 0x170, int) - 1, 0, 0,
                          F(m, 0x16C, int));
    }
    if (F(m, 0x134, int))
        return 0;

    if (*macroblock_type & 4) {
        if (F(m, 0x860, int))
            func_00107428(m, PMV, dmvector, mvfs, 1, motion_vector_count, mv_format,
                          F(m, 0x184, int) - 1, F(m, 0x188, int) - 1, 0, mvscale);
        else
            func_001075C8(m, PMV + 2, dmvector, F(m, 0x178, int) - 1, F(m, 0x178, int) - 1, 0, 0,
                          F(m, 0x174, int));
    }
    if (F(m, 0x134, int))
        return 0;

    if ((*macroblock_type & 1) && F(m, 0x198, int))
        func_00107DC8(m, 1);

    if (*macroblock_type & 3) {
        func_00109700(F(m, F(m, 0x828, int) * 0x140 + 0x5AC, int), 0x300);
        func_00107748(m);
        func_00107718(m, ((*macroblock_type & 1) << 27) | (*dct_type << 25) | ((F(m, 0x1C8, int) << 26) | 0x20000000) | (F(m, 0x1CC, int) << 16));
    } else {
        F(m, F(m, 0x828, int) * 0x140 + 0x6E4, int) = 1;
    }
    F(m, 0x1C8, int) = 0;
    if (F(m, 0x134, int))
        return 0;

    if (!(*macroblock_type & 1))
        F(m, 0x1C8, int) = 1;

    if ((*macroblock_type & 1) && !F(m, 0x198, int)) {
        PMV[0] = PMV[1] = PMV[4] = PMV[5] = 0;
        PMV[2] = PMV[3] = PMV[6] = PMV[7] = 0;
    }

    if (F(m, 0x168, int) == 2 && !(*macroblock_type & 9)) {
        PMV[0] = PMV[1] = PMV[4] = PMV[5] = 0;
        if (F(m, 0x18C, int) == 3) {
            *motion_type = 2;
        } else {
            *motion_type = 1;
            mvfs[0] = F(m, 0x18C, int) == 2;
        }
    }
    return 1;
}



