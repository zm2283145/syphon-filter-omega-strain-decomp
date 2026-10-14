void func_002F4E20(unsigned int ip, char *out)
{
    unsigned int i, v;
    if (out == 0) return;
    for (i = 0; i < 4; i++) {
        if (i) *out++ = '.';
        v = (ip & 0xFF000000) >> 24;
        ip <<= 8;
        if (v >= 100) {
            *out++ = v / 100 + '0';
            v = v % 100;
            goto tens;
        }
        if (v >= 10) {
tens:
            *out++ = v / 10 + '0';
            v = v % 10;
        }
        *out++ = v + '0';
    }
    *out = 0;
}
