extern int D_00518A00[];
extern void DeleteSema(int);
int func_002BB738(void)
{
    if (D_00518A00[0] >= 0) DeleteSema(D_00518A00[0]);
    if (D_00518A00[1] >= 0) DeleteSema(D_00518A00[1]);
    return 1;
}