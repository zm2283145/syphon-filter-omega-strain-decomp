typedef struct { int used; char pad[0x330]; } E26B230;
extern int D_0048B250;
extern E26B230 D_004FBB88[16];
extern int func_0026B3A0(int i);
int func_0026B230(void)
{
    int i;
    D_0048B250 = 0;
    for (i = 0; i < 16; i++) {
        if (D_004FBB88[i].used) {
            int r = func_0026B3A0(i);
            if (r < 0) return r;
        }
    }
    return 1;
}