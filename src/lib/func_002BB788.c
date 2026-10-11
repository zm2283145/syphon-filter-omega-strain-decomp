typedef struct { int used; char pad[0x18]; } SBB788;
extern SBB788 D_00518A08[];
int func_002BB788(void)
{
    int i;
    for (i = 0; i < 2; i++)
        if (D_00518A08[i].used == 0) return i;
    return -1;
}