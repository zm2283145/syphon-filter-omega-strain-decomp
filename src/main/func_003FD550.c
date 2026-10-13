extern unsigned char D_0055D450;
extern int D_0055CA90;
extern unsigned int strlen(const char*);

int AgentFile_EncodeName(const char* in, char* out, int digit, unsigned int max)
{
    if (!D_0055D450 || !D_0055CA90)
        return 0;
    if (!in || !out || strlen(in) * 2 + 1 >= max)
        return 0;
    if (digit < 0 || digit > 9)
        return 0;
    while (*in) {
        unsigned char c = *in;
        int idx;
        int hi;
        if (c < 0x20)
            return 0;
        idx = c - 0x20;
        if (idx >= D_0055CA90)
            return 0;
        hi = 0;
        while (idx >= 0x3E) {
            idx -= 0x3E;
            hi++;
        }
        out[0] = hi + 0x30;
        in++;
        out[1] = idx + 0x40;
        out += 2;
    }
    out[0] = digit + 0x30;
    out[1] = 0;
    return 1;
}

