extern short D_00491432;
extern unsigned char D_00491430;
int func_003143E0(void)
{
    if (D_00491432 <= 0) return 0x11;
    if (D_00491430 != 1) return 0x11;
    if (D_00491432 == 1) D_00491430 = 0;
    D_00491432--;
    return 0;
}