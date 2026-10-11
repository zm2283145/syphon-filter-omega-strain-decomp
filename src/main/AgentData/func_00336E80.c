typedef struct { char d[0xAC]; } E36E80;
extern int D_0052FE80;
extern E36E80 D_0052FE90[];
E36E80* func_00336E80(int unused, int i)
{
    if (i >= 0 && i < D_0052FE80)
        return &D_0052FE90[i];
    return 0;
}