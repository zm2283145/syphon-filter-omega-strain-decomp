typedef struct { int used; int id; char pad[0x14]; } SBB928;
extern SBB928 D_00518A08[];
int func_002BB928(int id)
{
    int i;
    for (i = 0; i < 2; i++)
        if (D_00518A08[i].used && D_00518A08[i].id == id) return i;
    return -1;
}