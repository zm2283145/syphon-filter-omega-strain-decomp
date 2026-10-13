extern int D_00490890;
extern int D_00490894;
extern int func_002F5150(void);
int func_002F5160(void)
{
    int now = func_002F5150();
    int d;
    if (D_00490890 == 1 && D_00490894 == 0) D_00490894 = now;
    d = now - D_00490894;
    if (d > 0x47FFF) {
        unsigned int q = (unsigned int)d / 0x48000;
        D_00490890 += q;
        D_00490894 += q * 0x48000;
    } else if (d < 0) {
        D_00490890 += (unsigned int)d / 0x48000;
        D_00490894 = now;
    }
    return D_00490890 ? D_00490890 : 1;
}
