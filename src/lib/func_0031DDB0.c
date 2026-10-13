void func_0031DDB0(float* in, float* out)
{
    unsigned int i, j, k;
    out += 255;
    j = 0xA280;
    for (i = 255; i >= 0x57; i--) { j -= 0xA2; k = (((j >> 8) + 0x41) * i + 0xD1 >> 8) + 0x1D; *out-- = in[k]; }
    j = 0x457D;
    for (i = 0x57; i != 0; i--) { j -= 0xCB; *out-- = in[j >> 8]; }
}
