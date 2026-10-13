extern int D_0048C4E8;
extern int func_002F5160(void);
int func_002ED5C0(void)
{
    if (D_0048C4E8 == 0) D_0048C4E8 = func_002F5160();
    D_0048C4E8 = D_0048C4E8 * 0x343FD + 0x269EC3;
    return (D_0048C4E8 >> 16) & 0x7FFF;
}
