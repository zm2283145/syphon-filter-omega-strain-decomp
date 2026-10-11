typedef struct { int a, b, c; int used; char pad[0xC]; } SE1BA0;
extern SE1BA0 D_0058D188[];
int func_002E1BA0(void)
{
    int i;
    for (i = 0; i < 0x7F; i++)
        if (D_0058D188[i].used == 0) return i;
    return 0x7F;
}