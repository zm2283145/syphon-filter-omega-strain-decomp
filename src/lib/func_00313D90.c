extern unsigned short D_004B12F0;
void func_00313D90(int *out)
{
    if ((D_004B12F0 >> 8) == 0x23) *out = 1;
    else *out = 0;
}