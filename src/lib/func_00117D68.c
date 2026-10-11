typedef struct N7D68 { struct N7D68 *next; int p[3]; } N7D68;
extern N7D68 D_004E96C0[];
extern N7D68 *D_004E9AC0;

int func_00117D68(void)
{
    int i;
    D_004E9AC0 = D_004E96C0;
    for (i = 0x3F; i >= 0; i--) D_004E96C0[i].next = &D_004E96C0[i + 1];
    D_004E96C0[0x3F].next = 0;
    return 0;
}