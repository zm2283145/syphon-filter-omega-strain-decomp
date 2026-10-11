extern int func_002FC388(int, float *);
extern int func_002E5008(int, int);
int func_002DD0F0(float *out)
{
    float buf[16];
    int r;
    if (out == 0) return 0x17;
    r = func_002E5008(func_002FC388(0, buf), 0x18);
    if (r) return r;
    out[2] = buf[6];
    out[3] = buf[7];
    out[0] = buf[3];
    out[1] = buf[4];
    out[6] = buf[12];
    out[7] = buf[13];
    out[4] = buf[9];
    out[5] = buf[10];
    return r;
}
