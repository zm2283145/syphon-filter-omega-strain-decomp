typedef struct { int a; int pad[6]; } EB898;
extern EB898 D_00518A08[];
int func_002BB898(unsigned int i)
{
    if (i >= 2)
        return 0;
    return D_00518A08[i].a != 0;
}
