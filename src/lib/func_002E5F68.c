typedef struct { char pad[0x10]; int h; char pad2[0x18]; char sub[0x18]; } E2E5F68;
extern E2E5F68 *D_0048C4A8;
extern void func_002DD328(int *);
extern void func_002F5348(char *);
int func_002E5F68(void)
{
    unsigned int i;
    if (D_0048C4A8 == 0) return 0;
    for (i = 0; i < 0x800; i++) {
        if (D_0048C4A8[i].h) func_002DD328(&D_0048C4A8[i].h);
        if (D_0048C4A8[i].sub) func_002F5348(D_0048C4A8[i].sub);
    }
    return 0;
}
